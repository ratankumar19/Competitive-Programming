#include<cmath>
int balancedBTs(int h) {
     int z=pow(10,9)+7;

    if(h==1 || h==0)
        return 1;
    else
    {
        int x=balancedBTs(h-1);
        int y=balancedBTs(h-2);
           long res1 = (long)x*x;
	        long res2 = (long)x*y*2;
        int ans1=(int)(res1%z);
        int ans2=(int)(res2%z);
        int ans=(ans1+ans2)%z;
        return ans;
    }
}
