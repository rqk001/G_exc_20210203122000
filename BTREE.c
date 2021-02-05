#include "btree.h"

// These functions assune the binary tree is presorted
//
// New nodes are always added at leaves, balancing is not done
//

// Returns a node with given key, 0 if not found
struct node *
btree_find(struct node *root, int key)
{
  struct node *f = root, *p;

  // Descend
  while (f) {
    p = f;
    // Found
    if (f->key == key)
      return f;

    // Which way to look
    if (f->key > key)
      f = f->left;
    else
      f = f->right;
  }
  return f; // 0
}
  
// Inserts a node into binary tree. Returns 0 on success, -1 on failure
int
btree_insert(struct node *root, struct node *el)
{
  struct node *f = root, *p;

  // Descend to the leaf with closest key
  while (f) {
    p = f;    // Keep track of the parent node

    // If there is a node with this key, bail out
    if (f->key == el->key)
      return -1;

    if (f->key > el->key)
      f = f->left;
    else
      f = f->right;
  }

  // Attach to the leaf
  if (p->key > el->key)
    p->left = el;
  else
    p->right = el;

  return 0;
}

