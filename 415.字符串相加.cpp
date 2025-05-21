/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        str.reserve(max(num1.size(),num2.size())+1);
        int carry=0;
        int end1=num1.size()-1,end2=num2.size()-1;
        
        while(end1>=0||end2>=0)
        {
            int x1=end1>=0?num1[end1--]-'0':0;
            int x2=end2>=0?num2[end2--]-'0':0;

            int val=x1+x2+carry;
            carry=val/10;
            val=val%10;

            str+=('0'+val);
        }

        if(carry==1)
        {
            str+='1';
        }
        reverse(str.begin(),str.end());

        return str;
    }
};
// @lc code=end

