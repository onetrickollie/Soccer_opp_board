#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

bool is_valid_path(const vector<vector<char>>& G, const vector<char>& candidate) {
    int r = G.size();
    int c = G[0].size();
    int x = 0, y = 0;

    for (int i = 0; i < candidate.size(); i++) {
        char move = candidate[i];
        if (move == '>') {
            y++;
        } else {
            x++;
        }
        if (x >= r || y >= c || G[x][y] == 'X') {
            return false;
        }
    }
    return x == r - 1 && y == c - 1;
}

int soccer_exhaustive(const vector<vector<char>>& G) {
    int r = G.size();
    int c = G[0].size();
    int n = r + c - 2;
    int counter = 0;

    for (int bits = 0; bits < (1 << n); bits++) {
        vector<char> candidate;
        for (int k = 0; k < n; k++) {
            candidate.push_back((bits & (1 << k)) ? '>' : 'v');
        }
        if (is_valid_path(G, candidate)) {
            counter++;
        }
    }
    return counter;
}

double run_timing(int n) {
    vector<vector<char>> field(n, vector<char>(n, '.'));
    clock_t start_time = clock();
    soccer_exhaustive(field);
    double elapsed_time = double(clock() - start_time) / CLOCKS_PER_SEC;
    return elapsed_time;
}

int main() {
    vector<vector<char>> field = {
        {'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', '.', 'X'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    int answer = soccer_exhaustive(field);
    cout << "Number of different paths to cross the field: " << answer << endl;

    vector<int> ns = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    for (int n = 0; n < ns.size(); n++) {
        double elapsed_time = run_timing(ns[n]);
        cout << "Elapsed time for n = " << ns[n] << ": " << elapsed_time << " seconds" << endl;
    }

    return 0;
}
