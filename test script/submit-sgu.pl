use strict;
use LWP::UserAgent;
use HTML::TableExtract;

open FD, "<$ARGV[0]";
my $FILE = "";
while(<FD>) {
	$FILE = $FILE.$_;
}
my $url = 'http://acm.sgu.ru/sendfile.php?contest=0';

my $id = '050794';
my $pass = '244393818';
my $prob = '100';
my $lang = 'GNU CPP (MinGW, GCC 4)';

my $ua = LWP::UserAgent->new();


my $arg = {
	"id" => $id,
	"pass" => $pass,
	"problem" => $prob,
	"elang" => $lang,
	"source" => $FILE
};

my $response = $ua->post($url, $arg);

# sleep(3);

loop:for(my $t = 1; $t <= 100; $t++) {
	my $rp = $ua->get("http://acm.sgu.ru/status.php");
	my $html = $rp->content;
	my $te = HTML::TableExtract->new( headers => [qw(ID: Date'n'Time Name: Task: .Ext: Status: Time: Memory:)] );
	$te->parse($html);
	foreach my $row ($te->rows) {
		foreach my $item (@$row) {
			$item =~ s/\s//gs;
		}
		if (@$row[5] eq "Waiting" || @$row[5] eq "Running") {
			next loop;
		}
		if (@$row[2] eq "lpeter83") {
			print join(', ', @$row), "\n" ;
			exit;
		}
	}
}


