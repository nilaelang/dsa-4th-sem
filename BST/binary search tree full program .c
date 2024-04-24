
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Error allocating memory!\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* searchNode(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

Node* findMinimum(Node *root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node *temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void printTree(Node *root, int space) {
    int i;
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}
void freeBST(Node *root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;
    int choice, data, count, i,space;

    while (1) {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert multiple data\n2. Delete data\n3. Search for data\n");
        printf("4. Inorder traversal\n5. Preorder traversal\n6. Postorder traversal\n7. Print\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many data items do you want to insert? ");
                scanf("%d", &count);
                for (i = 0; i < count; i++) {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    root = insertNode(root, data);
                }
                break;
            case 2:
                printf("How many data items do you want to delete? ");
                scanf("%d", &count);
                for (i = 0; i < count; i++) {
                    printf("Enter data to delete: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
                }
                break;
            case 3:
                printf("How many data items do you want to search for? ");
                scanf("%d", &count);
                for (i = 0; i < count; i++) {
                    printf("Enter data to search for: ");
                    scanf("%d", &data);
                    Node *found = searchNode(root, data);
                    if (found != NULL) {
                        printf("Data %d found in the tree.\n", found->data);
                    } else {
                        printf("Data %d not found in the tree.\n", data);
                    }
                }
                break;
            case 4:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printTree(root, space);
                break;
            case 8:
                freeBST(root);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

