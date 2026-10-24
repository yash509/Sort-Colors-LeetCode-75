/*
 * Problem: 75. Sort Colors
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-colors/
 *
 * Approach: Dutch National Flag Algorithm (Three Pointers)
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>   // for std::swap
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;                  // boundary for 0s
        int mid = 0;                  // current element
        int high = nums.size() - 1;   // boundary for 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
                // mid is not incremented because the swapped element needs to be checked
            }
        }
    }
};
