class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a map to store the indices of the elements in the array
        unordered_map<int, int> numsMap;
        
        // Loop through the array and store each element and its index in the map
        for (int i = 0; i < nums.size(); i++) {
            numsMap[nums[i]] = i;
        }
        
        // Loop through the array again
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement of the current element
            int complement = target - nums[i];
            
            // If the complement exists in the map and it's not the same element as the current one
            if (numsMap.count(complement) && numsMap[complement] != i) {
                // Return the indices of the two elements
                return {i, numsMap[complement]};
            }
        }
        
        // If no valid pair was found, return an empty vector
        return {};
    }
};
