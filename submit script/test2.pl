use strict;
use LWP::UserAgent;
use HTML::TableExtract;
use HTTP::Cookies;

my $cookie_jar = HTTP::Cookies->new();
my $ua = LWP::UserAgent->new();
$ua->cookie_jar($cookie_jar);

my $url = 'http://acm.zju.edu.cn/onlinejudge/login.do';
my $handle = 'lpeter';
my $password = '244393818';
my $arg = {
	"handle" => $handle,
	"password" => $password
};

my $res = $ua->post($url,$arg);


$res = $ua->get('http://acm.zju.edu.cn/onlinejudge/submit.do?problemId=1');

print $res->content;


