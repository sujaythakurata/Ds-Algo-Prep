/*

	*Print all triplets in sorted array that form AP using hasing
	*T.c -> O(n^2)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, v, diff;
	cin>>n;
	int arr[n];
	unordered_set<int>hs;
	
	for(int i = 0; i < n; i++){
		cin>>v;
		arr[i] = v;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			diff = arr[j] - arr[i];
			if(hs.find(arr[i]-diff) != hs.end())
				cout<<arr[i]-diff<<" "<<arr[i]<<" "<<arr[j]<<endl;
			
		}
		hs.insert(arr[i]);
	}

	return 0;
}
