#include <iostream>
#include<string.h>
#define MAX 70
using namespace std;
int match(char* s,string p)
{
    int count=0;
    for(int i=0;i<=strlen(s)-p.length();i++)
    {
        int idx=0;
        for(int j=i;j<i+p.length();j++)
        {
            if(s[j]!=p[idx++])
            {
                break;
            }
            else
            count++;
        }
        idx=0;
        if(count==p.length())
        {
        cout<<"pattern matched at "<<i<<endl;
        return i;
        }
        count=0;
    }
    cout<<"pattern not matched";
    return -1;
}
int main()
{
    char s[MAX];string p;
    cout<<"enter string"<<endl;
    cin.getline(s,MAX);
    cout<<"pattern string"<<endl;
    cin>>p;
    match(s,p);
    return 0;
}