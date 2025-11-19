class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1, st2;
        for(int i=0;i<nums1.size();i++){
            st1.insert(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }

        set<int> st;
        for(int i=0;i<nums1.size();i++){
            if(st2.find(nums1[i]) != st2.end()){
                st.insert(nums1[i]);
            }
        }
        vector<int> v;
        for(auto x : st){
            v.push_back(x);
        }
        return v;
    }
};