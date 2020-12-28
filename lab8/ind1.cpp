#include <iostream>
#include <cmath>
#include<string>
#include<vector>
using namespace std;
struct call
{
	string date = "";
	int code = 0;
	string name = "";
	int time = 0;
	int rate =  1;
	string number = "";
	int sum = 0;
};
vector<call>a;
void sort()
{
	for (int i = 1; i < a.size(); ++i)
	{
		for (int r = 0; r < a.size() - i; r++)
		{
			if (a[r].time < a[r + 1].time)
				{
					swap(a[r], a[r + 1]);
				}
		}
	}
}
void show()
{
	if (a.size() == 0)
	{
		cout << "Нет звонков\n";
	}
	else {
		cout << "==========================================\n";
		cout << "==========================================\n";
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i].code << "   ";
			cout << "\t" << a[i].date << endl;
			cout << "\t" << a[i].name << endl;
			cout << "\t" << a[i].number << endl;
			if (a[i].rate == -1)
			{
				cout << "\t" << "many calls , can't calculate rate" << endl;
			}
			else cout << "\t" << a[i].rate << endl;
			cout << "\t" << a[i].time << endl;
			cout << "*******************************" << endl;
		}
		cout << endl;
		cout << "==========================================\n";
		cout << "==========================================\n";
	}
}
int main()
{
	
	setlocale(LC_ALL, "Russian");
	int n = 10;
	while (n != 0) {
		cout << "Введите 1 , чтобы просмотреть разговоры\n";
		cout << "Введите 2 , чтобы добавить разговор\n";
		cout << "Введите 0 , чтобы закончить работу т вывести все разговоры по времени\n";
		cin >> n;
		if (n == 2)
		{
			call temp;
			string s;
			int t;
			cout << "Введите дату разговора:\n";
			cin >> s;
			cout << endl;
			temp.date = s;
			string gorod;
			cout << "Введите код и город(only english,uppercase first letter) в который звонили:\n";
			cin >> t >> gorod;
			bool already_exist = false;
			int already_exist_i = 0;
			for (int i = 0; i < a.size(); i++)
			{
				if (gorod == a[i].name)
				{
					already_exist_i = i;
					already_exist = true;
					break;
				}
			}
			cout << endl;
			temp.code = t;
			temp.name = gorod;
			cout << "Введите время разговоров(в секундах):\n";
			cin >> t;
			cout << endl;
			temp.time = t;
			cout << "Введите тариф(сек/рубль) и номер телефона:\n";
			cin >> t >> s;
			temp.rate = t;
			temp.number = s;
			temp.sum = temp.rate * temp.time;
			if (already_exist)
			{
				a[already_exist_i].date += " ";
				a[already_exist_i].date += temp.date;
				a[already_exist_i].number += " ";
				a[already_exist_i].number += temp.number;
				a[already_exist_i].sum += temp.rate * temp.time;
				a[already_exist_i].rate = -1;
				a[already_exist_i].time += temp.time;
			}else a.push_back(temp);
		}
		if (n == 1)
		{
			show();
		}
		if (n == 0)
		{
			sort();
			for (int i = 0; i < a.size(); i++)
			{
				cout << a[i].name << " " << a[i].time << " секунд"<< " " <<a[i].sum <<" рублей"<< endl;
			}
		}
		
	}

	return 0;
}
