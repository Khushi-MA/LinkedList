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
void inorder(NODE);
void displayall(NODE);
void printwithinrange(NODE,float,float, int);
void printless95(NODE);
NODE maxproductrating(NODE, int);
int getmindata(NODE);
NODE deleteless2022(NODE,int);
void deleteratingzero(NODE );



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

    printf("\nID\tname\tMRP\texp_date\trating\t");
    displayall(root);

    while(choice!=100)
    {
        printf("\nSelect function");
        printf("\n1.MRP<95\n2.delete exp<2022\n3.display within range\n4.max rating\n5.delete rating zero\n100. BYE BYE\nCHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printless95(root);
                    break;
/*
            case 2: deleteless2022(root,2022);
                    printf("\nID\tname\tMRP\texp_date\trating\t");
                    displayall(root);
                    break;
*/

            case 3: printf("lower value = ");
                    scanf("%f",&p);
                    printf("upper value = ");
                    scanf("%f",&q);
                    printwithinrange(root,p,q,count);
                    printf("number = %d",count);
                    break;

            case 4: temp = maxproductrating(root,0);
                    printf("MAX product rating:\n");
                    printf("product ID = %d\nName = %s\nMRP = %.2f\nExpiry date = %d\nproduct rating = %d\n",temp->data.p_id, temp->data.name, temp->data.MRP, temp->data.exp_date, temp->data.product_rating);
                    break;
              
            case 5: deleteratingzero(root);
                    break;
                    

            case 100: break;
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

void displayall(NODE root)
{
    if(root==NULL)
    return;

    else
    {
        displayall(root->l);
        printf("\n%d\t%s\t%f\t%d\t%d\t",root->data.p_id, root->data.name, root->data.MRP, root->data.exp_date, root->data.product_rating);
        displayall(root->r);
    }
    return;
}

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

NODE maxproductrating(NODE root, int max)
{
    NODE temp;
    if(root==NULL)
    return temp;

    if(root->data.product_rating>max)
    {
        max=root->data.product_rating;
        temp=root;
    }

        maxproductrating(root->l,max);
        maxproductrating(root->r,max);

    return root;
}
/*
void max(NODE root)
{
    NODE cur, prev;
    for(cur=root->r;cur!=NULL;prev=cur,cur=cur->r);
    printf("\nmaximum number in the tree is  %d",prev->data);
    return;
}
*/

/*
int getmindata(NODE root)
{
    NODE cur,prev;
    for(cur=root->l;cur!=NULL;prev=cur,cur=cur->l);
    return cur->data.exp_date;
}

NODE deleteless2022(NODE root, int tag)
{
    //int tag=2022;
    NODE temp;

    if(root==NULL)
    return temp;

    else
    {
        deleteless2022(root->l,tag);
        deleteless2022(root->r,tag);

        if(root->data.exp_date==tag)
        {
            if(root->r==NULL && root->l==NULL)
            {
                free(root);
                 return NULL;
            }

            else if(root->r==NULL && root->l!=NULL)
            {
                NODE temp=root->l;
                free(root);
                return temp;
            }

            else if(root->l==NULL && root->r!=NULL)
            {
                NODE temp=root->r;
                free(root);
                return temp;
            }

            else
            {
                int mindata=getmindata(root->r);
                root->data.exp_date=mindata;
                root->r=deleteless2022(root->r,mindata);
            }
        }
    }
    return;

}
*/


NODE deletenode(NODE root,int USN)
{
    if(root==NULL) //base case
        return root;
    if(USN<root->data.p_id) //key to be deleted is smaller than root's data, then it lies in left subtree
        root->l=deletenode(root->l,USN);
    else if(USN>root->data.p_id)  //key to be deleted is greater than root's data, then it lies in right subtree
        root->r=deletenode(root->r,USN);
    else  //if the key is same as root's key then this is the node to be deleted
    {
         if(root->l==NULL) //node with only 1 child or no child
        {
            struct node *temp=root->r;
            free(root);
            return temp;
        }
        else if(root->r==NULL)
        {
             struct node *temp=root->l;
            free(root);
            return temp;
        }
        else{
        int minval=minvaluenode(root->r); //node with 2 children...smallest in right subtrees
        root->data.p_id=minval;   //copy the inoder..successor's content to this node
        root->right=deletenode(root->right,minval);  //delete the inorder successor
        }
    }
    return root;
}


int minvaluenode(NODE node) //return the min key value found in that tree
{
    NODE cur=node;
    while(cur&&cur->l!=NULL)
        cur=cur->left;
    return (cur->data.p_id);
}

void deleteratingzero(NODE root)
{
    if(root==NULL)
    return;

    else
    {
        if(root->data.product_rating==0)
        {
            deletenode(root,root->data.p_id);
        }

        deleteratingzero(root->l);
        deleteratingzero(root->r);
    }
    return;

}




