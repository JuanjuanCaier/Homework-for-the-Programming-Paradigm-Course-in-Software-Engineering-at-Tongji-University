/*JuanjuanCaier-123456*/
#include <iostream>
#include <ctime>

using namespace std;
//基类
class Base {
public:
    virtual ~Base() = default;//虚析构函数，确保基类指针可以正确删除派生类对象
    //虚函数
    virtual void VirtualFunc() const {
    }
    //非虚函数
    void NonVirtualFunc() const {
    }
};
//新的类
class Derived : public Base {
public:
    //虚函数
    void VirtualFunc() const override {
    }
    //非虚函数在派生类中不需要重写s
};
//测试
int main() {
    Derived DerivedObj;
    Base* BasePtr = &DerivedObj;//向上转型
    //设定迭代次数，用于观察时间差异
    const int Iterations = 1000000;
    clock_t Start = clock();
    for (int i = 0; i < Iterations; i++) {
        (BasePtr->VirtualFunc)();//调用成员虚函数
    }
    clock_t EndV = clock();
    for (int i = 0; i < Iterations; i++) {
        (BasePtr->NonVirtualFunc)();//调用成员非虚函数
    }
    clock_t EndN = clock();
    double TimeV = double(EndV - Start) / CLOCKS_PER_SEC;
    double TimeN = double(EndN - Start) / CLOCKS_PER_SEC;
    cout << "Virtual function tooks " << TimeV << " seconds for " << Iterations << " iterations." << endl;
    cout << "Nonvirtual function tooks " << TimeN << " seconds for " << Iterations << " iterations." << endl;
    return 0;
}