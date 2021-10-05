bool isSibling(Node *root, int x, int y)
{
    // TERMINATING CONDITION
    if (root == NULL)
        return 0;
    bool a = false, b = false, c = false;
    if (root->left != NULL && root->right != NULL)
        a = ((root->left->data == x && root->right->data == y) ||
             (root->left->data == y && root->right->data == x));
    if (root->left != NULL)
        b = isSibling(root->left, x, y);
    if (root->right != NULL)
        c = isSibling(root->right, x, y);
    return (a || b || c);
}