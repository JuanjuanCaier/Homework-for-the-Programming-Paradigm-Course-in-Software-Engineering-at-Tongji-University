/*JuanjuanCaier-123456*/
#include <iostream>  
#include<vector>
#include<string>
using namespace std;

int TransformToDec(int NumberOfSenary) {//6转10
    int NumberOfDec = 0;
    NumberOfDec += 6 * 6 * 6 * 6 * 6 * 6 * 6 * (NumberOfSenary / 10000000);
    NumberOfSenary = NumberOfSenary % 10000000;
    NumberOfDec += 6 * 6 * 6 * 6 * 6 * 6 * (NumberOfSenary / 1000000);
    NumberOfSenary = NumberOfSenary % 1000000;
    NumberOfDec += 6 * 6 * 6 * 6 * 6 * (NumberOfSenary / 100000);
    NumberOfSenary = NumberOfSenary % 100000;
    NumberOfDec += 6 * 6 * 6 * 6 * (NumberOfSenary / 10000);
    NumberOfSenary = NumberOfSenary % 10000;
    NumberOfDec += 6 * 6 * 6 * (NumberOfSenary / 1000);
    NumberOfSenary = NumberOfSenary % 1000;
    NumberOfDec += 6 * 6 * (NumberOfSenary / 100);
    NumberOfSenary = NumberOfSenary % 100;
    NumberOfDec += 6 * (NumberOfSenary / 10);
    NumberOfSenary = NumberOfSenary % 10;
    NumberOfDec += NumberOfSenary;
    return NumberOfDec;
}

string TransformToTarget(int NumberOfDec, int TargetBinary) {//10转目标进制+倒置
    string NumberOfTarget;
    int Remainder = 0, Quotient = NumberOfDec;//余数和商
    while (Quotient >= TargetBinary) {
        Remainder = Quotient % TargetBinary;
        Quotient = Quotient / TargetBinary;
        if (Remainder < 10) {
            NumberOfTarget += to_string(Remainder);
        }
        else {
            NumberOfTarget += char(Remainder + 55);
        }
    }
    if (Quotient < 10) {
        NumberOfTarget += to_string(Quotient);
    }
    else {
        NumberOfTarget += char(Quotient + 55);
    }
    string TureNumberOfTarget = NumberOfTarget;
    int Loop1 = NumberOfTarget.size() - 1, Loop2 = 0;
    while (Loop1 >= 0) {
        TureNumberOfTarget[Loop2] = NumberOfTarget[Loop1];
        Loop1--;
        Loop2++;
    }
    return TureNumberOfTarget;
}

int main() {
    int TargetBinary = 0, NumberOfSenary = 0;//前者小于等于20，后者的十进制小于等于1000000
    cout << "请输入目标进制整数和六进制整数,以空格隔开。" << endl;
    cout << "注意，目标进制不小于2，不大于20；六进制整数不小于0，不大于33233344。" << endl;
    cin >> TargetBinary >> NumberOfSenary;
    int NumberOfDec = TransformToDec(NumberOfSenary);
    string NumberOfTarget = TransformToTarget(NumberOfDec, TargetBinary);
    cout << NumberOfTarget;
    return 0;
}