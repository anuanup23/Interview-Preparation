#include<bits/stdc++.h>
using namespace std;
void transformArray(int arr[], int n, int target){
    int i = 0, j = 0;
    // my code
    while(j < n){
        if(arr[i] < target){
            i++;
        }
        else{
            if(arr[j] < target && i != j){
                swap(arr[i],arr[j]);
                i++;
            }
        }
        j++;
        //cout << i << "  " << j << endl;
    }
    //return;
    i = n - 1;
    j = n - 1;
    while(j > -1){
        if(arr[i] > target){
            i--;
        }
        else{
            if(arr[j] > target && i != j){
                swap(arr[i],arr[j]);
                i--;
            }
        }
        j--;
    }
    // j = 1;
    // while(j < n){
    //     if(arr[i] < target){
    //         i++;
    //     }
    //     else{
    //         if(arr[j] < target){
    //             swap(arr[i],arr[j]);
    //             i++;
    //         }
    //     }
    //     j++;
    // }
    // j--;
    // while(i < j){
    //     if(arr[j] > target){
    //         j--;
    //     }
    //     else{
    //         if(arr[i] > target){
    //             swap(arr[i],arr[j]);
    //             j--;
    //         }
    //     }
    //     i++;
    // }

}
int main(){
    int arr[] = {2,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    transformArray(arr,n,0);
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}