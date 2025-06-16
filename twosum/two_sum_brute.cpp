#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        vector<int> twoSum(vector<int> &nums, int target){
            
            for(int i = 0; i < nums.size(); i++){
                for(int j = i + 1; j < nums.size();j++ ){
                    if(nums[j] == target - nums[i]){
                        return {i,j};
                    }
                }
            }

            return {};
        }


};



int main(){

    vector<int> v = {1,2,3,4,5};
    solution test;
    vector<int> solution = test.twoSum(v,8);

    for(auto i : solution){
        cout << i << " ";
    };
}