#include<iostream>
#include<queue>

using namespace std;

// queue 선언 시 대문자가 아닌 소문자..

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true)
    {
        int n;
        
        cin >> n;
        
        if(n == -1)break;
        
        queue<int> que;

        int sum = 1;
        for(int i=2; i<=n/2; i++)
        {
            if(n%i==0)
            {
                que.push(i);
                sum+=i;
            }
        }
    
        if(sum==n)
        {
            cout << n << " = " << 1;
            while(!que.empty())
            {
                cout << " + " << que.front();
                que.pop();
            }
        }
        else
        {
            cout << n << " is NOT perfect.";
        }
        cout << "\n";
    }
}