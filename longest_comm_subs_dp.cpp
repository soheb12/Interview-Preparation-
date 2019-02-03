#include<bits/stdc++.h>
#define f(a,n) for(ll i=a;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(v) v.begin(),v.end()
using namespace std;
const ll mod=(1e+9)+7;
const ll size = 2e5+9;
ll gcd(ll a,ll b) {if(b==0)return a;return gcd(b,a%b);}
ll power(ll a,ll b,ll m) {ll res = 1;while(b>0){if(b&1)res = (res*a)%m;b = b>>1;a = (a*a)%m;}return res;}

ll dp[1000][1000];

void solve()
{
    string a,b;
    cin>>a>>b;
    for(ll i=1;i<=a.size();i++)
    {
        for(ll j=1;j<=b.size();j++)
        {
            if(a[i] == b[j])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    cout<<dp[a.size()][b.size()]<<endl;
}

int main()
{
    #ifdef JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec, Copyright %c 2019 Skyscraper. \n", double(end - beg) / CLOCKS_PER_SEC , 184);
    return 0;
}
