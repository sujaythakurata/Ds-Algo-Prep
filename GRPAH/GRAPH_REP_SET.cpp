/*
	*graph representation using set
	*edges will be store in decending order
	*Adding an edge takes O(log V), as opposed to O(1) in vector implementation
*/

#include<iostream>
#include<set>
using namespace std;

int main(){
	
	int n = 5, e = 7, u, v;
	set<int , greater<int>>adj[n];
	
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	for(int i = 0; i < n; i++){
		cout<< i << " : ";
		for(auto j = adj[i].begin(); j != adj[i].end(); j++){
			cout<< *j<<" ";
		}
		cout<<"\n";
		
	}
	


	return 0;
}
