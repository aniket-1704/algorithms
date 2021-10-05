// Initial Template for C++
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(vector<vector<int>> &a,int x,int y,int n)
    {
        //column check
        for(int row=0;row<x;row++)
        {
            if(a[row][y]==1)
            {
                return false;
            }
        }
        //left diagnol check
        for(int i=x,j=y;i>=0 && j>=0;i--,j--)
        {
            if(a[i][j]==1)
            {
                return false;
            }
           
        }
        //right diagnol check
        for(int i=x,j=y;i>=0 && j<n;i--,j++)
        {
            if(a[i][j]==1)
            {
                return false;
            }
        }
        return true;
    }
    //x is the row
    //filling rowise
    bool fill(vector<vector<int>> &a,int x,int n,vector<vector<int>> &res)
    {
        if(x==n)
        {
            vector<int> vec;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]==1)
                    {
                        //positions
                        vec.push_back(j+1);
                    }
                }
            }
            res.push_back(vec);
           
            return true;
        }

        for(int col=0;col<n;col++)
        {
            
            if(check(a,x,col,n))
            {
                a[x][col]=1;
                
                fill(a,x+1,n,res);
               //backtracking statement
               //if the next row will return false then i will change it to 0
                a[x][col]=0;
            }
        }
        return false;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> v(n,vector<int>(n,0));
       
        vector<vector<int>> res;
        if(n==1)
        {
            vector<int> v;
            v.push_back(1);
            res.push_back(v);
            return res;
        }
        fill(v,0,n,res);
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return res;
    }
};

// { Driver Code Starts.

int main(){
        cout<<"enter dimension of checkboard"<<endl;
        int n;
        cin>>n;
        
        Solution ob;
        clock_t start, end;
        start=clock();
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
        end=clock();
    cout<<endl;
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
    return 0;
}  // } Driver Code Ends