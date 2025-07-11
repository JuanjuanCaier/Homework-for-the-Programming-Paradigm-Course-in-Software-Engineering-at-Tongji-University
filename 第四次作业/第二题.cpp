/*JuanjuanCaier-123456*/
#include <iostream>
#include<iomanip>

using namespace std;

class Matrix
{
public:
	float M[4][4];
	//构造函数
	Matrix(float m[16]) {
		int z = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				M[i][j] = m[z];
				z++;
			}
		}
	}
	//构造函数
	Matrix() {
		cout << "请输入矩阵的元素：" << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> M[i][j];
			}
		}
	}
	//重载+=运算符
	Matrix& operator+=(Matrix& M2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				M[i][j] += M2.M[i][j];
			}
		}
		return *this;
	}
	//矩阵加法
	void Add(Matrix& M2) {
		*this += M2;
	}
	//矩阵乘法
	void Multiply(Matrix& M2) {
		float Result[4][4] = { 0 };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int z = 0; z < 4; z++) {
					Result[i][j] += M[i][z] * M2.M[z][j];
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				M[i][j] = Result[i][j];
			}
		}
	}
	//打印
	void OutPut() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << setw(10) << M[i][j] << ' ';
			}
			cout << endl;
		}
	}
	//下面两个函数的变量未首字母大写是为了与pdf一致
	//获得指定元素指针
	float& operator()(int row, int column) {
		return M[row - 1][column - 1];
	}
	// 只允许读取元素的函数（返回值的副本）
	float operator()(int row, int column) const {
		return M[row - 1][column - 1];
	}
};
//逐个功能测试
int main() {
	//测试第一种构造函数
	cout << "构造函数1测试。" << endl;
	float Test[16] = { 1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,1.10,1.11,1.12,1.13,1.14,1.15,1.16 };
	Matrix Test1 = Test;
	Test1.OutPut();
	//测试第二种构造函数
	cout << "构造函数2测试，此矩阵将用于对第一个矩阵施加影响。" << endl;
	Matrix Test2;
	Test2.OutPut();
	//测试加法
	cout << "加法测试。" << endl;
	Test1.Add(Test2);
	Test1.OutPut();
	//测试乘法
	cout << "乘法测试。" << endl;
	Test1.Multiply(Test2);
	Test1.OutPut();
	//重载+=测试
	cout << "重载+=测试。" << endl;
	Test1 += Test2;
	Test1.OutPut();
	//获得可修改的元素测试
	int r, c;
	float Data;
	while (1) {
		cout << "请输入要修改的行和列：" << endl;
		cin >> r >> c;
		if (r >= 1 && r <= 4 && c >= 1 && c <= 4) {
			break;
		}
		cout << "输入有误" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	cout << "请输入要改为的值：" << endl;
	cin >> Data;
	cout << "修改前：" << endl;
	Test1.OutPut();
	cout << "修改后：" << endl;
	Test1(r, c) = Data;
	Test1.OutPut();
	//获得不可修改的元素测试
	while (1) {
		cout << "请输入要获取的行和列：" << endl;
		cin >> r >> c;
		if (r >= 1 && r <= 4 && c >= 1 && c <= 4) {
			break;
		}
		cout << "输入有误" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	cout << Test1(r, c) << endl;
	return 0;
}