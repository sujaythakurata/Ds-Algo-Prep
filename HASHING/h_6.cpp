/*

	*Count Substrings with equal number of 0s, 1s and 2s
	*T.c -> O(n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

void subarray(int arr[], int n){	
	
	int sum = 0, count = 0;
	unordered_map<int, int>hp;
	
	for(int i = 0; i < n;i++){
		sum += (arr[i] == 0?-3:arr[i]);
		
		if(sum == 0){
			count++;
		}
		
		if(hp[sum] > 0)
			count += hp[sum];
		
		if(hp[sum] == 0)
			hp[sum] = 1;
		else
			hp[sum]++;
		
	}
	
	cout<<count;
	
	

}


int main(){
	int n, e;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>e;
		arr[i] = e;
	}
	
	subarray(arr, n);

	return 0;
}
