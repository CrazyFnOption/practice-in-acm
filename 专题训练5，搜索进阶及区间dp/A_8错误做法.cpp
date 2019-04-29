#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct Board {
    char board[5][5];
    int beg,_end;
    Board(){};
    Board(char b[5][5],string p) {
        for (int i = 1 ; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                board[i][j] = b[i][j];
                if (b[i][j] == 'x') {
                    beg = i;
                    _end = j;
                }
            }
        }
        path = p;
    }

    string path;

    Board swap(int i,int j,int Case) {
        Board t(board,path);
        char tmp = t.board[i][j];
        switch(Case) {
            case 0 : {
                t.board[i][j] = t.board[i - 1][j];
                t.board[i - 1][j] = tmp;
                t.beg = t.beg - 1;
                t.path.push_back('u');
                break;
            }
            
            case 1: {
                t.board[i][j] = t.board[i + 1][j];
                t.board[i + 1][j] = tmp;
                t.beg = t.beg + 1;
                t.path.push_back('d');
                break;
            }

            case 2: {
                t.board[i][j] = t.board[i][j - 1];
                t.board[i][j - 1] = tmp;
                t._end = t._end - 1;
                t.path.push_back('l');
                break;
            }

            case 3: {
                t.board[i][j] = t.board[i][j + 1];
                t.board[i][j + 1] = tmp;
                t._end = t._end + 1;
                t.path.push_back('r');
                break;
            }
        }
        return t;
    }

    bool operator == (const Board &b) {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (this -> board[i][j] != b.board[i][j]) return false;
            }
        }
        return true;
    }
    
};


char tmp[5][5];
char res[5][5];

string bfs() {
    Board init(tmp, "");
    const Board _end(res,"");
    queue<Board> q;
    q.push(init);
    while (!q.empty()) {
        Board now = q.front();
        q.pop();
        if (now == _end) return now.path;
        for (int i = 0; i < 4; i++) {
            Board  next = now.swap(now.beg,now._end,i);
            if (next.beg < 1 || next.beg > 3 || next._end < 1 || next._end > 3) {
                continue;
            }
            q.push(next);
        }
        
    }
    return "yes";
}

int main()
{
    string ss;
    while (getline(cin,ss)) {
        int tot = 0,ins = 1;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                tmp[i][j] = ss[tot];
                res[i][j] = ins++;
                tot += 2;
                cout << res[i][j] <<" ";
            }
        }
        res[3][3] = 'x';
        

        //cout << bfs() << endl;
    }

    return 0;
}