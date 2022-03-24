#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int r = n - i; // 4
        for(int j = 0; j < n; ++j){
            cout << r - j;
        }
        cout << endl;
    }
    return 0;
}