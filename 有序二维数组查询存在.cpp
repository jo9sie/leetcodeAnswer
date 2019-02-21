


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int line = array.size();
		int col = array[0].size();
		//	cout << "line" << line<<endl;
		//	cout << "c" << col << endl;
		int i = line - 1;
		int j = 0;
		while ((i >= 0) && (j < col)) {
			//	cout << "thistime" << i << " " << j << endl;
			int minuse = array[i][j] - target;
			if (minuse == 0) {
				return true;
			}
			else if (minuse > 0) {
				i--;
			}
			else {
				j++;
			}

		}

		return false;
	}



};
int main() {

	cout << "hello world" << endl;
	int myArray[3][3] = { 1,4,5,4,5,6,7,8,9 };
	cout << myArray[1][2] << endl;


	vector<vector<int> > array;
	array.resize(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i].resize(3);
			array[i][j] = myArray[i][j];



		}
	}
	cout << "finish" << endl;
	Solution test;
	bool hi = test.Find(6, array);
	cout << hi << endl;
	getchar();
	return 0;
}