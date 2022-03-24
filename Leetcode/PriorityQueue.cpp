#include<bits/stdc++.h>
using namespace std;
void maxDiamonds(int A[], int N, int K){
    priority_queue<int> pq;
    for(int i = 0;i < N; ++i){
        pq.push(A[i]);
    }
    int ans = 0;
    while(!pq.empty() && K > 0){
        int top = pq.top();
        ans += top;
        pq.pop();
        pq.push(top/2);
        K--;
    }
    cout << ans << endl;
}
int main()
{
    int A[] = { 2, 1, 7, 4, 2 };
    int K = 3;
    int N = sizeof(A) / sizeof(A[0]);
    maxDiamonds(A, N, K);
 
    return 0;
}