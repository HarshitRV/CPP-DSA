#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    a = b;
    *b = temp;
}

int main()
{
    int arr[] = {1, 3, 5};

    cout << arr[0] << " - " << arr[1] << " - " << arr[2] << endl;
    swap(arr[0], arr[2]);
    cout << arr[0] << " - " << arr[1] << " - " << arr[2] << endl;
    return 0;
}