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
int sumdigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main()
{
    setIO();
    int n;
    cin >> n;
    while (n % sumdigits(n) != 0) n++;
    cout << n;
    return 0;
}