#include<iostream>
using namespace std;
#include<string>

class jsj//��ͨ��
{
public:
    int a, b;
    void get(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int jg(string fh)
    {
        if (fh == "+")
        {
            return a + b;
        }
        else if (fh == "-")
        {
            return a - b;
        }
        else if (fh == "*")
        {
            return a * b;
        }
        else if (fh == "/")
        {
            return a / b;
        }
    }
};

void test01()
{
    jsj j1;
    j1.get(10, 20);
    cout << "+��  " << j1.jg("+") << "  -��  " << j1.jg("-") << "  *��  " << j1.jg("*") << "  /��  " << j1.jg("/") << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}