#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL),next(NULL) {}
	
};
class Solution {
public:
	TreeNode* getNext(TreeNode* pNode) {
		if (pNode->right != NULL) {
			TreeNode* p = pNode->right;
			while(p->left != NULL) {
				p = p-> left;
			}
			return p;
		}
		else {
		
			TreeNode* pCur = pNode;
			TreeNode* p = pNode->next;
			while (p->left != pCur) {
				pCur = p;
				p = p ->next;

			}
			return p;
		
		}

	}
	
	
	TreeNode* constructTree(TreeNode* left, TreeNode* right, TreeNode* next,int val) {
		TreeNode* newNode = new TreeNode(val);
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->next = NULL;

		return newNode;
	}
	TreeNode* changeNode(TreeNode* myNode, TreeNode* left, TreeNode* right, TreeNode* next) {
		myNode->left = left;
		myNode->right = right;
		myNode->next = next;

		return myNode;
	}
};
int main() {
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector <int> vin = { 4,7,2,1,5,3,8,6 };
	Solution test;
	TreeNode* t1 = test.constructTree(NULL, NULL, NULL, 1);
		TreeNode * t2 = test.constructTree(NULL, NULL, NULL, 2);
		TreeNode * t3 = test.constructTree(NULL, NULL, NULL, 3);
		TreeNode * t4 = test.constructTree(NULL, NULL, NULL, 4);
		TreeNode * t5 = test.constructTree(NULL, NULL, NULL, 5);
		TreeNode * t6 = test.constructTree(NULL, NULL, NULL, 6);
		TreeNode * t7 = test.constructTree(NULL, NULL, NULL, 7);
		TreeNode * t8 = test.constructTree(NULL, NULL, NULL, 8);

		 t1 = test.changeNode(t1,t2, t3, NULL);
	t2 = test.changeNode(t2,t4, NULL, t1);
 t3 = test.changeNode(t3,t5, t6, t1);
 t4 = test.changeNode(t4,NULL, t7, t2);
 t5 = test.changeNode(t5,NULL, NULL, t3);
	 t6 = test.changeNode(t6,t8, NULL, t3);
	 t7 = test.changeNode(t7,NULL, NULL,t4);
	 t8 = test.changeNode(t8,NULL, NULL, t6);
	 TreeNode* thisNode = test.getNext(t1);
	 cout << thisNode->val << endl;




	getchar();
	return 0;
}
