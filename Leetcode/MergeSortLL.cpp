// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void getMiddle(Node *head, Node ** first, Node ** second){
        if(!head) return;
        Node * slow = head, *fast = head->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *first = head;
        *second = slow->next;
        slow->next = NULL;
    }
    Node * mergeBoth(Node * first, Node * second){
        Node * ans = NULL;
        if(!first) return second;
        if(!second) return first;
        if(first->data <= second->data){
            ans = first;
            ans->next = mergeBoth(first->next,second);
        }
        else{
            ans = second;
            ans->next = mergeBoth(first,second->next);
        }
        return ans;
    }
    void sortFunction(Node ** head){
        Node *cur = *head;
        Node * first, *second;
        if(!cur || !cur->next) return;
        getMiddle(cur,&first,&second);
        sortFunction(&first);
        sortFunction(&second);
        *head = mergeBoth(first,second);
    }
    Node* mergeSort(Node* head) {
        // your code here
        sortFunction(&head);
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends