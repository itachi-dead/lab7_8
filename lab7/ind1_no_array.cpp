
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
int to_decimal(char* str, int base)
{
    int len = strlen(str);
    int power = 1; 
    int num = 0;  
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }

        num += val(str[i]) * power;
        power = power * base;
    }

    return num;
}
string to_other(int b, int n) {

    string res = "";

    for (int i = 0; n > 0; i++) {

        if (n == b) {
            res = "10" + res;
            break;
        }

        else {
            if (n % b > 9) {
                res = char('A' + (n % b) - 10) + res;
            }
            else {
                res = char((n % b) + '0') + res;
            }
        }

        n /= b;
    }

    return res;
}

int main()
{

    char str[] = "11A";
    int base = 13;
    cout << "Use only ENGLISH upper letters: " << endl;
    cin >> str;
   
    cout << to_other(3, to_decimal(str, base));
    
    return 0;
}