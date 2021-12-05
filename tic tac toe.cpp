#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
char sq[10]={'o','1','2','3','4','5','6','7','8','9'};
int w=0,wi=0,d=0,l=0,li=0,i,player=1;
int checkwin();
void board();
void reset();
void store();
int main()
{
    int choice;
    char mark;
    TOP:
    do
   {

    board();
    player=(player%2)?1:2;
    mark=(player==1)?'X':'O';

    printf("\n\n\n\t\tPlayer %d|| Enter your choice:-\t",player);
    scanf("%d",&choice);
    if (choice ==1 && sq[1]=='1')
    sq[1]=mark;
    else if (choice ==2&& sq[2]=='2')
    sq[2]=mark;
    else if (choice ==3&& sq[3]=='3')
    sq[3]=mark;
    else if (choice ==4&& sq[4]=='4')
    sq[4]=mark;
    else if (choice ==5&& sq[5]=='5')
    sq[5]=mark;
    else if (choice ==6&& sq[6]=='6')
    sq[6]=mark;
    else if (choice ==7&& sq[7]=='7')
    sq[7]=mark;
    else if (choice ==8&& sq[8]=='8')
    sq[8]=mark;
    else if (choice ==9&& sq[9]=='9')
    sq[9]=mark;
    else
    {
       printf("Invalid move");
       player--;
       getch();
    }
    board();
    i=checkwin();

    player++;
   }while(i==-1);
   store();
    if (i)
        {
            printf("\n\nPlayer %d wins !!",player);
            //rematch statement
            char a,b;
            printf("\n\n\t\tplayer 1 Do you want a rematch?(Y/N)");
            fflush(stdin);
            a=toupper(getchar());
            printf("\n\n\t\tplayer 2 Do you want a rematch?(Y/N)");
            fflush(stdin);
            b=toupper(getchar());

    if (a=='Y'&& b=='Y')
        {
            reset();
            goto TOP;}
            else
            printf("\n\n\t\t Good game");
        }
    else
        printf("\n\n\t\t\tDraw!!\n\n");

    return 0;
}
int checkwin()
{
    if(sq[1]==sq[2]&&sq[2]==sq[3])
    return 1;
    else if (sq[4]==sq[5]&&sq[5]==sq[6])
    return 1;
    else if (sq[7]==sq[8]&&sq[8]==sq[9])
    return 1;
    else if (sq[1]==sq[4]&&sq[4]==sq[7])
    return 1;
    else if (sq[2]==sq[5]&&sq[5]==sq[8])
    return 1;
    else if (sq[3]==sq[6]&&sq[6]==sq[9])
    return 1;
    else if (sq[1]==sq[5]&&sq[5]==sq[9])
    return 1;
    else if (sq[3]==sq[5]&&sq[5]==sq[7])
    return 1;
    else if (sq[1]!='1'&&sq[2]!='2'&&sq[3]!='3'&&sq[4]!='4'&&sq[5]!='5'&&sq[6]!='6'&&sq[7]!='7'&&sq[8]!='8'&&sq[9]!='9')
    return 0;
    else
    return -1;
}



void board()
{
    system("cls");
    printf("\n\n\t\t\tTIC - TAC - TOE GAME");
    printf("\n \n Player 1-(X) \t\t Player 2-(O)");
    printf("\n\n\t\t\t|     |     |     |");
    printf("\n\t\t\t|  %c  |  %c  |  %c  |",sq[1],sq[2],sq[3]);
    printf("\n\t\t\t|     |     |     |");
    printf("\n\t\t\t|_____|_____|_____|");
    printf("\n\t\t\t|     |     |     |");
    printf("\n\t\t\t|  %c  |  %c  |  %c  |",sq[4],sq[5],sq[6]);
    printf("\n\t\t\t|     |     |     |");
    printf("\n\t\t\t|_____|_____|_____|");
    printf("\n\t\t\t|     |     |     |");
    printf("\n\t\t\t|  %c  |  %c  |  %c  |",sq[7],sq[8],sq[9]);

}

void reset()
{
        sq[0]='0',sq[1]='1',sq[2]='2',sq[3]='3',sq[4]='4',sq[5]='5',sq[6]='6',sq[7]='7',sq[8]='8',sq[9]='9';
}
void store()
{
    player--;

    if (i==1&& player==1)
    {
        w++;
        li++;
    }
    else if(i==1 && player ==2)
    {
        wi++;
        l++;
    }
    else
        d++;
    printf("\n\nwin=%d l=%d 2win=%d 2lose=%d Draw=%d",w,l,wi,li,d);
}
