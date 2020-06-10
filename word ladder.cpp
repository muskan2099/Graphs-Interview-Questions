class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> map;
        for(int i = 0; i < wordList.size(); i++){
            map.insert(wordList[i]);
        }
        queue<pair<string,int>>pending;
        pending.push({beginWord, 1});
        

        while(!pending.empty()) {
            
            if(pending.front().first == endWord) {
                return pending.front().second;
            }
            
            string front = pending.front().first;
            int count = pending.front().second;
            pending.pop();
            
            for(int i = 0; i < front.size(); i++) {
                
                char ch = front[i];
                
                for(char c = 'a'; c <= 'z'; c++) {
                    
                    if(ch == c) continue;
                    front[i] = c;
                    
                    if(map.find(front) != map.end()) {
                        pending.push({front, count + 1});
                        map.erase(front);
                    }
                    
                    front[i] = ch;
                }
            }
        }
        return 0;
    }
};