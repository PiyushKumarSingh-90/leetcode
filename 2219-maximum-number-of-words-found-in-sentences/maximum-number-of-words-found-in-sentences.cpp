class Solution 
{
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int a=0;


        for(int i=0;i<sentences.size();i++)
        {
            int count=0;

            for(int j=0;j<sentences[i].length();j++)
            {
            
                if(sentences[i][j]==' ')
                {
                    count++;
                }
            }
            if(count >= a)
            {
                a=count+1;

            }
        }

        return a;
    }
};