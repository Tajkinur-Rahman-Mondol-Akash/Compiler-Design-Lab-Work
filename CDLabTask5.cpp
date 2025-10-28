#include <iostream>
using namespace std;

int main() {
    int n, i;
    float sum = 0;
    cout << "Enter number of elements array: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " elements array: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    cout << "Average = " << sum / n;
    return 0;
}

