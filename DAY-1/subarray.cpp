#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();

        // Outer loop for the start index of the subarray
        for (int i = 0; i < n; i++)
        {
            // Inner loop for the end index of the subarray
            for (int j = i; j < n; j++)
            {
                bool ok = true; // Flag to check if subarray is increasing
                int lst = -1;   // Variable to keep track of the last element

                // Loop to check each element within or outside the subarray
                for (int k = 0; k < n; k++)
                {
                    if (k >= i && k <= j)
                    {
                        // Elements within the subarray are skipped
                    }
                    else
                    {
                        ok &= (lst < nums[k]); // Check if the current element is greater than the last one
                        lst = nums[k];         // Update the last element
                    }
                }

                ans += ok; // Increment count if the subarray is "incremovable"
            }
        }
        return ans; // Return the total count of "incremovable" subarrays
    }
};

// check out this optimised solution and next time implement this way

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
       int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
        {
            return 3;
        }

        long ans = 1; // removing all would be a solution

        // left increasing
        int left = 0;
        while (left < n - 1 && nums[left] < nums[left + 1])
        {
            left++;
        }
        ans += left + 1l;

        // right increasing
        int right = n - 1;
        while (right > 0 && nums[right - 1] < nums[right])
        {
            right--;
        }
        ans += n - right;

        // if all are increasing
        if (left >= right)
        {
            return ((n) * (n + 1)) / 2l;
        }

        left = 0;
        // middle handling
        while (left < right && right < n)
        {
            if (nums[left] < nums[right])
            {
                ans += right == n - 1 ? 1l : (long)(n - right);
                if (left < n - 1 && nums[left] < nums[left + 1])
                    left++;
                else
                    break;
            }
            else
            {
                right++;
            }
        }

        return ans;
    }
};