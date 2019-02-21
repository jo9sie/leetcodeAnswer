#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	double Power(double base, int exponent) {
		int a = 0;
		int b = 0;
		int flag = 1;
		if (exponent < 0) {
			flag = -1;

		} 
		if ((exponent == 0) && (base != 0)) {
			return 1;
		}
		while (exponent > 1) {
			if ((exponent % 2) == 1) {
				a++;
			
			}
			exponent = exponent / 2;
			b++;
		}
		while (exponent < -1) {
			if ((exponent % 2) == -1) {
				a++;

			}
			exponent = exponent / 2;
			b++;
		}
	
		double num = base;
		double plus =  base;
		if (exponent < 0) {
			num = 1 / base;
			plus =1 /base;
		}
		for (int i = 0; i < b; i++) {
			

			double temp = num * num;
		
		
			num = temp;
		
		}
		for (int i = 0; i <a; i++) {
			num = num * plus;

		}

		return num;

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

	cout<<test.Power(2,0);

	getchar();
	return 0;
}
