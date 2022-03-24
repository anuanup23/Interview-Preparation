#include<bits/stdc++.h>
using namespace std;
int main(){
    char c;
    int *p = (int*) &c;
    *p = 5;
    cout << *p << endl;
    int *x = static_cast<int*> (&c);
    return 0;
}