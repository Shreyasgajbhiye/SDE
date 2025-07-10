class Solution {
public:
    vector<int> getLeft( vector<int> h, int n){
        vector<int> v(n);
        v[0] = h[0];
        for(int i=1;i<h.size();i++){
            v[i] = max(h[i], v[i-1]);
        }
        return v;
    }

    vector<int> getRight( vector<int> h, int n){
        vector<int> v(n);
        v[n-1] = h[n-1];
        for(int i=v.size()-2;i>=0;i--){
            v[i] = max(h[i], v[i+1]);
        }
        return v;
    }
    int trap(vector<int>& height) {
        // int left = 0;
        // int right = height.size() - 1;
        // int leftMax = height[left];
        // int rightMax = height[right];
        // int water = 0;

        // while (left < right) {
        //     if (leftMax < rightMax) {
        //         left++;
        //         leftMax = max(leftMax, height[left]);
        //         water += leftMax - height[left];
        //     } else {
        //         right--;
        //         rightMax = max(rightMax, height[right]);
        //         water += rightMax - height[right];
        //     }
        // }

        // return water;


        // better
        vector<int> left(height.size());
        vector<int> right(height.size());   
        right[height.size()-1] = height[height.size()-1] ;

        left = getLeft(height, height.size());
        right = getRight(height,height.size());
        int sum = 0;
        for(int i=0;i<height.size();i++){
            int h = min(left[i], right[i]) - height[i];
            sum+=h;
        }
        return sum;
    }
};