#include <iostream>
#include <vector>

using namespace std;

enum class SomeEnum {
    A,
    B,
    C,
    VALUE
};

void PrintAvg() {
    vector<int> t = { -8, -7, 3 };
    int sum = 0;
    for (int x : t) {
        sum += x;
    }

    //int avg = (sum / t.size()) + vector<int>{};
    int avg = (sum / static_cast<int>(t.size()));
    cout << avg << endl;
}

int main()
{
    cout << (-1 < 1u) << endl;

    vector<int> x = { 4, 5 };

    for (int i = 0; i < x.size(); i++)
    {
        cout << i << " " << x[i] << endl;
    }

    for (size_t i = 0; i < x.size(); i++)
    {
        cout << i << " " << x[i] << endl;
    }

    for (int i = 0; i < static_cast<int>(x.size()); i++)
    {
        cout << i << " " << x[i] << endl;
    }

    PrintAvg();


    vector<int> v = { 1, 4, 6 };

    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i];
    }

    vector<int> c = { };

    // c.size < 0 error
    //for (size_t i = 0; i < c.size() - 1; i++)
    //{
    //    cout << c[i];
    //}

    for (size_t i = 0; i + 1 < c.size(); i++)
    {
        cout << c[i];
    }




    vector<int> cx = { 1, 3, 5 };
    // backwards error i can't be negative
    //for (size_t i = cx.size() - 1; i >= 0; --i)
    //{
    //    cout << cx[i];
    //}

    for (size_t k = cx.size(); k > 0; --k)
    {
        size_t i = k - 1;

        cout << cx[i];
    }

    uint32_t z = -1;

    // compile error
    //int32_t x = SomeEnum::VALUE;

    return 0;
}
