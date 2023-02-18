/**
 *author:xyz_123
 *created:08-02-2023(11:18:37)
 **/
#include <bits/stdc++.h>
using namespace std;
string isPal(deque<char> &dq)
{
    if (dq.size() == 1)
        return "YES";
    while (dq.size() > 1)
    {
        if (dq.front() != dq.back())
        {
            return "NO";
        }
        dq.pop_back();
        dq.pop_front();
    }
    return "YES";
}
int main()
{
    deque<char> dq;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        dq.push_back(str[i]);
    }
    cout << isPal(dq);
    return 0;
}