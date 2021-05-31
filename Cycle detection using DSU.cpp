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


//cycle detection in undirected graph using DSU

//If two nodes are in same set then cycle is detected

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
	bool cycle =false;
	for(int i=0;i<edges;i++){
		int a,b;
		cin>>a>>b;
		if (find_set(a)==find_set(b))
			cycle = true;
		else
			unioni(a,b);
	}

	if (cycle)
		cout<<"cycle is present";
	else
		cout<<"cycle is not present";
		
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)
	solve();
}
