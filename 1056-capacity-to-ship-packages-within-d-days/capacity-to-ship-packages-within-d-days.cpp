class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int min_cap=0;
        int max_cap=0;
        for(int weight:weights)
        {
            min_cap=max(min_cap,weight);
            max_cap+=weight;
        }

        while(min_cap<max_cap)
        {
            int mid=min_cap+(max_cap-min_cap)/2;
            int days=1,sum=0;
            for(int weight:weights)
            {
                if(sum+weight>mid)
                {
                    days++;
                    sum=0;
                }
                sum+=weight;
            }
            if(days>D)
            {
                min_cap=mid+1;
            }
            else {
                max_cap=mid;
            }

        }
        return min_cap;
    }
};