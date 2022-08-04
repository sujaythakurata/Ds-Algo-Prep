/*
	*Stepping Numbers
	*T.c -> O(n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>

using namespace std;

void bfs(int n, int m, int num){
	
	queue<int>que;
	int ele, lastdigit, e1, e2;
	que.push(num);
	
	while(!que.empty()){
		ele = que.front();
		que.pop();
		if(ele <=m && ele >=n)
			cout<<ele<<" ";
		if(ele == 0 || ele >m)
			continue;
			
		lastdigit = ele%10;
		e1 = ele*10 + (lastdigit - 1);
		e2 = ele*10 + (lastdigit + 1);
		if(ele == 0)
			que.push(e2);
		else if(ele == 9)
			que.push(e1);
		else{
			que.push(e1);
			que.push(e2);
		}
		
	}

}
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < 10; i++)
		bfs(n, m, i);

	return 0;
}
