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
    MyStruct obj1; // ʹ��Ĭ�Ϲ��캯����������value����ʼ��Ϊ0
    obj1.showValue();
    MyStruct obj2(10); // ʹ�ô������Ĺ��캯����������value����ʼ��Ϊ10
    obj2.showValue();
}