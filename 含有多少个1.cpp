#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	int  NumberOf1(int n) {
		//整数减一最右变为0
	
			int start = 1;
			int all = 0;
			while (n) {

				n = n && (n - 1);
			}
			return all;


		
	}
	};

int main() {

	Solution test;
	vector<int> gas;
	gas.resize(1);
	vector<int> cost;
	cost.resize(1);
	gas[0] = 5;
	cost[0] = 4;

	cout<<test.NumberOf1(1);

	getchar();
	return 0;
}
