/*
	*Minimum number of operation required to convert number x into y
	*T.c -> O(n)
	*S.c -> O(n)
*/

#include<bits/stdc++.h>

using namespace std;

int main(){

	int x, y;
	pair<int, int>ele;
	set<int>visited;
	queue<pair<int, int>>que;
	
	cin>>x>>y;
	if(x<=0)
		cout<<-1;
	else{
		que.push({x, 0});
		visited.insert(x);
	}
	
	while(!que.empty()){
		ele = que.front();
		que.pop();
		
		if(ele.first == y){
			cout<<ele.second;
			break;
		}
		
		if(visited.find(ele.first*2) == visited.end())
			que.push({ele.first*2, ele.second + 1});
		if(visited.find(ele.first - 1) == visited.end())
			que.push({ele.first-1, ele.second+1});
		
	}
	

	return 0;
}
