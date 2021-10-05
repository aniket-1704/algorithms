#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    clock_t start, end; //macro variablee for clock ticks
    int n, a[1000];
    cout << "entr the sizee of the array" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    cout << "unsorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    start = clock();

    //in selections sort
    //find minimum element in the array and
    //swap it with the first element in the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    end = clock();

    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
    return 0;
}