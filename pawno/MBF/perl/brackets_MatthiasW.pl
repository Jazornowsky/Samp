#!/usr/bin/perl

# Usage: perl brackets_MatthiasW.pl <filename>
# If it doesn't output anything, the brackets are balanced and everything is fine


# This script is made by MatthiasW and not by me
# copied from http://www.perl-community.de/bat/poard/thread/15398#ms_140866
# I added this script to my package because it may work better than mine

use strict;
use warnings;

my( $code, @open );

while ( my $line = <> ) {
    $code .= $line;

    $code =~ s/'(?:\\.|[^'])*'|"(?:\\.|[^"])*"//g; # strip strings
    $code =~ s!/\*.*\*/!!g;                        # strip comments

    if ( $code !~ /["']|\/\*/ ) {                  # no open comment/string?
        $code =~ s!//.*!!;                         # strip eol-comments
        
        for ( split //, $code ) {
            push @open, $. if /\{/;
            
            if (/\}/) {
                warn "uncalled-for closing brace at line $.\n" unless @open;
                pop @open;
            } # if
        } # for
        
        $code = '';
    } # if
} # while

warn @open ." open brace(s) not closed at line(s): ". join(", ", @open) ."\n"
    if @open;
	
	