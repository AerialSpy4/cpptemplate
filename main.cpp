/*
NOTES:
Ideas: Would this be a topological sorting problem? Cause we have to do them in a certain order??? 

Example:
5 5
.....
.E.S.
.....
.....
.N.E.

Maybe the edges are S->E, but if there were to be another one in that column, theres another edge from the S-> whatever one that is

But we reverse the edges and see if theres a valid solution
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MM = 2003;
const int MOD = 1e9+7;
char grid[MM][MM];
vector<pair<int, int>> adj[MM][MM];
int ind[MM][MM];
bool node[MM][MM];
void solve() {
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') {
                node[i][j] = true;
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (grid[i][j] == 'N') {
                for (int x=i-1; x>=0; x--) {
                    if (grid[x][j] == '.') continue;
                    adj[x][j].push_back({i, j});
                    ind[i][j]++;
                }
            } else if (grid[i][j] == 'S') {
                for (int x=i+1; x<N; x++) {
                    if (grid[x][j] == '.') continue;
                    adj[x][j].push_back({i, j});
                    ind[i][j]++;
                }
            } else if (grid[i][j] == 'E') {
                for (int y=j+1; y<M; y++) {
                    if (grid[i][y] == '.') continue;
                    adj[i][y].push_back({i, j});
                    ind[i][j]++;
                }
            } else if (grid[i][j] == 'W') {
                for (int y=j-1; y>=0; y--) {
                    if (grid[i][y] == '.') continue;
                    adj[i][y].push_back({i, j});
                    ind[i][j]++;
                }
            }
        }
    }
    queue<pair<int, int>> q;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (ind[i][j] == 0 && node[i][j]) {
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cout << "(" << x << "," << y << ")" << endl;
        for (auto [nx, ny] : adj[x][y]) {
            if (--ind[nx][ny] == 0) {
                q.push({nx, ny});
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    while (T--) {
        solve();
    }
}