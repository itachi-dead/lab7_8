#include <iostream>
#include<string>
#include<cmath>
using namespace std;
template<typename T>
string to_binary_string(T n)
{
    static_assert(is_integral<T>::value, "Integer required.");
    if (numeric_limits<T>::is_signed() &&
        n == numeric_limits<T>::min())
    {
        return string("-1") + string(sizeof(int) * CHAR_BIT - 1, '0');
    }
    string result;
    bool negative = (n < 0);
    if (negative)
        n = -n; 
    do
    {
        result += ('0' + (n % 2));
        n = n / 2;
    } while (n > 0);
    if (negative)
        result = "-" + result;
    return result;
}
int main()
{
    int a;
    cin >> a;
    cout << to_binary_string(a);
	
}
