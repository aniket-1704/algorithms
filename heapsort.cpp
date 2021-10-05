#include <iostream>
#include <time.h>
using namespace std;
//function to create max heap
void heapify(int arr[],int n,int i)
{
    int largest=i;//root
    int l=2*i+1;//left child
    int r=2*i+2;//right child

    if(l<n && arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);//create a max heap
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);//fix last element and delete from max heap
        heapify(arr,i,0);//check sub tree again and reconstruct 
    }
}
int main()
{
    int arr[]={56,90,32,67,100,23,44};
    int n=sizeof(arr)/sizeof(arr[0]);
    clock_t start, end;
    start=clock();
    heapsort(arr,n);
    end=clock();
    cout<<"sorted array "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
return 0;
}