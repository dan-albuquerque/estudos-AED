#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

void insert(TreeNode **root, int data);
void inorder(TreeNode *root);
void postorder(TreeNode *root);
void preorder(TreeNode *root);
int search(TreeNode *node, int key);

void delete(TreeNode **root, int key);
TreeNode *findMaxOnLeft(TreeNode **node);

int main() {
  TreeNode *tree = NULL;

  insert(&tree, 6);
  insert(&tree, 2);
  insert(&tree, 8);
  insert(&tree, 7);
  insert(&tree, 9);
  insert(&tree, 1);
  insert(&tree, 4);
  insert(&tree, 3);

  printf("\nPreorder Traversal:");
  preorder(tree);

  printf("\nInorder Traversal:");
  inorder(tree);

  printf("\nPostorder Traversal:");
  postorder(tree);
  printf("\n\n");

  int key = 4;
  if (search(tree, key)) {
    printf("\nThe number is in the tree!\n");
  } else { 
    printf("The number is NOT in the tree!\n");
  }

  printf("\nPreorder Traversal:");
  preorder(tree);
  printf("\n");

  delete(&tree, 8);

  printf("\nPrint after deletion (Preorder Traversal):");
  preorder(tree);
  printf("\n");

  return 0;
}
//auto formatação no VS code?

void preorder(TreeNode *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(TreeNode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postorder(TreeNode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void insert(TreeNode **root, int data) {
  if (*root == NULL) {
    *root = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = data;
  } else {
    if (data < (*root)->data) {
      insert(&(*root)->left, data);
    }
    if (data > (*root)->data) {
      insert(&(*root)->right, data);
    }
  }
}

int search(TreeNode *node, int key) {
  if (node == NULL)
    return 0;
  if (node->data == key)
    return 1;
  if (key < node->data)
    return search(node->left, key);
  else
    return search(node->right, key);
}

TreeNode *findMaxOnLeft(TreeNode **node) {
  if ((*node)->right != NULL)
    return findMaxOnLeft(&(*node)->right);
  else {
    TreeNode *temp = *node;
    if ((*node)->left != NULL) {
      *node = (*node)->left;
    } else {
      *node = NULL;
    }
    return temp;
  }
}

void delete(TreeNode **root, int key) {
  if (*root == NULL) {
    printf("Number does not exist in the tree!");
    return;
  }
  if (key < (*root)->data)
    delete(&(*root)->left, key);
  else if (key > (*root)->data)
    delete(&(*root)->right, key);
  else {
    TreeNode *tempNode = *root;
    // Case 1 - Node with no children
    if ((*root)->left == NULL && (*root)->right == NULL) {
      free(tempNode);
      (*root) = NULL;
    } else {
      // Case 2 - Node with a right child
      if ((*root)->left == NULL) {
        (*root) = (*root)->right;
        tempNode->right = NULL;
        free(tempNode);
        tempNode = NULL;
      } else {
        // Case 2 - Node with a left child
        if ((*root)->right == NULL) {
          (*root) = (*root)->left;
          tempNode->left = NULL;
          free(tempNode);
          tempNode = NULL;
        } else {
          // Case 3 - Node with two children
          tempNode = findMaxOnLeft(&(*root)->left);
          tempNode->left = (*root)->left;
          tempNode->right = (*root)->right;
          (*root)->left = (*root)->right = NULL;
          free((*root));
          *root = tempNode;
          tempNode = NULL;
        }
      }
    }
  }
}
