#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* head;

void print_list(ListNode* head) {
	for(ListNode* t=head;t!=NULL;t=t->next) {
		cout << t->val << ' ';	
	}
	cout << endl;
}

ListNode* sortList(ListNode* head) {
	if (head->next == NULL) return head;
    print_list(head);
	int len = 0;
	int m = 0;
	for(ListNode* t=head; t!=NULL; t=t->next) {
		len++;
	}
	m = len/2;
	ListNode* curt = head;
	ListNode* cur2 = NULL;
	for(int i=1; i<m;++i) curt=curt->next;
	cur2 = curt->next;
	curt->next = NULL;
	ListNode* cur = head;
	//so far we have two lists, cur and cur2
  cur = sortList(cur);
  cur2 = sortList(cur2);
  //print_list(cur);
  //print_list(cur2);
  //compare the first one to decide which is the head
  ListNode* res = cur->val <= cur2->val ? cur:cur2;
  //start to merge two lists
	while(cur != NULL && cur2 != NULL) {
		ListNode* prv = cur;
		while(cur != NULL && cur->val <= cur2->val) {
			prv = cur;
			cur = cur->next;
		}
		if (prv->val <= cur2->val) {
      prv->next = cur2;
      if (cur == NULL) break;
    }
		if (cur2->next == NULL) {
			cur2->next = cur;
			break;
		}
		//cur2 = cur2->next;
		prv = cur2;
		while(cur2 != NULL && cur2->val <= cur->val) {
			prv = cur2;
			cur2 = cur2->next;
		}
		if (prv->val <= cur->val) prv->next = cur;
		if (cur->next == NULL) {
			cur->next = cur2;
			break;
		}
		//cur = cur->next;
	}
	return res;	
}

int main()
{
  int a[] = {-96,-91,-85,-84,-81,-76,-73,-71,-61,-85,-85,-44};
	head = new ListNode(a[0]);
	ListNode* cur = head;
	for(int i=1;i<12;++i) {
		cur->next=new ListNode(a[i]);
		cur = cur->next;			
	}

	head = sortList(head);

	//print the list
	for(ListNode* cur= head; cur!=NULL; cur=cur->next){
		cout << cur->val << ' ';
	}	
	return 0;
}
