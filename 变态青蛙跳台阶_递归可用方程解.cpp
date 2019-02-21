#include <iostream>
#include <stack>
using namespace std;


	class Solution
	{
	public:
		int jumpFloorII(int number) {
			if ((number == 0) || (number == 1)) {
				return number;
			}
			else {
				int first = 2;
				for (int i = 2; i < number; i++) {
					first = 2 * first;

				}
				return first;
			}

		}
	};

int main() {

	Solution test;
	cout<<test.Fibonacci(10);

	getchar();
	return 0;
}
