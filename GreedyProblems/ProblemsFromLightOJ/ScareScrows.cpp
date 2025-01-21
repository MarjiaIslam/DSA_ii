#include <bits/stdc++.h>

using namespace std;

int MinScareScrows(string field, int N) {
    int scarecrow = 0;
    int i = 0;
    while (i < N) {
        if (field[i] == '.') {
            scarecrow++;
            i += 3;
        } else {
            i++;
        }
    }
    return scarecrow;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int N;
        cout << "Enter the length of the field: ";
        cin >> N;

        string field;
        cout << "Enter the field (using '.' for crop growing region and '#' for infertile region): ";
        cin >> field;

        int result = MinScareScrows(field, N);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
