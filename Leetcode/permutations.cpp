#include<bits/stdc++.h>
using namespace std;
//map<char,int> cnt;
void solve(int i, int n, string &s){
    if(i == n - 1) {
        cout << s << endl;
        return;
    }
    char prev = '&';
    for(int x = i; x < n; ++x){
        if(prev == s[x]) continue;
        swap(s[x],s[i]);
        prev = s[x];
        solve(i+1,n,s);
        swap(s[x],s[i]);
    }
}
int main(){
    string s; cin >> s;
    //for(auto x: s) cnt[x]++;
    sort(s.begin(),s.end());
    solve(0,s.size(),s);
    return 0;
}