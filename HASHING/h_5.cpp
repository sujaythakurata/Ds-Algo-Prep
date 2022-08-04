/*

	*Longest subarray having count of 1s one more than count of 0s
	*T.c -> O(n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

void subarray(int arr[], int n){	
	
	int sum = 0, maxlen = -1, end;
	unordered_map<int, int>hp;
	
	for(int i = 0; i < n;i++){
		sum += (arr[i] == 0?-1:1);
		
		if(sum == 1){
			maxlen = i+1;
			end = i;
		}
		
		if(hp.find(sum) == hp.end())
			hp[sum] = i;
		
		if(hp.find(sum-1) != hp.end()){
			
			if(maxlen < i - hp[sum-1]){
				maxlen = i - hp[sum-1];
				end = i;
			}
			
		}
		
	}
	
	cout<<maxlen;
	
	

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
