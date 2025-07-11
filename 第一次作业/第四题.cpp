/*JuanjuanCaier-123456*/
#include <iostream>  
#include <cstring>  
using namespace std;

typedef struct {
    string firstString;
    string secondString;
    int number;
} MyStruct;

int main() {
    MyStruct myInstance = { "Hello", "World", 114514 };//初始化
    cout << "原始值：" << endl;//打印原始值
    cout << "First String: " << myInstance.firstString << endl;
    cout << "Second String: " << myInstance.secondString << endl;
    cout << "Number: " << myInstance.number << endl;
    MyStruct* ptrToMyInstance = &myInstance;//指针 
    ptrToMyInstance->firstString = "Tongji";//修改
    ptrToMyInstance->secondString = "University";
    ptrToMyInstance->number = 1919810;
    cout << "修改后：" << endl;//打印修改后的值
    cout << "First String: " << ptrToMyInstance->firstString << endl;
    cout << "Second String: " << ptrToMyInstance->secondString << endl;
    cout << "Number: " << ptrToMyInstance->number << endl;

    return 0;
}