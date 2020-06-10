#include <bits/stdc++.h>
using namespace std;
void eularian(vector<vector<int>> graph){

	int *degree = new int[graph.size()];
	bool flag = 1;
	int countodd = 0;
	for(int i = 0; i < graph.size(); i++){
		degree[i] = graph[i].size();
		if(degree[i]%2 != 0){
			countodd++;
			flag = 0;
		}
	}
	if(flag == 1){
		cout << "The Graph HAS a eularian path and eularian circuit" << endl;
	}
	if(flag == 0){
		cout << "The Graph DOES NOT have a eularian circuit" << endl;
		if(countodd == 2){
			cout << "The Graph has a eularian path" << endl;
		}
		else{
			cout << "The Graph DOES NOT have a eularian path" << endl;
		}
	}
}
int main(){

	vector<vector<int>> graph(5);

	graph[0].push_back(1);
	graph[1].push_back(0);
	graph[1].push_back(2);
	graph[2].push_back(1);
	graph[0].push_back(2);
	graph[2].push_back(0);
	graph[0].push_back(3);
	graph[3].push_back(0);
	graph[3].push_back(1);
	graph[1].push_back(3);
	graph[3].push_back(4);
	graph[4].push_back(3);

	eularian(graph);
	return 0;
}