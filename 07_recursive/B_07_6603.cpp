#include <iostream>
#include <vector>

using namespace std;

vector<int> lotto; // 함수가 선택한 수 저장

void solve(vector<int> &a, int index, int cnt)
{
    if(cnt == 6)
    {
        for(int num : lotto)
        {
            printf("%d ", num);
        }
        printf("\n");
        return;
    }

    int n = a.size();

    if(n==index) return;

    // index번째를 선택
    // k개의 수는 항상 오름차순으로 입력되고, index는 index번째를 선택하는 것이 먼저이기 때문에 자동으로 사전순이 된다.
    lotto.push_back(a[index]);
    solve(a, index+1, cnt+1);

    // index번째를 선택하지 않음
    lotto.pop_back();
    solve(a, index+1, cnt);
}

int main()
{
    while(true)
    {
        int n;
        cin >> n;

        if(n==0) break;

        vector<int> a(n);

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        solve(a, 0, 0);
        cout << '\n'; // 테스트 케이스 사이 구분
    }

    return 0;
}