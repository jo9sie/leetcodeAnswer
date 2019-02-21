#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Step {
	bool* strMap;
	int target;
	int before;
	Step(int x,int y):strMap(NULL),target(x),before(y) {}



};

	class Solution
	{
	public:
		bool hasPath(char* matrix, int rows, int cols, char* str)
		{
			int len = rows * cols;
			bool* strMap = new bool[len];
			for (int i = 0; i < len; i++) {
				strMap[i] = true;
			}
			char target = str[0];
			int targetLen = strlen(str);
			stack<Step*> candidate;
			for (int i = 0; i < len; i++) {
				if (matrix[i] == target) {
					bool* newMap = new bool[len];
					for (int j = 0; j < len; j++) {
						newMap[j] = true;
					}
					newMap[i] = false;
					Step* newStep = new Step(0,i);
					newStep->strMap = newMap;
					candidate.push(newStep);

				}
			
			}
	//		int all = 0;
			bool print = false;
			while (!candidate.empty()) {
				Step* curStep = candidate.top();
				if (print) {
							cout << "size " << candidate.size() << endl;
				}
				candidate.pop();
				if(str[(curStep->target)]!=matrix[curStep->before]){
					
					continue;
				
				}
				else {
					if ((curStep->target)==(targetLen-1)) {
						return true;
					}
				}
				if (print) {
					cout <<"kk"<<matrix[curStep->before] << endl;
				}
				int upper = len;
				int truePos = (curStep->before) % cols;
				if ((truePos<cols)&&isRight(curStep->strMap, curStep->before + 1, len)) {
					bool* tempMap = newBoolMap(curStep->strMap, len);
					tempMap[curStep->before + 1] = false;
					Step* newStep = new Step((curStep->target)+1, curStep->before + 1);
					newStep->strMap = tempMap;
					if (print) {
							cout << matrix[curStep->before + 1] << endl;
					}
					candidate.push(newStep);
				}
				 if (isRight(curStep->strMap, curStep->before + cols, len)) {
					bool* tempMap = newBoolMap(curStep->strMap, len);
					tempMap[curStep->before + cols] = false;
					Step* newStep = new Step((curStep->target) + 1, curStep->before + cols);
					newStep->strMap = tempMap;
					if (print) {
						cout << matrix[curStep->before + cols] << endl;
					}
					candidate.push(newStep);
				}
			//	 cout << "truepos" << truePos << endl;
				 if ((truePos>0)&&isRight(curStep->strMap, curStep->before - 1, len)) {
					bool* tempMap = newBoolMap(curStep->strMap, len);
					tempMap[curStep->before - 1] = false;
					Step* newStep = new Step((curStep->target) + 1, curStep->before - 1);
					newStep->strMap = tempMap;
					if (print) {
						cout << matrix[curStep->before - 1] << endl;
					}
					candidate.push(newStep);
				}
				 if (isRight(curStep->strMap, curStep->before -cols, len)) {
					bool* tempMap = newBoolMap(curStep->strMap, len);
					tempMap[curStep->before - cols] = false;
					Step* newStep = new Step((curStep->target) + 1, curStep->before - cols);
					newStep->strMap = tempMap;
					if (print) {
						cout << matrix[curStep->before - cols] << endl;
					}
					candidate.push(newStep);
				
				}

			}
			return false;
		}
		bool* newBoolMap(bool* boolMap,int len) {
			bool* newMap = new bool[len];
			for (int i = 0; i < len; i++) {
				newMap[i] = boolMap[i];
			}
			return newMap;
		
		
		}
		bool* newBoolMap(bool* boolMap,int len) {
			bool* newMap = new bool[len];
			for (int i = 0; i < len; i++) {
				newMap[i] = boolMap[i];
			}
			return newMap;
		
		
		}

		bool isRight(bool* boolMap,int pos,int upper) {
			if ((pos < upper) && (boolMap[pos])) {
	//			cout << "can" << endl;
				return true;
			}
			else {
		//		cout << boolalpha<<boolMap [pos] << endl;
			//		cout<<"can not" << pos<<endl;
				return false;
			}
		}

	};

int main() {

	Solution test;
	 char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	 char str[] = "SLHECCEIDEJFGGFIE";
	cout<<test.hasPath(matrix,5,8,str);

	getchar();
	return 0;
}
