//Author @Harsh_xerus

#include<bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#define rep(i,n) for (int i = 0; i < n; i++)
#define mem0(arr) memset(arr, 0, sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define pb push_back
#define ff first
#define ss second
#define ll long long 
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define INF 1e18
#define nl '\n'
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
const ll maxn = 1e6 + 2;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
typedef unsigned long long ull;
typedef long double lld;
using namespace std;


//--------------------------Helper_functions-------------------------------//

//-------------------------------GCD---------------------------------------//

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}

//-------------------------------LCM---------------------------------------//

ll lcm(ll a, ll b){return (a * b) / gcd(a, b);}

//----------------------------Factorial------------------------------------//

ll fact(ll x){if(x==0)return 1;return (x*fact(x-1))%mod;}

//-----------------------------Bin_Expo------------------------------------//

ll binpow(ll a,ll b) {
     ll res = 1;
     while (b > 0) {
         if (b & 1)
             res = (res * a)%mod;
         a = (a * a)%mod;
         b >>= 1;
     }
     return res%mod;
}

//-------------------------Sum/Count of digits----------------------------//

ll sd(ll x){ll temp=0;while(x>0){temp+=x%10;x/=10;}return temp;}
ll cd(ll x){ll temp=0;while(x>0){temp++;x/=10;}return temp;}

//-------------------------------START-------------------------------------//

//minimum path from source node in DAG using DFS and topo sort

//using dfs for topo sort and then iterating through the
//stack obtained 

int n, m;
vector<int>vis(maxn,0);
vector<pair<int,int>>adj[maxn];
vector<int>dist(maxn,1e5);

void dfstoposort(int node , stack<int>&st){
    vis[node]=1;
    for(auto x:adj[node]){
        if(!vis[x.ff])
            dfstoposort(x.ff,st);
    }
    st.push(node);
}

void solve(){ 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
    }
    stack<int>st;
    int src;
    cin>>src;
    //first create a topo sort for this graph;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfstoposort(i,st);
        }
    }
    dist[0]=0;
    while(!st.empty()){
        int currnode = st.top();
        st.pop();

        //if the node has been reached previously
        if(dist[currnode]!=1e5){
            for(auto x:adj[currnode]){
                if(dist[currnode]+x.ss < dist[x.ff])
                    dist[x.ff] = dist[currnode]+x.ss;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<nl;

}

int main(){
    
    ll t = 1, i = 1;
    //cin >> t;
    cout << std::setprecision(15);
    //presolve();
    
    while (t--)
    {
        //cout << "Case #" << i << ": ";   //only during google contest
        //i++;                             //only during google contest
    
        solve();
    }
}
