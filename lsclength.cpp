#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcsLength(string x, string y) {
    int m = x.length();
    int n = y.length();

    int dp[101][101];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcsLength(str1, str2);
    return 0;
}
