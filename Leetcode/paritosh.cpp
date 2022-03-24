#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>> subSets;
void generateSubsets(vector<int> &A, int curIndex, int N, vector<int> &curSum){
    if(curIndex == N){
        subSets.push_back(curSum);
        return;
    }
    curSum.push_back(A[curIndex]);
    generateSubsets(A,curIndex + 1,N,curSum);
    curSum.pop_back();
    generateSubsets(A,curIndex + 1,N,curSum);
}
int MinDifference(vector<int> &A){
    vector<int> temp;
    generateSubsets(A,0,A.size(),temp);
    int answer = INT_MAX;
    for(int i = 0; i < subSets.size(); ++i){
        int sum = 0;
        int firstSum = accumulate(subSets[i].begin(),subSets[i].end(),sum);
        for(int j = i + 1; j < subSets.size(); ++j){
            int secondSum = accumulate(subSets[j].begin(),subSets[j].end(),sum);
            answer = min(answer, abs(secondSum - firstSum));
        }
    }
    return answer;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    vector<int> A(N);
    for(int j = 0; j < N; ++j){
        cin >> A[j];
    }
    int result = MinDifference(A);
    cout << result; 
    return 0;
}