/*JuanjuanCaier-123456*/
#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>
using namespace std;

void output(vector<float> floatData) {
	int loop = 0;
	while (loop <= 24) {
		cout << floatData[loop] << ' ';
		if ((loop + 1) % 5 == 0) {
			cout << endl;
		}
		loop++;
	}
}

int main() {
	srand(time(0));
	vector<float> floatData = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	int loop = 0;
	while (loop <= 24) {
		floatData[loop] = rand();
		floatData[loop] = (floatData[loop] / 32767) * 100;//平方后仍小于float上限
		loop++;
	}
	cout << "平方之前的：" << endl;
	output(floatData);
	cout << endl;
	loop = 0;
	while (loop <= 24) {
		floatData[loop] = floatData[loop] * floatData[loop];
		loop++;
	}
	cout << "平方之后的：" << endl;
	output(floatData);
	cout << endl;
	return 0;
}