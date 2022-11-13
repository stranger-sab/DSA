#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node
{
    int data;
    struct node* next;
};
struct node *head[MAX]={NULL},*c;
void insert(int n)
{

    int i,temp,key;
    /*struct node *c;
    struct node *head[n];
    head[n]=NULL;*/
    //head->data=NULL;
    printf("\nEnter the value to be inserted:\n");
    for (i=0;i<n;i++){
        scanf("%d",&key);
        temp=key%n;
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=key;
        newnode->next=NULL;
        if(head[temp]==NULL)
            head[temp]=newnode;
        else{
            c=head[temp];
            while(c->next!=NULL)
                c=c->next;
            c->next=newnode;
        }
    }
}
int main()
{
    int size,i;
    /*struct node *c;
    struct node *head[size];
    head[size]=NULL;*/
    printf("\nEnter the number of values:");
    scanf("%d",&size);
    insert(size);
    for(i=0;i<size;i++){
        printf("\nEntry at %d:" ,i);
        if(head[i]==NULL)
            printf("No entry!");
        else{
            for(c=head[i];c!=NULL;c=c->next)
                printf("%d->",c->data);
        }
    }
}
