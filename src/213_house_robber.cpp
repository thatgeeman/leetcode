/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution
{

public:
    int rob_all(vector<int> &nums)
    {
        int rob1 = 0;
        int rob2 = 0;
        int current_rob = 0;
        for (int money : nums)
        {
            current_rob = max(money + rob1, rob2);
            rob1 = rob2;
            rob2 = current_rob;
        }

        return current_rob;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        // sel;ect subset of the nums to avoid edges
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        return max(rob_all(nums1), rob_all(nums2));
    }

    void checkResult(vector<int> &results, vector<int> &answers)
    // checks if the answer is correct
    {
        int count = 0;
        if (results.size() != answers.size())
        {
            cout << "Sizes do not match" << endl;
        }

        for (int i = 0; i < results.size(); i++)
        {
            if (results[i] == answers[i])
            {
                count++;
                cout << "Test " << i << " passed: " << results[i] << " == " << answers[i] << endl;
            }
            else
            {
                cout << "Test " << i << " failed: " << results[i] << " != " << answers[i] << endl;
            }
        }

        cout << count << "/" << answers.size() << " tests passed" << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> questions{
        {2, 3, 2},
        {1, 2, 3, 1},
        {1, 2, 3},
        {1},
        {200, 3, 140, 20, 10},
        {1, 3, 1, 3, 100}};

    vector<int> answers{
        3,
        4,
        3,
        1,
        340,
        103,

    };
    vector<int> results(answers.size(), 0);
    Solution s;
    // check for all questions
    for (int i = 0; i < answers.size(); i++)
    {
        cout << "Problem " << i << endl;
        results[i] = s.rob(questions[i]);
    }
    cout << "All questions complete" << endl;
    s.checkResult(results, answers);

    return 0;
}
