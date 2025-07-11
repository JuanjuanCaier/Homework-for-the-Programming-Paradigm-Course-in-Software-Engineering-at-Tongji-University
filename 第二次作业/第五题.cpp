/*JuanjuanCaier-123456*/
#include <iostream>  
#include<vector>
using namespace std;

void Output(vector<char>& AddResult) {
    int Loop = AddResult.size() - 1;
    cout << "结果为：" << endl;
    while (Loop >= 0) {
        cout << AddResult[Loop];
        Loop--;
    }
    cout << endl;
}

void Add(vector<char>& AddNumber1, vector<char>& AddNumber2) {
    vector<char>AddResult;
    int Loop = 0, Length = 0, Sum = 0, Carry = 0;
    if (AddNumber1.size() > AddNumber2.size()) {
        while (AddNumber1.size() != AddNumber2.size()) {
            auto Pow = AddNumber1.begin();
            AddNumber2.insert(Pow, 48);
        }
    }
    else if (AddNumber1.size() <= AddNumber2.size()) {
        while (AddNumber1.size() != AddNumber2.size()) {
            auto Pow = AddNumber1.begin();
            AddNumber1.insert(Pow, 48);
        }
    }
    Length = AddNumber1.size();
    Loop = Length - 1;
    while (Loop >= 0) {
        if (Loop == (Length - 1)) {//处理开头
            Sum = AddNumber1[Loop] + AddNumber2[Loop] - 96;
            Carry = Sum / 10;
            AddResult.push_back(Sum % 10 + 48);
        }
        else {
            Sum = AddNumber1[Loop] + AddNumber2[Loop] - 96 + Carry;
            Carry = Sum / 10;
            AddResult.push_back(Sum % 10 + 48);
        }
        if ((Loop == 0) && (Carry > 0)) {//处理结尾
            AddResult.push_back(Carry + 48);
        }
        Loop--;
    }
    Output(AddResult);
}

int main() {
    int Digit1 = 0, Digit2 = 0, Loop = 0;
    char StoreChar;
    vector<char>AddNumber1;
    vector<char>AddNumber2;
    cout << "请输入两组位数和数字，使用回车键分隔" << endl;
    cin >> Digit1;
    for (Loop = 0; Loop < Digit1; Loop++) {
        cin >> StoreChar;
        AddNumber1.push_back(StoreChar);
    }
    cin >> Digit2;
    for (Loop = 0; Loop < Digit2; Loop++) {
        cin >> StoreChar;
        AddNumber2.push_back(StoreChar);
    }
    Add(AddNumber1, AddNumber2);
    return 0;
}