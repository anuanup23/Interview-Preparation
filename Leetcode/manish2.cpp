#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows, cols;
    cin >> rows >> cols;
    int currCol, currRow; cin >> currRow >> currCol;
    char matrix[rows][cols];
    for(int i = 0; i < rows; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < cols; ++j){
            matrix[i][j] = s[j];
        }
    }
    queue<pair<int,int>> q;
    q.push({currRow,currCol});
    int answer = 0;
    bool visited[rows][cols] = {false};
    visited[currRow][currCol] = true;
    bool found = false;
    while(!q.empty()){
        int sz = q.size();
        auto currElem = q.front(); q.pop();
        if(currElem.first == rows - 1 || currElem.second == cols - 1){
            found = true;
            break;
        }
        while(sz--){
            int dx[4] = {0,0,-1,1};
            int dy[4] = {1,-1,0,0};
            for(int k = 0; k < 4; ++k){
                int nx = currElem.first + dx[k];
                int ny = currElem.second + dy[k];
                if(nx < rows && nx > -1 && ny < cols && ny > -1 && !visited[nx][ny] && matrix[nx][ny] == '.'){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            } 
        }
        answer++;
    }
    if(found) cout << answer << endl;
    else cout << "-1" << endl;
    return 0;
}