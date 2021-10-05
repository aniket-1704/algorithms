#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	void dfs(int s,vector<int> &arr,vector<vector<int>> &adj,vector<int> &result)
	{