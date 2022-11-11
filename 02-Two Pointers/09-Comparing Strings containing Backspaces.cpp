class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int index1 =s.length()-1;
        int index2 =t.length()-1;
      while(index1 >= 0 || index2 >= 0)
      {
        int i1=(checkBackspace(s,index1));
        int i2=(checkBackspace(t,index2));
        if(i1 <0 && i2 < 0)
        {
            return true;
        }
        if(i1 <0 || i2 < 0)
        {
            return false;
        }
        if(s[i1] != t[i2])
        {
            return false;
        }
        index1 = i1-1;
        index2 = i2-1;
      }
      return true;
    }
private:
    static int checkBackspace(const string & str , int index)
    {
        int backspaceCount = 0;
        while(index >=0)
        {
        if(str[index] == '#')
        {
            backspaceCount++;
        }
        else if (backspaceCount > 0)
        {
            backspaceCount--;
        }
        else
        {
            break;
        }
        index--;
        }
        return index;
    }

};
