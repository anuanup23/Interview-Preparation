#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_multimap<int,int> mp;
    mp.insert({1,1});
    mp.insert({1,2});
    auto it = mp.find(1);
    cout << it->first << " " << it->second << endl;
    for(auto x: mp){
        cout << x.first << " "<< x.second << endl;
    }
    
    return 0;
}