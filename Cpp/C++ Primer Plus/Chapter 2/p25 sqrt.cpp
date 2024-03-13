#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    double area, side;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side
         << " feet to the side." << endl;
    cout << "How facinating!" << endl;
    return 0;
}