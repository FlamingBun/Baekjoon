#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    stack<char> st;
    
    char before;
    
    int cnt =0;
    
    for(auto ch : s)
    {
        if(ch == '(')
        {
            st.push(ch);
        }
        
        if(ch == ')')
        {
            if(before == ')')
            {
                cnt += 1;
                st.pop();
            }
            else
            {
                cnt += st.size() - 1;
                st.pop();
            }
        }
        before = ch;
    }
    cout << cnt << '\n';
}