#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long mix(long long s1, long long s2)
{
    return s1 + (s2 * 2);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //priority_queue<int> pq(scoville.begin(), scoville.end());
    priority_queue <int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    // while 모두 K 이상? -1인 경우는 언제 판단되지? -> 하나 남았을 때 K 이하
    while(pq.top() < K && pq.size() > 1)
    {
        // 가장 낮은 두 음식 뽑기, mix
        auto s1 = pq.top();
        pq.pop();
        
        auto s2 = pq.top();
        pq.pop();
        
        answer++;
        // 새로운 음식 배열
        pq.push(mix(s1, s2));
        // 재정렬
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