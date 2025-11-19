class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
         int left= 0;
         int top = 0;
         int right = arr[0].size()-1;
        int bottom = arr.size()-1;
        vector<int> v;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                v.push_back(arr[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                v.push_back(arr[i][right]);
            }
            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    v.push_back(arr[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i=bottom;i>=top;i--){
                    v.push_back(arr[i][left]);
                }
            }
            left++;
        }
        return v;
    }
};