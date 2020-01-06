#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

void code(ifstream& cin, ofstream& cout);

int main() {
    ios_base::sync_with_stdio(false);
    int TC = 1, cnt = 0;
    while (fopen((to_string(TC)+".in").c_str(), "r")) {
        ifstream fin(to_string(TC)+".in");
        ofstream fout("out");
        fin.tie(NULL), fout.tie(NULL);
        chrono::time_point<std::chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        code(fin, fout);
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_time = end - start; 
        ifstream out("out");
        ifstream ans(to_string(TC)+".out");
        string s, t;
        bool AC = true;
        while (getline(out, s) && getline(ans, t) && AC) {
            if (s != t) AC = false;
        }
        cout << "Test case " << TC << ": ";
        if (elapsed_time.count() > 2000) {
            cout << "TLE" << '\n';
        }
        else if (AC) {
            cout << "AC" << '\n';
            cnt++;
        }
        else {
            cout << "WA" << '\n';
        }
        cout << "Elapsed time: " << 1000 * elapsed_time.count() << " milliseconds\n";
        remove("out");
        TC++;
    }
    if (cnt == --TC) {
        cout << "All AC!" << endl;
    }
    else {
        cout << cnt << " / " << TC << endl;
    }
}