class Solution {
public:
    int helper(vector<vector<int>> routes, unordered_map<int, vector<int>> graph, int start, int end){
        if(start == end){
            return 0;
        }
        //visited for bus stops
        unordered_map<int, bool> busstops;
        unordered_map<int, vector<int>> :: iterator it;
        for(it = graph.begin(); it != graph.end(); it++){
            busstops[it -> first] = 0;
        }
        //visited for bus numbers
        bool *busnumber = new bool[routes.size()];
        for(int i = 0; i < routes.size(); i++){
            busnumber[i] = 0;
        }
        
        //BFS starts
        //pair for storing bus stops and count
        queue<pair<int, int>> pending;
        pending.push(make_pair(start, 0));
        busstops[start] = 1;
        
        while(!pending.empty()){
            pair<int, int> front = pending.front();
            pending.pop();
            
            int stop = front.first; // front stop
            int count = front.second; // front count 
            
            if(stop == end){
                return count;
            }
            
            //visiting each bus of that stop
            vector<int> buses = graph[stop];
            
            //here i represents the index of each bus
            for(int i = 0; i < buses.size(); i++){
                if(busnumber[buses[i]] == 1){
                    continue;
                }
                else{
                    
                    //visiting each stop of each bus
                    vector<int> stopsofbus = routes[buses[i]];
                    for(int j = 0; j < stopsofbus.size(); j++){
                        
                        //here j represents the stop number for ith bus
                        if(busstops[stopsofbus[j]] == 1){
                            continue;
                        }
                        else{
                            pending.push(make_pair(stopsofbus[j], count+1));
                            busstops[stopsofbus[j]] = 1;
                        }
                    }
                    busnumber[buses[i]] = 1;
                }
            }
            
        }
        return -1;
    }
    /*void printgraph(vector<vector<int>> graph){
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
    int countstops(vector<vector<int>> routes){
        unordered_set<int> map;
        
        for(int i = 0; i < routes.size(); i ++){
            for(int j = 0; j < routes[i].size(); j++){
                if(map.find(routes[i][j]) == map.end()){
                    map.insert(routes[i][j]);
                }
            }
        } 
        return map.size();
    }*/
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        //int numberofstops = countstops(routes);
        
        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                int index = routes[i][j];
                graph[index].push_back(i);
            }
        }
        return helper(routes, graph, S, T);
    }
};