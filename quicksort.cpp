#include <iostream>
#include <time.h>
using namespace std;
//best case if pivot is median :O(nlogn)
//worst case O(n^2)

int pivot(int a[], int l, int r)
{
    int piv = a[r];
    //fix pivot element as the last eleement of the array
    int i = l - 1;
    //now shift all smaller elements than piv to left and bigger to the right
    for (int j = l; j < r; j++)
    {
        if (a[j] < piv)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    //till i all smaller elements accumulated
    swap(a[i + 1], a[r]);
    return i + 1;
}
void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = pivot(a, l, r);



        quicksort(a, l, pi - 1);
        quicksort(a, pi + 1, r);
    }
}
int main()
{
    clock_t start, end;
    int n;int a[1000];
    cout << "enter the size of the array" << endl;
    cin >> n;
 

    for (int i = 0; i < n; i++)
    {
        a[i]=rand();
    }
    cout << "unsorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();

    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout<<endl;
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;

    return 0;
}