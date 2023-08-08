#include <iostream>
#include <queue>
using namespace std;

// 중간값을 찾기 위해 현재까지 입력된 숫자중 비교적 작은 값과 큰 값을 따로 저장하기
// max heap의 top이 중간값 -> max heap과 min heap의 크기 차 1이하 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    priority_queue<int> max_heap; // 작은 값들을 저장하는 max heap
    priority_queue<int, vector<int>, greater<int>> min_heap; // 큰 값들을 저장하는 min heap

    int N;
    cin >> N;

    int med; // 중간값

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (max_heap.empty() || a <= max_heap.top()) {
            max_heap.push(a);
        } else {
            min_heap.push(a);
        }

        // max_heap와 min_heap의 크기 차이를 최대 1로 유지하도록 조정
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        // 중간값 출력
        if (max_heap.size() > min_heap.size()) {
            med = max_heap.top();
        } else {
            med = min(max_heap.top(), min_heap.top());
        }
        cout << med << "\n";
    }

    return 0;
}
