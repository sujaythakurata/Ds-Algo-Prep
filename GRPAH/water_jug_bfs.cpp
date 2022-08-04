/*
	*water jug problem using bfs
	*T.c -> O(j1*j2); because there can be j1*j2 number of states

*/

#include<bits/stdc++.h>

using namespace std;

void print_graph(map<pair<int, int>, pair<int,int>>path, pair<int, int>u){
	if(u.first == 0 && u.second == 0){
		cout<< u.first <<" " << u.second<<endl;
		return;
	}
	print_graph(path, path[u]);
	cout<<u.first << " " << u.second << endl;
}

void bfs(int j1, int j2, int target){
	map<pair<int, int>, int>visited;
	map<pair<int, int>, pair<int,int>>path;
	list<pair<int, int>>queue;
	bool isSolve = false;
	int d, c;
	pair<int, int>ele;
	queue.push_back(make_pair(0,0));
	
	while(!queue.empty()){
		
		ele = queue.front();
		queue.pop_front();
		if(visited[ele] == 1)
			continue;
		if(ele.first < 0 || ele.first > j1 || ele.second < 0 || ele.second > j2)
			continue;
		
		visited[make_pair(ele.first, ele.second)] = 1;
		//hit the target
		if(ele.first == target || ele.second == target){
			
			isSolve = true;
			cout<<"New Solution"<<endl;
			print_graph(path, ele);
			if(ele.first == target){
					cout<< ele.first << " "<<0<<endl;
			}
			else{
				cout<<0<< " "<<ele.second<<endl;
			}
			break;
		}
			
			
		//fill j1
		if(visited[{j1, ele.second}] != 1){
			queue.push_back({j1, ele.second});
			path[make_pair(j1, ele.second)] = ele;
		}
		
		//fill j2
		if(visited[{ele.first, j2}] != 1){
			queue.push_back(make_pair(ele.first,j2));
			path[make_pair(ele.first, j2)] = ele;
		}
		
		//fill j1 -> j2
		d = j2 - ele.second;
		if(j1>=d){
			c = j1 - d;
			if(visited[{c, ele.second + d}] != 1){
				queue.push_back({c, ele.second+d});
				path[make_pair(c, ele.second + d)] = ele;
			}
		}else{
				c = ele.first + ele.second;
				if(visited[{0, c}] != 1){
					queue.push_back({0, c});
					path[make_pair(0,c)] = ele;
				}
			
		}
		
		//fill j2 -> j1
		
		d = j1 - ele.first;
		if(j2>= d){
			c = j2 - d;
			if(visited[{ele.first + d, c}] != 1){
				queue.push_back({ele.first + d, c});
				path[make_pair(ele.first + d, c)] = ele;
			}
		}else{
			c = ele.first + ele.second;
			if(visited[{c, 0}] != 1){
				queue.push_back({c, 0});
				path[make_pair(c, 0)] = ele;
			}
		}
		
		//empty j1
		
		if(visited[{0, ele.second}] != 1){
			queue.push_back({0, ele.second});
			path[{0, ele.second}] = ele;
		}
		
		//empty j2
		if(visited[{ele.first, 0}] != 1){
			queue.push_back({ele.first, 0});
			path[{ele.first, 0}] = ele;
		}
		
		

	}

if(!isSolve)
cout<<"No solution Found"; 

}

int main(){
	int j1, j2, t;
	cin>>j1>>j2>>t;
	bfs(j1, j2, t);

return 0;
}

