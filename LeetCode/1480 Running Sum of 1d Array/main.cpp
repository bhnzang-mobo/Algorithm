#include <stdio.h>
#include <vector>


using namespace std;

vector<int> nums;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int len = nums.size();
        vector<int> ret(len);
        ret[0]=nums[0];
        for(int i = 1 ; i < len; i ++){
            ret[i]=ret[i-1]+nums[i];
        }

        return ret;
    }
};

void init(){
    freopen("input.txt","r",stdin);
}
int main(){
    Solution sln;
    sln.runningSum(nums);
}