#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
string postToInfix(string post_exp)
{
    stack<string> s;
    int l = post_exp.size();
    for (int i =0; i <= l-1; i++)
    {
        if (isOperator(post_exp[i]))
        {
            string re1 = s.top();
            s.pop();
            string re2 = s.top();
            s.pop();
            string temp = "("+re2+post_exp[i]+ re1+")";
            s.push(temp);
        }
        else
        {
            s.push(string(1, post_exp[i]));
        }
    }
    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    string post_exp;
    cin >> post_exp;
    cout << "Infix:" << postToInfix(post_exp);
    return 0;
}