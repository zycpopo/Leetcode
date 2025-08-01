/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size()<t.size()) return "";
        if(s.size()==t.size()&&s==t) return s;

        int count=0;
        int count2=0;
        int max=-1,maxlen=INT_MAX;
        int hash1[128]={};
        int hash2[128]={};
        for(auto e:t){
            hash2[e-'A']++;
        }
        for(int i = 0; i < 128; i++) {
            if(hash2[i] > 0) count2++;
        }

        for(int left=0,right=0;right<s.size();right++)
        {
            hash1[s[right]-'A']++;
            if(hash1[s[right]-'A']==hash2[s[right]-'A']) count++;

            while(left<=right && count==count2){
                if(right-left+1 < maxlen)
                {
                    maxlen=right-left+1;
                    max=left;
                }
                hash1[s[left]-'A']--;
                if(hash1[s[left]-'A']<hash2[s[left]-'A']) count--;
                
                left++;
            }
        }
        return maxlen==INT_MAX?"":s.substr(max,maxlen);
    }
};

//更健壮的版本
/*// 函数功能：在字符串 s 中找到包含字符串 t 所有字符的最小窗口子串
string minWindow(string s, string t) {
    // hash1 数组用于统计字符串 t 中每个 ASCII 字符（范围 0 - 127）的频次，初始化为 0
    int hash1[128] = {0}; 
    // kinds 用于统计 t 中“有效不同字符”的种类数（即频次从 0 变为 1 时计数）
    int kinds = 0; 
    // 遍历字符串 t，统计每个字符的频次，同时统计有效字符种类
    for(auto ch : t) {
        // 如果当前字符在 hash1 中的频次是 0，说明是新的有效字符种类，kinds 加 1
        if(hash1[ch]++ == 0) kinds++; 
    }
    // hash2 数组用于统计滑动窗口中每个 ASCII 字符的频次，初始化为 0
    int hash2[128] = {0}; 

    // minlen 记录最小窗口的长度，初始设为 INT_MAX（一个很大的值，代表初始未找到有效窗口）
    // begin 记录最小窗口在 s 中的起始索引，初始为 -1 表示未找到
    int minlen = INT_MAX, begin = -1; 
    // left 是滑动窗口的左边界，right 是右边界，count 用于记录当前窗口中满足 t 字符频次要求的字符种类数
    for(int left = 0, right = 0, count = 0; right < s.size(); right++) { 
        // 当前右边界对应的字符
        char in = s[right]; 
        // 将字符 in 加入窗口，hash2 中其频次加 1。若加 1 后频次等于 hash1 中该字符的频次，
        // 说明该字符在窗口中的频次刚好满足 t 中的需求，count 加 1（代表一种字符已满足）
        if(++hash2[in] == hash1[in]) count++; 
        // 当 count 等于 kinds 时，说明当前窗口包含了 t 中所有种类的字符，开始尝试缩小左边界找最小窗口
        while(count == kinds) { 
            // 计算当前窗口的长度，若比已记录的 minlen 小，更新 minlen 和 begin
            if(right - left + 1 < minlen) { 
                minlen = right - left + 1;
                begin = left;
            }
            // 要移出窗口的左边界字符
            char out = s[left++]; 
            // 将字符 out 移出窗口，hash2 中其频次减 1。若减 1 后频次比 hash1 中该字符的频次小，
            // 说明该字符在窗口中的频次不再满足 t 中的需求，count 减 1（代表一种字符不满足了）
            if(hash2[out]-- == hash1[out]) count--; 
        }
    }
    // 如果 begin 还是 -1，说明没找到符合条件的窗口，返回空字符串；否则返回从 begin 开始，长度为 minlen 的子串
    if(begin == -1) return ""; 
    else return s.substr(begin, minlen); 
}*/
// @lc code=end

