#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct product
{
    int p_id;
    char name[10];
    float MRP;
    int exp_date;
    int product_rating;
};

struct node
{
    struct node* left;
    struct node* right;
    struct product data;
};

typedef struct node* NODE;
void readdata(NODE);
void insertnode(NODE );
NODE createnode(NODE);
void displayall(NODE);
NODE insert(NODE); //by trupti

/*
1. find and display MRP<95
2. find an ddelete exp<2022
3. find and display within range
4. max rating
5. find and delete rating=0
*/

int main()
{
    NODE root;
    readdata(root);
    displayall(root);
}

void displayall(NODE root)
{
    if(root==NULL)
        return;
    
    else
    {
        displayall(root->left);
        printf("\nproduct ID = %d\nName = %s\nMRP = %f\nExpiry date = %d\nproduct rating = %d\n",root->data.p_id, root->data.name, root->data.MRP, root->data.exp_date, root->data.product_rating);
        displayall(root->right);
    }
    return;
}

NODE createnode(NODE newnode)
{
    newnode=(NODE)malloc(sizeof(struct node));
    //struct product pro;

    printf("\n\nenter data one by one \nproduct_ID, name,  MRP, exp_date, product_rating\n\n");
        printf("product id = ");
        scanf("%d",&newnode->data.p_id);
        printf("product name = ");
        scanf("%s",newnode->data.name);
        printf("MRP = ");
        scanf("%f",&newnode->data.MRP);
        printf("expiry date = ");
        scanf("%d",&newnode->data.exp_date);
        printf("product rating = ");
        scanf("%d",&newnode->data.product_rating);

    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}


// void insertnode(NODE root)
// {
//     NODE newnode;
//     newnode=createnode(newnode);

//     NODE prev=NULL;
//     while(root!=NULL)
//     {
//         prev=root;
//         if(root->data.p_id==newnode->data.p_id)
//         {
//             printf("node already exists");
//             return;
//         }

//         else if(newnode->data.p_id<root->data.p_id)
//             root=root->left;

//         else
//             root=root->right;
//     }

//     if(newnode->data.p_id<prev->data.p_id)
//         prev->left=newnode;
//     else
//         prev->right=newnode;

//         return;

// }

NODE insert(NODE root)
{
    NODE newnode;
    newnode=createnode(newnode);
    int data=newnode->data.p_id;

    if(root==NULL)
    {
        root=createnode(root);
        return root;
    }

    if(root->data.p_id>data)
    {
        root->left=insert(root->left);
        return root;
    }

    else
    {
        root->right=insert(root->right);
        return root;
    }
}

void readdata(NODE root)
{
    int T,i;

    printf("enter the total number of products:  ");
    scanf("%d",&T);
    root=createnode(root);
    for(i=0;i<T-1;i++)
        insert(root);

    return;
}



/* 
with  root in insert

void insertnode(NODE root)
{
    NODE newnode;
    newnode=createnode();

    NODE prev=NULL,cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(cur->data.p_id==newnode->data.p_id)
        {
            printf("node already exists");
            return;
        }

        else if(newnode->data.p_id<cur->data.p_id)
            cur=cur->left;

        else
            cur=cur->right;
    }

    if(newnode->data.p_id<prev->data.p_id)
        prev->left=newnode;
    else
        prev->right=newnode;

        return;
}
*/

