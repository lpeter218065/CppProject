#include <algorithm>

using namespace std;

#include "heap.h"

void siftDown(int* a, int r, int sz) {
	int c = 2*r+1;
	while(c < sz) {
		if (c+1 < sz && a[c+1] < a[c]) 
			c++;
		if (a[c] >= a[r]) break; 
		swap(a[r],a[c]);
		r = c;
		c = c*2+1;
	}
}

void siftUp(int* a, int r, int sz) {
	while(r > 0) {
		int k=(r-1)/2;
		if (a[k] > a[r]) swap(a[k], a[r]);
		else break;
		r=k;
	}
}

void makeMinHeap(int* a, int sz) {
	for(int i=sz/2-1;i>=0;--i) {
		siftDown(a,i,sz);
	}
}

void delNode(int* a, int sz) {
	swap(a[0], a[sz-1]);
	siftDown(a, 0, sz-1);
}

void heapRevSort(int* a, int n) {
	for(int i=n-1;i>=1;i--) {
		swap(a[i], a[0]);
		siftDown(a,0,i);
	}
}