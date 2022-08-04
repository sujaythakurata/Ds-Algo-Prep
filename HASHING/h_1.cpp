/*
	*Index Mapping (or Trivial Hashing) with negatives allowed
	*T.c -> O(1) ->insert, delete, update
	*S.c ->O(n*2) -> O(n)
*/

#include<bits/stdc++.h>

using namespace std;
bool has[1000][2]={false};

bool search(int ele){
	if(ele>-1)
		return has[ele][0];
	else
		return has[abs(ele)][1];
		
}

int main(){
	int n, e, q;
	cin>>n>>q;
	for(int i = 0; i < n; i++){
		cin>>e;
		if(e>-1)
			has[e][0] = true;
		else
			has[abs(e)][1] = true;
	}
	
	for(int i = 0; i < q; i++){
		cin>>e;
		cout<<search(e)<<endl;
	}
	
	

	return 0;
}
