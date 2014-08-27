#include <algorithm>    
#include <cmath>
#include <iostream>
using namespace std;

const int END = 10e6;
const int MAX = END - 1;
const int LEN = (MAX - 1) / 2 + 1;

bool _sieve[LEN] = {0};

int Sieve () {
    int i, j, inc, end = (int(sqrt((double)MAX)) - 1) / 2 + 1, pend;
    pend = 1;
    for (i=1; i<end; ++i) {
        if (_sieve[i]) continue;  
        for (j=2*i*(i+1), inc=2*i+1; j<LEN; j+=inc) {
            _sieve[j] = true;
        }
    }
    return pend;
}

// prime test
bool IsPrime(int x) {
    return (x > 1) && ((x == 2) || (x & 1) && !_sieve[(x-1)>>1]);
}

int main(int argc, const char *argv[])
{
    Sieve();
    int a, d, n;
    while (cin >> a >> d >> n, a) {
        int now = a;
        while (true) {
            if (IsPrime(now)) {
                n--;
                if (0 == n)
                    break;
            }
            now += d;
        }
        cout << now << endl;
    }
    return 0;
}
