/*
Medium
Topics
Companies
Hint
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{

public:
    int maxArea(vector<int> &height)
    {

        int n = height.size();
        int max_area = 0;
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int width = abs(left - right);
            int h_left = height[left];
            int h_right = height[right];
            // cout << "left: " << left << " right: " << right << " width: " << width << " h_left: " << h_left << " h_right: " << h_right << endl;
            int area = h_right < h_left ? h_right * width : h_left * width; // take the smaller height
            // cout << " area: " << area << endl;
            max_area = max(area, max_area);
            // cout << " max_area: " << max_area << endl;
            if (h_right > h_left)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }

        return max_area;
    }

    void checkResult(vector<int> &results, vector<int> &answers)
    // checks if the answer is correct
    {
        int correct = 0;
        if (results.size() != answers.size())
        {
            cout << "Sizes do not match" << endl;
        }

        for (int i = 0; i < results.size(); i++)
        {
            if (results[i] == answers[i])
            {
                correct++;
                cout << "Test " << i << " passed: " << results[i] << " == " << answers[i] << endl;
            }
            else
            {
                cout << "Test " << i << " failed: " << results[i] << " != " << answers[i] << endl;
            }
        }

        cout << correct << "/" << answers.size() << " tests passed" << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> questions{
        {1, 8, 6, 2, 5, 4, 8, 3, 7},
        {1, 1},
        {4, 3, 2, 1, 4},
        {1, 2, 1},
        {2, 1, 2},
        {1, 2}};
    vector<int> answers{
        49,
        1,
        16,
        2,
        4,
        1};
    vector<int> results(answers.size(), 0);
    Solution s;
    // check for all questions
    for (int i = 0; i < answers.size(); i++)
    {
        cout << "Problem " << i << endl;
        results[i] = s.maxArea(questions[i]);
    }
    cout << "All questions complete" << endl;
    s.checkResult(results, answers);

    return 0;
}
