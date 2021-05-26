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

//Topological sort of graphs 

// Can also be used to find cycles in graph

//Maintaining count variable to check whether elements in the queue are equal to number of nodes

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
	
void solve(){
	int nodes,edges;
	cin>>nodes>>edges;
	vector<int>adj[nodes+1];
	int cnt=0;
	vector<int>indeg(nodes,0);
	int a,b;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		adj[a].pb(b);

		indeg[b]++;

	}
	queue<int>q;
	for(int i=0;i<nodes;i++){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		cnt++;
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(auto it:adj[x]){
			indeg[it]--;
			if(indeg[it]==0)
				q.push(it);
		}
	}
	
	
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
