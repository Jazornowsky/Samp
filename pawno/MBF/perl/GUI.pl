#!/usr/bin/perl
# Last edit: 16.01.2011   
# License: creativecommons 3 (http://creativecommons.org/licenses/by/3.0/)
# by Jeff / Remis / Rufus (contact: remis80@gmx.net / web@jeffersongta.de)
# GUI.pl
# Usage: perl GUI.pl

# About:
# Just a frontend for brackets.pm
use strict;
use warnings;
use Tkx;
use brackets qw(getVersion findBrackets);




my $version = getVersion();
my $printingLinesEnabled = 1;



sub checkbtnTriggered { enablePrinting($printingLinesEnabled); } # call the "enablePrinting" method from brackets.pm to sync the "printEnabled" variable



print "missing brackets finder $version \n \n Starting the GUI.. \n";

# create the main window
my $window = Tkx::widget->new(".", "Missing brackets finder $version  GUI");

# a button which will open a file dialog
$window->new_button(-text => "Open file", -command => \&loadFile)->g_grid(-column => 0, -row => 0, -sticky => "nw");

# a toggle box for enabling and disabling printing lines
my $toggleBox = $window->new_ttk__checkbutton(-text => "Print lines", -variable => \$printingLinesEnabled, -command => sub {checkbtnTriggered});
$toggleBox->g_grid(-column => 1, -row => 0, -sticky => "ns");


# just to change the title:
Tkx::wm_title(".", "Missing brackets finder $version  GUI");

# the textview which will contain the output of the brackets analysis
my $textview = $window->new_tk__text(-width => 100, -height => 40, -state => "disabled");
$textview->g_grid(-column => 0, -row => 1, -sticky => "nw");

# a scrollbar for the textview
my $scrollbar = $window->new_tk__scrollbar(-command => [$textview, "yview"], -orient => "vertical");
$scrollbar->g_grid(-column => 1, -row => 1, -sticky => "ns");

print "DONE.\n";

Tkx::MainLoop();


sub loadFile # the file dialog
{
	my $filename = Tkx::tk___getOpenFile(-parent => $window);
	$textview->configure(-state => "normal");
	$textview->delete("1.0", "end");
	
	if(length $filename)
	{
		my @result = findBrackets($filename);
		foreach(@result)
		{
			$textview->insert("end", $_);
		}
		#$textview->insert("end", @result);
	}
	else
	{
		$textview->insert("end", "Error opening $filename !");
	}
		
	$textview->configure(-state => "disabled");
}
