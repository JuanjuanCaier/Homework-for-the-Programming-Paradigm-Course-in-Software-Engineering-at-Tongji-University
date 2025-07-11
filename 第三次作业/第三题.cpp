/*JuanjuanCaier-123456*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void Compare(vector<int>Numbers, int IndexDiff, int ValueDiff) {
	int Loop1 = 0, Loop2 = 0;
	while (Loop1 < Numbers.size()) {
		Loop2 = Loop1 + 1;
		while (Loop2 < Numbers.size()) {
			if ((Loop1 != Loop2) && (abs(Loop1 - Loop2) <= IndexDiff) && (abs(Numbers[Loop1] - Numbers[Loop2]) <= ValueDiff)) {
				cout << "true" << endl;
				return;
			}
			Loop2++;
		}
		Loop1++;
	}
	cout << "false" << endl;
	return;
}

int main() {
	vector<int>Numbers;
	char Input;//便于读取结束标志
	int IndexDiff = 0, ValueDiff = 0;
	cout << "请输入数组，数字之间使用英文逗号隔开，左右两边包含中括号。例如：“[1,2,3,4]”" << endl;
	while ((Input = getchar()) && (Input != ']')) {
		if (Input >= '0' && Input <= '9') {//如果是数字的话就纳入数组
			Numbers.push_back((int)Input - 48);
		}
	}
	if (Numbers.size() < 2) {
		cout << "输入数组存在错误。" << endl;
		return 0;
	}
	cin.clear();
	cin.ignore(2100000000, '\n');//清空缓冲区
	while (1) {//错误处理
		cout << "请输入整数IndexDiff和ValueDiff。" << endl;
		cin >> IndexDiff >> ValueDiff;
		if ((cin.good()) && (IndexDiff >= 1) && (ValueDiff >= 0) && (IndexDiff <= Numbers.size())) {
			break;
		}
		cout << "输入非法，请重新输入。" << endl;
		cin.clear();
		cin.ignore(2100000000, '\n');//清空缓冲区
	}
	Compare(Numbers, IndexDiff, ValueDiff);
	return 0;
}