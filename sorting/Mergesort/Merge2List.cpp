#include <iostream>

using namespace std;

int *merge2List(int A[], int B[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;
    int *C = new int[m + n];

    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    for (; j < n; j++)
    {
        C[k++] = B[j];
    }
    return C;
}

int main()
{
    int A[] = {2, 10, 18, 20, 23};
    int B[] = {4, 9, 19, 25};

    int lenA = sizeof(A) / sizeof(A[0]);
    int lenB = sizeof(B) / sizeof(B[0]);

    int *C = merge2List(A, B, lenA, lenB);
    int lenOfC = lenA + lenB;

    for (int i = 0; i < lenOfC; i++)
        cout << C[i] << " - ";

    cout << endl;
    return 0;
}