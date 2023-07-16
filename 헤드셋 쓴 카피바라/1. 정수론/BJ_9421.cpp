#include "vector"
#include "iostream"
#include "cmath"
#include "set"

using namespace std;

void isPrime(int n, vector<bool> &is_prime){
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<= sqrt(n); i++){
        if(is_prime[i]){
            for(int j= i*i; j<= n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int getSum(int n) {
    int total = 0, tmp;
    while (n != 0) {
        tmp = n % 10;
        n /= 10;
        total += tmp * tmp;
    }
    return total;
}

bool getHappyNumber(int n){
    set<int> visited;
    visited.insert(n);

    while(true){
        n = getSum(n);
        if (n == 1){
            return true;
        }
        if(visited.find(n) != visited.end()){
            return false;
        }
        visited.insert(n);
    }
}

void isAnswer(int n, vector<bool> &is_answer){
    for(int i=2; i<=n; i++){
        if(is_answer[i]){
            is_answer[i] = getHappyNumber(i);
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<bool> is_prime(n+1, true);
    isPrime(n, is_prime);
    isAnswer(n, is_prime);

    for(int i=2; i<is_prime.size(); i++){
        if(is_prime[i]){
            cout << i << " ";
        }
    }
}