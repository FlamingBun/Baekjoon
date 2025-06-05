#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int m;
    vector<int> n_card;
    queue<int> m_card;
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        n_card.push_back(a);
    }
    
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int a;
        cin >> a;
        m_card.push(a);
    }
    
    sort(n_card.begin(), n_card.end());
    
    while(!m_card.empty())
    {
        int a = m_card.front();
        m_card.pop();
        if(binary_search(n_card.begin(),n_card.end(),a))
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
}