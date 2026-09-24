class Solution {
public:
int count(vector<int>& arr,int pages){
    int s=1;
    long long pageS=0;
    for(int i=0;i<arr.size();i++){
        if(pageS+arr[i]<=pages){
            pageS+=arr[i];
        }else{
            s+=1;
            pageS=arr[i];
        }
    }
    return s;
}

int find(vector<int>& arr,int n,int m){
    if(m>n)return -1;

    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int s=count(arr,mid);
        if(s>m){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return find(nums,nums.size(),k);
    }
};