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
    struct node* l;
    struct node* r;
    struct product data;
};

typedef struct node* NODE;

void insert(NODE ,int);
NODE create(int);
NODE createtree(NODE);
void displayall(NODE);
void printwithinrange(NODE,float,float, int);
void printless95(NODE);
NODE maxproductrating(NODE, int);
NODE deletenode(NODE, int);
NODE findmin(NODE);
void zeroratingout(NODE);

void outexpiryless2022(NODE);

int main()
{
    int a,T,i,choice,count=3;
    float p,q;
    NODE root=NULL,temp=NULL;
    struct product pro;

    printf("Enter the number of Nodes you want in the tree:  ");
    scanf("%d",&T);
    //printf("Start entering the values\n");
    //printf("\nproduct ID = ");
    scanf("%d",&a);
    root=create(a);
    for(i=0;i<T-1;i++)
    {
        //printf("\nproduct ID = ");
        scanf("%d",&a);
        insert(root,a);
    }

    printf("\nID\tname\tMRP\texpiry\trating\t");
    displayall(root);

    while(choice!=100)
    {
        printf("\nSelect function");
        printf("\n1.Add product\n2.MRP<95\n3.delete exp<2022\n4.display within range\n5.max rating\n6.delete rating zero\n100. BYE BYE\nCHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nenter the values: \nID\tname\tMRP\texp_date\trating\t");
                    scanf("%d",&a);
                    insert(root,a);
                    break;
            
            case 2: printless95(root);
                    break;

            case 3: outexpiryless2022(root);
                    printf("\nAfter deletion of expiry<2022:\nID\tname\tMRP\texpiry\trating\t");
                    displayall(root);
                    break;


            case 4: printf("lower value = ");
                    scanf("%f",&p);
                    printf("upper value = ");
                    scanf("%f",&q);
                    count=0;
                    printwithinrange(root,p,q,count);
                    printf("number = %d",count);
                    break;

            case 5: temp = maxproductrating(root,0);
                    printf("MAX product rating:  %d",temp->data.product_rating);
                    printf("\nID\tname\tMRP\texpdate\t");
                    printf("\n%d\t%s\t%.2f\t%d\t\n",temp->data.p_id, temp->data.name, temp->data.MRP, temp->data.exp_date);
                    break;

            case 6: zeroratingout(root);
                    printf("\nAfter deletion of rating=0 :\nID\tname\tMRP\texpiry\trating\t");
                    displayall(root);
                    break;

            //case 100: break;

            default: printf("\n!!!CHOICE DOESN'T EXIST!!!\n");
                    exit(0);
                    break;
        }
    }
    return 0;
}


NODE create(int data)
{
    NODE newnode=(NODE)malloc(sizeof(struct node));
    newnode->data.p_id=data;
    //printf("product name = ");
    scanf("%s",newnode->data.name);
    //printf("MRP = ");
    scanf("%f",&newnode->data.MRP);
    //printf("expiry date = ");
    scanf("%d",&newnode->data.exp_date);
    //printf("product rating = ");
    scanf("%d",&newnode->data.product_rating);
    newnode->r=NULL;
    newnode->l=NULL;
    return newnode;
}

void insert(NODE root,int data)
{
    NODE prev=NULL;
    //traverse
    while(root!=NULL)
    {
        prev=root;
        if(root->data.p_id==data)
        {
            printf("node already exist %d\n",data);
            return;
        }

        else if(data<root->data.p_id)
            root=root->l;

        else
            root=root->r;
    }

    NODE newnode=create(data);
    if(data<prev->data.p_id)
        prev->l=newnode;
    else
        prev->r=newnode;

    return;
}


/* to display all the products and their details*/
void displayall(NODE root)
{
    if(root==NULL)
    return;

    else
    {
        displayall(root->l);
        printf("\n%d\t%s\t%.2f\t%d\t%d\t",root->data.p_id, root->data.name, root->data.MRP, root->data.exp_date, root->data.product_rating);
        displayall(root->r);
    }
    return;
}

/*to display products whose MRP is less than Rs.95*/
void printless95(NODE root)
{
    if(root==NULL)
    return;

    else
    {
        printless95(root->l);
        if(root->data.MRP<95)
        printf("\nproduct ID = %d\nName = %s\nMRP = %f\nExpiry date = %d\nproduct rating = %d\n",root->data.p_id, root->data.name, root->data.MRP, root->data.exp_date, root->data.product_rating);
        printless95(root->r);
    }
    return;
}

/* print number of products within a certain MRP range*/
void printwithinrange(NODE root, float a, float b, int count)
{
    if(root==NULL)
    return;

    if(root->data.MRP>=a && root->data.MRP<=b)
        count=count+1;

    printwithinrange(root->l,a,b,count);
    printwithinrange(root->r,a,b,count);
    return ;
}

/* print product information with max product rating*/
NODE maxproductrating(NODE root, int max)
{
    if(root==NULL)
    return NULL;

    if(root->data.product_rating>max)
        max=root->data.product_rating;

        maxproductrating(root->l,max);
        maxproductrating(root->r,max);

    return root;
}

// deleting node according to product ID
NODE deletenode(NODE root, int value)
{
    if(root==NULL)
    return root;

    if(value<root->data.p_id)
    root->l=deletenode(root->l,value);

    else if(value>root->data.p_id)
    root->r=deletenode(root->r, value);

    else
    {
        // no child
        if(root->l==NULL && root->r==NULL)
        {
            free(root);
            return NULL;
        }

        // case 2: one node
        else if(root->l==NULL)
        {
            NODE temp=root;
            root=root->r;
            free(temp);
            return root;
        }

        else if(root->r==NULL)
        {
            NODE temp=root;
            root=root->l;
            free(temp);
            return root;
        }

        // case 3: two nodes
        else
        {
            NODE temp;
            temp=findmin(root->r);
            root->data.p_id=temp->data.p_id;
            root->r=deletenode(root->r,temp->data.p_id);
        }
    }
    return root;
}

NODE findmin(NODE root)
{
    NODE temp;
    for(temp=root;temp!=NULL && temp->l!=NULL;temp=temp->l);
    return temp;
}

// zero rating sending function
void zeroratingout(NODE root)
{
    if(root==NULL)
    return;

    else
    {
        if(root->data.product_rating==0)
        root=deletenode(root,root->data.p_id);
        
        zeroratingout(root->l);
        zeroratingout(root->r);
    }
    return;
}

void outexpiryless2022(NODE root)
{
    if(root==NULL)
        return;
       
        outexpiryless2022(root->r);
        outexpiryless2022(root->l);

        if(root->data.exp_date<2022)
        deletenode(root,root->data.p_id);
    return;
}

/* for reference only 
void inorder(NODE root)
{
    if(root==NULL)
    return;

    else
    {
        inorder(root->l);
        printf("%d  ",root->data.p_id);
        inorder(root->r);
    }
    return;
}

*/

/*
left and right view of the tree
BY BIBIJAN

void l_r_b(NODE root)
{
    NODE cur=root, temp=root;
    temp=root->l;
    cur=cur->r;
    NODE curl=cur, curr=cur, templ=temp, tempr=temp;

    printf("bottom view\n");
    while(templ->l!=NULL)
        templ=templ->l;

    printf("%d ",templ->data);

     while(tempr->r!=NULL)
        tempr=tempr->r;

    printf("%d ",tempr->data);

    while(curl->l!=NULL)
        curl=curl->l;

    printf("%d ",curl->data);

     while(curr->r!=NULL)
        curr=curr->r;

    printf("%d ",curr->data);

}

*/