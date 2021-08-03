 #include <stdio.h>

#include <stdlib.h>
#include <time.h>
int generate_Random_Number(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int result_of_game(int p, int c) //function to check who wins
{
    if (p == 1 && c == 2)
    {
        return 1;
    }
    else if (p == 2 && c == 1)
    {
        return 3;
    }
    else if (p == 2 && c == 3)
    {
        return 1;
    }
    else if (p == 3 && c == 2)
    {
        return 3;
    }
    else if (p == 3 && c == 1)
    {
        return 1;
    }
    else if (p == 1 && c == 3)
    {
        return 3;
    }
    else if (p == c)
    {
        return 2;
    }
}

int main()
{
    int player, computer, result;
    int comp=0,play=0;
    //To take input of name of player
    char name[15];
    // char player_selections,computer_selection;
    //RUles of Game to printed here 1.Rock 2.Paper 3.Scissor
    printf("Enter your name:");
    scanf("%s", &name);
    //****************************************************************************************************//
    for (int i = 0; i < 3; i++)
    {
        printf("This is turn number %d \n", i + 1);
        printf("Enter your response 1.Rock 2.Paper 3.Scissor\n");
        scanf("%d", &player);
        if (player < 1 || player > 3) //If player enters any value other than 1or2or3
        {
            printf("Please enter only number 1 or 2 or 3");
        }
        
        computer = generate_Random_Number(3); //3 because rock, paper , scissor! //NOTE:this computer will have 0,1,2 as output so while comparing adjust accordingly
        
        printf("%s input is:%d\n",name, player);
        
        printf("Computers input is:%d\n",computer+1);
        
        
        result = result_of_game(player, (computer + 1)); //becoz srand gives 0,1,2 and player has 1,2,3;
        //NOTE:If Computer Wins then return will be one And If player wins return will be 3, and if return is 2 then its a tie

        if (result==1)
        {
            comp+=1;
        }
        else if (result==3)
        {
            play+=1;
        }
        else if (result==2)
        {
            play+=0;
            comp+=0;
        }
        printf("Score of round %d is \n",i+1);
        printf("%s:%d\n",name, play);
        printf("Computer:%d\n\n\n",comp);
        
    }
    printf("*******************FINAL SCORES ARE*******************\n\n");
    printf("%s:%d\n\n",name,play);
    printf("Computer:%d\n\n",comp);
    if (play>comp)
    {
        printf("************WINNER IS %s*************\n",name);
    }
    else if (play<comp)
    {
        printf("***********WINNER IS COMPUTER************\n"); 
    }
    else if (play==comp)
    {
        printf("Its a tie\n");
    }
    return 0;
}
