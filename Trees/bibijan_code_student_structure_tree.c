#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int USN;
    char name[10];
    int marks[6];
    float Avg_marks;
    char grade;
};

struct node
{
    struct node *left;
    struct node *right;
    struct student data;
};

struct node *create(int USN)
{
    struct node *root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data.USN=USN;
    printf("Name,Avg_marks,Grade,Marks\n");
    scanf("%s %f %c",root->data.name,&root->data.Avg_marks,&root->data.grade);
    for(int i=0;i<6;i++)
        scanf("%d",&root->data.marks);
    printf("\n");
    root->left=NULL;
    root->right=NULL;
    return root;
};

struct node* insertnode(struct node* root,int USN)
{
    if(root==NULL)
    {
        root=create(USN);
        return root;
    }
     if(root->data.USN>USN)
    {
        root->left=insertnode(root->left,USN);
        return root;
    }
    if(root->data.USN<USN)
    {
        root->right=insertnode(root->right,USN);
        return root;
    }
}

struct node *count(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
        int left=count(root->left);
        int right=count(root->right);

    return 1+left+right;
}


void S_grade(struct node* root)
{
    if(root==NULL)
        return;
    if(root->data.grade=='S')
        printf("%d %s %0.2f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
        S_grade(root->left);
        S_grade(root->right);
}

static int a=0;
int A_grade(struct node* root)
{
    if(root!=NULL)
    {
       if(root->data.grade=='A')
       {
          printf("%d %s %0.2f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
          a++;
       }
          A_grade(root->left);
         A_grade(root->right);
    }
   return a;
}

static int b=0;
int B_grade(struct node* root)
{
    if(root!=NULL)
    {
       if(root->data.grade=='B')
       {
          printf("%d %s %0.2f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
          b++;
       }
        B_grade(root->left);
        B_grade(root->right);
    }
    return b;
}

static int c=0;
int C_grade(struct node* root)
{
    if(root!=NULL)
    {
       if(root->data.grade=='C')
       {
          printf("%d %s %0.2f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
          c++;
       }
        C_grade(root->left);
        C_grade(root->right);
    }
    return c;
}

static int f=0;
int F_grade(struct node* root)
{
    if(root!=NULL)
    {
    if(root->data.grade=='F')
    {
        printf("%d %s %0.2f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
        f++;
    }
        F_grade(root->left);
        F_grade(root->right);
    }
        return f;
}

void inorderoftree(struct node* root)
{
     if(root!=NULL)
     {
        inorderoftree(root->left);
        printf("%d %s %0.2f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
        inorderoftree(root->right);
    }
}

struct node *max_avg(struct node *root)
{
    float max=0.0;
    struct node* temp;
    if(root==NULL)
        return temp;
     if(root->data.Avg_marks > max)
     {
         max=root->data.Avg_marks;
         temp=root;
     }
     max_avg(root->left);
     max_avg(root->right);
     return root;
}

int minvaluenode(struct node * node) //return the min key value found in that tree
{
    struct node* cur=node;
    while(cur&&cur->left!=NULL)
        cur=cur->left;
    return (cur->data.USN);
}

int search(struct node* root,char grade)
{
    if(root==NULL)
        return -1;

    if(root->data.grade==grade)
    {
        return root->data.USN;
    }
        search(root->left,grade);
        search(root->right,grade);
        return ;

}

struct node* deletenode(struct node*root,int USN)
{
    if(root==NULL) //base case
        return root;
    if(USN<root->data.USN) //key to be deleted is smaller than root's data, then it lies in left subtree
        root->left=deletenode(root->left,USN);
    else if(USN>root->data.USN)  //key to be deleted is greater than root's data, then it lies in right subtree
        root->right=deletenode(root->right,USN);
    else  //if the key is same as root's key then this is the node to be deleted
    {
         if(root->left==NULL) //node with only 1 child or no child
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
             struct node *temp=root->left;
            free(root);
            return temp;
        }
        else{
        int minval=minvaluenode(root->right); //node with 2 children...smallest in right subtrees
        root->data.USN=minval;   //copy the inoder..successor's content to this node
        root->right=deletenode(root->right,minval);  //delete the inorder successor
        }
    }
    return root;
}

void display_all(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d %s %f %c\n",root->data.USN,root->data.name,root->data.Avg_marks,root->data.grade);
    display_all(root->left);
    display_all(root->right);
}

int main()
{
  struct node* root=NULL;
  root=insertnode(root,5);
  root=insertnode(root,3);
  root=insertnode(root,7);
  root=insertnode(root,4);
  root=insertnode(root,2);
  root=insertnode(root,8);
  root=insertnode(root,6);

 /* inorderoftree(root);
  printf("\n");

  printf("Students with S grade :\n");
  S_grade(root);
  printf("\n");

  printf("Students with A grade :\n");
  int a;
  a=A_grade(root);
  printf("A grade = %d\n",a);
  //printf("\nNumber of nodes in tree is %d\n",count(root));
  printf("\n");

  printf("Students with B grade :\n");
  int b;
  b=B_grade(root);
  printf("B grade = %d\n",b);
  printf("\n");

  printf("Students with C grade :\n");
  int c;
  c=C_grade(root);
  printf("C grade = %d\n",c);
  printf("\n");

  printf("Students with F grade :\n");
  int f;
  f=F_grade(root);
  printf("F grade = %d\n",f);
  printf("\n");

  struct node *temp=NULL;
  temp=max_avg(root);
  printf("Student with Maximum average marks \n%d %s %0.2f %c\n",temp->data.USN,temp->data.name,temp->data.Avg_marks,temp->data.grade);

  int USN;
  printf("\nEnter the USN to be withdrawn\n");
  scanf("%d",&USN);
  root=deletenode(root,USN);
  inorderoftree(root);
  printf("\n");

   int m;
   m=search(root,'F');
   root=deletenode(root,m);
   //inorderoftree(root);
   display_all(root);*/


   while(1)
     {
         int ch;
         int m,USN,a,b;
         struct node *temp=NULL;
         struct node*cur=root;
         printf("\nEnter the choice\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:inorderoftree(root);
             break;
             case 2:S_grade(root);
             break;
             case 3:a=A_grade(root);
                    printf("Number of students with A grade= %d\n",a);
             break;
             case 4:b=B_grade(root);
                    printf("Number of students with B grade=  %d\n",b);
             break;
             case 5:c=C_grade(root);
                    printf("Number of students with C grade=  %d\n",c);
             break;
             case 6:f=F_grade(root);
                    printf("Number of students with F grade=  %d\n",f);
             break;
             case 7:temp=max_avg(root);
                    printf("Student with Maximum average marks \n%d %s %0.2f %c\n",temp->data.USN,temp->data.name,temp->data.Avg_marks,temp->data.grade);
             break;
             case 8:
                printf("Enter the USN to be withdrawn\n");
                    scanf("%d",&USN);
                    cur=deletenode(cur,USN);
                    inorderoftree(cur);
             break;
             case 9:m=search(root,'F');
                    root=deletenode(root,m);
                    inorderoftree(root);
             break;
            default:exit(0);
              break;
         }
     }
}
