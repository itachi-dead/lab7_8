#include <iostream>
#include <cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
ofstream fout("flightsOut.txt");
ifstream fin("flightsIn.txt");
struct airport
{
	int number;
	string type;
	string path;
	string time;
	int real_time;
};
vector<airport>a;

pair<int,int >time_parser(string time)
{
	int hours, min;
	hours = (time[0] - 48) * 10 + (time[1] - 48);
	min = (time[3] - 48) * 10 + (time[4] - 48);
	return make_pair(hours, min);
}
bool compareByTime(const airport& a, const airport& b)
{
	return a.real_time > b.real_time;
}
void show()
{
	if (a.size() == 0)
	{
		cout << "Нет рейсов\n";
	}
	else {
		sort(a.begin(), a.end(), compareByTime);
		cout << "==========================================\n";
		cout << "==========================================\n";
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i].number << "   ";
			cout << "\t" << a[i].type << endl;
			cout << "\t" << a[i].time << endl;
			cout << "\t" << a[i].path << endl;
			cout << "*******************************" << endl;
		}
		cout << endl;
		cout << "==========================================\n";
		cout << "==========================================\n";
	}
}
int main()
{
	int number = 1;
	setlocale(LC_ALL, "Russian");
	int n = 10;
	while (n != 0) {
		cout << "Введите 1 , чтобы просмотреть рейсы\n";
		cout << "Введите 2 , чтобы добавить рейс\n";
		cout << "Введите 3 , чтобы удалить рейс\n";
		cout << "Введите 0 , чтобы закончить работу т вывести все разговоры по времени\n";
		cin >> n;
		if (n == 2)
		{
			cout << "Введиет номер рейса:\n";
			
			int number;
			cin >> number;
			bool already_exist = false;
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i].number == number)
				{
					cout << "Рейс уже существует.\n";
					already_exist = true;
					break;
				}
			}
			if (already_exist)
				continue;
			cout << "Введите время вылета на завтрашний день(00:00):\n";
			string time;
			cin >> time;
			pair<int,int>temp = time_parser(time);
			int real_time = temp.first * 60 + temp.second;
			cout << "Введите путь и тип самолета(only english):\n";
			string type, path;
			cin >> path >> type;
			airport kappa;
			kappa.number = number;
			kappa.path = path;
			kappa.time = time;
			kappa.type = type;
			kappa.real_time = real_time;
			a.push_back(kappa);
		}
		if (n == 1)
		{
			
			show();
		}
		if (n == 3)
		{
			show();
			cout << "Введите номер рейса который хотите удалить\n";
			int n;
			cin >> n;
			int kappa = a.size();
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i].number == n)
				{
					a.erase(a.begin() + i);
					
				}
			}
			if (kappa == a.size())
			{
				cout << "Такого рейса не существует.\n";
			}
			show();

		}
		if (n == 0)
		{
			show(); 
			if (a.size() == 0)
			{
				fout << "Нет рейсов\n";
			}else
			for (int i = 0; i < a.size(); i++)
			{
				fout << a[i].number << "   ";
				fout << "\t" << a[i].type << endl;
				fout << "\t" << a[i].time << endl;
				fout << "\t" << a[i].path << endl;
			}
		}
		
	}

	return 0;
}
