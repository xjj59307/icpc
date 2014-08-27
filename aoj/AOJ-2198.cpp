#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Product {
    string name;
    double cost;
    double ratio;
};
Product _products[55];

bool sort_product(const Product& lhs, const Product& rhs) {
    if (lhs.ratio == rhs.ratio)
        return lhs.name < rhs.name;
    else
        return lhs.ratio > rhs.ratio;
}

int main(int argc, const char *argv[])
{
    int n;
    while (cin >> n, n) {
        int ta;
        int tb;
        int tc;
        int td;
        int te;
        int count;
        int price;
        int turn;
        double time;
        double value;
        for (int i = 0; i < n; i++) {
            cin >> _products[i].name >> _products[i].cost;
            cin >> ta >> tb >> tc >> td >> te >> count >> price >> turn;
            time = ta + tb + tc + (te + td) * turn; 
            value = count * price * turn;
            _products[i].ratio = (value-_products[i].cost) / time;
        }
        sort(_products, _products+n, sort_product);

        for (int i = 0; i < n; i++) {
            cout << _products[i].name << endl;
        }
        cout << "#" << endl;
    }
    return 0;
}
