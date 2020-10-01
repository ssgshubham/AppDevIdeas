# include<stdio.h>
# include<time.h>
# include<windows.h>
struct b
{
    char color;
    char quality;
    int display;
    int n;
};
struct player
{
    char name[50];
    int home;
    int closed;
};
void set_background_color(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
void set_color(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void draw_dice(int turn)
{
    int i,j;
    printf("\n");
    if(turn==1)
    {
        for(i=0;i<3;i++)
        {
            printf(" ");
            set_background_color(0,15);
            for(j=0;j<3;j++)
            {
                if(j==1&&i==1)
                    printf(" %c ",233);
                else
                    printf("   ");
                if(j==2)
                {
                    set_background_color(0,0);
                    set_color(0);
                    printf("e\n");
                }
            }
        }
    }
    else if(turn==2)
    {
        for(i=0;i<3;i++)
        {
            printf(" ");
            set_background_color(0,15);
            for(j=0;j<3;j++)
            {
                if((i==0&&j==0)||(i==2&&j==2))
                    printf(" %c ",233);
                else
                    printf("   ");
                if(j==2)
                {
                    set_background_color(0,0);
                    set_color(0);
                    printf("e\n");
                }
            }
        }
    }
    else if(turn==3)
    {
        for(i=0;i<3;i++)
        {
            printf(" ");
            set_background_color(0,15);
            for(j=0;j<3;j++)
            {
                if((i==0&&j==0)||(j==1&&i==1)||(i==2&&j==2))
                    printf(" %c ",233);
                else
                    printf("   ");
                if(j==2)
                {
                    set_background_color(0,0);
                    set_color(0);
                    printf("e\n");
                }
            }
        }
    }
    else if(turn==4)
    {
        for(i=0;i<3;i++)
        {
            printf(" ");
            set_background_color(0,15);
            for(j=0;j<3;j++)
            {
                if((i==0&&j==0)||(j==0&&i==2)||(i==0&&j==2)||(i==2&&j==2))
                    printf(" %c ",233);
                else
                    printf("   ");
                if(j==2)
                {
                    set_background_color(0,0);
                    set_color(0);
                    printf("e\n");
                }
            }
        }
    }
    else if(turn==5)
    {
        for(i=0;i<3;i++)
        {
            printf(" ");
            set_background_color(0,15);
            for(j=0;j<3;j++)
            {
                if((i==0&&j==0)||(j==1&&i==1)||(i==2&&j==2)||(i==2&&j==0)||(i==0&&j==2))
                    printf(" %c ",233);
                else
                    printf("   ");
                if(j==2)
                {
                    set_background_color(0,0);
                    set_color(0);
                    printf("e\n");
                }
            }
        }
    }
    else
    {
        for(i=0;i<3;i++)
        {
            printf(" ");
            for(j=0;j<3;j++)
            {
                set_background_color(0,15);
                if((i==0&&j==0)||(j==0&&i==2)||(i==0&&j==2)||(i==2&&j==2)||(i==1&&j==0)||(i==1&&j==2))
                    printf(" %c ",233);
                else
                    printf("   ");
                if(j==2)
                {
                    set_background_color(0,0);
                    set_color(0);
                    printf("e\n");
                }
            }
        }
    }
}
void print_during(struct b board[][15], struct player a[])
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(i==6&&j==1)
            {
                set_background_color(0,3);
                set_color(0);
                if(board[i][j].display!=0)
                    printf(" %d ",board[i][j].display);
                else
                    printf("   ");
            }
            else if(i==1&&j==8)
            {
                set_background_color(0,4);
                set_color(0);
                if(board[i][j].display!=0)
                    printf(" %d ",board[i][j].display);
                else
                    printf("   ");
            }
            else if(i==8&&j==13)
            {
                set_background_color(0,2);
                set_color(0);
                if(board[i][j].display!=0)
                    printf(" %d ",board[i][j].display);
                else
                    printf("   ");
            }
            else if(i==13&&j==6)
            {
                set_background_color(0,6);
                set_color(0);
                if(board[i][j].display!=0)
                    printf(" %d ",board[i][j].display);
                else
                    printf("   ");
            }
            else if(board[i][j].color=='G')
            {
                set_background_color(0,2);
                if(i==14&&j==9)
                {
                    set_color(0);
                    printf("%s",a[2].name);
                    j+=strlen(a[2].name)/3;
                    if(strlen(a[2].name)%3==1)
                        printf("  ");
                    else if(strlen(a[2].name)%3==2)
                        printf(" ");
                    else
                        printf("   ");
                }
                else if(((i==10&&j==10)||(i==10&&j==13)||(i==13&&j==10)||(i==13&&j==13))&&board[i][j].display!=0)
                {
                    set_background_color(0,14);
                    printf(" %d ",board[i][j].display);
                }
                else if(j>=9&&j<14&&i==7)
                {
                    set_background_color(0,10);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='R')
            {
                set_background_color(0,4);
                if(i==0&&j==9)
                {
                    set_color(0);
                    printf("%s",a[1].name);
                    j+=strlen(a[1].name)/3;
                    if(strlen(a[1].name)%3==1)
                        printf("  ");
                    else if(strlen(a[1].name)%3==2)
                        printf(" ");
                    else
                        printf("   ");
                }
                else if(((i==1&&j==10)||(i==1&&j==13)||(i==4&&j==10)||(i==4&&j==13))&&board[i][j].display!=0)
                {
                    set_background_color(0,14);
                    printf(" %d ",board[i][j].display);
                }
                else if(i>=0&&i<6&&j==7)
                {
                    set_background_color(0,12);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='B')
            {
                set_background_color(0,3);
                if(i==0&&j==0)
                {
                    set_color(0);
                    printf("%s",a[0].name);
                    j+=strlen(a[0].name)/3;
                    if(strlen(a[0].name)%3==2)
                        printf(" ");
                    else if(strlen(a[0].name)%3==1)
                        printf("  ");
                    else
                        printf("   ");
                }
                else if(((i==1&&j==1)||(i==1&&j==4)||(i==4&&j==1)||(i==4&&j==4))&&board[i][j].display!=0)
                {
                    set_background_color(0,14);
                    printf(" %d ",board[i][j].display);
                }
                else if(j>=0&&j<6&&i==7)
                {
                    set_background_color(0,1);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='Y')
            {
                set_background_color(0,6);
                if(i==14&&j==0)
                {
                    set_color(0);
                    printf("%s",a[3].name);
                    j+=strlen(a[3].name)/3;
                    if(strlen(a[3].name)%3==1)
                        printf("  ");
                    else if(strlen(a[3].name)%3==2)
                        printf(" ");
                    else
                        printf("   ");
                }
                else if(((i==10&&j==1)||(i==10&&j==4)||(i==13&&j==1)||(i==13&&j==4))&&board[i][j].display!=0)
                {
                    set_background_color(0,14);
                    printf(" %d ",board[i][j].display);
                }
                else if(i>=9&&i<14&&j==7)
                {
                    set_background_color(0,14);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='O')
            {
                set_background_color(0,5);
                printf("%c%c%c",178,178,178);
            }
            else
            {
                if((i+j)%2==0)
                {
                    set_background_color(0,7);
                }
                else
                {
                    set_background_color(0,15);
                }
                if(board[i][j].display!=0)
                {
                    if(board[i][j].color=='b')
                    {
                        set_color(3);
                        printf(" %d ",board[i][j].display);
                    }
                    else if(board[i][j].color=='r')
                    {
                        set_color(4);
                        printf(" %d ",board[i][j].display);
                    }
                    else if(board[i][j].color=='y')
                    {
                        set_color(6);
                        printf(" %d ",board[i][j].display);
                    }
                    else if(board[i][j].color=='g')
                    {
                        set_color(2);
                        printf(" %d ",board[i][j].display);
                    }
                }
                else
                {
                    if((i+j)%2==0)
                    {
                        set_background_color(0,7);
                        if(board[i][j].quality=='S')
                        {
                            if(board[i][j].display!=0)
                            {
                                if(board[i][j].color=='b')
                                {
                                    set_color(3);
                                    printf(" %d ",board[i][j].display);
                                }
                                else if(board[i][j].color=='r')
                                {
                                    set_color(4);
                                    printf(" %d ",board[i][j].display);
                                }
                                else if(board[i][j].color=='y')
                                {
                                    set_color(6);
                                    printf(" %d ",board[i][j].display);
                                }
                                else if(board[i][j].color=='g')
                                {
                                    set_color(2);
                                    printf(" %d ",board[i][j].display);
                                }
                            }
                            else
                            {
                                printf("%c%c%c",176,176,176);
                            }
                        }
                        else
                        {
                            printf("   ");
                        }
                    }
                    else
                    {
                        set_background_color(0,15);
                        if(board[i][j].quality=='S')
                        {
                            if(board[i][j].display!=0)
                            {
                                if(board[i][j].color=='b')
                                {
                                    set_color(3);
                                    printf(" %d ",board[i][j].display);
                                }
                                else if(board[i][j].color=='r')
                                {
                                    set_color(4);
                                    printf(" %d ",board[i][j].display);
                                }
                                else if(board[i][j].color=='y')
                                {
                                    set_color(6);
                                    printf(" %d ",board[i][j].display);
                                }
                                else if(board[i][j].color=='g')
                                {
                                    set_color(2);
                                    printf(" %d ",board[i][j].display);
                                }
                            }
                            else
                            {
                                printf("%c%c%c",176,176,176);
                            }
                        }
                        else
                        {
                            printf("   ");
                        }
                    }
                }
            }
            if(j==14)
            {
                set_background_color(0,0);
                printf("e");
            }
        }
        printf("\n");

    }
}
int main()
{
    struct b board[15][15];
    struct player a[4];
    set_color(3);
    printf("Player 1 Enter Name:");
    fflush(stdin);
    gets(a[0].name);
    set_color(4);
    printf("Player 2 Enter Name:");
    fflush(stdin);
    gets(a[1].name);
    set_color(2);
    printf("Player 3 Enter Name:");
    fflush(stdin);
    gets(a[2].name);
    set_color(6);
    printf("Player 4 Enter Name:");
    fflush(stdin);
    gets(a[3].name);
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            board[i][j].display=0;
        }
    }
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(i>=0&&i<6)
            {
                if(j>=0&&j<6)
                {
                    board[i][j].color='B';
                    board[i][j].quality='X';
                }
                else if(j>=9&&j<15)
                {
                    board[i][j].color='R';
                    board[i][j].quality='X';
                }
                else
                {
                    board[i][j].color='W';
                    board[i][j].quality='N';
                }
            }
            else if(i>=9&&i<15)
            {
                if(j>=0&&j<6)
                {
                    board[i][j].color='Y';
                    board[i][j].quality='X';
                }
                else if(j>=9&&j<15)
                {
                    board[i][j].color='G';
                    board[i][j].quality='X';
                }
                else
                {
                    board[i][j].color='W';
                    board[i][j].quality='N';
                }
            }
            else
            {
                board[i][j].color='W';
                board[i][j].quality='N';
            }
        }
    }
    for(i=1;i<6;i++)
    {
        board[7][i].color='B';
        board[7][14-i].color='G';
        board[i][7].color='R';
        board[14-i][7].color='Y';
    }
    board[6][1].quality='S';
    board[6][1].color='B';
    board[13][6].quality='S';
    board[13][6].color='Y';
    board[8][13].quality='S';
    board[8][13].color='G';
    board[1][8].quality='S';
    board[1][8].color='R';
    board[8][2].quality='S';
    board[6][12].quality='S';
    board[2][6].quality='S';
    board[12][8].quality='S';
    for(i=6;i<9;i++)
    {
        for(j=6;j<9;j++)
        {
            board[i][j].color='O';
            board[i][j].quality='H';
        }
    }
    int r,g,b,y;
    r=g=b=y=1;
    //for(i=1;i<=240;i++)
        //printf("%d->%c\n",i,i);
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {

            if(board[i][j].color=='G')
            {
                set_background_color(0,2);
                if(i==14&&j==9)
                {
                    set_color(0);
                    printf("%s",a[2].name);
                    j+=strlen(a[2].name)/3;
                    if(strlen(a[2].name)%3==1)
                        printf("  ");
                    else if(strlen(a[2].name)%3==2)
                        printf(" ");
                    else
                        printf("   ");
                }
                else if((i==10&&j==10)||(i==10&&j==13)||(i==13&&j==10)||(i==13&&j==13))
                {
                    set_background_color(0,14);
                    board[i][j].display=g;
                    printf(" %d ",g++);
                }
                else if(j>=9&&j<14&&i==7)
                {
                    set_background_color(0,10);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='R')
            {
                set_background_color(0,4);
                if(i==0&&j==9)
                {
                    set_color(0);
                    printf("%s",a[1].name);
                    j+=strlen(a[1].name)/3;
                    if(strlen(a[1].name)%3==1)
                        printf("  ");
                    else if(strlen(a[1].name)%3==2)
                        printf(" ");
                    else
                        printf("   ");
                }
                else if((i==1&&j==10)||(i==1&&j==13)||(i==4&&j==10)||(i==4&&j==13))
                {
                    set_background_color(0,14);
                    board[i][j].display=r;
                    printf(" %d ",r++);
                }
                else if(j==7&&i<6&&i>=0)
                {
                    set_background_color(0,12);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='B')
            {
                set_background_color(0,3);
                if(i==0&&j==0)
                {
                    set_color(0);
                    printf("%s",a[0].name);
                    j+=strlen(a[0].name)/3;
                    if(strlen(a[0].name)%3==2)
                        printf(" ");
                    else if(strlen(a[0].name)%3==1)
                        printf("  ");
                    else
                        printf("   ");
                }
                else if((i==1&&j==1)||(i==1&&j==4)||(i==4&&j==1)||(i==4&&j==4))
                {
                    set_background_color(0,14);
                    board[i][j].display=b;
                    printf(" %d ",b++);
                }
                else if(i==7&&j>=0&&j<6)
                {
                    set_background_color(0,1);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='Y')
            {
                set_background_color(0,6);
                if(i==14&&j==0)
                {
                    set_color(0);
                    printf("%s",a[3].name);
                    j+=strlen(a[3].name)/3;
                    if(strlen(a[3].name)%3==1)
                        printf("  ");
                    else if(strlen(a[3].name)%3==2)
                        printf(" ");
                    else
                        printf("   ");
                }
                else if((i==10&&j==1)||(i==10&&j==4)||(i==13&&j==1)||(i==13&&j==4))
                {
                    set_background_color(0,14);
                    board[i][j].display=y;
                    printf(" %d ",y++);
                }
                else if(j==7&&i>=7&&i<14)
                {
                    set_background_color(0,14);
                    printf("   ");
                }
                else
                    printf("   ");
            }
            else if(board[i][j].color=='O')
            {
                set_background_color(0,5);
                printf("%c%c%c",178,178,178);
            }
            else
            {
                if((i+j)%2==0)
                {
                    set_background_color(0,15);
                    if(board[i][j].quality=='S')
                        printf("%c%c%c",176,176,176);
                    else
                        printf("   ");
                }
                else
                {
                    set_background_color(0,8);
                    if(board[i][j].quality=='S')
                        printf("%c%c%c",176,176,176);
                    else
                        printf("   ");
                }
            }
            if(j==14)
            {
                set_background_color(0,0);
                printf("e");
            }
        }
        printf("\n");

    }
    int blue_path[4][58][2]={{{1,1},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6}},
                            {{1,4},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6}},
                            {{4,1},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6}},
                            {{4,4},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{7,1},{7,2},{7,3},{7,4},{7,5},{7,6}}};

    int red_path[4][58][2]={{{1,10},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7}},
                            {{1,13},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7}},
                            {{4,10},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7}},
                            {{4,13},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7}}};

    int green_path[4][58][2]={{{10,10},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{7,13},{7,12},{7,11},{7,10},{7,9},{7,8}},
                              {{10,13},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{7,13},{7,12},{7,11},{7,10},{7,9},{7,8}},
                              {{13,10},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{7,13},{7,12},{7,11},{7,10},{7,9},{7,8}},
                              {{13,13},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{14,6},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{7,13},{7,12},{7,11},{7,10},{7,9},{7,8}}};

    int yellow_path[4][58][2]={{{10,1},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{13,7},{12,7},{11,7},{10,7},{9,7},{8,7}},
                               {{10,4},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{13,7},{12,7},{11,7},{10,7},{9,7},{8,7}},
                               {{13,1},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{13,7},{12,7},{11,7},{10,7},{9,7},{8,7}},
                               {{13,4},{13,6},{12,6},{11,6},{10,6},{9,6},{8,5},{8,4},{8,3},{8,2},{8,1},{8,0},{7,0},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{5,6},{4,6},{3,6},{2,6},{1,6},{0,6},{0,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,9},{6,10},{6,11},{6,12},{6,13},{6,14},{7,14},{8,14},{8,13},{8,12},{8,11},{8,10},{8,9},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{14,7},{13,7},{12,7},{11,7},{10,7},{9,7},{8,7}}};
    set_background_color(0,0);
    int win=0,prev[4][4],turn,c[4][4],d,k=0,l=0,p=0;
    int ch,m=0;
    for(i=0;i<4;i++)
    {
        a[i].closed=4;
        a[i].home=0;
        for(j=0;j<4;j++)
        {
            c[i][j]=0;
        }
        if(a[i].name[0]!='\0')
        {
            p++;
        }
    }
    set_color(15);
    system("pause");
    system("cls");
    printf("Let's Play.\n");
    while(win!=p-1)
    {
        srand(time(NULL));
        if(a[0].home!=4&&a[0].name[0]!='\0')
        {
            set_color(3);
            printf("%s's turn:",a[0].name);
            do
            {
                if(l==2)
                {
                    turn=rand()%5+1;
                    draw_dice(turn);
                    l=0;
                }
                else
                {
                    turn=rand()%6+1;
                    draw_dice(turn);
                }
                set_color(3);
                printf("You got a %d.\n",turn);
                if(turn==6&&a[0].closed!=0)
                {
                    printf("\nWould you like to open 1 for Yes and 0 for No:\n");
                    scanf("%d",&ch);
                    if(ch!=0)
                    {
                        printf("\nWhich one would you like to open?\n");
                        scanf("%d",&d);
                        board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].display=0;
                        c[0][d-1]+=1;
                        board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].display=d;
                        board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].color='b';
                        system("pause");
                        system("cls");
                        print_during(board,a);
                        set_color(15);
                        a[0].closed--;
                    }
                    else
                    {
                        if(a[0].closed!=4)
                        {
                            printf("\nWhich one would you like to move:\n");
                            scanf("%d",&d);
                            if(c[0][d-1]==0)
                            {
                                printf("You cannot move this.\n");
                                printf("You have lost your turn.");
                            }
                            else if(c[0][d-1]+turn<58)
                            {
                                board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].display=0;
                                if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].display!=0&&board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].quality!='S')
                                {
                                    for(i=0;i<4;i++)
                                    {
                                        if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].display==i+1)
                                        {
                                            if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].color=='r')
                                            {
                                                c[1][i]=0;
                                                a[1].closed++;
                                                board[red_path[i][c[1][i]][0]][red_path[i][c[1][i]][1]].display=i+1;
                                                k++;
                                                printf("%d %d\n\n",a[1].closed,k);
                                                break;
                                            }
                                            if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].color=='y')
                                            {
                                                c[3][i]=0;
                                                board[yellow_path[i][c[3][i]][0]][yellow_path[i][c[3][i]][1]].display=i+1;
                                                a[3].closed++;
                                                k++;
                                                break;
                                            }
                                            if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].color=='g')
                                            {
                                                c[2][i]=0;
                                                board[green_path[i][c[2][i]][0]][green_path[i][c[2][i]][1]].display=i+1;
                                                a[2].closed++;
                                                k++;
                                                break;
                                            }
                                        }
                                    }
                                }
                                c[0][d-1]+=turn;
                                board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].display=d;
                                board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].color='b';
                                if(k==1)
                                {
                                    k=0;
                                    system("pause");
                                    system("cls");
                                    print_during(board, a);
                                    printf("Chance for capturing token.\n");
                                    turn=6;
                                    continue;
                                }
                            }
                            else if(c[0][d-1]+turn==58)
                            {
                                printf("%d Moves Home\n.",d);
                                a[0].home++;
                                turn=6;
                                system("pause");
                                system("cls");
                                print_during(board,a);
                                printf("Chance for reaching home.\n");
                                continue;
                            }
                            else
                            {
                                printf("You cannot move this. You lost your turn.");
                            }
                            system("pause");
                            system("cls");
                            print_during(board, a);
                        }
                    }
                }
                else
                {
                    if(a[0].closed==4)
                    {
                        printf("\nYou can't move.\n");
                    }
                    else
                    {
                        printf("\nWhich one would you like to move:\n");
                        scanf("%d",&d);
                        if(c[0][d-1]==0)
                        {
                            printf("You cannot move this.\n");
                            printf("You have lost your turn.");
                        }
                        else if(c[0][d-1]+turn<58)
                        {
                            board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].display=0;
                            if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].display!=0&&board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].quality!='S')
                            {
                                for(i=0;i<4;i++)
                                {
                                    if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].display==i+1)
                                    {
                                        if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].color=='r')
                                        {
                                            c[1][i]=0;
                                            board[red_path[i][c[1][i]][0]][red_path[i][c[1][i]][1]].display=i+1;
                                            a[1].closed++;
                                            k++;
                                            break;
                                        }
                                        if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].color=='y')
                                        {
                                            c[3][i]=0;
                                            board[yellow_path[i][c[3][i]][0]][yellow_path[i][c[3][i]][1]].display=i+1;
                                            a[3].closed++;
                                            k++;
                                            break;
                                        }
                                        if(board[blue_path[d-1][c[0][d-1]+turn][0]][blue_path[d-1][c[0][d-1]+turn][1]].color=='g')
                                        {
                                            c[2][i]=0;
                                            board[green_path[i][c[2][i]][0]][green_path[i][c[2][i]][1]].display=i+1;
                                            a[2].closed++;
                                            k++;
                                            break;
                                        }
                                    }
                                }
                            }
                            c[0][d-1]+=turn;
                            board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].display=d;
                            board[blue_path[d-1][c[0][d-1]][0]][blue_path[d-1][c[0][d-1]][1]].color='b';
                            if(k==1)
                            {
                                k=0;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for capturing token.\n");
                                turn=6;
                                continue;
                            }
                        }
                        else if(c[0][d-1]==58)
                        {
                            printf("%d Moves Home\n.",d);
                            a[0].home++;
                            turn=6;
                            system("pause");
                            system("cls");
                            print_during(board, a);
                            printf("Chance for reaching home.\n");
                            continue;
                        }
                        else
                        {
                            printf("You cannot move this. You lost your turn");
                        }
                    }
                    system("pause");
                    system("cls");
                    print_during(board, a);
                    set_color(15);
                }
                if(a[0].home==4)
                {
                    win++;
                    printf("%s won. Position Secured %d",a[0].name,++m);
                }
                l++;
            }
            while(turn==6);
            l=0;
        }
        if(a[1].home!=4&&a[1].name[0]!='\0')
        {
            set_color(12);
            printf("%s's turn:",a[1].name);
            do
            {
                if(l==2)
                {
                    turn=rand()%5+1;
                    draw_dice(turn);
                    l=0;
                }
                else
                {
                    turn=rand()%6+1;
                    draw_dice(turn);
                }
                set_color(12);
                printf("You got a %d.\n",turn);
                if(turn==6&&a[1].closed!=0)
                {
                    printf("\nWould you like to open 1 for Yes and 0 for No:\n");
                    scanf("%d",&ch);
                    if(ch!=0)
                    {
                        printf("\nWhich one would you like to open?\n");
                        scanf("%d",&d);
                        board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].display=0;
                        c[1][d-1]+=1;
                        board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].display=d;
                        board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].color='r';
                        system("pause");
                        system("cls");
                        print_during(board,a);
                        set_color(15);
                        a[1].closed--;
                    }
                    else
                    {
                        if(a[1].closed+a[1].home!=4)
                        {
                            printf("\nWhich one would you like to move:\n");
                            scanf("%d",&d);
                            if(c[1][d-1]==0)
                            {
                                printf("You cannot move this.\n");
                                printf("You have lost your turn.");
                            }
                            else if(c[1][d-1]+turn<58)
                            {
                                board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].display=0;
                                if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].display!=0&&board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].quality!='S')
                                {
                                    for(i=0;i<4;i++)
                                    {
                                        if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].display==i+1)
                                        {
                                            if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].color=='b')
                                            {
                                                c[0][i]=0;
                                                a[0].closed++;
                                                board[blue_path[i][c[0][i]][0]][blue_path[i][c[0][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                            if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].color=='g')
                                            {
                                                c[2][i]=0;
                                                a[2].closed++;
                                                board[green_path[i][c[2][i]][0]][green_path[i][c[2][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                            if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].color=='y')
                                            {
                                                c[3][i]=0;
                                                a[3].closed++;
                                                board[yellow_path[i][c[3][i]][0]][yellow_path[i][c[3][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                        }
                                    }
                                }
                                c[1][d-1]+=turn;
                                board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].display=d;
                                board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].color='r';
                                if(k==1)
                                {
                                    k=0;
                                    system("pause");
                                    system("cls");
                                    print_during(board, a);
                                    turn=6;
                                    printf("Chance for capturing token.\n");
                                    continue;
                                }
                            }
                            else if(c[1][d-1]==58)
                            {
                                printf("%d Moves Home\n.",d);
                                a[1].home++;
                                turn=6;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for reaching home.\n");
                                continue;
                            }
                            else
                            {
                                printf("You cannot move this. You lost your turn.");
                            }
                        }
                        system("pause");
                        system("cls");
                        print_during(board, a);
                        set_color(15);
                    }

                }
                else
                {
                    if((a[1].closed+a[1].home)==4)
                    {
                        printf("\nYou can't move.\n");
                    }
                    else
                    {
                        printf("\nWhich one would you like to move:\n");
                        scanf("%d",&d);
                        if(c[1][d-1]==0)
                        {
                            printf("You cannot move this.\n");
                            printf("You have lost your turn.");
                        }
                        else if(c[1][d-1]+turn<58)
                        {
                            board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].display=0;
                            if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].display!=0&&board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].quality!='S')
                            {
                                for(i=0;i<4;i++)
                                {
                                    if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].display==i+1)
                                    {
                                        if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].color=='b')
                                        {
                                            c[0][i]=0;
                                            a[0].closed++;
                                            board[blue_path[i][c[0][i]][0]][blue_path[i][c[0][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                        if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].color=='g')
                                        {
                                            c[2][i]=0;
                                            a[2].closed++;
                                            board[green_path[i][c[2][i]][0]][green_path[i][c[2][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                        if(board[red_path[d-1][c[1][d-1]+turn][0]][red_path[d-1][c[1][d-1]+turn][1]].color=='y')
                                        {
                                            c[3][i]=0;
                                            a[3].closed++;
                                            board[yellow_path[i][c[3][i]][0]][yellow_path[i][c[3][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                    }
                                }
                            }
                            c[1][d-1]+=turn;
                            board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].display=d;
                            board[red_path[d-1][c[1][d-1]][0]][red_path[d-1][c[1][d-1]][1]].color='r';
                            if(k==1)
                            {
                                k=0;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for capturing token.\n");
                                turn=6;
                                continue;
                            }
                        }
                        else if(c[1][d-1]==58)
                        {
                            printf("%d Moves Home\n.",d);
                            a[1].home++;
                            turn=6;
                            system("pause");
                            system("cls");
                            print_during(board, a);
                            printf("Chance for reaching home.\n");
                            continue;
                        }
                        else
                        {
                            printf("You cannot move this. You lost your turn");
                        }
                    }
                    system("pause");
                    system("cls");
                    print_during(board, a);
                    set_color(15);
                }
                l++;
            }
            while(turn==6);
            l=0;
            if(a[1].home==4)
            {
                win++;
                printf("%s won. Position Secured %d",a[1].name,++m);
            }
        }
        if(a[2].home!=4&&a[2].name[0]!='\0')
        {
            set_color(10);
            printf("%s's turn:",a[2].name);
            do
            {
                if(l==2)
                {
                    turn=rand()%5+1;
                    draw_dice(turn);
                    l=0;
                }
                else
                {
                    turn=rand()%6+1;
                    draw_dice(turn);
                }
                set_color(10);
                printf("You got a %d.\n",turn);
                if(turn==6&&a[2].closed!=0)
                {
                    printf("\nWould you like to open 1 for Yes and 0 for No:\n");
                    scanf("%d",&ch);
                    if(ch!=0)
                    {
                        printf("\nWhich one would you like to open?\n");
                        scanf("%d",&d);
                        board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].display=0;
                        c[2][d-1]+=1;
                        board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].display=d;
                        board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].color='g';
                        system("pause");
                        system("cls");
                        print_during(board,a);
                        set_color(15);
                        a[2].closed--;
                    }
                    else
                    {
                        if(a[2].closed+a[2].home!=4)
                        {
                            printf("\nWhich one would you like to move:\n");
                            scanf("%d",&d);
                            if(c[2][d-1]==0)
                            {
                                printf("You cannot move this.\n");
                                printf("You have lost your turn.");
                            }
                            else if(c[2][d-1]+turn<58)
                            {
                                board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].display=0;
                                if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].display!=0&&board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].quality!='S')
                                {
                                    for(i=0;i<4;i++)
                                    {
                                        if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].display==i+1)
                                        {
                                            if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].color=='b')
                                            {
                                                c[0][i]=0;
                                                a[0].closed++;
                                                board[blue_path[i][c[0][i]][0]][blue_path[i][c[0][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                            if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].color=='r')
                                            {
                                                c[1][i]=0;
                                                a[1].closed++;
                                                board[red_path[i][c[1][i]][0]][red_path[i][c[1][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                            if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].color=='y')
                                            {
                                                c[3][i]=0;
                                                a[3].closed++;
                                                board[yellow_path[i][c[3][i]][0]][yellow_path[i][c[3][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                        }
                                    }
                                }
                                c[2][d-1]+=turn;
                                board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].display=d;
                                board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].color='g';
                                if(k==1)
                                {
                                    k=0;
                                    system("pause");
                                    system("cls");
                                    print_during(board, a);
                                    turn=6;
                                    printf("Chance for capturing token.\n");
                                    continue;
                                }
                            }
                            else if(c[2][d-1]==58)
                            {
                                printf("%d Moves Home\n.",d);
                                a[2].home++;
                                turn=6;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for reaching home.\n");
                                continue;
                            }
                            else
                            {
                                printf("You cannot move this. You lost your turn.");
                            }
                        }
                        system("pause");
                        system("cls");
                        print_during(board, a);
                        set_color(15);
                    }

                }
                else
                {
                    if((a[2].closed+a[2].home)==4)
                    {
                        printf("\nYou can't move.\n");
                    }
                    else
                    {
                        printf("\nWhich one would you like to move:\n");
                        scanf("%d",&d);
                        if(c[2][d-1]==0)
                        {
                            printf("You cannot move this.\n");
                            printf("You have lost your turn.");
                        }
                        else if(c[2][d-1]+turn<58)
                        {
                            board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].display=0;
                            if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].display!=0&&board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].quality!='S')
                            {
                                for(i=0;i<4;i++)
                                {
                                    if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].display==i+1)
                                    {
                                        if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].color=='b')
                                        {
                                            c[0][i]=0;
                                            a[0].closed++;
                                            board[blue_path[i][c[0][i]][0]][blue_path[i][c[0][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                        if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].color=='r')
                                        {
                                            c[1][i]=0;
                                            a[1].closed++;
                                            board[red_path[i][c[1][i]][0]][red_path[i][c[1][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                        if(board[green_path[d-1][c[2][d-1]+turn][0]][green_path[d-1][c[2][d-1]+turn][1]].color=='y')
                                        {
                                            c[3][i]=0;
                                            a[3].closed++;
                                            board[yellow_path[i][c[3][i]][0]][yellow_path[i][c[3][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                    }
                                }
                            }
                            c[2][d-1]+=turn;
                            board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].display=d;
                            board[green_path[d-1][c[2][d-1]][0]][green_path[d-1][c[2][d-1]][1]].color='g';
                            if(k==1)
                            {
                                k=0;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for capturing token.\n");
                                turn=6;
                                continue;
                            }
                        }
                        else if(c[2][d-1]==58)
                        {
                            printf("%d Moves Home\n.",d);
                            a[2].home++;
                            turn=6;
                            system("pause");
                            system("cls");
                            print_during(board, a);
                            printf("Chance for reaching home.\n");
                            continue;
                        }
                        else
                        {
                            printf("You cannot move this. You lost your turn");
                        }
                    }
                    system("pause");
                    system("cls");
                    print_during(board, a);
                    set_color(15);
                }
                l++;
            }
            while(turn==6);
            l=0;
            if(a[2].home==4)
            {
                win++;
                printf("%s won. Position Secured %d",a[2].name,++m);
            }
        }
        if(a[3].home!=4&&a[3].name[0]!='\0')
        {
            set_color(6);
            printf("%s's turn:",a[3].name);
            do
            {
                if(l==2)
                {
                    turn=rand()%5+1;
                    draw_dice(turn);
                    l=0;
                }
                else
                {
                    turn=rand()%6+1;
                    draw_dice(turn);
                }
                set_color(6);
                printf("You got a %d.\n",turn);
                if(turn==6&&a[3].closed!=0)
                {
                    printf("\nWould you like to open 1 for Yes and 0 for No:\n");
                    scanf("%d",&ch);
                    if(ch!=0)
                    {
                        printf("\nWhich one would you like to open?\n");
                        scanf("%d",&d);
                        board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].display=0;
                        c[3][d-1]+=1;
                        board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].display=d;
                        board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].color='y';
                        system("pause");
                        system("cls");
                        print_during(board,a);
                        set_color(15);
                        a[3].closed--;
                    }
                    else
                    {
                        if(a[3].closed+a[3].home!=4)
                        {
                            printf("\nWhich one would you like to move:\n");
                            scanf("%d",&d);
                            if(c[3][d-1]==0)
                            {
                                printf("You cannot move this.\n");
                                printf("You have lost your turn.");
                            }
                            else if(c[3][d-1]+turn<58)
                            {
                                board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].display=0;
                                if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].display!=0&&board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[2][d-1]+turn][1]].quality!='S')
                                {
                                    for(i=0;i<4;i++)
                                    {
                                        if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].display==i+1)
                                        {
                                            if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].color=='b')
                                            {
                                                c[0][i]=0;
                                                a[0].closed++;
                                                board[blue_path[i][c[0][i]][0]][blue_path[i][c[0][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                            if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].color=='r')
                                            {
                                                c[1][i]=0;
                                                a[1].closed++;
                                                board[red_path[i][c[1][i]][0]][red_path[i][c[1][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                            if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].color=='g')
                                            {
                                                c[2][i]=0;
                                                a[2].closed++;
                                                board[green_path[i][c[2][i]][0]][green_path[i][c[2][i]][1]].display=i+1;
                                                k++;
                                                break;
                                            }
                                        }
                                    }
                                }
                                c[3][d-1]+=turn;
                                board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].display=d;
                                board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].color='y';
                                if(k==1)
                                {
                                    k=0;
                                    system("pause");
                                    system("cls");
                                    print_during(board, a);
                                    turn=6;
                                    printf("Chance for capturing token.\n");
                                    continue;
                                }
                            }
                            else if(c[3][d-1]==58)
                            {
                                printf("%d Moves Home\n.",d);
                                a[3].home++;
                                turn=6;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for reaching home.\n");
                                continue;
                            }
                            else
                            {
                                printf("You cannot move this. You lost your turn.");
                            }
                        }
                        system("pause");
                        system("cls");
                        print_during(board, a);
                        set_color(15);
                    }

                }
                else
                {
                    if((a[3].closed+a[3].home)==4)
                    {
                        printf("\nYou can't move.\n");
                    }
                    else
                    {
                        printf("\nWhich one would you like to move:\n");
                        scanf("%d",&d);
                        if(c[3][d-1]==0)
                        {
                            printf("You cannot move this.\n");
                            printf("You have lost your turn.");
                        }
                        else if(c[3][d-1]+turn<58)
                        {
                            board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].display=0;
                            if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].display!=0&&board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].quality!='S')
                            {
                                for(i=0;i<4;i++)
                                {
                                    if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].display==i+1)
                                    {
                                        if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].color=='b')
                                        {
                                            c[0][i]=0;
                                            a[0].closed++;
                                            board[blue_path[i][c[0][i]][0]][blue_path[i][c[0][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                        if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].color=='r')
                                        {
                                            c[1][i]=0;
                                            a[1].closed++;
                                            board[red_path[i][c[1][i]][0]][red_path[i][c[1][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                        if(board[yellow_path[d-1][c[3][d-1]+turn][0]][yellow_path[d-1][c[3][d-1]+turn][1]].color=='g')
                                        {
                                            c[2][i]=0;
                                            a[2].closed++;
                                            board[green_path[i][c[2][i]][0]][green_path[i][c[2][i]][1]].display=i+1;
                                            k++;
                                            break;
                                        }
                                    }
                                }
                            }
                            c[3][d-1]+=turn;
                            board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].display=d;
                            board[yellow_path[d-1][c[3][d-1]][0]][yellow_path[d-1][c[3][d-1]][1]].color='y';
                            if(k==1)
                            {
                                k=0;
                                system("pause");
                                system("cls");
                                print_during(board, a);
                                printf("Chance for capturing token.\n");
                                turn=6;
                                continue;
                            }
                        }
                        else if(c[3][d-1]==58)
                        {
                            printf("%d Moves Home\n.",d);
                            a[3].home++;
                            turn=6;
                            system("pause");
                            system("cls");
                            print_during(board, a);
                            printf("Chance for reaching home.\n");
                            continue;
                        }
                        else
                        {
                            printf("You cannot move this. You lost your turn");
                        }
                    }
                    system("pause");
                    system("cls");
                    print_during(board, a);
                    set_color(15);
                }
                l++;
            }
            while(turn==6);
            l=0;
            if(a[3].home==4)
            {
                win++;
                printf("%s won. Position Secured %d",a[3].name,++m);
            }
        }

    }
}
