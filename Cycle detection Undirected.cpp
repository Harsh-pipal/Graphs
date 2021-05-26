#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long 
#define INF 1000000000
#define nl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;


//detection of a cycle in a Undirected graph 

//we go to each node and check whether it is visited earlier or not 


ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

bool iscycle(int src,vector<vector<int>>&adj ,vector<bool>&visited ,int parent){
	visited[src]=true;
	for(auto i: adj[src]){
		if(i!=parent){
			if(visited[i]){
				return true;
			}
			if(visited[i]=false and iscycle(i,adj,visited,src)){
				return true;
			}
		}
	}
	return false;
}
	
void solve(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<vector<int>>adj(nodes);
	int cnt=0;
	vector<int>indeg(nodes,0);
	int a,b;
	for(int i=0;i<nodes; i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}	

	bool cycle=false;
	vector<bool>visited(nodes,false);
	for(int i=0;i<nodes;i++){
		if(visited[i]!=true and iscycle(i,adj,visited,-1)){
			cycle =true;
		}
	}
	if(cycle){
		cout<<"Cycle is present ";
	}
	else{
		cout<<"Cycle is not present";
	}
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
