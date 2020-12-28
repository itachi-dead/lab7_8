
#include <iostream>
#include <conio.h>
#include <vector>
#include<string>

using namespace std;


unsigned long int l = 0,s =0;
int k = 1;


bool check(char s1[], char s2[]) {
	int k = 0;
	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] == s2[0]) {
			k++;
			for (int j = 1; j < strlen(s2); j++)
				if (s1[i + j] == s2[j]) k++;
		}
		if (k == strlen(s2)) return true;
		k = 0;
	}
	return false;
}

int main() {
	int n;
	cout << "Entern number n: ";
	cin >> n;

	vector <int> a;
	vector <unsigned long int> b;
	b.push_back(1);
	
	for (int i = 1; i <= 1000; i++) {
		if (i % (int)pow(2, k) == 0)
		{
			l = pow(10, k);
			b.push_back(l);
			k++;
		}
		else {
			s = l + b[i - pow(2, k - 1)];
			b.push_back(s);
		}
		char s1[80];
		_itoa_s(b[i - 1], s1, 80, 2);
		//_itoa_s(b[i - 1], s1, 20, 10);
		char s2[20];
		_itoa_s(b[i - 1], s2, 20, 10);
		//itoa_s(b[i - 1], s1, 80, 2);
		if (check(s1, s2)) a.push_back(b[i - 1]);
	}
	a.erase(a.begin());
	cout << "Answer: " << a[n - 1];
}