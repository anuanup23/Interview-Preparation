#include<bits/stdc++.h>
using namespace std;
class cmp {
    vector<int> param;
public:
    cmp(vector<int> p) : param(p) {}
    bool operator()(int i, int j) {
        // logic uses param
        //for(auto x: param) cout << x << " ";
        //cout << endl;
        string I = to_string(i);
        string J = to_string(j);
        reverse(I.begin(),I.end());
        reverse(J.begin(),J.end());
        i = stoi(I);
        j = stoi(J);

        int x = 0;
        int y = 0;
        while(i){
            x = 10*x + param[i%10];
            i /= 10;
            y++;
        }
        int z = 0;
        y = 0;
        while(j){
            z = 10*z + param[j%10];
            j /= 10;
            y++;

        }
        cout << x << "-" << z << endl;
        return x < z;
    }
};

int main() {
    vector<int> v = {991,338,38};
    // initialize v with some random values
    // for(int i = 0; i < 100; ++i){
    //     v[i] = rand() % 500;
    // }
    //unordered_map<int,int> paramA;
    vector<int> temp = {8,9,4,0,2,1,3,5,7,6};
    sort(v.begin(), v.end(), cmp(temp));
    for(auto x: v) cout << x << " ";
}