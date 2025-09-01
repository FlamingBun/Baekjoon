#include <iostream>

using namespace std;

int n, m;

string a[20];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int go(int step, int x1, int y1, int x2, int y2)
{
    if(step == 11) return -1; // 11번 이동 -> 불가능

    bool fall1 = false, fall2 = false;

    // 각 동전이 떨어졌는지 체크
    if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;
    if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;

    if(fall1 && fall2) return -1; // 두 동전 모두 떨어진 경우 -> 불가능

    if(fall1 || fall2) return step; // 두 동전 중 하나가 떨어진 경우 -> 버튼 누른 횟수 반환

    int ans = -1;

    // 4개 방향 조사
    for(int k=0; k<4; k++)
    {
        int nx1 = x1 + dx[k];
        int ny1 = y1 + dy[k];
        int nx2 = x2 + dx[k];
        int ny2 = y2 + dy[k];

        // 이동하려는 방향이 벽인지 체크 -> 벽이면 제자리
        if(0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#')
        {
            nx1 = x1;
            ny1 = y1;
        }

        if(0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#')
        {
            nx2 = x2;
            ny2 = y2;
        }

        // 이동
        int temp = go(step+1, nx1, ny1, nx2, ny2);

        // 불가능하면 넘기고
        if(temp == -1) continue;

        // 최소값을 최신화하고
        if(ans == -1 || ans > temp)
        {
            ans = temp;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;

    int x1, y1, x2, y2;

    x1=y1=x2=y2=-1;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        for(int j=0; j<m; j++)
        {
            if(a[i][j] == 'o')
            {
                // 동전 1의 위치 기록
                if(x1 == -1)
                {
                    x1 = i;
                    y1 = j;
                }
                // 동전 2의 위치 기록
                else
                {
                    x2 = i;
                    y2 = j;
                }
                a[i][j] = '.'; // 동전 있는 칸도 일단 빈칸으로 변경
            }
        }
    }

    cout << go(0, x1, y1, x2, y2) << '\n';
    return 0;
}
