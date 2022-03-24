#include<bits/stdc++.h>
using namespace std;
void insert_by_sorting(int x, stack<int> &st){
    //cout << x  << " * " << endl;
    if(st.size() == 0) st.push(x);
    else{
        if(st.top() <= x) st.push(x);
        else{
            int y = st.top();
            st.pop();
            insert_by_sorting(x,st);
            st.push(y);
        }
    }
}
void sortStack(stack<int> &st){
    if(st.size() == 0) return;
    int x = st.top();
    st.pop();
    sortStack(st);
    insert_by_sorting(x,st);
}
void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(5);
    st.push(17);
    st.push(67);
    st.push(35);
    print(st);
    sortStack(st);
    print(st);
    return 0;
}