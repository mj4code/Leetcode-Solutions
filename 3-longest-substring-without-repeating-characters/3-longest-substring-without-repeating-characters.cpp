class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.length()==0)
            return 0;
        map<char,int>m;
        
        int max_len=1;
        int curr_len=1;
        m[s[0]]=0;
        for(int i=1;i<s.length();i++)
        {
            if(m.find(s[i])==m.end() or i-curr_len>m[s[i]])
            {
                curr_len+=1;
                max_len=max(max_len,curr_len);
            }
            else
            {
                max_len=max(max_len,curr_len);
                curr_len=i-m[s[i]];
                //curr_len+=1;
                
            }
            m[s[i]]=i;
            
        }
        return max_len;
        
    }
};