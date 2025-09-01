#include <iostream>

using namespace std;

int a[500][500];

bool c[500][500];

int n, m;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int ans = 0;

void go(int x, int y, int sum, int cnt)
{
    // 칸을 4개 방문했으면 최대값 갱신
    if(cnt == 4)
    {
        if(ans < sum) ans = sum;
        return;
    }

    // 불가능한 경우 1: 범위를 벗어난 경우
    if(x < 0 || x >= n || y < 0 || y >= m) return;

    // 불가능한 경우 2: 이미 방문한 칸을 또 방문한 경우
    if(c[x][y]) return;

    // 모든 브루트 포스에서 함수 호출하기 전에 미리 세탕하고 함수를 호출하고 나면 되돌려주는 구문이 있다.

    // 세팅 구문
    c[x][y] = true;

    for(int k = 0; k < 4; k++)
    {
        go(x+dx[k], y+dy[k], sum + a[x][y], cnt + 1);
    }

    // 되돌리는 구문
    c[x][y] = false; // !! DFS와 다른 이유: DFS에서는 방문한 칸을 다시 되돌리지 않기 때문
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            go(i,j,0,0); // 모든 (i,j) 칸에서 이동 시작
            if(j+2 < m)
            {
                int temp = a[i][j] + a[i][j+1] + a[i][j+2];
                // 'ㅗ' 모양 체크
                if(i-1 >= 0)
                {
                    int temp2 = temp + a[i-1][j+1];
                    if(ans < temp2) ans = temp2;
                }
                // 'ㅜ' 모양 체크
                if(i+1 < n)
                {
                    int temp2 = temp + a[i+1][j+1];
                    if(ans < temp2) ans = temp2;
                }
            }
            if(i+2 < n)
            {
                int temp = a[i][j] + a[i+1][j] + a[i+2][j];
                // 'ㅏ' 모양 체크
                if(j+1 < m)
                {
                    int temp2 = temp + a[i+1][j+1];
                    if()
                }
                // 'ㅓ' 모양 체크
                if(j-1 >= 0)
                {
                    int temp2 = temp + a[i+1][j-1];
                    if(ans < temp2) ans = temp2;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}