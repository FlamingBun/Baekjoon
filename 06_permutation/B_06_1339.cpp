#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

char alpha[256]; // i 아스키 코드

int calc(vector<string> &a, vector<char> &letters, vector<int> &d)
{
    int m = letters.size();
    int sum = 0;

    for(int i=0; i<m; i++)
    {
        alpha[letters[i]] = d[i];
    }

    for(string s : a)
    {
        int now = 0;
        for(char x : s)
        {
            now = now * 10 + alpha[x];
        }
        sum+=now;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<string> a(n);
    vector<char> letters;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        for(char x : a[i])
        {
            letters.push_back(x);
        }
    }

    // 중복된 알파벳 제거
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end()); 

    // 큰 수 vector 만들기
    int m = letters.size();

    vector<int> d;

    for(int i = 9; i > 9-m; i--)
    {
        d.push_back(i);
    }

    sort(d.begin(), d.end()); // 모든 순열을 살펴보기 위해 정렬

    int ans = 0;

    // 모든 순열 확인
    do
    {
        int now = calc(a, letters, d);

        if(ans < now)
        {
            ans = now;
        }
    }while(next_permutation(d.begin(), d.end()));

    cout << ans << '\n';

    return 0;
}