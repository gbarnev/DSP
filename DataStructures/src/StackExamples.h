#pragma once
#include <iostream>
#include "LinkedStack.h"
#include <string>

using namespace DSP;
using namespace std;

template <typename T>
void printStack(LinkedStack<T> stack)
{
	while (!stack.empty())
	{
		cout << stack.top() << ' ';
		stack.pop();
	}
	cout << endl;
}

bool isOp(char c)
{
	return c == '+' || c == '-' ||
		c == '*' || c == '/' || c == '^';
}

char opWeight(char c)
{
	switch (c)
	{
		case '^':
			return 0;
		case '*':
		case '/':
			return 1;
		case '+':
		case '-':
			return 2;
		default:
			throw std::out_of_range("Unable to get weight of operation");
	}
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

char parseDigit(char c)
{
	return c - '0';
}

string normalToRevPolNot(string expr)
{
	string result = "";
	LinkedStack<char> stack;
	int pos = 0;
	while (pos < expr.length())
	{
		char ch = expr.at(pos);

		if (isOp(ch))
		{
			char weight = opWeight(ch);
			while (!stack.empty() && stack.top() != '(' && weight >= opWeight(stack.top()))
			{
				result += stack.top();
				stack.pop();
			}
			stack.push(ch);
		}
		else if (ch == '(')
		{
			stack.push(ch);
		}
		else if (ch == ')')
		{
			while (!stack.empty() && stack.top() != '(')
			{
				result += stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else
		{
			result += ch;
		}
		pos++;
	}
	while (!stack.empty())
	{
		result += stack.top();
		stack.pop();
	}
	return result;
}


int calcRevPolNot(const char* expr)
{
	int pos = 0;
	LinkedStack<int> digits;

	while (expr[pos] != '\0')
	{
		if (isDigit(expr[pos]))
		{
			digits.push(parseDigit(expr[pos]));
		}
		else if (isOp(expr[pos]))
		{
			int d1 = digits.top();
			digits.pop();
			int d2 = digits.top();
			digits.pop();
			int result;
			switch (expr[pos])
			{
				case '+':
					result = d1 + d2;
					break;
				case '-':
					result = d1 - d2;
					break;
				case '*':
					result = d1 * d2;
					break;
				case '/':
					result = d1 / d2;
					break;
				case '^':
					result = (int)pow(d1, d2);
					break;
				default:
					throw runtime_error("Wrong operation");
			}
			digits.push(result);
		}
		++pos;
	}
	
	return digits.top();
}