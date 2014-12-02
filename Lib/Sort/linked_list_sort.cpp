#include <iostream>
#include <cstdio>

#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *head;

//sort the linkedlist
ListNode* sortList(ListNode* head) {
	if (head->next=NULL) return head; //single node
	int length=0;
	for(ListNode *t=head; t!=NULL; t=t->next) length++;
	int m=length/2;
	int cnt=0;
	ListNode* sec;
	for(ListNode *t=head; t!=NULL; t=t->next) {
		cnt++;
		if (cnt==m) {
			sec=t->next;
			t->next=NULL;
			break;
		}
	}
	head = sort(head);
	sec = sort(sec);
	//merge the two list
	ListNode* c1=head;
	ListNode* c2=sec;
	while(c2 != NULL) {
		while(c1 != NULL && c1->val < c2->val) c1=c1->next;
		//now c1==null||c1.val>c2.val
		
	}
}

int main()
{
	//initialize
	head = new ListNode(20);
	ListNode *cur = head;
	for(int i=0;i<10;++i) {
		cur->next=new ListNode(10-i);
		cur=cur->next;
	}
	// Sort
	head=sort(head);
	
	//Print
	
	return 0;
}