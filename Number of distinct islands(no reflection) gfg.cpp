// C++ implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 
bool isvalid(int row, int col, int n, int m){
    //cout << "THIS IS VALID" << endl;

	if(row > 0 && row < n - 1 && col > 0 && col < m-1){
		return 1;
	}
	return 0;
}
void dfs(vector<vector<int>> grid, int row, int col, vector<vector<int>> &visited, string &code){

//cout << "THIS IS DFS" << endl;
if(visited[row][col] == 1){
    return;
}
	visited[row][col] = 1;
	//for top
            if(row > 0 && grid[row - 1][col] == 1){
                string temp = code + "t";
                code = temp;
                dfs(grid, row - 1, col, visited, code);
            }
            //for bottom
            if(row < grid.size() - 1 && grid[row + 1][col] == 1){
                string temp = code + "b";
                code = temp;
                dfs(grid, row + 1, col, visited, code);
            }
            //for right
            if(col < grid[row].size() - 1 && grid[row][col + 1] == 1){
                string temp = code + "r";
                code = temp;
                dfs(grid, row, col + 1, visited, code);
            }
            //for left
            if(col > 0 && grid[row][col - 1] == 1){
                string temp = code + "l";
                code = temp;
                dfs(grid, row, col - 1, visited, code);
            }
	code = code + "x";
}
int countDistinctIslands(vector<vector<int>>& grid) 
{ 
	unordered_set<string> ans;
	int count = 0;
	//cout << "count  was created" << endl;
	vector<vector<int>> visited(grid.size());
	for(int i = 0; i < grid.size(); i++){
	    visited[i] = vector<int>(grid[0].size());
		for(int j = 0; j < grid[0].size(); j++){
			visited[i][j] = 0;
		}
	}
	//cout << "Visited was created" << endl;
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[0].size(); j++){

			if(grid[i][j] == 1 && visited[i][j] == 0){

				string code = "s";
				dfs(grid, i, j, visited, code);
                //cout << code << endl;
				if(ans.find(code) == ans.end()){
				    ans.insert(code);
					count++;
				}
			}
		}
	}
	return count;
} 
int main() 
{ 
	vector<vector<int> > grid = { { 1, 1, 0, 1, 1 }, 
                                  { 1, 0, 0, 0, 0 }, 
                                  { 0, 0, 0, 0, 1 }, 
                                  { 1, 1, 0, 1, 1 } }; 

	cout << "Number of distinct islands is "
		<< countDistinctIslands(grid); 

	return 0; 
} 
