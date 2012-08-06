#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

bool _visited[125][125];
bool _barrier[125][125];
int _movex[] = {0, 1, 0, -1, 1, -1};
int _movey[] = {1, 0, -1, 0, 1, -1};
queue< pair<int, int> > _pos;
queue<int> _turn;
int _res;

void BFS() {
    pair<int, int> cur_pos = _pos.front();
    _pos.pop();
    int left_turn = _turn.front();
    _turn.pop();
    if (left_turn <= 0)
        return;

    for (int i = 0; i < 6; ++i) {
        int x = cur_pos.first + _movex[i];
        int y = cur_pos.second + _movey[i];

        if (_visited[x][y])
            continue;
        if (_barrier[x][y])
            continue;

        _pos.push(make_pair(x, y));
        _turn.push(left_turn-1);
        _visited[x][y] = true;
        _res++;
    }
}

int main(int argc, const char *argv[])
{
    int t;
    int n;
    while (cin >> t >> n, t+n) {
        memset(_visited, 0, sizeof(_visited));
        memset(_barrier, 0, sizeof(_barrier));
        while (!_pos.empty())
            _pos.pop();
        while(!_turn.empty())
            _turn.pop();

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            x += 60;
            y += 60;
            _barrier[x][y] = true;
        }    

        int sx, sy;
        cin >> sx >> sy;
        sx += 60;
        sy += 60;
        _pos.push(make_pair(sx, sy));
        _turn.push(t);
        _visited[sx][sy] = true;

        _res = 1;
        while (!_pos.empty())
            BFS();

        cout << _res << endl;
    } 

    return 0;
}
