/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    bool check(int* hash1,int* hash2)
    {
        for (int i = 0; i < 26; i++) {
            if (hash1[i] != hash2[i])
                return false;
        }   
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    int hash1[26]={0};
    int hash2[26]={0};
    for(int i=0;i<p.length();i++)
    {
        hash2[p[i]-'a']++;
    }
    for(int left=0,right=0;right<s.length();right++)
    {
        hash1[s[right]-'a']++;
        if(right-left+1>p.length())
        {
            hash1[s[left]-'a']--;
            left++;
        }
        if (right - left + 1 == p.length() && check(hash1, hash2)) {
            ret.push_back(left);
        }
    }
    return ret;
    }
};

//count记录有效匹配字符的个数（较优的解法）
/*vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    int hash1[26] = {0}, hash2[26] = {0};
    int m = p.size();

    for (auto ch : p) hash1[ch - 'a']++;

    int left = 0, count = 0;
    for (int right = 0; right < s.size(); right++) {
        char in = s[right];
        if (++hash2[in - 'a'] <= hash1[in - 'a']) count++;

        if (right - left + 1 > m) {
            char out = s[left++];
            if (hash2[out - 'a']-- <= hash1[out - 'a']) count--;
        }

        if (count == m) ret.push_back(left);
    }
    return ret;
}*/
// @lc code=end

