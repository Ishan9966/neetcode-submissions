class KthLargest {
    int K;
        priority_queue<int,vector<int>,greater<int>> p;

public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        priority_queue<int,vector<int>,greater<int>> pq=p;;
        for(int &num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        p=pq;
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>K){
            p.pop();
        }
        return p.top();
    }
};
