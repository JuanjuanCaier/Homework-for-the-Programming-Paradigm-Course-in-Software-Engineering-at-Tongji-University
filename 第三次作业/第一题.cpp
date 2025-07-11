/*JuanjuanCaier-123456*/
#include<iostream>
#include<vector>
using namespace std;

void Compare(vector<int>Numbers) {
	int Loop1 = 0, Loop2 = 0;
	while (Loop1 < Numbers.size()) {
		Loop2 = Loop1 + 1;
		while (Loop2 < Numbers.size()) {
			if (Numbers[Loop1] == Numbers[Loop2]) {
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
	cout << "请输入数组，数字之间使用英文逗号隔开，左右两边包含中括号。例如：“[1,2,3,4]”" << endl;
	while ((Input = getchar()) && (Input != ']')) {
		if (Input >= '0' && Input <= '9') {//如果是数字的话就纳入数组
			Numbers.push_back((int)Input - 48);
		}
	}
	if (Numbers.size() < 1) {
		cout << "输入数组存在错误。" << endl;
		return 0;
	}
	Compare(Numbers);
	return 0;
}
