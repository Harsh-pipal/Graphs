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

//cycle detection in directed graphs 

//we use stack for this purpose 

//if an element in the stack points to the element below it then it means that we got a cycle

//same ideology is used we visit each noded of root node and check for the cycle

bool iscycle(int src , vector<vector<int>>&adj , vector<bool>&visited , vector<int>&stack){
	stack[src]=true;
	if(visited[src]==false){
		visited[src]=true;
		for(auto i:adj[src]){
			if(visited[i]==false and iscycle(i,adj,visited,stack))
				return true;
			if(stack[i]==true)
				return true;
		}
	}
	stack[src]=false;
	return false;
}
ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}


	
void solve(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<vector<int>>adj(nodes);
	for(int i=0;i<edges;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
	}
	bool cycle =false;

	vector<bool>visited(nodes,false);
	vector<int>stack(nodes,0);

	for(int i=0;i<nodes;i++){
		if(visited[i]==false and iscycle(i,adj,visited,stack))
			cycle =true;
	}
	if(cycle)
		cout<<"Cycle is present";
	else
		cout<<"Cycle is not present";
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
