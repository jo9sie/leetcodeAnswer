#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Step {
	int before;
	Step(int y):before(y) {}



};

	class Solution
	{
	public:
		int movingCount(int threshold, int rows, int cols)
		{
			int t = addBit(0) + addBit(0);
			if (t > threshold) {
				return 0;

			}
			int len = rows * cols;
			bool* strMap = new bool[len];
			for (int i = 0; i < len; i++) {
				strMap[i] = true;
			}
			stack<Step*> candidate;
					bool* newMap = new bool[len];
					for (int j = 0; j < len; j++) {
						newMap[j] = true;
					}
					int tempResult = addBit(0) + addBit(0);
					newMap[0] = false;
					Step* newStep = new Step(0);
					candidate.push(newStep);

		
			bool print = true;
			int max = 0;
			int times = 1;
			while (!candidate.empty()) {
				Step* curStep = candidate.top();
				if (print) {
					cout << "size " << candidate.size() << endl;
				}
				candidate.pop();
		 
				
				if (print) {
		//			cout << "kk" << matrix[curStep->before] << endl;
				}
				int upper = len;
				int truePos = (curStep->before) % cols;
				bool goOn = false;
				int trueRow = (curStep->before) % rows;
				
			
				if (canIn(curStep->before + 1,cols,rows,threshold) && isRight(newMap, curStep->before + 1, len)) {
					newMap[curStep->before + 1] = false;
					Step* newStep = new Step( curStep->before + 1);
					
					if (print) {
						cout << "pos" << endl;
						cout << curStep->before + 1 << endl;
					}
					candidate.push(newStep);
					goOn = true;
					times++;
				}
				if (canIn(curStep->before + cols, cols, rows, threshold) &&isRight(newMap, curStep->before + cols, len)) {
					newMap[curStep->before + cols] = false;
					Step* newStep = new Step(curStep->before + cols);
					if (print) {
						cout << "pos" << endl;
						cout << curStep->before + cols << endl;
					}
					candidate.push(newStep);
					goOn = true;
					times++;
				}
				//	 cout << "truepos" << truePos << endl;
				if (canIn(curStep->before - 1, cols, rows, threshold)  && isRight(newMap, curStep->before - 1, len)) {
					newMap[curStep->before - 1] = false;
					Step* newStep = new Step(curStep->before - 1);
					if (print) {
						cout << "pos" << endl;
						cout << curStep->before - 1 << endl;
					}
					candidate.push(newStep);
					goOn = true;
					times ++;
				}
				if (canIn(curStep->before -cols, cols, rows, threshold)&&isRight(newMap, curStep->before - cols, len)) {
					newMap[curStep->before - cols] = false;
					Step* newStep = new Step( curStep->before - cols);
					if (print) {
						cout << "pos" << endl;
						cout << curStep->before - cols<< endl;
					}
					candidate.push(newStep);
					goOn = true;
					times++;

				}

				

			}
			return times;
		
		
		}
		bool* newBoolMap(bool* boolMap, int len) {
			bool* newMap = new bool[len];
			for (int i = 0; i < len; i++) {
				newMap[i] = boolMap[i];
			}
			return newMap;


		}
		int addBit(int number) {
			
			int p = 1;
			int all = 0;
	//		if (number > 10) {
			//	cout << endl;
		//		cout << "start" << endl;
			//	cout << number << endl;
//			}
			while (number > p) {
				p = p * 10;
				all += (number%p)/(p/10);
				
			}
			p = p * 10;
			all += (number%p) / (p / 10);

		
	//		if (number > 10) {
		//		cout << all << endl;
			//}
			return all;
		
		}
		bool canIn(int pos, int cols, int rows, int threshold) {
			int truePos = (pos) % cols;
			int trueRow = (pos)/ cols;
			int tempResult = addBit(truePos) + addBit(trueRow);

			if ((tempResult > threshold)||(truePos<0)||(trueRow<0)) {
				return false;

				cout << "not in" << endl;
				cout <<"col "<< truePos << endl;
				cout << "row " << trueRow << endl;
				cout << threshold << endl;
				cout << pos << endl;
				cout << "result " << tempResult << endl;
				cout << "11" << endl;
				
			}
			else {
				return true;
				cout << "in" << endl;
				cout << "col " << truePos << endl;
				cout << "row " << trueRow << endl;
				cout << threshold << endl;
				cout << pos << endl;
				cout << "result " << tempResult << endl;
				cout << "11" << endl;
				
			}
		
		}
		bool isRight(bool* boolMap, int pos, int upper) {
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
	cout<<test.movingCount(-10,10,10);

	getchar();
	return 0;
}
