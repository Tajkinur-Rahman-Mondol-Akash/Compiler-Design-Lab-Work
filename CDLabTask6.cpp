#include <iostream>
using namespace std;

int main() {
    int n, i;
    cout << "Enter number of Array: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " elements of array: ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    int min = a[0], max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    cout << "Minimum Number = " << min << endl;
    cout << "Maximum Number = " << max;
    return 0;
}
