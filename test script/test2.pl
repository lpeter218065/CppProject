use strict;
use LWP::UserAgent;
use HTML::TableExtract;

my $ua = LWP::UserAgent->new();
my $url2 = 'http://acm.zju.edu.cn/onlinejudge/showRuns.do?contestId=1';

my @head = ('Run ID','Submit Time','Judge Status','Problem ID','Language','Run Time\(ms\)','Run Memory\(KB\)','User Name');

loop:for(my $t = 1; $t <= 100; $t++) {
	my $rp = $ua->get($url2);
	my $html = $rp->content;
	my $te = HTML::TableExtract->new( headers => [@head]);
	$te->parse($html);
	foreach my $row ($te->rows) {
		foreach my $item (@$row) {
			$item =~ s/\s//gs;
		}
		# if (@$row[5] eq "Waiting" || @$row[5] eq "Running") {
			# next loop;
		# }
		if (@$row[7] eq "dap") {
			print "@head\n" ;
			print join(', ', @$row), "\n" ;
			exit;
		}
	}
}