/*
	*Find the smallest binary digit multiple of given number
	*T.c -> O(v+e) i.e. v = number of nodes we come across before reach the result
	*S.c -> O(v)
	
*/

#include<bits/stdc++.h>
#include <functional>
using namespace std;

string findminmultiple(int n){
	queue<string>que;
	set<int>visited;
	string t;
	int res;
	que.push("1");
	while(!que.empty()){
		t = que.front();
		que.pop();
		
		res = stoi(t)%n;
		if(res == 0)
			return t;
			
		if(visited.find(res) == visited.end()){
			visited.insert(res);
			que.push(t+"0");
			que.push(t+"1");
		}
	
	}
	
	return "1";


}


int main(){
	int n;
	cin>>n;
	cout<<findminmultiple(n);
	return 0;
}
