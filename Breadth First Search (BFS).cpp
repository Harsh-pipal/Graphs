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
#define INF 1e18
#define nl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){ 
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>visited(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int>bfsOrder;
    for(int i=1;i<=n;i++){
        if (visited[i]==0){
            queue<int>q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfsOrder.pb(node);
                for(auto it:adj[node]){
                    if(visited[it]==0){
                        q.push(it); 
                        visited[it]=1;                        
                    }                    
                }
            }
        }
    }
    rep(i,n)cout<<bfsOrder[i]<<" ";
    cout<<nl;

}   
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout<<fixed<<setprecision(10);
    int T=1;
    //cin>>T;
    while(T--)
    solve();
}       
