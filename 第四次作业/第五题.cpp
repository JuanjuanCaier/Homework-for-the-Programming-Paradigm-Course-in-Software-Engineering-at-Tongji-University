/*JuanjuanCaier-123456*/
#include <iostream>

using namespace std;

//基类
class Base {
public:
    virtual ~Base() = default; //虚析构函数，确保正确删除派生类对象
    //纯虚函数，要求派生类必须实现clone()
    virtual Base* clone() const = 0;
    //虚函数，用于展示对象类型
    virtual void ShowType() const {
        cout << "Type: Base" << endl;
    }
};
//派生类A
class DerivedA : public Base {
public:
    Base* clone() const override {
        //返回DerivedA类型的指针，但向上转型为Base类型，即题中的“首先尝试返回基类类型”
        return new DerivedA(*this);
    }
    //虚函数，用于展示对象类型
    void ShowType() const override {
        cout << "Type: DerivedA" << endl;
    }
};
//派生类B
class DerivedB : public Base {
public:
    DerivedB* clone() const override {
        //返回DerivedB类型的指针，即题中的“再尝试返回确切的派生类型”
        return new DerivedB(*this);
    }
    //虚函数，用于展示对象类型
    void ShowType() const override {
        cout << "Type: DerivedB" << endl;
    }
};
//测试
int main() {
    //创建DerivedA和DerivedB对象
    DerivedA A;
    DerivedB B;
    //向上转型为Base指针
    Base* BasePtrA = &A;
    Base* BasePtrB = &B;
    //验证克隆副本的子类型
    BasePtrA->ShowType();//应该输出Type: DerivedA
    BasePtrB->ShowType();//应该输出Type: DerivedB
    //可以发现在这种情况下，返回的指针无论是基类的还是派生类的，作用的一致的。
    /*
    在什么情况下，返回确切的派生类型是必要的？
        1.在模板或泛型编程中，有时需要根据模板参数的类型来返回不同类型的指针，一般可以使用智能指针解决。
        2.在多态性中，基类的指针或引用可能指向派生类的对象。如果clone()方法返回基类类型，那么复制的对象
    将丢失派生类的特定属性和方法，这会导致不正确的行为或数据丢失‌。
    */
    return 0;
}