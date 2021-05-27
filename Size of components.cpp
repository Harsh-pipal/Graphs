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


//Q. find the size of each component of the graph

//Connected components are different seperated parts of the graph

//Basically we are using dfs for this 

//go to the depth of each node and find out whether it is visited or not 
//ans add its size to the vector components


int nodes,edges;
vector<vector<int>>adj;
vector<bool>visited;
vector<int>components;


int get_comp(int src){
	int ans=1;
	if(visited[src]==true){
		return 0;
	}
	visited[src]=true;
	for(auto i:adj[src]){
		if(visited[i]==false){
			
			ans+=get_comp(i);
			visited[i]=true;          //very important to mark true after calling the get_comp function
		}
	}
	return ans;
}

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
	
void solve(){
	//int nodes,edges;
	cin>>nodes>>edges;
	adj=vector<vector<int>>(nodes);
	visited=vector<bool>(nodes,false);
	

	for(int i=0;i<edges;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i=0;i<nodes;i++){
		if(visited[i]==false){
			components.pb(get_comp(i));
		}
	}

	for(auto i:components){
		cout<<i<<" ";
	}

}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
