class Solution {
public:
    void solve(vector<int>& arr,vector<int>&dummy, int index, int target,vector<vector<int>>&ans){
        if(index==arr.size()){
            if(target==0){
                ans.push_back(dummy);
            }
            return;
        }
        solve(arr,dummy,index+1,target,ans); // to not take
        if(arr[index]<=target){
            dummy.push_back(arr[index]); //to take
            solve(arr,dummy,index,target-arr[index],ans);
            dummy.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>dummy;
        int index=0;
        solve(arr,dummy,index,target,ans);
        return ans;
    }
};