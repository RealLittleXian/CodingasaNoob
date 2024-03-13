// strtype3.cpp -- more string class features
#include <iostream>
#include <string>
#include <cstring>
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // assignment 赋值
    str1 = str2;
    strcpy(charr1, charr2);

    // append 连接
    str1 += " paste";
    strcat(charr1, " juice");

    // find the length 字符串长度
    int len1 = str1.size();
    int len2 = strlen(charr1);

    //...
}