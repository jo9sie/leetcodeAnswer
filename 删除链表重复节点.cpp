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
	ListNode* deleteDuplication(ListNode* pHead) {
	
		ListNode* p = pHead;
		bool NfindFirst = true;
		int k = 0;
		ListNode* pPre = new ListNode(-1);
		ListNode*  pReturn =NULL;
		int sameVal = -1;
		if (p == NULL) {
			return NULL;
		}
		while (p->next != NULL) {

			if (NfindFirst && (p->next->val != p->val) && (p->val != sameVal)) {
				pReturn = p;
				NfindFirst = false;
			}
			if (p->next->val == p->val) {
				ListNode* delNode = p;
				p = p->next;
				delete delNode;
				sameVal = p->val;

			}
			else if (p->val == sameVal) {
				ListNode* delNode = p;
				p = p->next;
				delete delNode;

			}
			else {
				sameVal = p->val;
				pPre->next = p;

				pPre = p;
				p = p->next;
			}
		}
		if (p->val != sameVal) {
			pPre->next = p;
			if (NfindFirst) {
				pReturn = p;
			}
		}
		else {
			ListNode* delNode = p;
		 
			delete delNode;
			pPre->next = NULL;
		
		}

		return pReturn;




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
	Solution test;
	ListNode* head = test.buildList(8,arrayL);
	ListNode* returnNode = test.deleteDuplication(head);
	return 0;
}