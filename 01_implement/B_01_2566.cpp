#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[9][9];
    
    int max = -1; // max가 0이 될 수도 있으므로 max를 -1로 초기화
    int x;
    int y;
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> arr[i][j];
            if(max < arr[i][j])
            {
                max = arr[i][j];
                x=i;
                y=j;
            }
        }
    }
    
    cout << max << "\n";
    cout << x+1 << " " << y+1 << "\n";
}