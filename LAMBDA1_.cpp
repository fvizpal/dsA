class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        auto dqToStr = [](const deque<int>& dq) -> string {
            string s;
            for(int num : dq) 
                s += to_string(num) + ",";
            return s;
        };
        
        auto check = [&](int mid) -> bool {
            unordered_set<string> set;
            deque<int> tmp;

            for(int i = 0; i < m; i++) {
                tmp.push_back(nums1[i]);
                if(tmp.size() > mid) tmp.pop_front();
                if(tmp.size() == mid) set.insert(dqToStr(tmp));
            }

            tmp.clear();
            for(int i = 0; i < n; i++) {
                tmp.push_back(nums2[i]);
                if(tmp.size() > mid) tmp.pop_front();
                if(
                    tmp.size() == mid && 
                    set.find(dqToStr(tmp)) 
                        != set.end()
                ) {
                    return true;
                }
            }

            return false;
        };

        int low = 0, high = min(m, n) + 1;
        while(low < high) {
            int mid = (low + high) >> 1;
            if(check(mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low - 1;
    }
};