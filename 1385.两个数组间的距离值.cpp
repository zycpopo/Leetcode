/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start
/*class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret=0;
        int cha=0;
        int n=arr1.size(),m=arr2.size();
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                cha=arr1[i]>arr2[j]?arr1[i]-arr2[j]:arr2[j]-arr1[i];
                if(cha<=d) 
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==0) ret++;
        }
        return ret;
    }
};*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        sort(arr2.begin(),arr2.end());

        for(int x:arr1)
        {
            auto it=lower_bound(arr2.begin(),arr2.end(),x-d);
            if(it==arr2.end()||*it>x+d)
            {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

