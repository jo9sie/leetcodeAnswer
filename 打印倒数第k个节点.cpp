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
	ListNode* deleteDuplication(ListNode* pHead, int k) {
	
		ListNode* p = pHead;
		if (p == NULL) {
			return NULL;
		}
		ListNode* pFrom = NULL;
		while (p->next != NULL) {
			ListNode* pTemp = p->next;
			p->next = pFrom;
			pFrom = p;
			p = pTemp£»
			
		
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
	Solution test;
	ListNode* head = test.buildList(8,arrayL);
	ListNode* returnNode = test.deleteDuplication(head,5);
	return 0;
}