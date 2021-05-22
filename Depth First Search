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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

const int N=1e5+2;

bool visited[N];
vector<int> adj[N];


void dfs(int node){

	//preorder prints in the top to bottom fashion

	visited[node]=true;
	cout<<node<<" ";

	//inorder

	for(int i=0;i<adj[node].size();i++){
		if(visited[adj[node][i]]==false)
			dfs(adj[node][i]);
	}

	//post order prints all the nodes which lie at the end point of each path
}

void solve(){
	int nodes,edges;
	cin>>nodes>>edges;

	for(int i=0;i<=nodes;i++){
		visited[i]=false;
	}

	int x,y;

	for(int i=0;i<edges;i++){
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1);   //root node is given to the function call
	
	return 0;
} 
int main(){
	int t=1;
	//cin>>t;
	while(t--)
	solve();
}
