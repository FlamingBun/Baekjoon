#include<iostream>
#include<list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    list<char> charList;
    
    string s;
    cin >> s;
    
    for(auto ch : s)
    {
        charList.push_back(ch);
    }
    
    list<char>::iterator it = charList.end();
    
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++)
    {
        char order;
        cin >> order;
        
        if(order == 'L')
        {
            if(it != charList.begin()) it--;   
        }
        else if(order == 'D')
        {
            if(it != charList.end()) it++;
        }
        else if(order == 'B')
        {
            if(it != charList.begin())
            {
                --it;
                it = charList.erase(it);
            }
        }
        else if(order == 'P')
        {
			char x;
			cin >> x;
            charList.insert(it, x);
        }
    }
    
    for(auto ch : charList)
        cout << ch;
}