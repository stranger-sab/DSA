#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
  

void create()
{
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &data);
            start->info = data;
  
            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to"
                       " be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}
  

void traverse()
{
    struct node* temp;
  
    
    if (start == NULL)
        printf("\nList is empty\n");
  
    
    else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}
  

void insertF()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;
  
    
    temp->link = start;
    start = temp;
}
  

void insertE()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
  
    
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
  
    
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
  

void insertP()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
  
    
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
  
    
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}
  

void deleteF()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}
  

void deleteE()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}
  

void deleteP()
{
    struct node *temp, *position;
    int i = 1, pos;
  
    
    if (start == NULL)
        printf("\nList is empty\n");
  
    
    else {
        printf("\nEnter index : ");
  
        
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
  
        
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
  
        
        position = temp->link;
        temp->link = position->link;
  
        
        free(position);
    }
}
  void sort()
{
    struct node* current = start;
    struct node* index = NULL;
    int temp;
  
    
    if (start == NULL) {
        return;
    }
  
    
    else {
  
        
        while (current != NULL) {
            index = current->link;
  
            
            while (index != NULL) {
  
                
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
  
            
            current = current->link;
        }
    }
}

void search()
{
    int data;
    struct node*current =start;
    int i=0;
    _Bool flag=fclose;
    printf("Enter the search element:");
    scanf("%d", &data);
    if(start==NULL)
    {
        printf("Empty list\n");
    }
    else
    while(current!=NULL)
    {
        if (current->info==data){
            flag=free;
            break;
        }i++;
        current=current->link;
    }
    if(flag){
        printf("Element %d is present at position %d\n", data, i);
    }
    else
        printf("Element not found in the list");
}

int main()
{
    int choice;
    while (choice!="10") 
    {
  
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at first\n");
        printf("\t3  For insertion at end\n");
        printf("\t4  For insertion at  any position\n");
        printf("\t5  For deletion of first element\n");
        printf("\t6  For deletion of last element\n");
        printf("\t7  For deletion of element at any position\n");
        printf("\t8  To sort the element\n");
        printf("\t9  To search for a particular element\n");
        printf("\t10 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
  
        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insertF();
                break;
            case 3:
                insertE();
                break;
            case 4:
                insertP();
                break;
            case 5:
                deleteF();
                break;
            case 6:
                deleteE();
                break;
            case 7:
                deleteP();
                break;
            case 8:
                sort();
                break;
            case 9:
                search();
                break;
            case 10:
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
    return 0;
}
