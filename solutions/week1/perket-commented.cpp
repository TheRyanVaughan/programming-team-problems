#include <bits/stdc++.h>
using namespace std;

int main()
{
    // number of ingredients
    int n;
    cin >> n;

    // This is equivalent to creating an int array of size [n][2].
    // Could store sour and bitter of item i in v[i][0] and v[i][1] respectively.
    // Could also create 2 arrays, sour and bitter. sour[i] holds sour value of ith item, same for bitter[i].
    vector<pair<int, int>> v(n); 

    // read input
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int sour, bitter;

    /*
    We are told sour/bitter will never surpass 1 billion (1e9).
    So, answer can never surpass 1e9, so begin outside this range. 
    */
    int ans = 1e9 + 1; 

    /*
    We know that n is going to be relatively small (<=10).
    Therefore, a O(2^N) algorithm checking every combination will not be too slow.
    Therefore, we can brute force check every possible combination of ingredients.
    
    consider n = 2
    let a 1 in a bit mean that item is chosen
    let a 0 mean that item is not included in the dish.
    check: 01 10 11 (all possible combinations of choosing at least 1 element)
    start at 1 b/c perket must have 1 ingredient.
    
    mask: our iterator
    mask < (1 << n) : 1 << n gives us the amount of bits we need in order to check all combinations.
    Consider n == 3
    1 << 1 == 10 (2 in decimal)
    1 << 2 == 100 (4 in decimal)
    1 << 3 == 1000 (8 in decimal)
    This works because we only want to consider 3 bits since we have 3 items.
    If we consider the 4th bit, that would act as having a 4th item, so mask must remain less than 8 (1000 in binary)
    */
    for (int mask = 1; mask < (1 << n); mask++)
    {
        sour = 1;
        bitter = 0;

        /*
        Checks if a bit is activated. 
        (1 << j) will put a 1 in the desired bit. 
        */
       for (int j = 0; j < n; j++)
       {
            // if mask's binary representation has a 1 bit at the desired bit location: add the ingredient
            if (mask & 1 << j)
           {
               sour *= v[j].first;
               bitter += v[j].second;
           }
       }
       // want the minimum difference, so update answer accordingly.
       ans = min(ans, abs(sour - bitter));
    }
    cout << ans;
    return 0;
}