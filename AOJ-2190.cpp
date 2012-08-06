#include <cstdio>
using namespace std;

int _n;
int _m;
int _t[50005];
int _s[50005];

inline int Convert(const char* tune_str) {
    if(tune_str[0]=='C' && tune_str[1]=='\0') return 0;
    if(tune_str[0]=='C' && tune_str[1]=='#' ) return 1;
    if(tune_str[0]=='D' && tune_str[1]=='\0') return 2;
    if(tune_str[0]=='D' && tune_str[1]=='#' ) return 3;
    if(tune_str[0]=='E' && tune_str[1]=='\0') return 4;
    if(tune_str[0]=='F' && tune_str[1]=='\0') return 5;
    if(tune_str[0]=='F' && tune_str[1]=='#' ) return 6;
    if(tune_str[0]=='G' && tune_str[1]=='\0') return 7;
    if(tune_str[0]=='G' && tune_str[1]=='#' ) return 8;
    if(tune_str[0]=='A' && tune_str[1]=='\0') return 9;
    if(tune_str[0]=='A' && tune_str[1]=='#' ) return 10;
    return 11;
}

bool Reverse(int t_pos) {
    for (int i = _m-1; i >= 0; --i) {
        int t_tune = _t[t_pos];
        int s_tune = _s[i];
        int diff = (s_tune - t_tune + 12) % 12;

        int move;
        if (diff == 0)
            t_pos -= 1;
        else if (diff == 1)
            t_pos -= 2;
        else if (diff == 11)
            t_pos += 1;
        else
            return false;

        if (i == 0 && t_pos == -1 )
            return true;
        if (t_pos < 0 || t_pos >= _n)
            return false;
    }

    return false;
}

int main(int argc, const char *argv[])
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &_n, &_m);
        char tune[5];
        for (int i = 0; i < _n; i++) {
            scanf("%s", tune);
            _t[i] = Convert(tune);
        }
        for (int i = 0; i < _m; i++) {
            scanf("%s", tune);
            _s[i] = Convert(tune);
        }

        if (Reverse(_n-1) || Reverse(_n-2))
            puts("Yes");    
        else
            puts("No");
    }
    return 0;
}

/* #include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

struct Element {
    int stair_pos;
    int song_pos;

    Element(int _stair_pos, int _song_pos) {
        stair_pos = _stair_pos;
        song_pos = _song_pos;
    }

    bool operator>(const Element& element) const {
        return song_pos > element.song_pos;
    }
};
priority_queue< Element, vector<Element>, greater<Element> > _elements;
int _stair_cnt;
int _song_len;
int _stair_tune[50005];
int _song_tune[50005];
int _move_stair[] = {-1, 1, 2};
int _move_tune[] = {11, 0, 1};

inline int Convert(const char* tune_str) {
    if(tune_str[0]=='C' && tune_str[1]=='\0') return 0;
    if(tune_str[0]=='C' && tune_str[1]=='#' ) return 1;
    if(tune_str[0]=='D' && tune_str[1]=='\0') return 2;
    if(tune_str[0]=='D' && tune_str[1]=='#' ) return 3;
    if(tune_str[0]=='E' && tune_str[1]=='\0') return 4;
    if(tune_str[0]=='F' && tune_str[1]=='\0') return 5;
    if(tune_str[0]=='F' && tune_str[1]=='#' ) return 6;
    if(tune_str[0]=='G' && tune_str[1]=='\0') return 7;
    if(tune_str[0]=='G' && tune_str[1]=='#' ) return 8;
    if(tune_str[0]=='A' && tune_str[1]=='\0') return 9;
    if(tune_str[0]=='A' && tune_str[1]=='#' ) return 10;
    return 11;
}

int main(int argc, const char *argv[])
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &_stair_cnt, &_song_len);
        
        char tune_str[3];
        for (int i = 1; i <= _stair_cnt; ++i) {
            scanf("%s", tune_str);
            _stair_tune[i] = Convert(tune_str);
        }
        for (int i = 1; i <= _song_len; ++i) {
            scanf("%s", tune_str);
            _song_tune[i] = Convert(tune_str);
        }
        
        while (!_elements.empty())
            _elements.pop();
        _elements.push(Element(0, 0));
        bool res;
        res = false;

        while (!_elements.empty() && !res) {
            Element element = _elements.top();
            _elements.pop();

            int least_step = (_stair_cnt+2 - element.stair_pos) / 2;
            int left_song = _song_len - element.song_pos + 1;
            if (left_song < least_step)
                continue;

            if (element.song_pos == _song_len) {
                if (element.stair_pos+1 == _stair_cnt+1 ||
                    element.stair_pos+2 == _stair_cnt+1) {
                    res = true;
                    break;
                }
                continue;
            }

            for (int i = 0; i < 3; ++i) {
                int next_stair_pos = element.stair_pos + _move_stair[i];
                int next_tune_pos = element.song_pos + 1;
                
                if (next_stair_pos <= 0 || next_stair_pos > _stair_cnt)
                    continue;
                
                int next_stair_tune =
                    _stair_tune[next_stair_pos] + _move_tune[i];
                if (next_stair_tune >= 12) 
                    next_stair_tune -= 12;
                if (next_stair_tune != _song_tune[next_tune_pos])
                    continue;
                _elements.push(Element(next_stair_pos, next_tune_pos)); 
            }
        }

        puts(res ? "Yes" : "No");
    }

    return 0;
} */
