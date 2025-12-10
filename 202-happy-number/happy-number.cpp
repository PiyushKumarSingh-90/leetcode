class Solution 
{
public:
    bool isHappy(int n) 
    {
        if(n==1) return true;

        if(n<5 && n != 1) return false;

        int z = 0;

        while(n>0)
        {
            z += pow( n%10 , 2 );
            n = n/10;
        }

        return isHappy(z);
    }
};