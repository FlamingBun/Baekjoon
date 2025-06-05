#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    
    string s;
    vector<string> sv;
    
    for(int i=0; i<n; i++)
    {
        cin >> s;
        sv.push_back(s);
    }
    
    sort(sv.begin(), sv.end());
    
    for(int i=0; i<m; i++)
    {
        cin >> s;
        if(binary_search(sv.begin(), sv.end(), s)) cnt++;
    }
    
    cout << cnt << "\n";
}