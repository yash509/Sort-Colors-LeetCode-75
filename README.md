# 75. Sort Colors – LeetCode Solution

**Problem Link:** [https://leetcode.com/problems/sort-colors/](https://leetcode.com/problems/sort-colors/)

## Problem Statement

Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We use the integers `0`, `1`, and `2` to represent the color red, white, and blue respectively.

You must solve this problem **without** using the library's sort function.

### Example 1

Input:  nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

### Example 2

Input:  nums = [2,0,1]
Output: [0,1,2]


## Approach: Dutch National Flag Algorithm

We use three pointers:

- `low`  → next position to place a `0`
- `mid`  → current element being examined
- `high` → next position to place a `2`

### Logic
- If `nums[mid] == 0` → swap with `low`, increment both `low` and `mid`
- If `nums[mid] == 1` → just increment `mid`
- If `nums[mid] == 2` → swap with `high`, decrement `high` (do **not** increment `mid`)

This partitions the array into three sections in a single pass.

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
