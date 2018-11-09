#include <map>
#include <limits>
#include <iostream>

using namespace std;

int main()
{
    double firstSmall = -10000;
    double secondBig = numeric_limits<double>::min();

    if (firstSmall < secondBig)
    {
        cout << "Think-Cell? U used Template so we got the point in your question ^^" << endl;
        cout << "secondBig: " << secondBig << endl;

        cout << "numeric_limits<float>::min(): " << numeric_limits<float>::min() << endl;
        cout << "numeric_limits<unsigned long long>::min(): " << numeric_limits<unsigned long long>::min() << endl;
        cout << "numeric_limits<unsigned int>::min(): " << numeric_limits<unsigned int>::min() << endl;
    }   cout << "numeric_limits<unsigned int>::max(): " << numeric_limits<unsigned int>::max() << endl;

    getchar();

    return 0;
}
