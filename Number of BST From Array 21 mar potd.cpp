class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
       
        vector<long long> cat(n + 1, 0);
        cat[0] = 1;  
        if (n >= 1) cat[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cat[i] += cat[j] * cat[i - 1 - j];
            }
        }
        
       
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int L = 0, R = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) L++;
                else if (arr[j] > arr[i]) R++;
            }
            result.push_back((int)(cat[L] * cat[R]));
        }
        
        return result;
    }
};
