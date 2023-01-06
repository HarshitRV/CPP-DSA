#include <iostream>

using namespace std;

int closerNumber(int arr[], int n, int target)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == target)
        {
            cout << "element position " << i << "\n";
            return 0;
        }
        if (abs(target - res) > abs(target - arr[i]))
        {
            res = arr[i];
        }
    }
    return res;
}

int main()
{
    int arr[] = {12, 32, 31, 29, 90};
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int n = sizeof(arr) / sizeof(arr[0]);

    if (closerNumber(arr, n, target))
        cout << closerNumber(arr, n, target) << " is the closest";
}