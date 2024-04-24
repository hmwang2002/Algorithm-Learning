/**
 * 对应leetcode 34 查找元素的第一个位置和最后一个位置
 * 要求nums是非递减的，即nums[i] <= nums[i + 1]
 * 
 * lower_bound函数
 * 返回最小的满足nums[i] >= target 的i
 * 如果不存在，返回len(nums)
 * 
*/
#include <vector>

using namespace std;

class Solution
{
    // lower_bound 返回最小的满足 nums[i] >= target 的 i
    // 如果数组为空，或者所有数都 < target，则返回 nums.size()
    // 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]

    // 闭区间写法
    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0, right = (int)nums.size() - 1; // 闭区间 [left, right]
        while (left <= right)
        { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            }
            else
            {
                right = mid - 1; // 范围缩小到 [left, mid-1]
            }
        }
        return left;
    }

    // 左闭右开区间写法
    int lower_bound2(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(); // 左闭右开区间 [left, right)
        while (left < right)
        { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1; // 范围缩小到 [mid+1, right)
            }
            else
            {
                right = mid; // 范围缩小到 [left, mid)
            }
        }
        return left; // 返回 left 还是 right 都行，因为循环结束后 left == right
    }

    // 开区间写法
    int lower_bound3(vector<int> &nums, int target)
    {
        int left = -1, right = nums.size(); // 开区间 (left, right)
        while (left + 1 < right)
        { // 区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid; // 范围缩小到 (mid, right)
            }
            else
            {
                right = mid; // 范围缩小到 (left, mid)
            }
            // 也可以这样写
            // (nums[mid] < target ? left : right) = mid;
        }
        return right;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = lower_bound(nums, target); // 使用其中一种写法即可
        if (start == nums.size() || nums[start] != target)
        {
            return {-1, -1}; // nums 中没有 target
        }
        // 如果 start 存在，那么 end 必定存在
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};