#include<bits/stdc++.h>
using namespace std;
int moduloBy11(vector<int> digit, vector<int> freq){
    int sum = 0;
    int n = digit.size();
    int length = 0;
    for(int i = 0; i < n; ++i){
        if(freq[i] % 2 == 0) continue;
        // freq length in odd
        int curSum = 0;
        if(length % 2 == 0){
            sum += -digit[i];
        }
        else{
            sum += digit[i];
        }
    }
    return sum;
}
int main(){
    int N;
    cin >> N;
    vector<int> digit(N);
    for(int j = 0; j < N; ++j){
        cin >> digit[j];
    }
    vector<int> freq(N);
    for(int j = 0; j < N; ++j){
        cin >> freq[j];
    }
    int result;
    result = moduloBy11(digit,freq);
    cout << result;
    return 0;
}