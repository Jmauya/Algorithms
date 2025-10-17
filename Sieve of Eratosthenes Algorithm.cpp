#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
bool status[MAXN + 1];

void siv(int N) {
    status[0] = status[1] = true; // 0 and 1 are not prime

    for (int i = 4; i <= N; i += 2) {
        status[i] = true; // mark even numbers as non-prime
    }

    int sq = sqrt(N);
    for (int i = 3; i <= sq; i += 2) {
        if (!status[i]) {
            for (int j = i * i; j <= N; j += i) {
                status[j] = true; // mark multiples of i as non-prime
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    siv(N);

    cout << "Primes up to " << N << ":\n";
    for (int i = 2; i <= N; ++i) {
        if (!status[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
