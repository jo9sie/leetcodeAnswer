#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead1, ListNode* pHead2) {

		ListNode* p2 = pHead2;
		ListNode* p1 = pHead1;
		ListNode* p = NULL;
		ListNode* pHead = NULL;
		
		ListNode* pPre = pHead;
		while ((p1->next != NULL) && (p2->next != NULL)) {
			if (p1->val < p2->val) {
				pPre->next = p1;
				p1 = p1->next;
				pPre = pPre->next;
			}
			else {
				pPre->next = p2;
				p2 = p2->next;
				pPre = pPre->next;
			}
		}
		if (p1->next != NULL) {
			pPre->next = p1->next;
		} else if(p2->next != NULL) {
			pPre->next = p2->next;
		}
		
		return p;




	}

	ListNode* buildList(int n,int arrayL[]) {
		ListNode* head = new ListNode(arrayL[0]);
		ListNode* p = head;
		for (int i = 1; i < n; i++) {
			ListNode* newNode = new ListNode(arrayL[i]);
			p->next = newNode;
			p = newNode;
		}
		return head;
	
	}
};
int main()
{
	int arrayL[8] = { 1,1,2,3,3,4,5,5 };
	int arrayR[5] = { 1,3,4,5,5 };
	Solution test;
	ListNode* head1 = test.buildList(8,arrayL);
	ListNode* head2 = test.buildList(5, arrayR);
	ListNode* returnNode = test.deleteDuplication(head,head2);
	return 0;
}