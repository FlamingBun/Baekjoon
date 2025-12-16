#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "---";
	while(s != ".")
	{
		getline(cin, s);
		
		stack<char> st;
		
		if(s == ".")
		{
			continue;
		}
		
		for(auto ch : s)
		{
			if(ch == '.')break;
			if(ch == '[' || ch == '(')
			{
				st.push(ch);
			}
			
			if(ch == ']')
			{
				if(st.empty()) 
				{
					st.push('a');
					break;
				}
				
				if(st.top() == '[')
				{
					st.pop();
				}
				else
				{
					st.push('a');
					break;
				}
			}
			else if(ch == ')')
			{
				if(st.empty())
				{
					st.push('a');
					break;
				}
				
				if(st.top() == '(')
				{
					st.pop();
				}
				else
				{
					st.push('a');
					break;
				}
			}
		}
		
		if(st.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}