/*
	*Minimum steps to reach end of array under constraints
	*T.c -> O(n^2)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>

using namespace std;

int bfs(int s, int dest, int n, vector<int>index[], int arr[]){
	queue<pair<int, int>>que;
	pair<int, int>src;
	vector<bool>vs(n, false);
	que.push({s, 0});
	vs[s] = true;
	while(!que.empty()){
		src = que.front();
		que.pop();
		if(src.first == dest)
			return src.second;
		if(src.first+1 < n && !vs[src.first+1]){
			que.push({src.first+1, src.second + 1});
			vs[src.first+1] = true;
		}
		if(src.first-1 > -1 && !vs[src.first-1]){
			que.push({src.first-1, src.second + 1});
			vs[src.first-1] = true;
		}
		for(int i = 0; i < index[arr[src.first]].size(); i++){
			//if(arr[i] == arr[src.first]){
				if(!vs[index[arr[src.first]][i]]){
					que.push({index[arr[src.first]][i], src.second+1});
					vs[index[arr[src.first]][i]] = true;
				}
			//}
		}
		
	
	}
	
	return src.second;
}

int main(){
	int n, ele;
	cin>>n;
	int arr[n];
	vector<int>index[10];
	for(int i = 0; i < n; i++){
		cin>>ele;
		arr[i] = ele;
		index[ele].push_back(i);
	}

	
	cout<<bfs(0,n-1, n, index, arr);
	
	


	return 0;
}
