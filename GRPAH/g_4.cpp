/*
	*Move weighting scale alternate under given constraints
	*T.c -> O(steps * weights array size())
	*S.c -> O(steps)

*/

#include<bits/stdc++.h>

using namespace std;
bool dfs(int diff, int cur, int arr[], int path[], int n, int steps){
	
	if(cur>steps && steps != 0)
		return true;
	
	for(int i = 0; i < n; i++){
	
		if(arr[i] > diff && arr[i] != path[cur - 1]){
			path[cur] = arr[i];
			if(dfs(arr[i] - diff, cur + 1, arr, path, n, steps))
				return true;
		}
	}
	
	return false;

}
int main(){
	int n, steps, w;
	cin>>n>>steps;
	int arr[n];
	int path[steps];
	for(int i = 0; i<n; i++){
		cin>>w;
		arr[i] = w;
	}
	
	if(dfs(0,0,arr, path,n, steps)){
		for(int i = 0; i<steps; i++)
			cout<<path[i]<<" ";
	}else
		cout<<"-1";
	
	return 0;
}
