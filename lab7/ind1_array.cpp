
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

char model[14] = { '0', '1','2','3','4','5','6','7','8','9','A', 'B', 'C', 'D'};
char lower_model[14] = { '0', '1','2','3','4','5','6','7','8','9','a', 'b', 'c', 'd'};

int conversion_to_int(string s)
{
    double result = 0;
    int digits = s.length();
    double razr;
    double osn = 13;
    for (int i = digits; i > 0; i--)
    {
        for (int b = 0; b <= 13; b++)
        {
            if (s[digits - i] == model[b] || s[digits - i] == lower_model[b])
            {
                razr = b;
                break;
            }
            if (b == 13)
            {
                return 0;
            }
        }
        result = result + razr * pow(osn, i - 1);

    }
    return (int)result;
}
string conversion_to_other(int digit, int num) 
{
    string number;
    int ostatok;
    while (num >= digit)
    {
        ostatok = num % digit;
        number = number + model[ostatok];
        num = num / digit;
    }
    number = number + model[num];
    reverse(number.begin(), number.end());
    return number;

}

int main()
{
    string s;
    int result;
    for (int i = 0; i < 13; i++)
    {
        cout << model[i] << " ";

    }
    cout << endl << endl;
    cout << "ENTER ONLY ENGLISH LETTERS" << endl << endl;
    cin >> s;
    result = conversion_to_int(s);

   
    cout << conversion_to_other(3, result) << endl;
}