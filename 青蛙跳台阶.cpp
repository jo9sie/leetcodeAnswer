#include <iostream>
#include <stack>
using namespace std;


	class Solution
	{
	public:
		int jumpFloor(int number) {
			if ((number == 0) || (number == 1)) {
				return number;
			}
			else if (number == 2) {
				return 2;
			}
			else {
				int first = 1;
				int second = 2;
				int result = 0;
				for (int i = 3; i < number + 1; i++) {
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
