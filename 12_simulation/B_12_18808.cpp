#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;

int r, c;

int note[42][42];
int paper[12][12];

void rotate()
{
    int temp[12][12];
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            temp[i][j] = paper[i][j];
    
    for(int i=0; i<c; i++)
        for(int j=0; j<r; j++)
            paper[i][j] = temp[r-1-j][i];
    
    swap(r, c);
}

bool pastable(int x, int y)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(note[x+i][y+j] == 1 && paper[i][j]==1)
                return false;
        }
    }
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(paper[i][j] == 1)
                note[x+i][y+j] = 1;
        }
    }       
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    
    while(k--)
    {
        cin >> r >> c;
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin >> paper[i][j];
        
        for(int rot =0; rot<4; rot++)
        {
            bool is_pastable = false;
            
            for(int x=0; x<=n-r; x++)
            {
                if(is_pastable) break;
                
                for(int y=0; y<=m-c; y++)
                {
                    if(pastable(x, y))
                    {
                        is_pastable = true;
                        break;
                    }
                }
            }
            
            if(is_pastable) break;
            rotate();
        }
    }
    
    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cnt += note[i][j];
    
    cout << cnt << '\n';
}