/*JuanjuanCaier-123456*/
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

void functionOfArray(string* targetstring) {//将小写字母转换为大写字母
	if (targetstring != nullptr) {
		for ( char& singleChar : *targetstring) {//范围循环
			singleChar = toupper(singleChar);
		}
	}
}

void functionOfRefer(string& targetstring) {//将大写字母转换为小写字母
	int arrayOfString = 0;
	while (targetstring[arrayOfString] != '\0') {
		targetstring[arrayOfString] = tolower(targetstring[arrayOfString]);
		arrayOfString++;
	}
}

void output(const string targetstring) {
	int arrayOfString = 0;
	while (targetstring[arrayOfString] != '\0') {
		cout << targetstring[arrayOfString];
		arrayOfString++;
	}
	cout << endl;
}

int main() {
	string targetstring = "I Love Tongji University!";
	cout << "修改之前的：" << endl;
	output(targetstring);
	cout << "使用传入指针方式修改的：" << endl;
	functionOfArray(&targetstring);
	output(targetstring);
	cout << "使用传入引用方式修改的：" << endl;
	functionOfRefer(targetstring);
	output(targetstring);
	return 0;
}