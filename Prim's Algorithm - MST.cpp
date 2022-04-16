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

//Prim's algorithm ....finding the minimun spanning tree...
//a tree with n nodes and n-1 edges and the weight of this tree should be 
//minimum.

int n, m;
vector<int>vis(maxn,0);
vector<pair<int,int>>adj[maxn];
vector<int>dist(maxn,1e5);


void solve(){ 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int par[n];
    bool mst[n];
    int key[n];

    for(int i=0;i<n;i++){
        par[i]=-1;
        key[i]=1e6;
        mst[i]=false;
    }

    // brute force approach //
    //--------------------------------------------------------------------------//
    //par[0]=-1;
    //key[0]=0;
    //for(int i=0;i<n-1;i++){
    //    //we are iterating only for n-1 edges
    //    int mini=INT_MAX,u;
    //    for(int j=0;j<n;j++){
    //        if(mst[j]==false and key[j]<mini){
    //            mini=key[j];
    //            u=j; 
    //        }
    //    }
//
    //    //adding this minimum node to the tree
    //    mst[u]=true;
//
    //    for(auto it:adj[u]){
    //        int curr = it.first;
    //        int val = it.second;
    //        if(mst[curr]==false and key[curr]>val){
    //            key[curr]=val;
    //            par[curr]=u;
    //        }
    //    }
    //}
//
    //for(int i=1;i<n;i++){
    //    cout<<"edge is from"<<" "<<par[i]<<" "<<i<<nl;
    //}

    //--------------------------------------------------------------------------//

    //Efficient approach

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,0});

    for(int i=0;i<n-1;i++){
        int curr = pq.top().second;
        pq.pop();

        mst[curr]=true;

        for(auto it : adj[curr]){
            int val = it.second;
            int v = it.first;
            if(mst[v]==false and val<key[v]){
                par[v]=curr;
                pq.push({val,v});
                key[v]=val;
            }
        }
    }

    for(int i=1;i<n;i++){
        cout<<"Edge from"<<" "<<par[i]<<" "<<i<<nl;
    }

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
