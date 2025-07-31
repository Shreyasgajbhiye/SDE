class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;

        stringstream ss(version1);
        string token;
        while (getline(ss, token, '.')) {
            v1.push_back(token);
        }

        stringstream ss2(version2);
        while (getline(ss2, token, '.')) {
            v2.push_back(token);
        }

        
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int num1 = (i < v1.size()) ? stoi(v1[i]) : 0;
            int num2 = (i < v2.size()) ? stoi(v2[i]) : 0;

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }

        return 0;
    }
};