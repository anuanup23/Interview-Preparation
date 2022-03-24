#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int k;
	cin >> k;
	deque <int> Q(k);
	int i;
	//int currmax = INT_MIN;
	for(i = 0; i < k; ++i){
	    while(!Q.empty() && arr[i] > arr[Q.back()]){
	        Q.pop_back();
            cout << "ddd " << i  << " " << Q.size() << endl;
        }
	     Q.push_back(i);
	}
	for(; i < n; ++i){
		cout<<arr[Q.front()]<<" ";
		while(!Q.empty() && Q.front() <= i - k) Q.pop_front();
		while(!Q.empty() && arr[i] > arr[Q.back()]) Q.pop_back();
		Q.push_back(i);
	}
	cout<<arr[Q.front()]<<" " << endl;
	return 0;
}