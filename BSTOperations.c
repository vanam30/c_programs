#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node * create(int item){
    struct Node * node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("-->%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("-->%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("-->%d ",root->data);
}

struct Node * insertion(struct Node *root, int item){
    if(root == NULL){
        return create(item);
    }
    if(item < root->data){
        root->left = insertion(root->left, item);
    }
    else if (item > root->data){
        root->right = insertion(root->right, item);
    }
    else{
        return root;
    }
}
//find the in-order successor
struct Node *findInorderSuccessor(struct Node *node ){
    struct Node *current = node;
    //Find the leftmost leaf
    while(current && current->left != NULL){
        current = current->left;
    }

    return current;
}
struct Node * deleteNode(struct Node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        //if the node is with one child or no child
        if(root->left == NULL){
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        //If the node has two children
        struct Node *temp = findInorderSuccessor(root->right);
        //place the in-order successor in position of the node to be deleted
        root->data = temp->data;
        //Delete the in-order successor.
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool isFullBinaryTree(struct Node *root){
    //Checking tree emptiness
    if(root == NULL){
        return true;
    }
    //Checking the presence of children
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left && root->right){
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }
    return false;
}
int countNumOfNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNumOfNodes(root->left) + countNumOfNodes(root->right);
}
bool isCheckCompleteBinaryTree(struct Node *root, int index, int numberOfNodes){
    //Check if the tree is complete
    if(root == NULL){
        return true;
    }
    if(index >= numberOfNodes){
        return false;
    }
    return (isCheckCompleteBinaryTree(root->left, 2*index + 1, numberOfNodes) &&
            isCheckCompleteBinaryTree(root->right, 2*index + 2, numberOfNodes));
}
int height(struct Node* root){
    if(root == NULL)
        return 0;
    else{
        int leftDepth = height(root->left);
        int rightDepth = height(root->right);

        if(leftDepth > rightDepth){
            return leftDepth + 1;
        }
        else{
            return rightDepth + 1;
        }
    }
}
//Check for height balance
bool checkHeightBalance(struct Node *root, int *height){
    //Check for emptiness
    int leftHeight = 0, rightHeight = 0;
    int L = 0, R = 0;

    if(root == NULL){
        *height = 0;
        return 1;
    }

    L = checkHeightBalance(root->left, &leftHeight);
    R = checkHeightBalance(root->right, &rightHeight);

    *height = ((leftHeight > rightHeight)? leftHeight:rightHeight) + 1;

    if((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2)){
        return 0;
    }
    else
        return L && R;
}


int main()
{
    struct Node *root = NULL;
    int choice, item;
    do{
        printf("\nBST Operations");
        printf("\nPress 1 to insert.");
        printf("\nPress 2 to delete.");
        printf("\nPress 3 to Pre-order traversal.");
        printf("\nPress 4 to  In-order traversal.");
        printf("\nPress 5 to Postorder traversal");
        printf("\nPress 6 to check for full binary tree");
        printf("\nPress 7 to check for Complete Binary tree");
        printf("\nPress 8 to print the height of Binary tree");
        printf("\nPress 9 to check height balance of the tree.");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice (0, 1, 2, 3, 4, 5, 6, 7) : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("\nEnter the item which you want to insert : ");
                scanf("%d", &item);
                root = insertion(root, item);
                break;
            }
            case 2:{
                printf("\nEnter the item which you want to delete : ");
                scanf("%d", &item);
                root = deleteNode(root, item);
                break;
            }
            case 3:{
                preorder(root);
                break;
            }

            case 4:{
                inorder(root);
                break;
            }

            case 5:{
                postorder(root);
                break;
            }
            case 6:{
                bool b = isFullBinaryTree(root);
                if(b){
                    printf("\nIt is a full binary tree.");
                }
                else{
                    printf("\nIt is not a full binary tree.");
                }
                break;
            }
            case 7:{
                int nodeCount = countNumOfNodes(root);
                int index = 0;
                if(isCheckCompleteBinaryTree(root, index, nodeCount)){
                    printf("\nThe tree is complete binary tree.\n");
                }
                else{
                    printf("\nThe tree is not a complete binary tree.\n");
                }
                break;
            }
            case 8:{
                int h = height(root);
                printf("\nHeight of the tree : %d", h);
                break;
            }
            case 9:{
                int height = 0;
                if(checkHeightBalance(root, &height)){
                    printf("\nThe tree is balanced.");
                }
                else{
                    printf("\nThe tree is not balanced.");
                }
                break;
            }
            case 0:{
                exit(choice);
            }
            default:{
                printf("\nWrong option selected.");
            }
        }
    }while(1);
    return 0;
}
