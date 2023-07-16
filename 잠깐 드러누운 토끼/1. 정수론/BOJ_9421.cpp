#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 999999;

// 에라토스테네스의 체 -> 소수 판단 
vector<bool> getPrimes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

// 자리수 별로 제곱의 합 구하는 함수 
int GetSum(int n) {
    int sum = 0, digit;
    while (n > 0) {
        digit = n % 10;
        n = n / 10;
        sum = sum + digit * digit;
    }
    return sum;
}

// 상근수인지 판단 
bool check(int n) {
    vector<int> visited(500, 0);
    while (n != 1) {
        int sum = GetSum(n);
        if (visited[sum]) {
            return false;
        }
        visited[sum] = 1;
        n = sum;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<bool> is_prime = getPrimes(n);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && check(i)) { // 소수이면서 상근수이면
            cout << i << "\n";
        }
    }

    return 0;
}
