#include<bits/stdc++.h>
using namespace std;
void insert_at_bottom(int x, stack<int> &st){
    //cout << "bottom" << endl;
    if(st.size() == 0) st.push(x);
    else{
        // pop the elements recursively
        int y = st.top();
        st.pop();
        insert_at_bottom(x,st);
        st.push(y);
    }
}
void reverse(stack<int> &st){
    //cout << "reverse" << endl;
    if(st.size() == 0) return;
    int x = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(x,st);
}
void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printStack(st);
    reverse(st);
    //cout << st.size() << endl;
    printStack(st);
    return 0;
}