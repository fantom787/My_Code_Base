#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

string postfix(string infix)
{
	stack<char> s;
	string pos;
	for (int i = 0; i < infix.length(); i++)
	{
		char c = infix[i];
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
		{
			pos += c;
		}
		else if (c == '(')
		{
			s.push('(');
		}
		else if (c == ')')
		{
			while (s.top() != '(')
			{
				pos += s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while (!s.empty() && precedence(c) <= precedence(s.top()))
			{
				pos += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
	while (!s.empty())
	{
		pos += s.top();
		s.pop();
	}
	return pos;
}

int main()
{
	string exp = "(a+b)*c/d+e^f/g";
	cout << postfix(exp);
	return 0;
}