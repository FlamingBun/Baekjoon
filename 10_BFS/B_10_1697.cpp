#include<iostream>
#include<queue>

using namespace std;

int board[100001];
int visit[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x;
	
	cin >> n >> x;
	
	queue<int> q;
	
	fill(visit, visit+100001, -1);
	
	q.push(n);
	visit[n] = 0;
	
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		for(int i=0; i<3; i++)
		{
			int nxt;
			
			if(i == 0)
			{
				nxt = cur + 1;
			}
			else if(i == 1)
			{
				nxt = cur - 1;
			}
			else
			{
				nxt = cur * 2;
			}
			
			if(nxt < 0 || nxt >= 100001) continue;
			if(visit[nxt] >= 0)continue;
			
			visit[nxt] = visit[cur] + 1;
			q.push(nxt);
		}
	}
	
	cout << visit[x] << '\n';
}