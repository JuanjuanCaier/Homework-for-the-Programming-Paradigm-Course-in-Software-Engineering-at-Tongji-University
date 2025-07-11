/*JuanjuanCaier-123456*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class findstring {
public:
	int numberOfTargetString = 0;
	string line;//逐行检查
	void findString() {
		char* position = &line[0];
		while ((position[0] != '\0')&&
			   (position[1]!='\0')&&
			   (position[2] != '\0')&&
			   (position[3] != '\0')) {
			if ((position[0] == 't') || (position[0] == 'T')) {
				if ((position[1] == 'h') && (position[2] == 'a') && (position[3] == 't')) {
					numberOfTargetString++;
				}
			}
			position++;
		}
	}
};

int main() {
	int choice = 0;
	string fileName;
	findstring find;
	cout << "请选择选项（按1读取指定文件，按2退出）：";
	while (1) {
		cin >> choice;
		if (choice == 2) {
			break;
		}
		else if (choice == 1) {
			cout << "请输入文件路径" << endl;
			cin >> fileName;
			ifstream inputfile(fileName);
			if (!inputfile) { // 检查文件是否成功打开  
				cout << "打开失败，请重新选择" << endl;
				continue;
			}
			else {
				while (getline(inputfile, find.line)) { // 逐行读取文件  
					find.findString();
				}
			}
			cout << "共有" << find.numberOfTargetString << "个‘that’（包括首字母大写）" << endl;
			break;
		}
		else {
			cout << "输入错误，请重新选择" << endl;
			cin.clear();
			cin.ignore(2100000000, '\n');
		}
	}
	return 0;
}