#include <iostream>
#include <functional>

using namespace std;

 template<typename T, typename Func = less<T>>
 bool customCompare(const T& a, const T& b, Func comp = Func())
 {
    return comp(a, b);
 }

int main()
{

    int x = 10, y = 20;
    cout << "Using default less-than comparison: " << boolalpha << customCompare(x, y) << '\n';

    // Using greater-than comparison
    cout << "Using greater-than comparison: " << customCompare(x, y, greater<int>()) << '\n';

    double p = 5.5, q = 3.3;
    cout << "Using default less-than comparison for doubles: " << customCompare(p, q) << '\n';

    // Using greater-than comparison for doubles
    cout << "Using greater-than comparison for doubles: " << customCompare(p, q, greater<double>()) << '\n';

    return 0;
}