#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int len = 0;
		int space = 0;
		while (str[len] != '\0') {
			if (str[len] == 32) {
				space++;
			}
			len++;
		}
		len++;
		int  i = len - 1;
		int  j = len - 1 + 2 * space;
		int count = 0;
		while (count < space) {
			while (str[i] != 32) {
				str[j] = str[i];
				i--;
				j--;
			}
			count++;
			i--;
			str[j] = '0';
			str[--j] = '2';
			str[--j] = '%';
			j--;
		
		}
		


	}


};
int main() {
	char my[30] = "We Happy ";
	Solution test;
	test.replaceSpace(my, 30);


	getchar();
	return 0;
}
