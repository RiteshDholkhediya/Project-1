#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

// Ascii codes
//space = 32; enter  = 13; 0 = 48;


 

 int main(){

    while(1){

        int a[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32},b[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,32},i=0,j,ch1,ch2,row=3,col=3,temp,flag,count=15,lower=1,upper=15,*p,counter,chances;
        char name[20],choice;
        
        system("cls");
        p=&a[0][0];

        printf("\n\n\n\n\nPlayer Name : ");
        fgets(name,20,stdin);

        getch();
        system("cls");
        printf("\t\tMATRIX PUZZLE\n");
        printf("\t\tRULE OF THIS GAME\n");
        printf("\n1. You can move only 1 step at a time with the arrow key.\n");
        printf("Move Up    : by Up arrow key\n");
        printf("Move Down  : by Down arrow key\n");
        printf("Move Left  : by Left arrow key\n");
        printf("Move Right : by Right arrow key\n");

        printf("\n2. You can move numbers at an empty position only.\n");
        printf("\n3. For each valid move : your total number of moves will decrease by 1.\n");
        printf("\n4. Winning Situation : Number in a 4*4 matrix should be in order from 1 to 15\n");
        

        printf("\nwinning situation:\n\n");

        for(i=0;i<25;i++){
            printf("-");
        }
        printf("\n");
        for(i=0;i<4;i++){ 
            for(j=0;j<4;j++){
                if(i==3 && j==3){
                        printf("|   %c |",b[i][j]);
                    
                }
                else{
                    if(b[i][j]>9){
                        if(j==3){
                            printf("|  %d |",b[i][j]);
                        }
                        else
                            printf("|  %d ",b[i][j]);
                    }
                    else{
                        if(j==3){
                            printf("|   %d |",b[i][j]);
                        }
                        else
                            printf("|   %d ",b[i][j]);
                    }
                    
                }
                
            }
            printf("\n");
        }
        for(i=0;i<25;i++){
            printf("-");
        }

        printf("\n5. You can exit the game  at any time by pressing 'E' or 'e'");
        printf("\nSo try to win in minimum no. of move.");
        printf("\nEnter number of moves");
        scanf("%d",&chances);
        printf("\nEnter any key to start...");
        getch();

        i=0;
        srand(time(0));
        while(i<count) {
            
            flag=1;
            int num = (rand() %
            (upper - lower + 1)) + lower;
        
                for(j=0;j<=i;j++){
                    if(*(p+j)==num){
                        flag=0;
                    }
                }
                if(flag){
                    p[i]=num;
                    i++;
                }   

        }


        while(1){
            system("cls");
            temp=0;
            printf("\n\nHello %s",name);
            printf("Move Remaining : %d\n",chances);
            for(i=0;i<25;i++){
                printf("-");
            }
            printf("\n");
            for(i=0;i<4;i++){ 
                for(j=0;j<4;j++){
                    if(i==row && j==col){
                        if(j==3){
                            printf("|   %c |",a[i][j]);
                        }
                        else
                            printf("|   %c ",a[i][j]);
                    }
                    else{
                        if(a[i][j]>9){
                            if(j==3){
                                printf("|  %d |",a[i][j]);
                            }
                            else
                                printf("|  %d ",a[i][j]);
                        }
                        else{
                            if(j==3){
                                printf("|   %d |",a[i][j]);
                            }
                            else
                                printf("|   %d ",a[i][j]);
                        }
                        
                    }
                    
                }
                printf("\n");
            }
            for(i=0;i<25;i++){
                printf("-");
            }
            printf("\n");
            ch1=getch();
            ch2=0;
            if(ch1==0xE0){
                ch2=getch();
                switch(ch2){
                    case 72:if(row<3){
                                row++;
                                temp = a[row][col];
                                a[row][col] = 32;
                                row--;
                                a[row][col] = temp;
                                row++;
                            }
                            break;

                    case 75: if(col<3){
                                col++;
                                temp = a[row][col];
                                a[row][col] = 32;
                                col--;
                                a[row][col] = temp;
                                col++;
                            }
                            break;
                    
                    case 77: if(col>0){
                                col--;
                                temp = a[row][col];
                                
                                a[row][col]=32;
                                
                                col++;
                                a[row][col]=temp;
                            
                                col--;
                            }
                            break;
                    case 80: if(row>0){
                                row--;
                                temp=a[row][col];
                                a[row][col] = 32;
                                row++;
                                a[row][col]=temp;
                                row--;
                            }

                }

                flag=1;
                for(i=0;i<4;i++){
                    for(j=0;j<4;j++){
                        if(a[i][j]!=b[i][j]){
                            flag=0;
                        }
                        
                    }
                }

                

                if(flag!=0 && chances){
                    break;
                }
                else if(chances == 0)
                    break;
                chances--;

            }
            else if(ch1=='E' || ch1=='e'){
                exit(0);
            }

            else{
                continue;
            }
    
        }
        system("cls");
        if(flag){
            printf("\nYou have Win the Game");
        }
        else
            printf("\nYou lose");

        printf("\nDo you want to play again?");
        printf("\nEnter 'y' to play again otherwise n : ");
        choice = getch();
        if(choice=='y' || choice=='Y')
            continue;
        else
            break;

    }
    
 
    

    return 0;    
}
