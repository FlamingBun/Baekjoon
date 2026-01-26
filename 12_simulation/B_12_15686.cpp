#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define X first
#define Y second

int board[55][55];
int n, m;

vector<pair<int, int>> houseV;
vector<pair<int, int>> chickenV;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1) houseV.push_back({i, j});
            if(board[i][j] == 2) chickenV.push_back({i, j});
        }
    }
    
    int chickenCnt = chickenV.size();
    
    vector<int> brute(chickenCnt, 1);
    fill(brute.begin(), brute.begin()+chickenCnt-m, 0);
    
    int minDist = 0x7f7f7f7f;
    
    do
    {
        int dist = 0;
        for(auto house : houseV)
        {
            int tmp = 0x7f7f7f7f;
            
            for(int i=0; i<chickenCnt; i++)
            {
                if(brute[i] == 0) continue;
                tmp = min(tmp, abs(chickenV[i].X - house.X) + abs(chickenV[i].Y - house.Y));
            }
            
            dist += tmp;
        }
        
        minDist = min(minDist, dist);
    }while(next_permutation(brute.begin(), brute.end()));
    
    cout << minDist;
}