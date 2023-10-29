#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node* r;
    struct node* l;
};

typedef struct node* NODE;

NODE create(int);
NODE createtree(NODE);
NODE initialtree(NODE);
void insert(NODE,int);
void max(NODE);
void topview(NODE);
void findorinsertk(NODE);
int search(NODE, int);
void leaf(NODE);
void maxminleftright(NODE);
void depth__(NODE);
int depth(NODE);
void largestsubtree(NODE );
void lessequaln(NODE);
int lessequaln__(NODE, int);
void printpath(NODE);
void printpath__(NODE, int);
void common_ancestor(NODE);
void ancestor(NODE, int, int);
void addlarge(NODE);
void inorder(NODE);
int addd(NODE);

int main()
{
    int d,T,choice;
    NODE root=NULL;
    printf("1. Go with the present tree\n2. type your tree\nchoice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: root = initialtree(root);
                break;
        case 2: root = createtree(root);
                break;
        default: printf("choice doesn't exist  ");
    }

    printf("\nEnter function:\n1.find the maximum element\n2. print the top view of binary tree.\n3. Search key, if not present, then insert.\n");
    printf("4.Print all the leaf nodes.\n5.Find max and min of left and right subtree\n6.Find the depth of the given BST.\n7.Find the Largest subtree.\n");
    printf("8.find the greatest number in the binary search tree that is less than or equal to N.\n9.path from root to a given node.\n");
    printf("10.Print all the nodes that are common for 2 given nodes in a BST.\n11. Add the numbers larger than the node data\n");
    printf("100. Terminate this thing!\n");

    while(choice!=100)
    {
        printf("\nchoice:   ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: max(root); 
            break;

            case 2: topview(root);   
            break;

            case 3: findorinsertk(root);  
            break;

            case 4: leaf(root); 
            break;

            case 5: maxminleftright(root);  
            break;

            case 6: depth__(root);  
            break;

            case 7: largestsubtree(root); 
            break;

            case 8: lessequaln(root);   
            break;

            case 9: printpath(root); 
            break;

            case 10: common_ancestor(root); 
            break;

            case 11: addlarge(root);
            break;

            case 100: break;

            default: printf("\n.\n.\n.\nplease check your eyes!!!\n");
        }
    }
    printf("\n\nBYEEEEE\n");
    return 0;
}

NODE initialtree(NODE root)
{
    root=create(5);
    insert(root,2);
    insert(root,12);
    insert(root,1);
    insert(root,3);
    insert(root,9);
    insert(root,21);
    insert(root,19);
    insert(root,25);
    return root;
}

NODE createtree(NODE root)
{
    int T,a;
    printf("Enter the number of Nodes you want in the tree:  ");
    scanf("%d",&T);
    printf("Start entering the values");
    scanf("%d",&a);
    root=create(a);
    while(--T)
    {
        scanf("%d",&a);
        insert(root,a);
    }
    return root;
}

NODE create(int data)
{
    NODE newnode=(NODE)malloc(sizeof(struct node));
    newnode->data=data;
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
        if(root->data==data)
        {
            printf("no already exist %d\n",data);
            return;
        }

        else if(data<root->data)
            root=root->l;

        else
            root=root->r;
    }

    NODE newnode=create(data);
    if(data<prev->data)
        prev->l=newnode;
    else
        prev->r=newnode;
    
    return;
}

/* 1.  The task is to find the maximum element in this given BST */
void max(NODE root)
{
    NODE cur, prev;
    for(cur=root->r;cur!=NULL;prev=cur,cur=cur->r);
    printf("\nmaximum number in the tree is  %d",prev->data);
    return;
}

/* 2.  The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.*/
void topview(NODE root)
{
    NODE temp=root;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->l;
    }
    temp=root->r;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->r;
    }
}

/* 3. If key K is not present in the BST, Insert a new Node with a value equal to K into the BST. Note: If K is already present in the BST, don't modify the BST */
void findorinsertk(NODE root)
{
    int K, flag;
    printf("enter K:  ");
    scanf("%d",&K);
    flag = search(root, K);
    if(flag==1)
        printf("K found!!!");
    else
    {
        insert(root,K);
        printf("\nK not found. Therefore K has been inserted!");
    }
    return;
}
int search(NODE root, int N)
{
    NODE cur=root, prev=NULL;
    int flag=0;
    while(cur!=NULL)
    {
        if(cur->data==N)
        {
            flag=1;
            break;
        }

        else if(N>cur->data)
            cur=cur->r;

        else
            cur=cur->l;
    }
    return flag;
}

/* Print all the leaf nodes. */
void leaf(NODE root)
{
    NODE cur=root;
    if(root==NULL)
        return;

    if(cur->l==NULL && cur->r==NULL)
        printf("%d  ",cur->data);

        leaf(root->l);
        leaf(root->r);
    return;
}

/* Find max and min of given subtree. */
void maxminleftright(NODE root)
{
    NODE cur, prev;

    for(cur=root->l;cur!=NULL;prev=cur,cur=cur->r);
    printf("\nmax in left sub tree is  %d",prev->data);
    for(cur=root->l;cur!=NULL;prev=cur,cur=cur->l);
    printf("\nmin in left sub tree is  %d",prev->data);
    for(cur=root->r;cur!=NULL;prev=cur,cur=cur->l);
    printf("\nmin in right sub tree is  %d",prev->data);
    for(cur=root->r;cur!=NULL;prev=cur,cur=cur->r);
    printf("\nmax in right sub tree is  %d",prev->data);
    return;
}

/* 4. Find the depth of the given BST. */
void depth__(NODE root)
{
    int d=depth(root);
    printf("\ndepth of the tree is  %d",d);
}
int depth(NODE root)
{
    if(root==NULL)
        return -1;

    int rd=depth(root->r), ld=depth(root->l);

    if(rd>ld)
        return rd+1;

    else
        return ld+1;
}

/* 7. Find the Largest subtree. */
void largestsubtree(NODE root)
{
    int rd=depth(root->r), ld=depth(root->l);
    if(rd>ld)
        printf("right sub tree is larger");

    else if(ld>rd)
        printf("left sub tree is larger");

    else
        printf("both trees have equal depth");
}

/* 9. Given a binary search tree and a number N, find the greatest number in the binary search tree that is less than or equal to N. */
void lessequaln(NODE root)
{
    int N;
    printf("enter N for -less than or equal to- function:   ");
    scanf("%d",&N);
    int d;
    d=lessequaln__(root,N);
    printf("\nnumber = %d",d);
    return;
}
int lessequaln__(NODE root, int N)
{
    NODE cur=root, prev=NULL;
    while(1)
    {
        if(N==cur->data)
            return N;

        if(N>cur->data)
        {
            prev=cur;
            cur=cur->r;
        }

        else if(N<cur->data)
        {
            prev=cur;
            cur=cur->l;
        }

        if(N>prev->data && N<cur->data)
            return (prev->data);
    }
}

/* 10. Print path from root to a given node in a BST. */
void printpath(NODE root)
{
    int N;
    printf("Enter the node for the path:  ");
    scanf("%d",&N);
    printpath__(root,N);
    return;
}
void printpath__(NODE root, int N)
{
    int d;
    NODE prev=NULL, cur=root;
    while(1)
    {
        printf("%d  ",cur->data);
        if(cur->data==N)
            return;

        else if(N<cur->data)
        cur=cur->l;

        else
        cur=cur->r;
    }
    return;
}

/* Given a BST and two nodes, the task is to Print all the nodes that are common for 2 given nodes in a BST */
void common_ancestor(NODE root)
{
    int a,b;
    printf("enter the numbers for common ancestors:\n");
    scanf("%d %d",&a,&b);

    if(a<b)
        ancestor(root,a,b);

    else
        ancestor(root,b,a);
    return;
}

void ancestor(NODE root, int A, int B)
{
    int d;
    NODE cur=root;
    if(root->data==A || root->data==B)
        printf("\nNo ancestors as one of the inputs is the root!");
    
    else
    {
        while(1)
        {
            printf("%d  ",cur->data);

            if(A>cur->data && B>cur->data)   
            cur=cur->r;

            else if (A<cur->data && B<cur->data)
            cur=cur->l;

            else
            break;
        }
    }
    
    return;
}

/* 8. Given a BST, modify it so that all greater values in the given BST are added to every node. */
void addlarge(NODE root)
{
    // NODE cur=root, prev=NULL;
    // int sum;
    // //inorder(root);
    // sum=addd(root);
    // printf("sum = %d",sum);
   
    printf("\nNOT YET DONE!!!   ;)\n");
    return;

}

int addd(NODE root)
{
    // if(root==NULL)
    //     return 0;

    // int sum;
    // sum=addd(root->r)+addd(root->l)+root->data;
    // printf("%d + %d + %d = %d",root->r->data,root->l->data,root->data,sum);
    // return sum;

    return 0;
}