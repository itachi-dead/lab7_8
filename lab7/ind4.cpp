#include <iostream>
#include <windows.h>
#include<string>
#include<vector>
using namespace std;
int a[9] = {10,11,12,13,14,15,16,17,18 };
char b[9] = { 'A','B','C','D','E','F','G','H','I' };
int t = 0;
int check(char c)
{
	if (c <= '9')
	{
		return c-48;
	}
	if(c>=65) {
			return a[c-65];
	}
	
}
void add(string& q, int sum)
{
	if (t == 1)
	{
		sum++;
		if (sum >= 19)
		{
			sum -= 10;
			t++;
		}
		else t--;
	}
	if (sum < 19)
	{
		if (sum <= 9)
		{
			q += (char)(sum + 48);
		}
		else {
			q += b[sum - 11];
		}
	}
}
int main()
{
	cout << "Enter two number in 19'th form:";
	string num1, num2;
	cout << endl;
	cin >> num1;
	cin >> num2;
	char c;
	cout << "Enter + for addition or - for substraction:";
	cout << endl;
	cin >> c;

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int n = max(num1.size(), num2.size());
	if (num1.size() > num2.size())
	{
		for (int i = 0; i <= num1.size() - num2.size(); i++)
			num2 += "0";
	}
	if (num1.size() < num2.size())
	{
		for (int i = 0; i <= num2.size() - num1.size(); i++)
			num1 += "0";
	}
	/*cout << num1 << ' ' << num2;
	cout << endl;
	cout << endl;*/
	vector<int>numbers;
	if (c == '+')
	{
		
		for (int i = 0; i < num1.size(); i++)
		{
			int hm = check(num1[i]) + check(num2[i]);
			numbers.push_back(hm);
		}
		
		vector<char>ans;
		for (int i = 1; i < n; i++)
		{
			if (numbers[i-1] > 18)
			{
				numbers[i]+=1;
				
				numbers[i-1] -= 19;
				if (numbers[i-1] > 9)
					ans.push_back(b[numbers[i-1] - 10]);
				else ans.push_back((char)(numbers[i-1] + 48));
			}
			else {
				if (numbers[i-1] > 9)
					ans.push_back(b[numbers[i-1] - 10]);
				else ans.push_back((char)(numbers[i-1] + 48));
			}
		}
		if (numbers[numbers.size() -1] > 9)
			ans.push_back(b[numbers[numbers.size()-1] - 10]);
		else ans.push_back((char)(numbers[numbers.size() - 1] + 48));
	
		cout << endl;
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
	}

	else {
		
		for (int i = 0; i < num1.size(); i++)
		{
			int hm = check(num1[i]) - check(num2[i]);
			numbers.push_back(hm);
		}
		cout << endl;
		vector<char>ans; 
		for (int i = 0; i < n; i++)
		{
			if (numbers[i] < 0)
			{
				numbers[i + 1] -= 1;
				numbers[i] += 19;
				if (numbers[i] > 9)
					ans.push_back(b[numbers[i] - 10]);
				else ans.push_back((char)(numbers[i] + 48));
			}
			else {
				if (numbers[i] > 9)
					ans.push_back(b[numbers[i] - 10]);
				else ans.push_back((char)(numbers[i] + 48));
			}
			

		}
		
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] ;
		}
		
	}
}

