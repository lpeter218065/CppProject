//{{{ 
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=a;i<(b);++i)

typedef long long LL;
//}}}


int c[100][100];

int main() {

	for(int i=0;i<50;++i) {
		c[i][i]=c[i][0]=1;
		for(int j=0;j<=i;++j) {
			c[i+1][j+1]=c[i][j+1]+c[i][j];
		}
	}	
	cout<< c[4][2] << ' ' << c[3][0] << endl;
	return 0;
}