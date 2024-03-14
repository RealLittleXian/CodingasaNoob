#include <iostream>
using namespace std;
int main() 
{
    float m,h,BMI;
    cin>>m>>h;
    BMI=m/(h*h);
    if (BMI<18.5)
        cout<<"Underweight";
    else if (BMI>=18.5 && BMI<24)
        cout<<"Normal";
    else if (BMI>=24)
        cout<<BMI<<endl<<"Overweight";
    
}