class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> temp;
        string n = "";
        for(int i=0;i<s.size();i++)
        {
            if(temp.empty())
                temp.push(s[i]);
            else if(s[i] == temp.top())
                temp.pop();
            else
                temp.push(s[i]);
        }
        while(!temp.empty())
        {
            n += temp.top();
            temp.pop();

        }
        reverse(n.begin(),n.end());
        return n;
    }
};
