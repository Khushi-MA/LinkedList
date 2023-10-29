/*
    Data structures evaluation 1 on structure pointers

    Name : Amogh Shrikant Dodawad
    Roll number : 1001
    USN : 01FE21BCS114
    Date : 27//5/2022
*/

#include<stdio.h>
#include<string.h>

typedef struct VISITOR {
    char name[100];
    int age;
    int y;
    char place;
    char zone[6];
    char mName[100];
} VISITOR;

int n;

int schoolChildrenCount(VISITOR *p){
    int c=0,i;
    for( i=0;i<n;i++){
        if(p->age <= 17)
            c++;
        p++;
    }
    return c;
}

int numberOfInternationalVisitors(VISITOR *p){
    int I=0,i;
    for(i=0;i<n;i++){
        if(p->place == 'I' || p->place == 'i')
            I++;
        p++;
    }
    return I;
}

void displayInfo(VISITOR *p, char mName_1[100]){
    int flag = 0,i;
    printf("Only the selected ones will be shown below\n");
    for(i=0;i<n;i++){
        if(strcmp((p+i)->mName,mName_1) == 0){
            flag = 1;
            break;
        }
        // p++;
    }
    if(flag == 1){
        printf("Name\t\tPlace\t\tAge\t\tYear of visit\t\tMuseum\t\tZone\n");
        for(i=0;i<n;i++){
        if(strcmp((p+i)->mName,mName_1) == 0){
            printf("%s\t\t",(p+i)->name);
            printf("%c\t\t",(p+i)->place);
            printf("%d\t\t",(p+i)->age);
            printf("%d\t\t",(p+i)->y);
            printf("%s\t\t",(p+i)->mName);
            printf("%s\t\t",(p+i)->zone);
            printf("\n");
            // flag = 1;
        }
        // p++;
    }
    }

    if(!flag)
        printf("No such visitors\n");
    return;
}

void read(VISITOR *p){
    int i;
    printf("Enter user details\n");
    for(i=0;i<n;i++){
        printf("Enter visitor name\n");
        scanf("%s",p->name);
        char ch = getchar();
        printf("Enter Place\n");
        scanf("%c",&p->place);
        printf("Enter age\n");
        scanf("%d",&p->age);
        printf("Enter year of visit\n");
        scanf("%d",&p->y);
        printf("Enter Museum name\n");
        scanf("%s",&p->mName);
        printf("Enter Museum zone\n");
        scanf("%s",&p->zone);
        p++;
    }
    return;
}

void displayAll(VISITOR *p){
    int i;
    printf("Name\t\tPlace\t\tAge\t\tYear of visit\t\tMuseum\t\tZone\n");
    for(i=0;i<n;i++){
        printf("%s\t\t",p->name);
        printf("%c\t\t",p->place);
        printf("%d\t\t",p->age);
        printf("%d\t\t",p->y);
        printf("%s\t\t",p->mName);
        printf("%s\t\t",p->zone);
        printf("\n");
        p++;
    }

}

int main(){
    VISITOR p[100];char mName_1[100];
    printf("Enter the number of visitors\n");
    scanf("%d",&n);
    read(p);
    int I = numberOfInternationalVisitors(p);
    int c = schoolChildrenCount(p);
    printf("Enter the museum to be searched\n");
    scanf("%s",mName_1);
    printf("International = %d\nSchool children = %d\n",I,c);
    displayAll(p);
    displayInfo(p,mName_1);
    return 0;
}

