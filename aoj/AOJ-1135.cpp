#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char *argv[])
{
    int cases;
    cin >> cases;
    while (cases--) {
        double money;
        int year;
        int pros;
        double max = -1;
        cin >> money >> year >> pros;

        while (pros--) {
            int type;
            double rate;
            double cost;
            double res = money;
            cin >> type >> rate >> cost;

            int interest = 0;
            for (int i = 0; i < year; ++i) {
                if (0 == type)
                    interest += res * rate; 
                else
                    res += (int)(res * rate);
                res -= cost;
            }
            if (0 == type) {
                int tmp = res + interest;
                if (tmp > max)
                    max = tmp;
            }
            else if (res > max)
                 max = res;   
        }

        cout << (int)max << endl;
    }   
    return 0;
}
