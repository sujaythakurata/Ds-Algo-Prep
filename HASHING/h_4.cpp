/*
	*Count subarrays with equal number of 1’s and 0’s
	*T.c -> O(n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, v,sum = 0, count = 0;
	cin>>n;
	int arr[n];
	unordered_map<int, int>hp;
	
	for(int i = 0; i < n; i++){
		cin>>v;
		arr[i] = v;
	}
		
		
	for(int i = 0; i < n; i++){
	
		sum += (arr[i] == 0?-1:1);
		if(sum == 0)
			count++;
			
		if(hp[sum]>0)
			count += hp[sum];
			
		if(hp[sum] == 0)
			hp[sum] = 1;
		else
			hp[sum]++;
			
	}
	
	cout<<count;
	
	
	
	
	return 0;
}
