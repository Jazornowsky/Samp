package brackets;
# Last edit: 18.01.2011   
# License: creativecommons 3 (http://creativecommons.org/licenses/by/3.0/)
# by Jeff / Remis / Rufus (contact: remis80@gmx.net / web@jeffersongta.de)
# brackets.pm
# Usage: include brackets.pm as module and export the findBrackets function

# About:
# Analyses your code in terms of angle brackets ( { }): It counts the amount of both of them
# If there are more "{" than "}" or more "}" than  "{" there is obviously a bracket missing somewhere (or even more)
# This script tells you which brackets have a missing bracket, so you can fix your code (the pawn compiler is buggy in this aspect)
# It can also help you if you don't even know whether brackets are the problem.
# The script tells your if there is everyhing with the brackets

# Credtis:
# www.perl-community.de (GwenDragon and MatthiasW): Helped me using Text::Balanced, fixing some bugs and stripping out strings (text inside quotes) and gave me more tips in perl

use strict;
use warnings;

our @EXPORT_OK;

BEGIN {
	use Exporter 'import';
	use Text::Balanced qw( extract_delimited);

	@EXPORT_OK = qw(getVersion findBrackets);
}



$brackets::version = "1.1.0";
$brackets::printing = 1;



sub enablePrinting {	$brackets::printing = shift;	}

sub getVersion {	return $brackets::version;	}


# findBrackets($filename): Looks for angle brackets without a pair and prints the line of them
sub findBrackets {
	my $filename = shift;
	my @bracketsData; # contains a hash: line, pairpos (-1 means it doesn't have a pair), type and depth
	my $depth = 1;
	my $realCount, my $countAfter = 0;

	# since we will delete the commented lines, the line information will be wrong
	# so we compare the amount of all lines in the files with the amounts of elements in the array
	# the difference will be the amount of all deleted lines. This offset will be added to the line number, to get the real line numbers.
	
	print "Reading file... \n";
	
	open(my $in, '<', $filename) or die "Can not open file $filename: $!";
	$realCount++	while <$in>;
	close $in;
	
	print "amount of lines: $realCount \n " if($brackets::printing == 1);

	open($in,'<', $filename);
	local $/ = undef; # enable localized slurp: store the whole content into $_
	my $_ = <$in>;
	# regex by Jeffrey Friedl and later Fred Curtis ( http://perldoc.perl.org/perlfaq6.html#How-do-I-use-a-regular-expression-to-strip-C-style-comments-from-a-file%3f )
	# to strip out C-like comments: //, /*  */
	s#/\*[^*]*\*+([^/*][^*]*\*+)*/|//([^\\]|[^\n][\n]?)*?\n|("(\\.|[^"\\])*"|'(\\.|[^'\\])*'|.[^/"'\\]*)#defined $3 ? $3 : ""#gse;
	close $in or die "$in: $!";;
	
	# count "\n"s
	$countAfter++	while $_ =~ /\n/g;
	
	print "lines after removing comments: $countAfter \n" if($brackets::printing == 1);
	print "DONE \n Checking for open brackets... \n";

	my $lineNumber = $realCount - $countAfter;
	my @lines = split /\n/;
	
	foreach(@lines)
	{ 
		$lineNumber++;
		print "line $lineNumber / $realCount \n" if($brackets::printing == 1);
		
		# Before, remove all strings.
		# The checked script could use brackets in texts in another term of use, for example: print("Output: {");
		# That would cause a false positive. So we remove the strings.
		# Since Iam not experienced with regex, I used a regex created by someone other: abhinavg
		# http://stackoverflow.com/questions/1067414/how-can-i-strip-html-in-a-string-using-perl/1067418#1067418
		# the original regex removed all html code (things between < and >), so I just changed < and > to " in the regex
		# s|\'.+?\'||g; 
		s/("|').+?("|')//g; 

		# Now split the line by each char and go char by char
		for( split // )
		{
			if($_ eq "}")
			{
				push @bracketsData, { line=>$lineNumber, pairpos=>-1, type=>"}", depth=>0}  if($depth <= 1);

				if($depth > 1) # we werer looking for a closing angle bracket and found the bracket pair :)
				{		    
					#Search the pair, which was looking for a pair. It has to have the same depth
					my $hrefBracket = -1;
					foreach my $href (@bracketsData)
					{
						# I need the LAST open bracket with the same depth, not the first one
						# $hrefBracket will be overwritten until I have the last one (similar to pop of a stack)
						$hrefBracket = $href if(defined $href && $href->{depth} == $depth);
					}

					if($hrefBracket == -1) # no bracket with same depth, there is one missing
					{
						push @bracketsData, { line=>$lineNumber, pairpos=>-1, type=>"}", depth=>$depth};
					}
					else # pair found, everything fine
					{
						push @bracketsData, { line=>$lineNumber, pairpos=>$hrefBracket->{line}, type=>"}", depth=>$depth};
						$hrefBracket->{haspair} = 1;
						$hrefBracket->{pairpos} = $lineNumber;
					}

					$depth--;
				}  
			}
			if($_ eq "{")
			{
				$depth++;
				push @bracketsData, { line=>$lineNumber, pairpos=>-1, type=>"{", depth=>$depth};
			}
		} 	
	}

	my $openbrackets = 0;
	my $closebrackets = 0;
	my $missing = 0;
	my @returnBuffer;

	# now go through the @bracketsData array and search for brackets without pair
	foreach my $href(@bracketsData)
	{
		$openbrackets++ if($href && $href->{type} eq "{");
		$closebrackets++ if($href && $href->{type} eq "}");

		if($href && $href->{pairpos} == -1) # bracket without pair
		{
			$missing++;
			push @returnBuffer, "MISSING BRACKET: The { bracket on line ", $href->{line}, " does not have a pair!\n"	if($href->{type} eq "{");
			push @returnBuffer, "MISSING BRACKET: The } bracket on line ", $href->{line}, " does not have a pair!\n"	if($href->{type} eq "}");
		}	
	}
	
	print "DONE \n \n";
	push @returnBuffer, "Result: \n";
	push @returnBuffer, "Opening angle brackets ({): $openbrackets \n";
	push @returnBuffer, "Closing angle brackets (}): $closebrackets \n";
	push @returnBuffer, "Everything was fine \n"	if($missing == 0); # we don't need to check whether $openbrackets is smaller or bigger than $closebrackets we already checked before
	push @returnBuffer,  $missing, " angle brackets without pair! Fix it! \n"	if($missing > 0);
			
		
	return @returnBuffer;
}

1;
