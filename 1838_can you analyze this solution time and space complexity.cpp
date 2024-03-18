class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int res = 1, n = nums.size();
        long long cursum = 0;
        while(right<n){
            cursum += nums[right];
            while((long long)(right-left+1)*nums[right]-cursum > k && left < right){
                cursum -= nums[left];
                left++;
            }

            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};
