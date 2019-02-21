#include <iostream>
#include <vector>
using namespace std;


	class Solution
	{
	public:
		int minNumberInRotateArray(vector<int> rotateArray) {
			if (rotateArray.size() == 0) {
				return 0;
			}
			int end = rotateArray.size()-1;
			int start = 0;
			int mid = (end + start) / 2;
			
			while ((end - start) > 1) {
				cout << start << endl;
				cout << end << endl;
				if (rotateArray[mid] > rotateArray[end]) {
					start = mid;
					mid = (start + end) / 2;
				}
				else {
					end = mid;
					mid = (start + end) / 2;

				}
			}
			return rotateArray[end];

		}
	};

int main() {

	Solution test;
	vector<int> myVec;
	myVec.resize(6);
	for (int i = 0; i < 3; i++) {
		myVec[i] = i + 4;
	}
	for (int i = 0; i < 3; i++) {
		myVec[i+3] = i + 1;
	}
	cout<<test.minNumberInRotateArray(myVec);

	getchar();
	return 0;
}
