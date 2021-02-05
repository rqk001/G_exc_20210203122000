/*
 *  Test for BTREE.c
 *
 *  Populates the tree with up to NRAND random numbers
 *  (NRAND - collisions) in range 0 - (NRAND-1) and prints
 *  it out.
 *
 *  A nifty way of printing a btree was inspired by
 *  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
 *
 *  Uses malloc() and recursion.
 *
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#include "btree.h"

#define COUNT 5 // Indent in printout
#define NRAND 32  // # of tosses
#define RANGE 100 // Rang

// Helper function to allocates a new node 
struct node* newnode(int data) 
{ 
    struct node* node = malloc(sizeof(struct node)); 
    node->key = data; 
    node->left = node->right = 0; 
    return node; 
} 
  
// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->key); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void print2D(struct node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 
  
// Driver program to test above functions 
int main() 
{  
  struct node *root=0, *new;
  int i, n;

  srandom(time(0)); // Seed the RG

  n = random() % 100;
  root = newnode(n);

  for (i=0; i<NRAND; ++i) {
    n = random() % 100;
    if (btree_find(root, n) == 0) {   // Not found
      new = newnode(n);
      btree_insert(root, new);
    }
  }

  print2D(root);

  return 0;
}

