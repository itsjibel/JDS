template<typename T> class BTree
{
public:
    T data;
    BTree* left = NULL;
    BTree* right = NULL;

    BTree* create(const T& data)
    {
        BTree* t = new BTree;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    long long int hight(BTree* t) const
    {
        if (t == NULL)
            return -1;
        if (t->left == NULL && t->right == NULL)
            return 0;

        long long int lh = hight(t->left);
        long long int rh = hight(t->right);

        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
};