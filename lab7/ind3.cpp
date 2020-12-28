#include <iostream>
#include <windows.h>
#include<string>
#include<vector>
using namespace std;
vector<int>sum;
void funcs(string& s, vector<int>& a)
{
	for (int i = 0; i < s.size(); i++)
	{
		
		a.push_back((int)s[i]-48);
	}
}
void dop(bool f,vector<int>& a)
{
	if(f)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 0)
				a[i] = 1;
			else a[i] = 0;
		}
		
		a[0]++;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > 1)
			{
				a[i] = 0;
				a[i + 1]++;
			}
		}
	}
}
void summary(vector<int>& a, vector<int>& b)
{
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i-1] + b[i-1] == 0)
		{
			sum.push_back(0);
			continue;
		}
		if (a[i-1] + b[i-1] == 1)
		{
			sum.push_back(1); 
			continue;
		}
		if (a[i-1] + b[i-1] == 2)
		{
			sum.push_back(0);
			a[i]++;
			continue;
		}
		if (a[i-1] + b[i-1] == 3)
		{
			a[i]++;
			sum.push_back(1); 
			continue;
		}
	}
	sum.push_back(0);
}
int main( )
{
	
	string number1, number2;
	vector<int>num1;
	vector<int>num2;
	bool fir = false, sec=false;
	cin >> number1 >> number2;
	if (number1[0] == '-')
	{
		fir = true;
		string str = "";
		for (int i = 1; i < number1.size(); i++)
			str +=number1[i];
		number1 = str;
		funcs(number1, num1);
	}
	else {
		funcs(number1, num1);
	}
	if (number2[0] == '-')
	{
		sec = true;
		string str = "";
		for (int i = 1; i < number2.size(); i++)
			str +=number2[i];
		number2 = str;
		funcs(number2, num2);
	}
	else {
		funcs(number2, num2);
	}
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	while (num1.size() != 16)
	{
		num1.push_back(0);
	}
	while (num2.size() != 16)
	{
		num2.push_back(0);
	}
	dop(fir, num1);
	dop(sec, num2);
	cout << "Two's complement code:" << endl;
	for (int i = num1.size()-1; i >= 0; i--)
		cout << num1[i];
	cout << endl;
	for (int i = num2.size() - 1; i >= 0; i--)
		cout << num2[i];
	cout << endl;
	cout << "Summary of two's comple,ent code:" << endl;
	summary(num1, num2);
	for (int i = sum.size()-1; i >= 0; i--)
		cout << sum[i];
	cout << endl;
	int i = 0;
	while (sum[i] != 1)
	{
		sum[i] = 0;
	}
	sum[i] = 0;
	if (sum[0] == 1)
	{
		for (int i = 0; i < sum.size(); i++)
			if (sum[i] == 1)
			{
				sum[i] = 0;
			}
			else sum[i] = 1;
	}
	reverse(sum.begin(), sum.end());
	cout << "Summary in compleent code:" << endl;
	for (int i = 0; i < sum.size(); i++)
		cout << sum[i];
}

