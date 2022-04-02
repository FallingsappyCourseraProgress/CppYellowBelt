#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    vector<int> t = { -8, 7, 3 };

    int sum = 0;

    for (int x : t) {
        sum += x;
    }

    int avg = sum / t.size(); // wrong answer

    int x = 2'000'000'000;

    cout << x << " ";
    cout << x * 22 << " ";

    cout << sizeof(int16_t) << endl;

    int y;
    cout << sizeof(y) << endl;
    cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;

    cout << numeric_limits<long int>::min() << " " << numeric_limits<long int>::max() << endl;

    return 0;
}
