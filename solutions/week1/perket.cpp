#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
typedef long long ll;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define f first
#define s second
#define forn(i, e) for(ll i = 0; i<e; i++)

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
 
void solve()
{
    
}
int main()
{
    setIO();
    int n;
    cin >> n;
    vector<pii> v(n);
    forn(i, n)
    {
        cin >> v[i].f >> v[i].s;
    }
    int sour, bitter;
    int ans = 1e9 + 1;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        sour = 1;
        bitter = 0;
        /*
        consider n = 2
        let a 1 in a bit mean that item is chosen
        let a 0 mean that item is not included in the dish.
        this will check: 01 10 11 (all possible combinations of choosing at least 1 element)
        Check all pairs, and min answer is the answer to the problem. 
        start at 1 b/c perket must have 1 ingredient.
        */
       for (int j = 0; j < n; j++)
       {
           if (mask & 1 << j)
           {
               sour *= v[j].f;
               bitter += v[j].s;
           }
       }
       ans = min(ans, abs(sour - bitter));
    }
    cout << ans;
    return 0;
}