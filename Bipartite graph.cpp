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

//Bipartite graph

//It is graph in which all vertices can be divided into two disjoint sets and independent sets U and V 
//such that every edge connects a vertex in U to V

//The graph does not contains any odd length cycle 

//the graph is 2 colorable

//2 colorable is if i color a node as red(0) then all its neighbour will be blue(1)

vector<vector<int>>adj;
vector<bool>visited;
vector<int>col;
bool bipartite;

void color(int u,int curr){
	if(col[u]!=-1 and col[u]!=curr){
		bipartite=false;
		return;
	}
	col[u]=curr;
	if(visited[u]==true)
		return;
	visited[u]=true;
	for(auto i:adj[u]){
		color(i,curr xor 1);

		// 0 xor 1 = 1
		// 1 xor 1 = 0
	}
}


ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
	
void solve(){

	bipartite=true;
	int nodes,edges;
	cin>>nodes>>edges;
	adj=vector<vector<int>>(nodes);
	visited=vector<bool>(nodes,false);
	col=vector<int>(nodes,-1);

	for(int i=0;i<edges;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);

	}

	for(int i=0;i<nodes;i++){
		if(visited[i]==false){
			color(i,0);
		}
	}
	if(bipartite==true){
		cout<<"Bipartite garph";
	}
	else
		cout<<"Not a Bipartite graph";
	
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
