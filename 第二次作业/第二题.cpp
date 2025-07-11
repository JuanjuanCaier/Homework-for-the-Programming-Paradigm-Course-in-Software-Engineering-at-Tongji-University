/*JuanjuanCaier-123456*/
#include <iostream>  
#include<vector>
using namespace std;

void Multiply(vector<char>& Store, int Number) {
    int CarryNumber = 0, MiddleData;//记录进位
    long long int Loop = 0;
    while (Loop <= Store.size() - 1) {
        if (Loop == 0) {//处理开头
            MiddleData = ((int)Store[Loop] - 48) * Number;
            Store[Loop] = (char)(MiddleData % 10 + 48);
            CarryNumber = MiddleData / 10;
        }
        else if (Loop == (Store.size() - 1)) {//处理末尾
            MiddleData = ((int)Store[Loop] - 48) * Number + CarryNumber;
            Store[Loop] = (char)(MiddleData % 10 + 48);
            CarryNumber = MiddleData / 10;
            if (CarryNumber > 0) {
                Store.push_back(char(CarryNumber + 48));
                break;
            }
        }
        else {
            MiddleData = ((int)Store[Loop] - 48) * Number + CarryNumber;
            Store[Loop] = (char)(MiddleData % 10 + 48);
            CarryNumber = MiddleData / 10;
        }
        Loop++;
    }
}

void CountMao(vector<char>& Store,const long long int NumberOfMao) {
    long long int Loop = 0;
    while (Loop < NumberOfMao) {
        if (Loop % 2 == 0) {//偶数位
            Multiply(Store, 5);
        }
        else {//奇数位
            Multiply(Store, 4);
        }
        Loop++;
    }
}

void Output(vector<char>& Store) {
    long long int Loop = Store.size() - 1;
    while (Loop >= 0) {
        cout << Store[Loop];
        Loop--;
    }
}

int main() {
    long long int NumberOfMao = 0;
    vector<char> Store = { '1','0' };
    cout << "请输入密码箱提示数字：" << endl;
    cin >> NumberOfMao;
    if (NumberOfMao == 1) {
        cout << 5 << endl;
        return 0;
    }
    CountMao(Store, NumberOfMao);
    cout << "长度为" << NumberOfMao << "的毛哥数数目为：" << endl;
    Output(Store);
    cout << endl;
    return 0;
}