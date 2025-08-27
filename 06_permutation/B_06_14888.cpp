#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int ans = a[0];
    for(int i=1; i<n; i++)
    {
        int sign = b[i-1];
        if(sign == 0)
        {
            ans = ans + a[i];
        }
        else if(sign == 1)
        {
            ans = ans - a[i];
        }
        else if(sign == 2)
        {
            ans = ans * a[i];
        }
        else
        {
            ans = ans / a[i];
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    // 수 입력
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    // 연산자 입력 (+,-,*,/) -> (0,1,2,3)
    vector<int> b;
    for(int i=0; i<4; i++)
    {
        int cnt;
        cin >> cnt;
        for(int k=0; k<cnt; k++)
        {
            b.push_back(i);
        }
    }
    sort(b.begin(), b.end());
    vector<int> result;

    do
    {
        int temp = calc(a,b);
        result.push_back(temp);
    }while(next_permutation(b.begin(), b.end()));

    auto ans = minmax_element(result.begin(), result.end());
    cout << *ans.second << '\n';
    cout << *ans.first << '\n';

    return 0;
}