use HTML::TableExtract;

open FD, "<test.html";
my $FILE = "";
while(<FD>) {
	$FILE = $FILE.$_;
}

 $te = HTML::TableExtract->new( headers => [qw(ID: Date'n'Time Name: Task: .Ext: Status: Time: Memory:)] );
 $te->parse($FILE);

 # Examine all matching tables
 # foreach $ts ($te->tables) {
   # print "Table (", join(',', $ts->coords), "):\n";
   # foreach $row ($ts->rows) {
      # print join(',', @$row), "\n";
   # }
 # }

 # Shorthand...top level rows() method assumes the first table found in
 # the document if no arguments are supplied.
 foreach $row ($te->rows) {
	foreach $item (@$row) {
		$item =~ s/\s//gs;
	}
	if (@$row[2] eq "lpeter83") {
		print join(', ', @$row), "\n" ;
		last;
	}
 }