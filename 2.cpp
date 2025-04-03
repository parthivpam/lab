class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 

        int length = 1;
        int maxlength = 1; 

        
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]); 
                }
            }
        }

        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {  
                length++;
                maxlength = max(maxlength, length);  
            } else if (nums[i] != nums[i - 1]) { 
                length = 1;
            }
        }

        return maxlength; 
    }
};