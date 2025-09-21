/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */

// @lc code=start

//暴力解法
/*class Solution {
public:
    int f(string str)
    {
        int hash[26]={0};
        for(int i=0;i<str.size();i++)
        {
            hash[str[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0) return hash[i];
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer;

        int n=words.size();

        for(int i=0;i<queries.size();i++)
        {
            int count=0;
            int freq_query = f(queries[i]);  // 优化：只算一次
            
            for (int j = 0; j < n; j++) 
            {
                int freq_word = f(words[j]);  // 可优化：预计算 words 的 f 值
                if (freq_query < freq_word) {
                    count++;
                }
            }
            answer.push_back(count);
        }

        return answer;
    }
};*/


//预计算+二分查找
/*class Solution {
    int func(string str){//f 函数实现利用 map 集合的有序性
        map<char,int>m;
        for(char c:str){
            m[c]++;
        }
        auto it=m.begin();
        return it->second;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        vector<int>w;
        for(int i=0;i<words.size();i++){
            w.push_back(func(words[i]));
        }
        ranges::sort(w);//排序
        for(int i=0;i<queries.size();i++){
            int q=func(queries[i]);
            ans.push_back(w.end()-ranges::upper_bound(w,q));//指针运算
        }
        return ans;
    }
};*/

// @lc code=end

