#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* [백준 2981: 검문]
 * A, B, C를 M으로 나눴을 때의 나머지가 모두 같을 때, 이 나머지 값을 K라 하면
 * A = M * a + K, B = M * b + K, C = M * c + K 이므로
 * B - A = (M * b + K) - (M * a + K) = M(b - a)
 * C - B = (M * c + K) - (M * b + K) = M(c - b)
 * 즉, 우리가 구해야 하는 M은 각 검문소 사이 간격 간의 모든 공약수!
 * 
 * 1. 검문소 사이 간격 간의 최대공약수 구하기
 * 2. 1에서 구한 최대공약수의 모든 약수 구하기
 *    (모든 약수를 구할 때 시간초과 주의!)
 */

int getGcdRecur(int a, int b) {
    if(b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

vector<int> findM(vector<int> &nums) { // m에 해당하는 수 집합 리턴하는 함수
    vector<int> m;

    // 두 수 사이 간격의 최대공약수 구하기
    int gcd = nums[1] - nums[0];
    for(int i = 2; i < nums.size(); i++) {
        gcd = getGcdRecur(max(gcd, nums[i] - nums[i-1]), min(gcd, nums[i] - nums[i-1]));
    }

    // 공약수 구하기: 공약수는 최대공약수의 약수
    for(int i = 2; i <= gcd/2; i++) {
        if(gcd % i == 0) {
            m.push_back(i);
        }
    }
    m.push_back(gcd);

    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    vector<int> m = findM(nums);

    for(int i : m) {
        cout << i << " ";
    }

    return 0;
}