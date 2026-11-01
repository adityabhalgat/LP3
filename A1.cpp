#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cout << fib(i) << " ";

    return 0;
}

// Non Recursive

// #include <iostream>
// using namespace std;

// int main() {
//     int n, a = 0, b = 1, c;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         cout << a << " ";
//         c = a + b;
//         a = b;
//         b = c;
//     }

//     return 0;
// }