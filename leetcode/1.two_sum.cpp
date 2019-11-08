#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v(2);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    v[0] = i;
                    v[1] = j;
                }
            }
        }
        return v;
    }
};
int main()
{

    int nums[4] = {2, 7, 11, 15};
    vector<int> c(nums, nums + 4);

    int target = 17;
    Solution A;
    vector<int> d = A.twoSum(c, target);

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << endl;
    }
    return 0;
}
