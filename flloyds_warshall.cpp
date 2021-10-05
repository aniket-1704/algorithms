
#include<bits/stdc++.h>
using namespace std;
#include<climits>
#include<time.h>
 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  const int inf=1e9;
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int v = matrix.size();
	    
	     for(int i = 0; i < v; i++){
	            for(int j = 0; j < v; j++){
	                if(matrix[i][j] == -1)
	                matrix[i][j] = INT_MAX;
	             }
	       }
	        
	    
	    for(int k = 0; k < v; k++){
	        for(int i = 0; i < v; i++){
	            for(int j = 0; j < v; j++){
	                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
	                continue;
	                else if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                }
	            }
	        }
	    }
	    for(int i = 0; i < v; i++){
	            for(int j = 0; j < v; j++){
	                if(matrix[i][j] == INT_MAX)
	                matrix[i][j] = -1;
	            }
	    }

	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
        
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
        clock_t start, end;
        start=clock();
		obj.shortest_distance(matrix);
        end=clock();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
         cout<<endl;
        cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;
	}
	return 0;
}  // } Driver Code Ends