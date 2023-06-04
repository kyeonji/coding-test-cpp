#include <string>
#include <vector>
#include <algorithm>

// priority queue 사용
// 자동 정렬 됨 (default: 큰 값이 top)
// push, pop, empty, top
#include <queue>

using namespace std;

long long mix(long long s1, long long s2)
{
    return s1 + (s2 * 2);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // priority_queue<int> pq(scoville.begin(), scoville.end());
    // 아래와 같이 정의하면, 작은 값이 top으로 가게 할 수 있다. 
    // vector로 생성 가능
    // vector로 효율성 통과 못할 경우, 다른 구조체를 사용해보자.
    priority_queue <int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    // while 모두 K 이상? -1인 경우는 언제 판단되지? -> 하나 남았을 때 K 이하
    while(pq.top() < K && pq.size() > 1)
    {
        // 가장 낮은 두 음식 뽑기
        auto s1 = pq.top();
        pq.pop();
        
        auto s2 = pq.top();
        pq.pop();
        
        answer++;
        
        // mix, 새로운 음식 배열
        pq.push(mix(s1, s2));
        
        // 재정렬 -> priority queue 사용시 필요 없음
        // sort(l_scoville.begin(), l_scoville.end());
    }
    
    if (pq.top() >= K)
    {
        return answer;
    }
    else
    {
        return -1;
    }
    
}

int main()
{
    return -1;
}