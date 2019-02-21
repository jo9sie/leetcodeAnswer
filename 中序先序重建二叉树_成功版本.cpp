/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode) {
		TreeLinkNode* temp = pNode;
		if (temp->right != NULL) {
			TreeLinkNode* p = temp->right;
			while (p->left != NULL) {
				p = p->left;
			}
			return p;
		}
		else {

			TreeLinkNode* pCur = pNode;
			TreeLinkNode* p = pNode->next;
			while ((p->left != pCur) && (p != NULL)) {
				pCur = p;
				p = p->next;

			}
			return p;

		}

	}

};