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
    if (sz(name) > 0)
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
    int a, b;
    cin >> a >> b;
    cout << min(a, b) << " " << max(a, b);
    return 0;
}