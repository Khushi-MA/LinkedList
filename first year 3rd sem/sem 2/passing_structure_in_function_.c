#include<stdio.h>

// template
typedef struct cricket_player
{
    char player_name[20];
    char team_name[20];
    float average;
    int highest_score;
    int centuries;
    int ODI_rank;
}CRIP;     //typedef usage: "CRIP"

//  initializing the function to display some elements
void display(char[], float, int);

//  initializing the function to display whole structure
void display_2 (struct cricket_player);



//  function to display only the elements
void display(char player_name[20], float average, int ODI_rank)
{
    printf("\n%s\n%f\n%d\n",player_name,average,ODI_rank);
}


// function to display the whole structure
void display_2 (struct cricket_player p1)
{
    printf("\n%s\n%s\n%f\n%d\n%d\n%d\n",p1.player_name,    // string
                                        p1.team_name,      // string
                                        p1.average,        // float
                                        p1.highest_score,  // int
                                        p1.centuries,      // int
                                        p1.ODI_rank );     // int

}

void display_3 (CRIP p1)
{
    printf("\n%f\n%d\n",p1.average, p1.centuries);
}

int main()
{
    struct cricket_player p1={"Virat","India",59.76,183,39,1};

    // function call to display only the elements
    display(p1.player_name, p1.average, p1.ODI_rank);

    printf("\n\n");

    // function call to display the whole structure
    display_2(p1);

    // function call using typedef CRIP
    display_3(p1);


    return 0;
}
