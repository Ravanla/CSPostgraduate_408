#include <bits/stdc++.h>

using namespace std;

void insertElem(int A[], int m, int n)
{
    int i, j;
    int temp;
    for (i = m; i < m + n; i++)
    {
        temp = A[i];
        for (j = i - 1; j >= 0 && temp < A[j]; --j)
            A[j + 1] = A[j];
        A[j + 1] = temp;
    }
}

int main()
{

    return 0;
}