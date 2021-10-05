#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int s,vector<int> &arr,vector<int>adj[],vector<int> &result)
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
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> arr(V,0);
	    vector<int> result;
	    dfs(0,arr,adj,result);
	    return result;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cout<<"enter number of graphs"<<endl;
	cin >> tc;
	while(tc--){
		int V, E;
		cout<<"entter the number of vertices and edges"<<endl;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
			cout<<"enter edge "<<i<<endl;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
		clock_t start, end;
        start=clock();
        vector<int>ans=obj.dfsOfGraph(V, adj);
		end=clock();
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        
        cout<<endl;
        cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;

	}
	return 0;
} 