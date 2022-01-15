#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node{
char data[10];
struct node *left;
struct node *right;
};

struct node *create()
{
    struct node *k;
char n[10];
printf("\nenter the Team and Members:");
scanf("%s",n);
if(strcmp(n,"null")==0)
{
    return 0;
}
    k=(struct node*) malloc(sizeof(struct node));
strcpy(k->data,n);
printf("\nEnter the Left wing player  %s:",n);
k->left=create();
printf("\Eenter the Right wing player %s:",n);
k->right=create();
return k;
}

int isfull(struct node *t)
{
    if (t == NULL)
        return 1;

    if (t->left == NULL && t->right == NULL)
        return 1;

    if ((t->left) && (t->right))
        return (isfull(t->left) && isfull(t->right));

      return 0;
}
int del(struct node *t)
{


    if (t == NULL) return 0;

    del(t->left);
    del(t->right);
    free(t);

}

void preord(struct node *t)
{
    if(t!=NULL)
    {
        printf("\n%s\n",t->data);
        preord(t->left);
        preord(t->right);
    }
}
void inord(struct node *t)
{
    if(t!=NULL)
    {
        inord(t->left);
        printf("\n%s\n",t->data);
        inord(t->right);
    }
}
void post(struct node *t)
{
    if(t!=NULL)
    {
        post(t->left);
        post(t->right);
        printf("\n%s\n",t->data);
    }
}
int main()
{
    struct node *root;
    int n;
    while(n!=0)
    {
        printf("\tFOOTBALL TEAM \n");
        printf("1.Entering the Players:\n");
        printf("2.Prerder\n");
        printf("3.Inorder\n");
        printf("4.Postorder\n");
        printf("5.Isfull or not\n");
        printf("6.Deletion\n");
        printf("\nEnter the option:");
        scanf("%d",&n);
        switch(n)
        {

case 1:{
    root=create();
    break;
}
case 2:
    {
printf("\nPreorder\n");
preord(root);
printf("\n");
break;
}
case 3:
    {
printf("\nInorder\n");
inord(root);
printf("\n");
break;
    }
case 4:{
printf("\nPostorder\n");
post(root);
printf("\n");
break;
}
case 5:{
    int m=isfull(root);
    if(m==1)
    {
        printf("\nTeam is complete\n\n");
    }
    else
        printf("\nTeam is Incomplete\n\n");
    break;
        }
case 6:{
printf("\nTEAM DELETED\n");
del(root);
printf("\n");
break;
}
}
    }
return 0;
}
