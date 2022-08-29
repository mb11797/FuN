#include<iostream>
using namespace std;

void update_assignment(int optimal_path[], int path[], int path_len){
	for(int i=0; i<path_len; i++)
		optimal_path[i] = path[i] + 1;
	return;
}

void assign_chapters(int u, int sum, int n_chapters, int k, vector<vector<int>> &dag, int optimal_path[], int path[], int path_len){
	static int minm = INT_MAX;

	if(k < 0)
		return;

	path[path_len] = u;
	path_len++;

	if(k == 0 && u == n_chapters){
		if(sum < minm){
			update_assignment(optimal_path, path, path_len);
			minm = sum;
		}
	}

	for(int v=u+1; v<=n_chapters; v++){
		sum += dag[u][v];
		assign_chapters(v, sum, k-1, dag, optimal_path, path, path_len);
		sum -= dag[u][v];
	}
	return;
}

void min_assignment(int pages[], int n_chapters, int n_days, int optimal_path[]){
	int avgPages = 0;
	int sum = 0;
	int S[n_chapters+1];
	int path[n_days+1];

	S[0] = 0;

	for(int i=0; i<n_chapters; i++){
		sum += pages[i];
		S[i+1] = sum;
	}

	avgPages = round(sum / n_days);
	vector<vector<int>> dag;	//Directed Acyclic Graph
	for(int i=0; i<=n_chapters; i++){
		vector<int> row;
		for(int j=0; j<=n_chapters; j++){
			if(j<=i){
				//no link
				row.push_back(-1);
			}
			else{
				sum = abs(avgPages - (S[j] - S[i]));
				dag[i][j] = sum;
			}
		}
	}

	assign_chapters(0, 0, n_chapters, n_days, dag, optimal_path, path, 0);

	cout<<"OPTIMAL CHAPTER ASSIGNMENT: "<<endl;

	for(int i=0; i<n_days; i++){
		ch = optimal_path[i];
		cout<<"Day "<<i+1<<": "<<ch<<" ";
		ch++;
		while((i < n_days-1 && ch < optimal_path[i+1]) || (i == n_days-1 && ch <= n_chapters)){
			cout<<ch<<" ";
			ch++;
		}
		cout<<endl;
	}
	return;
}

int main(){
	int n_chapters;
	cin>>n_chapters;

	int pages[n_chapters];
	for(int i=0; i<n_chapters; i++){
		cin>>pages[i];
	}

	int n_days;
	cin>>n_days;

	int optimal_path[n_days+1];

	min_assignment(pages, n_chapters, n_days, optimal_path);

	return 0;
}