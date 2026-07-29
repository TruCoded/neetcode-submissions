class Solution {
public:
int daysreq(vector <int> &weights,int cap){
    int day=1,load=0;
    for(int i=0;i<=weights.size()-1;i++){
        if(load+weights[i]>cap){
            day=day+1;
            load=weights[i];
        }
        else load+=weights[i];
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
int low=*max_element(weights.begin(),weights.end());
int high=accumulate(weights.begin(),weights.end(),0);
while(low<=high){
    int mid=(low+high)/2;
    int noOfdays=daysreq(weights,mid);
    if(noOfdays<=days) high=mid-1;
    else low=mid+1;
}
return low;    
    }
};