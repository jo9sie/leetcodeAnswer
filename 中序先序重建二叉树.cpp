#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int pEnd = pre.size() - 1;
		int vEnd = vin.size() - 1;
		TreeNode* root = constructTree(0,pEnd, 0, vEnd, pre, vin);
		printTree(root);
		return root;
	}
	TreeNode* constructTree(int p1, int p2, int vS, int vE, vector<int> pre, vector<int> vin) {
		if (p1 < p2) {
			int value = pre[p1];
			int pos = findNumber(value, vS, vE, vin);
			TreeNode* newNode = new TreeNode(value);



			//construct left tree
			TreeNode* leftNode = constructTree((p1 +1), ( p1+pos-vS), vS, (pos - 1), pre, vin);
			//construct right tree
			TreeNode* rightNode = constructTree((pos-vS+p1+ 1), p2, (pos + 1), vE, pre, vin);
			newNode->left = leftNode;
			newNode->right = rightNode;
			return newNode;
		}
		else if (p1 == p2) {
			TreeNode* newNode = new TreeNode(pre[p1]);
			newNode->left = NULL;
			newNode->right = NULL;

			return newNode;
		}
		else if (vS == vE) {
		TreeNode* newNode = new TreeNode(vin[vS]);
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}
	else {
	
	return NULL;
}
		
	}
	
	int findNumber(int target,int start,int end,vector<int> numbers) {
		int len = numbers.size();
		for (int i = start; i <= end; i++) {
			if (numbers[i] == target) {
				return i;
			}
		
		}
		return -1;
	}
	void printTree(TreeNode* node) {
		if (node != NULL) {
		cout << node->val << endl;
		printTree(node->left);
		printTree(node->right);
	}
	}
};
int main() {
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector <int> vin = { 4,7,2,1,5,3,8,6 };
	Solution test;
	TreeNode* myTree = test.reConstructBinaryTree(pre, vin);


	getchar();
	return 0;
}
