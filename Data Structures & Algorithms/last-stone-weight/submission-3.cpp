class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {

        if(stones.size()==1) return stones[0];
        if(stones.size()==0) return 0;
        priority_queue<int> pq(stones.begin(),stones.end());

        // for (int& st : stones) {
        //     pq.push(st);
        // }
        int x, y;
        while (!pq.empty() ||pq.size()==1) {
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();
            if (y != x) {
                pq.push(y - x);
            }
            if(pq.size()==1 ||pq.size()==0){
                break;
            }
        }
if(pq.size()==1)return pq.top();
        return y-x;
    }
};
