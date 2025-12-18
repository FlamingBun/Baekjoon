#include<iostream>
#include<queue>

using namespace std;

#define X first
#define Y second

int board[101][101];
int visit[101][101];

int n, m;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<pair<int, int>> q;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++)
        {
            int a= s[j] - '0';
            board[i][j+1] = a;
        }    
    }
    
    visit[1][1] = 1;
    q.push({1,1});
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx<1 || nx>n || ny<1 || ny>m) continue;
            if(board[nx][ny]!=1) continue;
            
            int temp = visit[cur.X][cur.Y] + 1;
            
            if(visit[nx][ny] != 0)
            {
                if(visit[nx][ny] > temp) 
                {
                    visit[nx][ny] = temp;
                    q.push({nx, ny});
                }
            }
            else
            {
                visit[nx][ny] = temp;
                q.push({nx, ny});
            }
        }
    }
    
    cout << visit[n][m] << '\n';
}