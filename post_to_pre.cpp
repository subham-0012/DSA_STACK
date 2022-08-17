#include <iostream>
#include <stack>
using namespace std;
bool isoperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 1;
    }
    return 0;
}
string postToPre(string str)
{
    stack<string> stk;
    int length = str.size();
    for (int i = 0; i < length; i++)
    {
        if (isoperator(str[i]))
        {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            string temp = str[i] + op2 + op1;
            stk.push(temp);
        }
        else
        {
            stk.push(string(1, str[i]));
        }
    }
    return stk.top();
}
int main()
{
    string str;
    cin >> str;
    str = postToPre(str);
    cout << str;
}