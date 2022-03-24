#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int val;
    Node * next;
    Node * prev;
    Node(){
        val = 0;
        next = prev = NULL;
    }
    Node(int x){
        val = x;
        next = prev = NULL;
    }
};
class Stack{
    public:
    Node * stack; // head element 
    Node * middle;
    int cnt = 0;
    Stack(){cnt = 0;}
    void push(int x){
        Node * newNode = new Node(x);
        if(cnt == 0){
            stack = newNode;
            middle = stack;
            cnt += 1;
            return;
        }
        stack->prev = newNode;
        newNode->next = stack;
        stack = newNode;
        cnt += 1;
        if(cnt % 2 == 0){
            middle = middle->prev;
        }
    }
    void pop(){
        if(cnt == 0){
            cout << "stack is Empty Cannot POP" << endl;
            return;
        }
        if(cnt == 1){
            delete(stack);
            cnt = 0;
            return;
        }
        Node *temp = stack;
        stack->next->prev = NULL;
        stack = stack->next;
        cnt -= 1;
        if(cnt % 2 == 1){
            middle = middle->next;
        }
        delete temp;
    }
    void getmiddle(){
        if(cnt == 0){
            cout << "stack is Empty Cannot find Middle Element" << endl;
            return;
        }
        cout <<"Middle value is : " <<  middle->val << endl;
    }
    void print(){
        if(cnt == 0){
            cout << "stack has no elements to print" << endl;
            return;
        }
        Node * temp = stack;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Stack st;
    st.pop();
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    st.print();
    st.getmiddle();
    st.pop();
    st.print();
    st.getmiddle();
    st.pop();
    st.print();
    st.getmiddle();
    st.pop();
    st.print();
    st.getmiddle();
    st.pop();
    st.pop();
    st.pop();
    st.print();
    st.getmiddle();
    st.push(100);
    st.push(200);
    st.push(120);
    st.push(2200);
    st.push(120);
    st.push(220);
    st.print();;
    st.getmiddle();
    return 0;
}