// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<iostream> 
#include<algorithm> 
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
char id;	 // Job Id 
int dead; // Deadline of job 
int profit; // Profit if job is over before or on deadline 
}; 
bool compare(Job a, Job b){
	return a.profit > b.profit;
}
void printJobScheduling(Job arr[], int n) 
{ 
	sort(arr, arr + n, compare);
	int maxdead = INT_MIN;

	for(int i = 0; i < n; i++){
		maxdead = max(maxdead, arr[i].dead);
	}

	char *seq = new char[maxdead];
	int ans = 0;
	for(int i = 0; i < maxdead; i++){
		seq[i] = '_';
	}

	for(int i = 0; i < n; i++){
		int haveto = arr[i].dead - 1;
		int prof = arr[i].profit;
		int type = arr[i].id;

		if(seq[haveto] == '_'){
			seq[haveto] = type;
			ans += prof;
		}
		else{
			int count = haveto;
			while(count >= 0 && seq[count] != '_'){
				count--;
			}
			if(count < 0){
				continue;
			}
			else{
				seq[count] = type;
				ans += prof;
			}
		}
	}
	cout << ans << endl;
	cout << "The Following is the sequence:" << endl;

	for(int i = 0; i < maxdead; i++){
		cout << seq[i] << " ";
	}
} 
 
int main() 
{ 
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
				{'d', 1, 25}, {'e', 3, 15}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Following is maximum profit sequence of jobs:"; 
	printJobScheduling(arr, n); 
	return 0; 
} 
