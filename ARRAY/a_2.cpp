/*
	*Rearrange an array such that arr[i] = i
	*T.c -> O(n)
	*S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, v, x, y;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n;i ++){ 
		cin>>v;
		arr[i] = v;
	}
	
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl<<endl;
	
	for(int i = 0; i < n; i++){

		while(arr[i] != -1 && arr[i] != i){
			
			x = arr[i];
			while(arr[x] != -1 && arr[x] != x){
				y = arr[x];
				arr[x] = x;
				x = y;
			}
			arr[x] = x;
			
			if(arr[i] != i)
				arr[i] = -1;
			
		}
		
	}
	
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	

	return 0;
}
