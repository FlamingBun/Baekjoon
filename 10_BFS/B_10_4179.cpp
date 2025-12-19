#include<iostream>
#include<queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;

char board[1001][1001];

int dist[1001][1001];
int distF[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	queue<pair<int, int>> jq;
	queue<pair<int, int>> fq;
	
	for(int i=0; i<n; i++)
	{
			string s;
			cin >> s;
			for(int j=0; j<m; j++)
			{
				board[i][j] = s[j];
				
				if(board[i][j] == 'J')
				{
					jq.push({i,j});
				}
				else if(board[i][j] == 'F')
				{
					fq.push({i,j});
				}
			}
	}
	
	while(!fq.empty())
	{
		auto cur = fq.front();
		fq.pop();
		
		for(int dir = 0; dir<4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
			if(distF[nx][ny] != 0 || board[nx][ny] == '#') continue;
			
			distF[nx][ny] = distF[cur.X][cur.Y] + 1;
			fq.push({nx, ny});
		}
	}
	
	int ans = 0;
	
	while(!jq.empty())
	{
		auto cur = jq.front();
		jq.pop();
		
		for(int dir = 0; dir<4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			int nextStep = dist[cur.X][cur.Y] + 1;
			
			if(nx<0 || nx>=n || ny<0 || ny>=m) 
			{
				ans = nextStep ;
				while(!jq.empty())jq.pop();
				break;
			}
			if(dist[nx][ny] != 0 || board[nx][ny] != '.' || (distF[nx][ny]!=0&&distF[nx][ny] <= nextStep)) continue; 
			
			dist[nx][ny] = nextStep;
			jq.push({nx, ny});
		}
	}
	
	if(ans == 0)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << '\n';
}