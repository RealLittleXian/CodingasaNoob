// Asked ChatGPT
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int x = 0, y = n / 2;
    magicSquare[x][y] = 1;

    for (int k = 2; k <= n * n; k++) {
        int newX = (x - 1 + n) % n;
        int newY = (y + 1) % n;     //令人惊讶的算法！

        if (magicSquare[newX][newY] == 0) {
            x = newX;
            y = newY;
        } else {
            x = (x + 1) % n;
        }

        magicSquare[x][y] = k;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}