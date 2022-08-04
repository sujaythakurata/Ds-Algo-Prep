/*

	*Largest subarray with equal number of 0s and 1s
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
		
		if(sum == 0){
			maxlen = i+1;
			end = i;
		}
		
		if(hp.find(sum) != hp.end()){
			
			if(maxlen < i - hp[sum]){
				maxlen = i - hp[sum];
				end = i;
			}
			
		}else
			hp[sum] = i;
		
	}
	
	if(maxlen != -1)
		cout<<end - maxlen + 1<<" to "<<end;
	else
		cout<<-1;
	
	

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
