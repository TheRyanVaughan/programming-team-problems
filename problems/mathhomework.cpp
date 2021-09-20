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
    int b, d, c, l;
    cin >> b >> d >> c >> l;
    bool impossible = true;
    for (int i = 0; i * b <= l; i++)
    {
        for (int j = 0; (j * d) + (i * b) <= l; j++)
        {
            for (int k = 0; (k*c) + (j*d) + (i*b) <= l; k++)
            {
                if ((i*b) + (k*c) + (j*d) == l)
                {
                    cout << i << " " << j << " " << k << endl;
                    impossible = false;
                }
            }
        }
    }
    if (impossible) cout << "impossible";
    return 0;
}