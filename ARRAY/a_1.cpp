/*
	*Program for array rotation (juggling algo)
	*T.c ->O(n)
	*S.c ->O(1)
*/

#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
	int rem; 
	while(true && a > 0){
		rem = b % a;
		if(rem == 0)
			break;
		b = a;
		a = rem;
	}
	return a;
}

int main(){
	int n, v, d, s, j, k, temp;
	cin>>n>>d;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>v;
		arr[i] = v;
	}
	
	for(int i = 0; i < n; i ++)
		cout<<i[arr]<<" ";
	cout<<endl;
	
	d = d%n;
	s = gcd(d, n);
	
	for(int i = 0; i < s; i++){
		temp = arr[i];
		j = i;
		
		while(true){
			k = (j+d)%n;
			
			if(k == i)
				break;
				
			arr[j] = arr[k];
			j = k;
		
		}
		arr[j] = temp;
	}
	
	for(int i = 0; i < n; i ++)
		cout<<i[arr]<<" ";
	
	

	return 0;
}
