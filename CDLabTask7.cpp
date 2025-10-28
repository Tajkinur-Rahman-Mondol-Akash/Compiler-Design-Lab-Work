#include <iostream>
using namespace std;

int main() {
    string first, last, full;
    cout << "Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;

    full = first + " " + last;

    cout << "Full name = " << full;
    return 0;
}
