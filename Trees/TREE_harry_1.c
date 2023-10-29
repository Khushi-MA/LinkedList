#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

// Not used " typedef struct node* NODE; " in this function

struct node * create_node(int);
void insert_node(struct node*, int);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
int isBST (struct node*);
int searchnode(struct node*, int);
struct node * searchnode2(struct node *, int);
struct node * deletenode(struct node *, int);
struct node * inorderpredecessor(struct node *);

int main()
{
    // constructing the root node with create node
    struct node *p = create_node(50);
    // inserting the remaining nodes (this can be done manually too)
    insert_node(p,30);
    insert_node(p,60);
    insert_node(p,10);
    insert_node(p,40);
    insert_node(p,20);
    insert_node(p,15);
    

    // tree looks like this
    //               50
    //              / \
    //            30   60
    //           / \
    //         10   40

    // printf("\nPreorder:  ");
    // preorder(p);
    printf("\nInorder:  ");
    inorder(p);
    // printf("\nPostorder:  ");
    // postorder(p);
    // if(isBST(p))     // output is 1
    // printf("\nYes it is a BST!!!");
    // else
    // printf("\nIt is not a BST!!!");
    int target;
    printf("enter the target to search:  ");
    scanf("%d", &target);
    // if(searchnode(p,target))
    // printf("Target found!!!");
    // else printf("Target NOT found");
    // struct node * outputnode = searchnode2(p,target);
    // if(outputnode!=NULL)
    // printf("Target - %d -  found!!!", outputnode->data);
    // else printf("Target NOT found"); 
    deletenode(p,target);
    printf("\nInorder:  ");
    inorder(p);

    return 0;
}

struct node* create_node(int key)
{
    struct node *p;    // creating the node pointer
    p = (struct node*)malloc(sizeof(struct node));    // allocating the memory
    p->left = NULL;
    p->right = NULL;
    p->data = key;
    return p;   // returning the created node
}

void insert_node(struct node* root, int key)
{
    struct node* prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("\nCannot insert %d, already there in teh BST", key);
            return;
        }

        else if(key<root->data)
        root = root->left;

        else // (key>root->data)
        root = root->right;
    }

    struct node* new = create_node(key);

    if(key<prev->data)
    prev->left=new;

    else
    prev->right=new;
    return;
}


// root ->left ->right
// inbuilt: 5 3 1 4 6

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return; 
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
    return; 
}

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
    return; 
}

int isBST (struct node* root)
{
    static struct node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
            return 0;

        if(prev!=NULL && root->data <= prev->data)
            return 0;

        return isBST(root->right);
    }
    else
    return 1; 
}

int searchnode(struct node *root, int target)
{
    struct node* cur=root;
    while(cur!=NULL)
    {
        if(cur->data==target)
        return 1;

        else if(target < cur->data)
        cur=cur->left;

        else
        cur=cur->right;
    }
    return 0;
}

struct node * searchnode2(struct node * root, int target)
{
    if(root==NULL || root->data==target)
    return root;

    else if(target < root->data)
    return searchnode2(root->left, target);

    else
    return searchnode2(root->right, target);
}

/*
search for the node
Search for inorder pre or the inorder post
keep doing this until the tree has no nodes

*/

struct node * inorderpredecessor(struct node * root)
{
    root = root->left;
    while(root->right!=NULL)
        root = root->right;

    return root;
}

struct node * deletenode(struct node * root, int target)
{
    if(root==NULL)
        return NULL;

    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    
    struct node * ipre;
    // search for the node to be deleted
    if(target < root->data)
        root->left = deletenode(root->left,target);

    else if(target > root->data)
        root->right = deletenode(root->right, target);

    else
    {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

