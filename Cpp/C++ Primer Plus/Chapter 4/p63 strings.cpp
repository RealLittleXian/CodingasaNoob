// strings.cpp -- storing strings in an array
#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    const int size = 15;
    char name1[size];              // empty array
    char name2[size] = "C++owboy"; // initialized array

    cout << "Howdy! I'm " << name2 << '. ';
    cout << "What's your name?" << endl;
    cin >> name1;
        // cin.getline(name, size);

        // or

        // cin.get(name, size).get(); // 将两个类成员函数拼接起来（合并）
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored in an array of ";
    cout << sizeof(name1) << " bites.";
    cout << "Your initial is " << name1[0] << ".\n";

    name2[3] = '\0';
    cout << "The first 3 character of your name: " << name2 << endl;
    return 0;
}