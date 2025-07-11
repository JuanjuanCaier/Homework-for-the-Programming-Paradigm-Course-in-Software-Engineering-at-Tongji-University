/*JuanjuanCaier-123456*/
#include <iostream>
#include <string>

using namespace std;

//Pager类定义
class Pager {
private:
    string PagerContent;
public:
    //接受一个string参数的构造函数
    Pager(const string& content) : PagerContent(content) {}
    //拷贝构造函数
    Pager(const Pager& other) : PagerContent(other.PagerContent) {}
    //赋值运算符
    Pager& operator=(const Pager& other) {
        if (this != &other) { //检查自赋值
            PagerContent = other.PagerContent;
        }
        return *this;
    }
    //用于输出页面内容的函数
    void Display() const {
        cout << "Pager content: " << PagerContent << endl;
    }
};
//Traveler类定义
class Traveler {
private:
    string TravelerName;

public:
    //接受一个string参数的构造函数
    Traveler(const string& name) : TravelerName(name) {}
    //拷贝构造函数
    Traveler(const Traveler& other) : TravelerName(other.TravelerName) {}
    //赋值运算符
    Traveler& operator=(const Traveler& other) {
        if (this != &other) { //检查自赋值
            TravelerName = other.TravelerName;
        }
        return *this;
    }
    //用于输出旅行者名称的函数
    void Introduce() const {
        cout << TravelerName << endl;
    }
};
//BusinessTraveler类定义，继承自Traveler
class BusinessTraveler : public Traveler {
private:
    Pager BusinessPager;
public:
    //默认构造函数（需要调用基类构造函数）
    BusinessTraveler()
        : Traveler(""), BusinessPager("") {
    }
    //接受一个string参数的构造函数（同时初始化Pager对象）
    BusinessTraveler(const string& name, const string& PageContent)
        : Traveler(name), BusinessPager(PageContent) {
    }
    //拷贝构造函数
    BusinessTraveler(const BusinessTraveler& other)
        : Traveler(other), BusinessPager(other.BusinessPager) {
    }
    //赋值运算符
    BusinessTraveler& operator=(const BusinessTraveler& other) {
        if (this != &other) { //检查自赋值
            Traveler::operator=(other); //调用基类的赋值运算符
            BusinessPager = other.BusinessPager;
        }
        return *this;
    }
    //用于输出业务旅行者信息的函数
    void ShowInfo() const {
        Introduce(); //调用基类的成员函数
        BusinessPager.Display(); //调用Pager对象的成员函数
    }
};

int main() {
    //测试代码
    BusinessTraveler bt1("John Doe", "Business report");
    bt1.ShowInfo();

    BusinessTraveler bt2 = bt1;//使用拷贝构造函数
    bt2.ShowInfo();

    BusinessTraveler bt3;//使用默认构造函数
    bt3 = bt1;//使用赋值运算符
    bt3.ShowInfo();
    return 0;
}