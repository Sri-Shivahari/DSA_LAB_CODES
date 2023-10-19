#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->item);
}

// Create a new Node
struct node* create(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = create(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = create(value);
  return root->right;
}

// Function to take user input for binary tree
struct node* buildBinaryTree() {
  int n, value;
  struct node* root = NULL;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Invalid number of elements.\n");
    return NULL;
  }

  printf("Enter the root value: ");
  scanf("%d", &value);
  root = create(value);

  for (int i = 1; i < n; i++) {
    printf("Enter the value for node %d: ", i + 1);
    scanf("%d", &value);

    struct node* current = root;
    while (1) {
      printf("Insert to the left (l) or right (r) of %d: ", current->item);
      char choice;
      scanf(" %c", &choice);

      if (choice == 'l') {
        if (current->left == NULL) {
          insertLeft(current, value);
          break;
        } else {
          current = current->left;
        }
      } else if (choice == 'r') {
        if (current->right == NULL) {
          insertRight(current, value);
          break;
        } else {
          current = current->right;
        }
      }
    }
  }

  return root;
}

int main() {
  struct node* root = buildBinaryTree();

  if (root == NULL) {
    printf("Binary tree creation failed.\n");
    return 1;
  }

  printf("Traversal of the inserted tree \n");
  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);

return 0;
}
