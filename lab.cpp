#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
    public:
    //Function to return Depth First Traversal of given graph.
	void dfs(int s,vector<int> &arr,vector<vector<int>> &adj,vector<int> &result)
	{
	    result.push_back(s);
	    arr[s]=1;
	    for(int x:adj[s])
	    {
	        if(arr[x]==0)
	        {
	            dfs(x,arr,adj,result);
	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<vector<int>> &adj)
	{
	    
	    vector<int> arr(V,0);
	    vector<int> result;
	    dfs(0,arr,adj,result);
	    return result;
	}
	//Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<vector<int>> &adj)
	{
	   
	    vector<int> visited(V,0);
	    visited[0]=1;
	    queue<int> q;
	    q.push(0);
	    vector<int>result;
	    while(!q.empty())
	    {
	        int ab=q.front();
	        q.pop();
	        result.push_back(ab);
	        for(auto e:adj[ab])
	        {
	            if(visited[e]==0)
	            {
	                visited[e]=1;
	                q.push(e);
	            }
	        }
	    }
	    return result;
	    
	}
};
// this is the graph i have taken maam
        //             0
		//           / | \
		//          1 2  3
		//           /\   \
		//          4 5    6

// { Driver Code Starts.
int main(){
        cout<<"enter the number of vertices and edges"<<endl;
		int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V,vector<int>(V,0));//adjacency matrix

    	for(int i = 0; i < E; i++)
    	{
            cout<<"enter edge "<<i+1<<endl;
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
			adj[u][v]=1;
			//commented because graph is directed
			// adj[v][u]=1;
			// adj[v].push_back(u);
    	}
		cout<<"adjacency matrix of the graph"<<endl;
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}
		
        Solution obj;
        clock_t start, end;
        start = clock();
        vector<int>ans=obj.bfsOfGraph(V, adj);
        end = clock();
		cout<<"bfs of the graph is:"<<endl;
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
		cout<<endl;
		cout<<"dfs of graph"<<endl;
		vector<int> ans2=obj.dfsOfGraph(V,adj);
		for(int i=0;i<ans2.size();i++){
        	cout<<ans2[i]<<" ";
        }
        cout<<endl;
        cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
	
	return 0;
}