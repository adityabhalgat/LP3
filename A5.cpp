#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int helper(vector<int>& arr, int low, int high) {

    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {

        while (i <= high && arr[i] <= pivot)
            i++;

        while (j > low && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Deterministic Quick Sort
void deterministic(vector<int>& arr, int low, int high) {

    if (low < high) {

        int p = helper(arr, low, high);

        deterministic(arr, low, p - 1);
        deterministic(arr, p + 1, high);
    }
}

// Randomized Quick Sort
void randomized(vector<int>& arr, int low, int high) {

    if (low < high) {

        int randomIndex = low + rand() % (high - low + 1);

        swap(arr[low], arr[randomIndex]);

        int p = helper(arr, low, high);

        randomized(arr, low, p - 1);
        randomized(arr, p + 1, high);
    }
}

int main() {

    srand(time(0));

    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n1. Deterministic Quick Sort";
    cout << "\n2. Randomized Quick Sort";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        deterministic(arr, 0, n - 1);

    else if (choice == 2)
        randomized(arr, 0, n - 1);

    else {
        cout << "Invalid choice";
        return 0;
    }

    cout << "\nSorted array: ";

    for (int x : arr)
        cout << x << " ";

    return 0;
}