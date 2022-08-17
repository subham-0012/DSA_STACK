#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
string preToPost(string pre_exp)
{
    stack<string> s;
    int l = pre_exp.size();
    for (int i = l-1; i>=0; i--)
    {
        if (isOperator(pre_exp[i])) {
            string re1 = s.top();
            s.pop();
            string re2 = s.top();
            s.pop();
            string temp = re1+re2+pre_exp[i];
            s.push(temp);
        }
        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    string pre_exp;
    cin>>pre_exp;
    cout <<"Postfix:"<<preToPost(pre_exp);
    return 0;
}