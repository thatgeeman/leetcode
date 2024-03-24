/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.



*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{

public:
    int findDuplicate(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i + 1] == nums[i])
            {
                return nums[i];
            }
        }
        return -1;
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
        {1, 3, 4, 2, 2},
        {3, 3, 3, 3},
        {3, 1, 3, 4, 2},
    };

    vector<int> answers{
        2,
        3,
        3};
    vector<int> results(answers.size(), 0);
    Solution s;
    // check for all questions
    for (int i = 0; i < answers.size(); i++)
    {
        results[i] = s.findDuplicate(questions[i]);
    }
    cout << "All questions complete" << endl;
    s.checkResult(results, answers);

    return 0;
}
