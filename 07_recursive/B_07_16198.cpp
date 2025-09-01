#include <iostream>
#include <vector>

using namespace std;

int go(vector<int> &a)
{
    int n = a.size();

    // 구슬이 2개 -> 불가능
    if(n == 2) return 0;

    int ans = 0;

    for(int i=1; i<n-1; i++)
    {
        int energy = a[i-1] * a[i+1];

        vector<int> b(a);

        b.erase(b.begin()+i); // i 번째 만든 거를 지워준다.

        energy += go(b);

        if(ans < energy)
        {
            ans = energy;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    cout << go(a) << '\n';

    return 0;
}