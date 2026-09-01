class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi;
        vector<double> ans;

        auto balance = [&]() {
            while (lo.size() > hi.size() + 1) {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }

            while (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
        };

        auto add = [&](int x) {
            if (lo.empty() || x <= *lo.rbegin())
                lo.insert(x);
            else
                hi.insert(x);
            balance();
        };

        auto remove = [&](int x) {
            auto it = lo.find(x);
            if (it != lo.end())
                lo.erase(it);
            else
                hi.erase(hi.find(x));
            balance();
        };

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);

            if (i >= k)
                remove(nums[i - k]);

            if (i >= k - 1) {
                if (k % 2)
                    ans.push_back(*lo.rbegin());
                else
                    ans.push_back(((double)*lo.rbegin() + *hi.begin()) / 2);
            }
        }

        return ans;
    }
};
