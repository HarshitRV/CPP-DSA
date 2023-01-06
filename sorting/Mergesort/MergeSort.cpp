#include <iostream>

using namespace std;

int *mergeSort(int A[], int low, int mid, int high)
{
    int i = 0;

    int j = mid;

    int *B = new int[100];
    int k = 0;
    while (low < j && mid < high)
    {
        cout << "low: " << low << " mid: " << mid << endl;
        if (A[low] < A[mid])
        {
            cout << "IF A[low] = " << A[low] << " A[mid] = " << A[mid] << endl;
            B[k++] = A[low++];
        }
        else
        {
            cout << "ELSE A[low] = " << A[low] << " A[high] = " << A[mid] << endl;
            B[k++] = A[mid++];
        }
    }
    for (; low < j; low++)
    {
        B[k++] = A[low];
    }
    for (; mid < high; mid++)
    {
        cout << "MID: " << A[mid] << endl;
        cout << "K: " << k << endl;
        B[k++] = A[mid];
    }
    return B;
}

int main()
{
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10, 15};

    int lenA = sizeof(A) / sizeof(A[0]);
    cout << "lenA : " << lenA << endl;

    int *B = mergeSort(A, 0, (0 + 9) / 2, 9);

    for (int i = 0; i < lenA; i++)
        cout << B[i] << " - ";
    return 0;
}