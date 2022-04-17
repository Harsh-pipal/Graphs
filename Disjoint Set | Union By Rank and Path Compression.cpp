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
ll par[10000];
ll ran[10000];

//initializing parents to itself and rank to zero

void makeset(){
    for(int i=1;i<=n;i++){
        par[i]=i;
        ran[i]=0;
    }
}

//we are using path compression to reduce the time complexity to O(4x) from logn

int findpar(int u){
    if(u==par[u])
        return u;

    return par[u]=findpar(par[u]);
}

//attaching the node with less rank value to higher one else increase rank by 1

void unio(int u , int v){
    u=findpar(u);
    v=findpar(v);

    if(ran[u]<ran[v]){
        par[u]=v;
    }
    else if(ran[v]<ran[u]){
        par[v]=u;
    }
    else{
        par[v]=u;
        ran[u]++;
    }
}

void solve(){ 
    cin>>n>>m;
    makeset();
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unio(u,v);
    }
    
    cout<<findpar(6)<<nl;

    //check whether two nodes belong to same component or not

    if(findpar(6)!=findpar(3))
        cout<<"DIFFERENT"<<nl;
    else
        cout<<"SAME"<<nl;
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
