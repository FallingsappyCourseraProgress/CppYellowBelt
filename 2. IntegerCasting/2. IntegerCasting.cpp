#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void PrintAvg() {
    vector<int> t = { -8, -7, 3 };
    int sum = 0;
    for (int x : t) {
        sum += x;
    }

    //int avg = (sum / t.size()) + vector<int>{};
    int avg = (sum / t.size());
    cout << avg << endl;
}

int main()
{
    cout << numeric_limits<int>::max() + 1 << endl;
    cout << numeric_limits<int>::min() - 1 << endl;

    // overflow during sum
    int x = 2'000'000'000;
    int y = 1'000'000'000;
    cout << (x + y) / 2 << endl;


    int d = 2'000'000'000;
    unsigned int w = d;
    cout << d << " " << w << endl;

    // cant put signed in unsigned
    int z = -2'000'000'000;
    unsigned int v = z;
    cout << z << " " << v << endl;

    int s = -1;
    unsigned int u = 1;
    cout << (s < u) << endl;
    cout << (-1 < 1u) << endl;

    return 0;
}
