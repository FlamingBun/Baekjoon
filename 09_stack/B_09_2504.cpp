#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<char> st;
    
    int ans = 0, t = 1;
    
    string s;
    
    cin >> s;
    
    auto it = s.begin();
    
    while(it != s.end())
    {
        if(*it == '(')
        {
            t*=2;
            st.push(*it);
        }
        else if(*it == '[')
        {
            t*=3;
            st.push(*it);
        }
        else if(*it == ')')
        {
            if(st.empty() || st.top() != '(')
            {
                ans = 0;
                break;
            }
            
            if(*(it-1) == '(')
            {
                ans += t;
            }
            t/=2;
            st.pop();
        }
        else if(*it == ']')
        {
            if(st.empty() || st.top() != '[')
            {
                ans = 0;
                break;
            }
            
            if(*(it-1) == '[')
            {
                ans += t;
            }
            t/=3;
            st.pop();
        }
        it++;
    }
    
    if(!st.empty())
    {
        ans =0;
    }
    
    cout << ans << '\n';
}