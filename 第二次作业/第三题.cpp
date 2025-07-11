/*JuanjuanCaier-123456*/
#include <iostream>  
#include<vector>
#include<string>
using namespace std;

bool CheckSeven(long long int Number) {//检测7
    string NumberStr = to_string(Number);//转化为字符串
    for (char ch : NumberStr) {
        if (ch == '7') {
            return true;
        }
    }
    if (Number % 7 == 0) {//检测是否是7的倍数
        return true;
    }
    return false;
}

bool CheckCho(vector<long long int>& Eat) {//检查是否只剩一个巧克力
    if (Eat.size() == 1) {
        cout << Eat[0] << endl;
        return true;
    }
    return false;
}

void EatGame(vector<long long int>& Eat) {//吃
    long long int Loop = 0, Number = 1;
    while (1) {
        if (Loop == Eat.size()) {//绕圈
            Loop = 0;
        }
        if (CheckSeven(Number)) {
            auto EatChoco = Eat.begin() + Loop;
            Eat.erase(EatChoco);//表示被吃了
            Loop--;
        }
        if (CheckCho(Eat)) {
            return;
        }
        Loop++;
        Number++;
    }
}

int main() {
    long long int NumberOfCho = 0, Loop = 0;
    cout << "请输入巧克力的数量（正整数）：" << endl;
    cin >> NumberOfCho;
    vector<long long int> Eat;
    for (Loop = 0; Loop < NumberOfCho; Loop++) {//赋初值
        Eat.push_back(Loop + 1);
    }
    cout << "最后剩下的是：" << endl;
    if (NumberOfCho == 1) {
        cout << 1 << endl;
        return 0;
    }
    EatGame(Eat);
    return 0;
}