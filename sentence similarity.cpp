#include <bits/stdc++.h>
using namespace std;
int find(unordered_map<int, int> &parent, int x){
        //cout << "THIS IS FIND" << endl;
        if(parent[x] == x){
            return x;
        }
        int px = find(parent, parent[x]);
        parent[x] = px;
        return px;
    }
    
    void unionofdsu(unordered_map<int, int> &parent, int* &rank, int a, int b){
        //cout << "THIS IS UNION" << endl;
        int la = find(parent, a);
        int lb = find(parent, b);
        
        if(la != lb){
            if(rank[la] > rank[lb]){
                parent[lb] = la;
            }
            else if(rank[la] < rank[lb]){
                parent[la] = lb;
            }
            else{
                parent[la] = lb;
                rank[lb]++;
            }
        }
    }

bool sentencesimilarity(vector<string> s1, vector<string> s2, vector<vector<string>> similar){
	unordered_map<string, int> hashing;
	
	int temp = 0;
	for(int i = 0; i < similar.size(); i++){
		string word1 = similar[i][0];
		string word2 = similar[i][1];

		if(hashing.count(word1) == 0){
			hashing[word1] = temp;
			temp++;
		}
		if(hashing.count(word2) == 0){
			hashing[word2] = temp;
			temp++;
		}
	}
	int sizeofpar = temp + 1;

	unordered_map<int, int> parent;
	int *rank = new int[sizeofpar];

	for(int i = 0; i < sizeofpar; i++){
		rank[i] = 1;
	}
	for(int i = 0; i < similar.size(); i++){

		string word1 = similar[i][0];
		string word2 = similar[i][1];

		if(parent.count(hashing[word1]) == 0){
			parent[hashing[word1]] = hashing[word1];
		}
		if(parent.count(hashing[word2]) == 0){
			parent[hashing[word2]] = hashing[word2];
		}
		unionofdsu(parent, rank, hashing[word1], hashing[word2]);
	}

	for(int i = 0; i < s1.size(); i++){
		if(hashing.count(s1[i]) == 0 || hashing.count(s2[i]) == 0){
			return false;
		}
		if(parent[hashing[s1[i]]] != parent[hashing[s2[i]]]){
			return false;
		}
	}
	return true;
}
int main(){

	/*vector<string> s1 = {"great", "acting", "skills", "kathak", "Saoumya", "Karan" , "kid"};
	vector<string> s2 = {"fine", "drama", "talent", "ballet", "Manisha" , "Vandit" , "kid"};

	vector<vector<string>> similar = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"},
										{"dancing", "ballet"} , {"dancing", "kathak"} , {"girl",  "Manisha"},
										{"girl", "Saoumya"} , {"boy", "Karan"} , {"boy", "Vandit"} , {"boy" , "kid"}, {"girl" , "kid"}};*/
	vector<string> s1 = {"great", "acting", "skills"};
	vector<string> s2 = {"fine", "drama", "talent"};
	vector<vector<string>> similar = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};

	cout << sentencesimilarity(s1, s2, similar) << endl;

	return 0;
}