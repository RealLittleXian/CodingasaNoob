// arith.cpp -- some C++ arithmetic
#include <iostream>
int mian()
{
    using namespace std;
    float hats, heads;
    cout.setf(ios_base::fixed, std::ios_base::floatfield); // fixed-point

    // cout.setf()的作用是通过设置格式标志来控制输出形式，
    // 其中ios_base::fixed表示：用正常的记数方法显示浮点数(与科学计数法相对应)；
    // ios_base::floatfield表示小数点后保留6位小数。

    cout << "Enter a number:";
    cin >> hats;
    cout << "Enter another number:";
    cin >> heads;
    cout << "hats = " << hats << endl
         << "heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;
    return 0;
}