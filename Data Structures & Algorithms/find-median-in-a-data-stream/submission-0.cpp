class MedianFinder {
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.empty()||num<left.top()){
            left.push(num);
        }else{
            right.push(num);
        }

        if(abs((int)left.size()-(int)right.size())>1){
            right.push(left.top());
            left.pop();
        }else if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()>right.size())return left.top();
        return (double)(left.top()+right.top())/2;
    }
};
