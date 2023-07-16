class BSTree
{
public:
    typedef long long int lli;
    lli data;
    BSTree* left = NULL;
    BSTree* right = NULL;

    BSTree* create(const lli& data)
    {
        BSTree* t = new BSTree;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    void deleteTree(BSTree* t)
    {
        if (t == NULL)
            return;
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
};