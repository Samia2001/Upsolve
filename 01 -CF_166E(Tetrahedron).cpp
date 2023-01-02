#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define    rrep(X,Y)    for(X=Y-1;X>=0;X--)
#define    rrep1(X,Y)   for(X=Y;X>=1;X--)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define case "Case "<<g+1<<": "
#define fs(n) fixed << setprecision(n)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define yes cout << "yes\n"
#define No cout << "No\n"
#define no cout << "no\n"
#define      len(n)             (long long)((log(n)/log(10))+1.0000000001)
#define FastRead                      \
ios_base::sync_with_stdio(false); \
cin.tie(0);
#define pi acos(-1)
#define pb push_back
#define pll pair<ll , ll>
#define ceill(ggg,gg) (ggg/gg)+bool(ggg%gg)
#define pqmn priority_queue<ll, vector<ll>, std::greater<ll> >
#define nm -1e18

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
///Chess moves.........
// int dx[] = {+0, +0, -1, +1}; ///Up-down, Left-Right// int dy[] = {+1, -1, +0, +0};
// int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's Move// int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
// int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2}; ///Knight's Move// int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
///Constants........
const ll mod = 1e9 + 7;
const ll Max = 2e5 + 5;
const ll inf = 1e18 + 5;
ll fact[2000005];
void factorial() {fact[0] = fact[1] = 1; for (ll i = 2 ; i <= 2000004; i++)fact[i] = (i * fact[i - 1]) % mod;}
ll BigMod(ll base, ll pow, ll mod)
{
  if (pow == 0)
    return 1;
  else if (pow % 2 == 1)
  {
    ll a = BigMod(base, pow - 1, mod) % mod;
    ll b = base % mod;
    return (a * b) % mod;
  }
  else
  {
    ll a = BigMod(base, pow / 2, mod) % mod;
    return (a * a) % mod;
  }
}

ll ncr(ll n , ll r) {return (((fact[n] * BigMod(fact[r], mod - 2, mod)) % mod) * BigMod(fact[n - r], mod - 2, mod)) % mod;}
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
  if (a.first == b.first)
    return (a.second > b.second);
  else
    return (a.first < b.first);
}
vector<vector<ll>>mat
{ {0 , 1 , 1, 1},
  {1 , 0 , 1 , 1},
  {1, 1 , 0 , 1},
  {1 , 1 , 1, 0}
};
vector<vector<ll>>rec(ll n)
{
  ll i, j, k;
  vector<vector<ll>> dp1;
  vector<vector<ll>> dp2;
  if (n == 1)
    return mat;
  else if (n % 2 == 0)
  {
    dp1 = dp2 = rec(n / 2);
  }
  else
  {
    dp1 = mat;
    dp2 = rec(n - 1);
  }
  vector<vector<ll>>dp(4, vector<ll>(4, 0));
  rep(i, 4)
  {
    rep(j, 4)
    {
      ll s = 0;
      rep(k, 4)
      {
        s = (s + (dp1[i][k] * dp2[k][j]) % mod) % mod;
      }
      dp[i][j] = s;
    }
  }
  return dp;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i, j;

  nml {
    ll n;
    cin >> n;
    vector<vector<ll>>ans = rec(n);
    cout << ans[0][0] << endl;



  }

  return 0;
}
