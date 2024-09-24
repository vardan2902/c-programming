#include "ft_btree.h"

void    btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (!root)
        return ;
    btree_apply_suffix(root->left);
    btree_apply_suffix(root->right);
    applyf(root->item);
}
