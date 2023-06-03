#include <string>
#include <vector>
#include <iostream>

using namespace std;

void increase(int n, vector<int> &num)
{
    int i = 0;
    num[i]++;
    for(; i < num.size(); i++)
    {
        if (num[i] == n)
        {
            num[i] = 0;
            if (i != num.size() - 1)
            {
                num[i + 1]++;
            }
            else
            {
                num.push_back(1);
            }    
        }
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string num_list = "";
    vector<int> num(1);
    int count = 1;
    while (answer.length() < t)
    {
        for (auto rit = num.rbegin(); rit != num.rend(); rit++)
        {
            string str;
            if (*rit > 9)
            {
                char ch = 'A' + (*rit) - 10;
                str += ch;
            }
            else
            {
                str = to_string(*rit);
            }
            cout<<str<<" ";
            num_list += str;
        }
        increase(n, num);
        
        if (num_list.length() > count * m)
        {
            answer += num_list[(count - 1) * m + p - 1];
            count++;
        }
    }
    
    
    return answer;
}