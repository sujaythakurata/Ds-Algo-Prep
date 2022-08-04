/*

	*Print all triplets in sorted array that form AP without hashing
	*T.c -> O(n^2)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, v, diff;
	cin>>n;
	int arr[n];
	
	for(int i = 0; i < n; i++){
		cin>>v;
		arr[i] = v;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i+1, k = i-1; j < n && k >-1;){
			if(arr[j]+arr[k] == 2*arr[i]){
				cout<<arr[k]<<" "<<arr[i]<<" "<<arr[j]<<endl;
				j++;
				k--;
			}
			else if(arr[j]+arr[k] > 2*arr[i])
				k--;
			else
				j++;
			
		}
	}

	return 0;
}
