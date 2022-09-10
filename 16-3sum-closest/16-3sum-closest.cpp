class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        int ans,diff=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int low=i+1,high=nums.size()-1;
            while(low<high){
                int sum=nums[low]+nums[high]+nums[i];
                if(abs(target-sum)<diff)
                {
                    diff=abs(target-sum);
                    ans=sum;
                }
                
                if(sum<target)
                {
                    low++;
                }else if(sum>target){
                    high--;
                }else{
                    break;
                }
                
                
            }
        }
        
        return ans;
        
    }
};