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
string preToInfix(string str)
{
    stack<string> stk;
    int length=str.size();
    for(int i=length-1;i>-1;i--)
    {
        if(isoperator(str[i]))
        {
            string op1=stk.top();
            stk.pop();
            string op2=stk.top();
            stk.pop();
            string temp="("+op1+str[i]+op2+")";
            stk.push(temp);
        }
        else
        {
            stk.push(string(1,str[i]));
        }
    }
    return stk.top();
}
int main()
{
    string str;
    cin>>str;
    str=preToInfix(str);
    cout<<str;
}