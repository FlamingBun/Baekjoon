#include<iostream>
#include<queue>

using namespace std;

#define X first
#define Y second

int board[502][502];
int visit[502][502];
int n, m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int cnt = 0;
int maxW = 0;

void BFS(int x, int y)
{
    cnt++;
    
    queue<pair<int,int>> q;
    
    q.push({x,y});
    
    visit[x][y] = 1;
    
    int w = 1;
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir<4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny]|| board[nx][ny] != 1) continue;
            
            w++;
            visit[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    
    if(maxW < w) maxW = w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    cin >> m;
    
    for(int i=0; i<n; i++)
    {
        int a;
        for(int j=0; j<m; j++)
        {
            cin >> a;
            board[i][j] = a;
        }   
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visit[i][j] == 0 && board[i][j] == 1)
                BFS(i, j);
        }
    }
    
    cout << cnt << '\n';
    cout << maxW << '\n';
}