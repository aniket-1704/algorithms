#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
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

    	vector<int> adj[V];//adjacency list

    	for(int i = 0; i < E; i++)
    	{
            cout<<"enter edge "<<i+1<<endl;
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
			adj[v].push_back(u);
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
        cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
	
	return 0;
}