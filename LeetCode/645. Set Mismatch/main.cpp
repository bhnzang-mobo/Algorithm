#include <stdio.h>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        int even = 0;
        for(int i = 0 ; i < n ; i ++){
            if(i%2==0){
                even ^= i;
            }
            else{
                odd ^= i;
            }
        }
        for(int i = 0 ; i < n ; i ++){
            if(nums[i]%2==0){
                even ^= nums[i];
            }
            else{
                odd ^= nums[i];
            }
        }
        //Now, one of two (odd, even) is duplicate numb, and the other is missing numb
        for (int i = 0 ; i < n ; i ++){
            if(nums[i]==even) return {even, odd};
        }
        return {odd, even};
    }
};

vector<int> init(){
    freopen("input.txt","r",stdin);
    int i;
    vector<int> ret;
    while(scanf("%d ",&i)!=EOF){                          
        ret.push_back(i);
    }
    return ret;
}

int main(){
    vector<int> t = init();
    Solution sl;
    sl.findErrorNums(t);
    return 0;
}