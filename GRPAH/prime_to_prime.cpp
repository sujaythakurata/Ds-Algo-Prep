/*

	*reach from one prime number to another prime number only changing one digit
	*T.c -> O(v+e)

*/


#include<bits/stdc++.h>

using namespace std;

void fill_prime(vector<int>&plist){
	
	vector<bool>prime(10000, true);
	for(int i = 2; i<10000; i++){
		if(prime[i]){
			for(int j = i *i; j<10000; j+=i)
				prime[j] = false;
		}
	
	}
	
	for(int i = 2; i < 10000; i++){
		
		if(prime[i])
			plist.push_back(i);
	
	}

}

bool compare(int num1, int num2){
		int c = 0;
		string s1 = to_string(num1), s2 = to_string(num2);
		if(s1[0] != s2[0])
			c++;
		if(s1[1] != s2[1])
			c++;
		if(s1[2] != s2[2])
			c++;
		if(s1[3] != s2[3])
			c++;
			
		return (c == 1);
	
}

int bfs(vector<int>adj[], int pos1, int pos2, vector<int>&visited, int n){
	list<int>queue(n);
	int ele;
	queue.push_back(pos1);
	visited[pos1] = 1;
	while(!queue.empty()){
		ele = queue.front();
		queue.pop_front();
		for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
			if(!visited[*i]){
				visited[*i] = visited[ele] + 1;
				cout<<*i<<"\n";
				queue.push_back(*i);
			}
			if(*i == pos2)
				return visited[pos2]-1;
		}
	
	}
	
	return visited[pos2]-1;
	

}

int main(){
	
	int p1, p2, pos1, pos2;
	vector<int>plist;
	fill_prime(plist);
	vector<int>adj[plist.size()];
	vector<int>visited(plist.size(), 0);
	for(int i = 0; i < plist.size(); i++){
		for(int j = i+1; j < plist.size(); j++){
			if(compare(plist[i], plist[j])){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	
	cin>>p1>>p2;
	
	for(int i = 0; i < plist.size(); i++){
		if(plist[i] == p1)
			pos1 = i;
	}
	for(int i = 0; i < plist.size(); i++){
		if(plist[i] == p2)
			pos2 = i;
	}
	
	cout<<bfs(adj, pos1, pos2, visited, plist.size());
	
	

	return 0;
}
