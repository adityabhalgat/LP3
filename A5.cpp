#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n-1);

    for (int x : a)
        cout << x << " ";

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int partition(vector<int>& a, int low, int high) {
//     int pivot = a[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (a[j] < pivot) {
//             i++;
//             swap(a[i], a[j]);
//         }
//     }

//     swap(a[i+1], a[high]);
//     return i+1;
// }

// void quickSort(vector<int>& a, int low, int high) {
//     if (low < high) {
//         int r = low + rand() % (high-low+1);
//         swap(a[r], a[high]);

//         int p = partition(a, low, high);

//         quickSort(a, low, p-1);
//         quickSort(a, p+1, high);
//     }
// }

// int main() {
//     srand(time(0));

//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     quickSort(a, 0, n-1);

//     for (int x : a)
//         cout << x << " ";

//     return 0;
// }