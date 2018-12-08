#include<cstdlib>
int islegal(int ix,int iy,int fx,int fy,int board[][8])
{
    int type=board[ix][iy];
    int var=type%2;

        if ((abs(fy-iy)==1 && fx-ix == 1 - 2*var))
        {
            return 1;

        }
        else if ((fx-ix==2*(1-2*var))&&abs(fy-iy)==2)
        {
            if (board[(fx+ix)/2][(fy+iy)/2]==1+var||(board[(fx+ix)/2][(fy+iy)/2])==3+var)
            {
                board[(fx+ix)/2][(fy+iy)/2]=0;
                return 2;
            }
            else return 0;
        }
    //}

    if(type==4||type==3)
    {
        if ((abs(fy-iy)==1&& abs(fx-ix) == 1))
        {
            return 1;

        }
        else if ((abs(fx-ix)==2)&&abs(fy-iy)==2)
        {
            if ((board[(fx+ix)/2][(fy+iy)/2])==1+var||(board[(fx+ix)/2][(fy+iy)/2]==3+var))
            {
                board[(fx+ix)/2][(fy+iy)/2]=0;
                return 2;
            }
            else return 0;
        }

    }
    else
        return 0;
}
