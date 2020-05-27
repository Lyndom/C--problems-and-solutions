/*
49 丑数
优先队列解法
https://www.cnblogs.com/wmyskxz/p/9301021.html
*/
typedef long long LL;
const int coeff[3] = {2, 3, 5};

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<LL , vector<LL>, greater<LL>> pq;
        set<LL> s;
        pq.push(1);
        s.insert(1);
        int i = 1;
        LL x,x2;
        while(true)
        {
            x = pq.top();
            pq.pop();
            if(i == n)
            {
                return (int)x;
            }
            for(int j = 0; j < 3; j++)
            {
                x2 = x * coeff[j];

                if(!s.count(x2)){
                    s.insert(x2);
                    pq.push(x2);
                }
            }
            i++;
        }
        return 0;
    }
};