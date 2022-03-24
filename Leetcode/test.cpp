#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "asdfsdftra";
    deque<char> q;
    unordered_map<char,int> map;
    for(int i = 0; i < s.size(); ++i){
        // cout << "ss";
        if(map.find(s[i]) == map.end()) q.push_back(i);
        map[s[i]]++;
        while(!q.empty() && map[q.front()] > 1){
           // cout << "jj";
            q.pop_back();
        } 
    }
    cout << q.front() << endl;
    return 0;
}
// string s = "asdfsdftra";
// dequeue<char> q;
// unordered_map<char,i> map;
// int ans = -1;
// int minidx = INT_MAX;
// // for(int i = str.size() - 1; i >= 0; --i){
// // 	if(st.find(str[i]) == st.end()){  O(1) // not present
// //   	ans = i; ====a,r,t,f,d,s
// //     st.insert(str[i]);
// //     else{
// // 			minidx = min(ans,i);
// //     }
// //   }
// //   if(minidx != INT_MAX) return "no answer";
// //   else return str[i];
  
// // }  asdfsdftra

// for(int i = 0; i < s.size(); ++i){
//     if(mp[str[i]] == 0])
//         q.push(i);
//     map[str[i]]++;
//     while(!q.empty() && map[q.front()] > 1) q.pop();
// }
// return q.front();