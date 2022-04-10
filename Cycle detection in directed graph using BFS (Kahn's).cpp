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


//using BFS Kahn's algorithm

int n,m;
vector<int>adj[maxn];
vector<bool>vis(maxn,0);
vector<int>indegree(maxn,0);


void solve(){ 
    cin>>n>>m;
    stack<int>st;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    for(int i=1;i<=n;i++){
        for(auto x:adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cnt++;
        for(auto x:adj[curr]){
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }
    cout<<(cnt==n?"NO":"YES")<<nl;
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
