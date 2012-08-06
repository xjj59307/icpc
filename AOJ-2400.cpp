#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Team {
    int id;
    int cnt;
    int penalty;
    bool right[15];
    int wrong[15];
};
Team _teams[55];

bool sort_team(const Team& lhs, const Team& rhs) {
    if (lhs.cnt != rhs.cnt)
        return lhs.cnt > rhs.cnt;
    else if (lhs.penalty != rhs.penalty)
        return lhs.penalty < rhs.penalty;
    else
        return lhs.id < rhs.id;
}

int main(int argc, const char *argv[])
{
    int T;
    int P;
    int R;
    while (cin >> T >> P >> R, T) {
        for (int i = 1; i <= T; ++i) {
            _teams[i].id = i;
            _teams[i].cnt = 0;
            _teams[i].penalty = 0;
            fill_n(_teams[i].wrong+1, P, 0);
            fill_n(_teams[i].right+1, P, 0);
        }
        for (int i = 0; i < R; ++i) {
            int tid;
            int pid;
            int time;
            string msg;
            cin >> tid >> pid >> time >> msg;

            if (msg == "WRONG") {
                _teams[tid].wrong[pid]++;
            }
            else {
                if (_teams[tid].right[pid])
                    continue;
                _teams[tid].cnt++;
                _teams[tid].penalty += (_teams[tid].wrong[pid] * 1200 + time);
                _teams[tid].right[pid] = true;
            }
        }
        sort(_teams+1, _teams+T+1, sort_team);

        for (int i = 1; i <= T; ++i)
            cout << _teams[i].id << " " << _teams[i].cnt << " " << _teams[i].penalty << endl;
    } 

    return 0;
}
