#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string first = "", second = "";
    int firstMap[26] = {0}, secondMap[26] = {0};
    int inputCnt = 0;
    while(inputCnt < 2 && cin >> s){
        if(first.size() == 0) first = s;
        else second = s;
        inputCnt++;
    }
    for(int i = 0; i < first.size(); ++i){
        firstMap[first[i] - 'a']++;
    }
    for(int j = 0; j < second.size(); ++j){
        secondMap[second[j] - 'a']++;
    }
    int answer = 0;
    for(int i = 0; i < 26; ++i){
        answer += min(firstMap[i], secondMap[i]);
    }
    cout <<  answer << endl;
    return 0;
}



/*
anup
unpa
apnu
anpu
anup*/