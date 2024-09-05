#include <iostream>
struct MyStruct
{
    int value;

    MyStruct()
    {
        value = 0;
    }


    MyStruct(int v) : value(v) {}

public:
    void showValue()
    {
        std::cout << "Value:" << value << std::endl;
    }
};

int main()
{
    MyStruct obj1; // 使用默认构造函数创建对象，value被初始化为0
    obj1.showValue();
    MyStruct obj2(10); // 使用带参数的构造函数创建对象，value被初始化为10
    obj2.showValue();
}