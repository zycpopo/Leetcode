using namespace std;
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        dfs(A,B,C,A.size());
    }
        void dfs(vector<int>& A, vector<int>& B, vector<int>& C,int n)
        {
            if(n==1)
            {
                C.push_back(A.back());
                A.pop_back();
                return;
            }

            dfs(A,C,B,n-1);
            C.push_back(A.back());
            A.pop_back();
            dfs(B,A,C,n-1);    
        }
    
};