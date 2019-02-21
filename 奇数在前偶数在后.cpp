#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		int i = 0;
		int j = len - 1;
		for (int times=0;times<len;times++){
			for (int t = 1; t < len; t++) {
				bool a = (array[t - 1] % 2) == 0;
				bool b = (array[t] % 2) == 1;
				if (a&&b) {
					int temp = array[t - 1];
					array[t - 1] = array[t];
					array[t] = temp;

				}
			}
			

		}
	}
};

int main() {

	Solution test;
	vector<int> gas;
	gas.resize(7);
	gas = { 1,2,3,4,5,6,7 };

test.reOrderArray(gas);

	getchar();
	return 0;
}
