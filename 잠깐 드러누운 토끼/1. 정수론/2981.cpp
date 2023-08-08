#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 최대공약수(GCD) 계산 함수: 유클리드 호제법 이용
int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int diff = abs(v[1] - v[0]);  // 첫 번째 수와 두 번째 수의 차이의 절댓값으로 초기화
    for (int i = 2; i < n; i++) {
        diff = getGCD(diff, abs(v[i] - v[i - 1]));  // 이전의 차이와 현재 수의 차이의 절댓값의 최대공약수 계산
    }

    for (int i = 2; i <= diff/2; i++) {
        // 중복되는 약수 제거
        if (diff % i == 0) {
            ans.push_back(i);
        }
    }
    ans.push_back(diff);
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
