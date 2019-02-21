#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL),next(NULL) {}
	
};

	class Solution
	{
	public:
		void push(int node) {
			if (stack1.size() != 0) {
				stack1.push(node);
			}
			else {
				stack2.push(node);
			
			}

		}

		int pop() {
			if (stack1.size() != 0) {
				int len = stack1.size()-1;
				for (int i = 0; i < len; i++) {
					
					stack2.push(stack1.top());
					stack1.pop();
				}
				int re = stack1.top();
				stack1.pop();

				int len1 = stack2.size();
					for (int i = 0; i < len1; i++) {

						stack1.push(stack2.top());
						stack2.pop();
					}

				return re;
			}
			else {
				int len = stack2.size() - 1;
				for (int i = 0; i < len; i++) {
					stack1.push(stack2.top());
					stack2.pop();
				}
				int re = stack2.top();
				stack2.pop();
				int len1 = stack1.size();
				for (int i = 0; i < len1; i++) {

					stack2.push(stack1.top());
					stack1.pop();
				}

				return re;

			}


		}
	

	private:
		stack<int> stack1;
		stack<int> stack2;
	};

int main() {

	Solution test;
	test.push(1);
	test.push(2);
	test.push(3);
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	test.push(4);
	cout << test.pop() << endl;
	test.push(5);
	cout << test.pop() << endl;

	cout << test.pop() << endl;






	getchar();
	return 0;
}
