class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,maxwater=0,ht=0,w=0;
        while(l<r)
        {
            w=r-l;
            ht=min(height[l],height[r]);
           int currwater=w*ht;
            maxwater=max(maxwater,currwater);
            height[l] < height[r] ? l++:r--;
        }
        return maxwater;
    }
};