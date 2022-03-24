#include<bits/stdc++.h>
using namespace std;
int openCnt = 0, closeCnt = 0;
void solve(int i, int n, string &s){
    if(i == n){
        cout << s << endl;
        return;
    }
    if(closeCnt < openCnt){
        s += ')';
        closeCnt++;
        solve(i+1,n,s);
        s.pop_back();
        closeCnt--;

    }
    if(openCnt < n/2) {
        s += '(';
        openCnt++;
        solve(i+1,n,s);
        s.pop_back();
        openCnt--;
    }
}
int main(){
    int n; cin >>n;
    if(n % 2 == 1){
        cout << "not possible" << endl;
    }
    else{
        string s ="";
        solve(0,n,s);
    }
    return 0;
}