#include <iostream>
#include <stack>
using namespace std;


	class Solution
	{
	public:
		int Fibonacci(int n) {
			if ((n == 0) || (n == 1)) {
				return n;
			}
			else {
				int first = 0;
				int second = 1;
				int result = 0;
				for (int i = 2; i < n + 1; i++) {
					result = first + second;
					first = second;
					second = result;

				}
				return result;
			}
		}
	};

int main() {

	Solution test;
	cout<<test.Fibonacci(10);

	getchar();
	return 0;
}
