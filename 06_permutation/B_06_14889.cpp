#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> b(n); // 순열 -> 0,1을 n/2개씩

    // 반만 1로 변경
    for(int i=0; i<n/2; i++)
    {
        b[i] = 1;
    }

    // 정렬 -> [0,0,0,0,0,...,1,1,1,1,1,...]
    sort(b.begin(), b.end());

    int ans = INT_MAX;

    do
    {
        // 0이면 1번팀 1이면 2번팀 각 팀의 index 저장
        vector<int> first, second;
        for(int i=0; i<n; i++)
        {
            if(b[i] == 0)
            {
                first.push_back(i);
            }
            else
            {
                second.push_back(i);
            }
        }

        int one = 0;
        int two = 0;

        for(int i=0; i<n/2; i++)
        {
            for(int j=0; j<n/2; j++)
            {
                if(i==j) continue;
                one += a[first[i]][first[j]];
                two += a[second[i]][second[j]];
            }
        }
        int diff= one - two;
        if(diff < 0) diff = -diff;
        if(ans>diff) ans = diff;
    }while(next_permutation(b.begin(), b.end()));

    cout << ans << '\n';
    return 0;
}