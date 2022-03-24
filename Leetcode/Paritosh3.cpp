#include<bits/stdc++.h>
using namespace std;
int largestGroup(int N, int M, vector<int> &AR){
    unordered_map<int,int> mp;
    int cnt = 0;
    int answer = N;
    for(int i = 0; i < N; ++i){
        mp[AR[i]]++;
    }
    for(int i = 0; i < N; ++i){
        if(mp.find(M - AR[i]) != mp.end()){
            answer -= mp[AR[i]]++;
            answer -= mp[M - AR[i]]++;
        }
    }
    return answer;
}
int main(){
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> AR(N);
    for(int i = 0; i < N; ++i){
        cin >> AR[i];
    }
    int result = largestGroup(N,M,AR);
    cout << result;
    return 0;
}