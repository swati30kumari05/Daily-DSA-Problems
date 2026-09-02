class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        bool r = false, c = false;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 0) {
                    if (i == 0) r = true;
                    if (j == 0) c = true;
                    a[0][j] = a[i][0] = 0;
                }
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (a[i][0] == 0 || a[0][j] == 0)
                    a[i][j] = 0;
        
        if (r) fill(a[0].begin(), a[0].end(), 0);
        if (c)
            for (auto &row : a) row[0] = 0;
    }
};
