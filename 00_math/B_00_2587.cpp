#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> vec;
    int sum=0;
    for(int i=0; i<5; i++)
    {
        int a;
        cin >> a;
        sum+=a;
        vec.push_back(a);
    }
    
    sort(vec.begin(), vec.end());
    
    cout << sum/5 << "\n";
    cout << vec[2] << "\n";
    
}