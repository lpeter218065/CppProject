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
#include "heap.h"

typedef long long LL;
//}}}

int a[10] = {2,5,7,5,4,6,2,1,3,2};
int n = 10;


int main()
{
	makeMinHeap(a,n);
	delNode(a,n);
	heapRevSort(a,n-1);
	
	REP(i,n-1) cout << a[i] << ' ';
	cout << endl;
	return 0;
}
