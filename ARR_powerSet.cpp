class solution{
    //the function;
    private:        // make sure to add answer vector by refrence
        void solve( vector<int> num, vector<int > output, int index, vector<vector<int>>& ans){
            //basse case
            if ( index >= nums.size()){
                ans.push_back(output);
                return;
            }
            //exclude
            solve( nums. output, index + 1, ans);

            //include
            int element = nums[index];
            output.push_back(element);
            solve(nums, output, index + 1, ans);
            
        }

    public:
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve ( nums, output, index , ans);
        return ans;
}