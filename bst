#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *node;

treeNode* Create(treeNode *node, int data)
{
    if (node == NULL)
    {
        treeNode *temp;
        temp= (treeNode*)malloc(sizeof(treeNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data))
        node->left = Create(node->left, data);
    else if (data > node->data)
        node -> right = createtree(node->right, data);
    return node;
}

treeNode* Find(treeNode *node, int data)
{
    if(node == NULL)
        printf("\nElement not found");
    else if(data < node->data)
        node->left=search(node->left, data);
    else if(data > node->data)
        node->right=search(node->right, data);
    else
        printf("\nElement found is: %d", node->data);
    return node;
}


void PrintInorder(treeNode *node)
{
    if(node != NULL)
    {
        PrintInorder(node->left);
        printf("%d\t", node->data);
        PrintInorder(node->right);  
    }
}

void PrintPreorder(treeNode *node)
{
    if(node != NULL)
    {
        printf("%d\t", node->data);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
    }
}

void PrintPostorder(treeNode *node)
{   
    if(node != NULL)
    {  
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d\t", node->data);
    }
}

treeNode* findMin(NODE *node)
{
    if(node==NULL)
        return NULL;
    if(node->left)
        return findMin(node->left);
    else
        printf("\t%d",node->data);
    return node;
}

treeNode* findMax(treeNode *node)
{
    if(node==NULL)
        return NULL;
    if(node->right)
        return findMax(node->right);
    else
        printf("\t%d",node->data);
    return node;
}

treeNode* Delete(treeNode *node, int data)
{
    treeNode *temp;
    if(node == NULL)
        printf("\nElement not found");
    else if(data < node->data)
        node->left = Delete(node->left, data);
    else if(data > node->data)
        node->right = Delete(node->right, data);
    else{
/* Now We can delete this node and replace with either minimum element in the right sub tree or maximum element in the left subtree */
        if(node->right && node->left)
        { /* Here we will replace with minimum element in the right sub tree */
            temp = findMin(node->right);
            node -> data = temp->data;
/* As we replaced it with some other node, we have to delete that node */
            node -> right = Delete(node->right,temp->data);
        }
        else
        {
/* If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child */
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); /* temp is longer required */
        }
    }
    return node;
}

void main()
{
    int data, ch, i, n;
    treeNode *root=NULL;
    printf("\nImplementation of binary search tree\nEnter number if nodes: " );
    scanf("%d", &n);
    printf("\nEnter number to be inserted:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &data);
        root=Create(root, data);
    }
    while (1)
    {
        printf("\n1.Insertion in Binary Search Tree");
        printf("\n2.Search Element in Binary Search Tree");
        printf("\n3.Delete Element in Binary Search Tree");
        printf("\n4.Display by Inorder\n5.Display by Preorder\n6.Display by Postorder\n7.Find Minimum Element\n8.Find Maximum Element\n9.Exit");
        printf("\nEnter your choice: ");

scanf("%d", &ch);


switch (ch)

{

case 1: printf("\nEnter how many elements you want to insert: " );

scanf("%d", &n);

printf("\nEnter the values to create the binary tree:\n");

for(i=0; i<n; i++)

{

scanf("%d", &data);

root=createtree(root, data);

}

break;


case 2: printf("\nEnter the element to search: ");

scanf("%d", &data);

root=search(root, data);

printf("\nDisplaying the tree by Inorder Traversal of BST: \n");

inorder(root);

break;


case 3: printf("\nEnter the element to delete: ");

scanf("%d", &data);

root=del(root, data);

printf("\nDisplaying the tree by Inorder Traversal of BST: \n");

inorder(root);


break;


case 4: printf("\nInorder Traversal: \n");

inorder(root);

break;


case 5: printf("\nPreorder Traversal: \n");

preorder(root);

break;


case 6: printf("\nPostorder Traversal: \n");

postorder(root);

break;


case 7: printf("\nMinimum element in the BST: \n");

findMin(root);

break;


case 8: printf("\nMaximum element in the BST: \n");

findMax(root);

break;


case 9: exit(0);

default:printf("\nWrong option");

break;

}

}

}
