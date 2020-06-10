#include <bits/stdc++.h>
using namespace std;
void eularian(vector<vector<int>> graph){

	int *outdegree = new int[graph.size()];
	int *indegree = new int[graph.size()];
	for(int i =0; i < graph.size();i++){
		indegree[i] = 0;
	}

	for(int i = 0; i < graph.size(); i++){
		outdegree[i] = graph[i].size();
		for(int j = 0; j < graph[i].size(); j++){
			indegree[graph[i][j]]++;
		}
	}
	int countnotin = 0;
	int countnotout = 0;
	int count = 0;
	bool iscircuit = 1;
	for(int i = 0; i< graph.size(); i++){
		if(outdegree[i] != indegree[i]){
			iscircuit = 0;
			count++;
			if(outdegree[i] > indegree[i] && outdegree[i] - indegree[i] == 1){
				countnotout++;
			}
			else if(outdegree[i] < indegree[i] && indegree[i] - outdegree[i] == 1){
				countnotin++;
			}
		}
	}
	if(iscircuit == 1){
		cout << "The graph has both eularian path and circuit" << endl;
	}
	if(iscircuit == 0){
		cout << "The Graph DOES NOT have a eularian circuit" << endl;
		if(count == 2 && countnotout == 1 && countnotin == 1){
			cout << "The Graph has a eularian path" << endl; 
		}
		else{
			cout << "The Graph DOES NOT have a eularian path" << endl;
		}
	}
}
int main(){

	vector<vector<int>> graph(5);

	graph[1].push_back(0);
	graph[0].push_back(3);
	graph[3].push_back(4);
	graph[4].push_back(2);
	//graph[0].push_back(2);
	graph[2].push_back(1);

	eularian(graph);
	return 0;
}