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


//Kruskal algorithm 
//Find minimum spanning tree 
//sort edges according to weight
//exclude edges which forms cycle in graph

const int N=1e5+2;
vector<int>parent(N);
vector<int>sz(N);

void make_set(int a){
	parent[a]=a;
	sz[a]=1;
}

int find_set(int a){
	if (parent[a]==a)
		return a;
	else
		return parent[a]=find_set(parent[a]);
}

void unioni(int a, int b){
	a=find_set(a);
	b=find_set(b);

	if (a!=b){
		if (sz[a]<sz[b])
			swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
		
	}
}
void solve(){
	for (int i=0;i<N;i++){
		make_set(i);
	}

	int nodes,edges;
	cin>>nodes>>edges;
	vector<vector<int>>adj;

	for (int i=0;i<edges;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj.push_back({w,u,v});
	}
	sort(adj.begin(),adj.end());
	int cost=0;
	for(auto i: adj){
		int w=i[0];
		int u=i[1];
		int v=i[2];

		if(find_set(u)==find_set(v))
			continue;
		else{
			cout<<u<<" "<<v<<endl;
			cost+=w;
			unioni(u,v);
		}
	}
	cout<<cost<<endl;
			
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
