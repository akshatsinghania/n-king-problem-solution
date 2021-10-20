#include <bits/stdc++.h>

using namespace std;

#define int long long
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define endl '\n'

void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM)
{
    cerr << endl;
}
vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)

/*MODIFY N HERE*/
int n = 4;
/*MODIFY N HERE*/
vector<vector<int>> board(n, vector<int>(n));

bool isValid(vector<vector<int>> b, int row, int col)
{
    vector<pair<int, int>> directions = {
        /*top*/
        {-1, -1},
        {-1, 0},
        {-1, 1},
        /*middle*/
        {0, -1},
        {0, 0},
        {0, 1},
        /*bottom*/
        {1, -1},
        {1, 0},
        {1, 1}};

    for (auto i : directions)
    {
        int x = row + i.f;
        int y = col + i.s;

        if (x > -1 && x < b.size())
        {
            if (y > -1 && y < b[x].size())
            {
                // debug(b[x][y], x, y);
                if (b[x][y] == 1)
                    return false;
            }
        }
    }
    return true;
}

void debug_board(vector<vector<int>> b)
{
    for (auto i : b)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl
         << endl;
}

set<vector<vector<int>>> ans;

void search(int currentRow = 0, vector<vector<int>> b = board)
{
    if (currentRow == b.size())
    {
        ans.insert(b);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isValid(b, currentRow, i))
        {
            b[currentRow][i] = 1;
            search(currentRow + 1, b);
            b[currentRow][i] = 0;
        }
    }
}

void solve()
{
    vector<vector<int>> b = {{0, 1, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0}};
    // debug(isValid(b, 1, 0));
    search();

    for (auto x : ans)
        debug_board(x);
    debug(ans.size());
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // tc
    {
        solve();
    }
    return 0;
}