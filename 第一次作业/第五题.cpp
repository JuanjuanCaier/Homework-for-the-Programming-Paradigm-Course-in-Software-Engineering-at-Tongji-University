/*JuanjuanCaier-123456*/
#include <iostream>  
#include <vector> 
#include<cstring>
#include<sstream>
using namespace std;

int main() {
    vector<int> prices;
    string inputLine;
    int maxprofit = 0, loopFirst = 0, loopSecond = 1, length = 0, getInput = 0;
    while (1) {
        cout << "请输入价格数组，例：‘1 2 3 4’" << endl;
        getline(cin, inputLine);//按行读取
        istringstream iss(inputLine);
        int number;//提取整数
        while (iss >> number) {//放入prices
            prices.push_back(number);
        }
        length = prices.size();
        if (length == 1) { //错误处理
            cout << "天数过少，请重新输入" << endl;
            cin.clear();
            cin.ignore(2100000000, '\n');
            continue;
        }
        else {
            while (loopFirst <= (length - 2)) {//内外循环遍历
                loopSecond = loopFirst + 1;
                while (loopSecond <= (length - 1)) {
                    if ((prices[loopSecond] - prices[loopFirst]) > maxprofit) {
                        maxprofit = prices[loopSecond] - prices[loopFirst];
                    }
                    loopSecond++;
                }
                loopFirst++;
            }
            break;
        }
    }
    cout << maxprofit;
    return 0;
}