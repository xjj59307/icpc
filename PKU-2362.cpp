#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

const int MAX_M = 25;
int _m;
int _stick[MAX_M];
int _len;
bool _visited[MAX_M];
bool _find = false;

void dfs(int now, int step, int index) {
    if (step == 3) _find = true;
    if (_find) return;

    for (int i = index; i < _m; ++i) {
        if (_visited[i]) continue;

        _visited[i] = true;

        if (now + _stick[i] < _len) {
            dfs(now + _stick[i], step, i + 1);
        } else if (now + _stick[i] == _len) {
            dfs(0, step + 1, 0);
        }

        _visited[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        cin >> _m;

        // input
        int sum = 0;
        for (int i = 0; i < _m; ++i) {
            cin >> _stick[i];
            sum += _stick[i];
        }

        if (sum % 4 != 0) {
            cout << "no" << endl;
            continue;
        }
        _len = sum / 4;
        sort(_stick, _stick + _m, greater<int>());

        // case initialization
        fill_n(_visited, _m, 0);
        _find = false;
        dfs(0, 0, 0);

        cout << (_find ? "yes" : "no") << endl;
    }
    return 0;
}