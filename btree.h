struct node {
  int   key;
  struct node *left;
  struct node *right;
};

struct node *btree_find(struct node *root, int key);
int btree_insert(struct node *root, struct node *el);

