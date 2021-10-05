#include <iostream>
#include<time.h>
using namespace std;
// merge sort TIME COMPLEXITY:O(nlogn)
//merge 2 sorted arrays
void merge(int a[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i] = a[i+l];
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = a[i+mid+1];
    }
    int k = l;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            a[k] = a1[i];
            k++;
            i++;
        }
        else
        {
            a[k] = a2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        a[k] = a1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = a2[j];
        k++;
        j++;
    }
}
//divide and conquer
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}
int main()
{
    int a[] = {6, 8, 3, 4, 9, 10, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    clock_t start, end;
    start=clock();
    mergeSort(a,0,n-1);
    end=clock();
    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
    return 0;
}