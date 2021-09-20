#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
typedef long long ll;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define forn(i, e) for (ll i = 0; i < e; i++)

void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool reachInOneMove(pair<int, int> a, pair<int, int> b)
{
    if (abs(a.f - b.f) == abs(a.s - b.s))
    {
        return true;
    }
    return false;
}

void solve()
{
    pair<int, int> start, end;
    char st, e;
    cin >> st >> start.s >> e >> end.s;
    start.f = st - 'A';
    end.f = e - 'A';
    start.s--;
    end.s--;
    /*
    Coordinates are now stored as if it is a 2d array where indices are 0..7 and 0..7
    */
    if (start.f % 2 + start.s % 2 == (end.f % 2 + end.s % 2) % 2)
    {
        /*
        We now know we are going to the correct color square.
        Max moves fora bishop to reach any square is 2.
        Therefore, this is simple.
        Print out starting square (into string stream)
        If start = end, print 0, print ss
        If bishop can reach it instantly, print 1, add end to ss, print end.
        (create function to check if bishop can reach square in one move)
        otherwise, add each coordinate that the bishop can move to into a stack. pop each of these until we find the right answer. 
        */

        stringstream ss;
        ss << ((char)(start.f + 'A')) << " " << start.s + 1 << " ";
        if (start.f == end.f && start.s == end.s)
        {
            cout << 0 << " " << ss.str() << endl;
        }
        else
        {
            if (reachInOneMove(start, end))
            {
                ss << ((char)(end.f + 'A')) << " " << end.s + 1 << " ";
                cout << 1 << " " << ss.str() << endl;
            }
            else
            {
                // check all squares that the bishop canc urrently reach, see if theyt can reacha the intended one
                
                int currX = start.f, currY = start.s;
                while (currX >= 0 && currY >= 0)
                {
                    if (reachInOneMove(make_pair(currX, currY), end))
                    {
                        ss << ((char)(currX + 'A')) << " " << ((char)currY + 1) << " ";
                        ss << ((char)(end.f + 'A')) << " " << end.s + 1 << " ";
                        cout << 2 <<" " << ss.str() << endl;
                        return;
                    }
                    currX--;
                    currY--;
                }
                currX = start.f; currY = start.s;
                
                while (currX >= 0 && currY <= 7)
                {
                    if (reachInOneMove(make_pair(currX, currY), end))
                    {
                        ss << ((char)(currX + 'A')) << " " << ((char)currY + 1) << " ";
                        ss << ((char)(end.f + 'A')) << " " << end.s + 1 << " ";
                        cout << 2 <<" " <<  ss.str() << endl;
                        return;
                    }
                    currX--;
                    currY++;
                }
                currX = start.f; currY = start.s;
                
                while (currX <= 7 && currY >= 0)
                {
                    if (reachInOneMove(make_pair(currX, currY), end))
                    {
                        ss <<((char)(currX + 'A')) << " " << ((char)currY + 1) << " ";
                        ss << ((char)(end.f + 'A')) << " " << end.s + 1 << " ";
                        cout << 2 << " " <<ss.str() << endl;
                        return;
                    }
                    currX++;
                    currY--;
                }
                currX = start.f; currY = start.s;
                while (currX <= 7 && currY <= 7)
                {
                    if (reachInOneMove(make_pair(currX, currY), end))
                    {
                        ss << ((char)(currX + 'A')) << " " << ((char)currY + 1) << " ";
                        ss << ((char)(end.f + 'A')) << " " << end.s + 1 << " ";
                        cout << 2 << " "<<ss.str() << endl;
                        return;
                    }
                    currX++;
                    currY++;
                }
            }
        }
    }
    else
    {
        cout << "Impossible" << endl;
    }
}
int main()
{
    setIO();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}