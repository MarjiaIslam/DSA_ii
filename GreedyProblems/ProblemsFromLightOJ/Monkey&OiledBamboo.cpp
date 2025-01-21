#include <bits/stdc++.h>
using namespace std;

int findMinMax(vector<int> rungs) {
    int n = rungs.size();
    int maxJump = 0;
    for (int i = 1; i < n; i++) {
        maxJump = max(maxJump, rungs[i] - rungs[i - 1]);
    }
    return maxJump;
}

int main() {
    int c;
    cout << "Enter the number of cases: ";
    cin >> c;
    for (int i = 1; i <= c; i++) {
        int r;
        cout << "Enter the number of rungs: ";
        cin >> r;
        vector<int> rungs(r);
        cout << "Enter the height of rungs: " <<endl;
        for (int j = 0; j < r; j++) {
            cin >> rungs[j];
        }
        int result = findMinMax(rungs);
        cout << "Case " << i << " : " << result << endl;
    }
}
