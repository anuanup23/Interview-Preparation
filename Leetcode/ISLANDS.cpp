// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //vector<vector<int>> vis{501,vector<int>(501,0)};
    int vis[501][501] = {};
    bool dfs(int i,int j,int &n, int &m, vector<vector<char>> &mat){
        if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && mat[i][j] == 'O') return false;
        //if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && mat[i][j] == 'X') return true;
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        
        if(mat[i][j] == 'X') return true;
        vis[i][j] = 1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        bool here = true;
        for(int k = 0;k < 4; ++k){
            if(i + dx[k] >= 0 && j + dy[k] >= 0 && !vis[i + dx[k]][j + dy[k]]){
                here &= dfs(i + dx[k], j + dy[k], n, m, mat);
                if(!here) return false;
            }
        }
        // if(here){
        //     mat[i][j] = 'X';
        //     cout << i << " *  " << j << endl;
        // }
        return here;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here
        memset(vis,0,sizeof vis);
        int cnt = 0;
        for(int i = 0; i <= n - 1; ++i){
            for(int j = 0; j <= m - 1; ++j){
                if(mat[i][j] == 'O'){
                   bool surrounded =  dfs(i,j,n,m,mat);
                   if(surrounded) cnt++;
                }
            }
        }
        cout << "CNT __ " << cnt << endl;
        return mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        cout << endl;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends