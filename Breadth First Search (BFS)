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

	
void solve(){
	int nodes,edges;
	cin>>nodes>>edges;
	bool visited[nodes+1];
	vector<int>adj[nodes+1];
	for(int i=0;i<=nodes;i++){
		visited[i]=false;
	}
	int a,b;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	queue<int>q;
	q.push(1);
	visited[1]=true;
	while(!q.empty()){
		int  node=q.front();
		
		q.pop();
		cout<<node<<" ";
		for(int i=0;i<adj[node].size();i++){
			if(visited[adj[node][i]]==false){
				visited[adj[node][i]]=true;
				q.push(adj[node][i]);
			}
		}
	}
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
