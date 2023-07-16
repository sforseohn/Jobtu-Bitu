#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}

vector<int> solution(int n, vector<int> &numbers) {
    vector<int> result;

    int gcd = numbers[1] - numbers[0];
    for (int i = 2; i < n; i++) {
        gcd = getGCD(gcd, numbers[i] - numbers[i - 1]);
    }

    for (int i = 2; i * 2 <= gcd; i++) {
        if (gcd % i == 0) {
            result.push_back(i);
        }
    }
    result.push_back(gcd);

    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);

    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    vector<int> result = solution(n, numbers);

    for(int i = 0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}