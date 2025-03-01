#include <bits/stdc++.h>
#define NAME "a"
using namespace std;

const int NTEST = 100;

mt19937_64 rd(time(0));

long long Rand(long long l, long long h) {
    return uniform_int_distribution<long long>(l, h)(rd);
}

void MakeTest() {
    ofstream cout (NAME".inp");
    long long n = Rand(500, 1000), q = Rand(1, 10);
    cout << n << '\n';
    long long nnn;
    for (long long i = 1; i <= n; i++)
        nnn = Rand(1, 100000);
        long long random = Rand(nnn, 100000);
        cout << random << ' ';
    
    while (q--) {
        cout << Rand(1, n) << ' ' << Rand(1, n) << " " << Rand(1, n) << '\n';
    }
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        MakeTest();

        system(NAME".exe <"NAME".inp >"NAME".out");
        system(NAME"_trau.exe <"NAME".inp >"NAME".ans");

        if (system("fc "NAME".out "NAME".ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
}