#include <bits/stdc++.h>
using namespace std;
 #include <time.h>
// implementation of traveling Salesman Problem
int travllingSalesmanProblem(vector<vector<int>> &graph, int s,int V)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
 
// Driver Code
int main()
{
    // matrix representation of graph
    int n;int val;
    cout<<"enter the number of vertices"<<endl;
    cin>>n;
    vector<vector<int>> graph;
    cout<<"enter the graph cities i and j"<<endl;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            cin>>val;
            v.push_back(val);
        }
        graph.push_back(v);
    }
    int s;
    cout<<"enter source vertex"<<endl;
    cin>>s;
    cout<<"the distance is"<<endl;
    clock_t start, end;
    start=clock();
    cout << travllingSalesmanProblem(graph, s,n) << endl;
     end=clock();
    cout<<endl;
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
    return 0;
}