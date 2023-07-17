#include <iostream>
#include <vector>
#include "../../Queue/Queue/queue.hpp"

class BTree
{
public:
    typedef long long int lli;
    lli data;
    BTree* left = NULL;
    BTree* right = NULL;

    BTree* create(const lli& data)
    {
        BTree* t = new BTree;
        t->data = data;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    lli height(BTree* t) const
    {
        if (t == NULL)
            return -1;
        if (t->left == NULL && t->right == NULL)
            return 0;

        lli lh = height(t->left);
        lli rh = height(t->right);

        if (lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }

    lli numof_nodes(BTree* t) const
    {
        if (t == NULL)
            return 0;
        return 1 + numof_nodes(t->left) + numof_nodes(t->right);
    }

    lli max(BTree* t) const
    {
        if (t == NULL)
            return INT32_MIN;

        lli m, lmax, rmax;
        m = t->data;
        lmax = max(t->left);
        rmax = max(t->right);

        if (lmax > m)
            m = lmax;
        if (rmax > m)
            m = rmax;

        return m;
    }

    void preorder(BTree* t)
    {
        if (t == NULL)
            return;
        std::cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }

    void inorder(BTree* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        std::cout<<t->data<<" ";
        inorder(t->right);
    }

    void postorder(BTree* t)
    {
        if (t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        std::cout<<t->data<<" ";
    }

    void levelorder(BTree* t)
    {
        if (t == NULL)
            return;

        Queue<BTree*> q(numof_nodes(t));
        std::cout<<t->data<<" ";
        do
        {
            if (t->left)
                q.add(t->left);
            if (t->right)
                q.add(t->right);
            t = q.del();
            std::cout<<t->data<<" ";
        } while (q.size() != 0);
    }

    void draw_tree(BTree* t)
    {
        lli tree_height = t->height(t) + 1;
        std::vector<std::vector<BTree*>> tree;
        std::vector<BTree*> level;
        level.push_back(t);
        for (lli i=0; i<tree_height; i++)
        {
            tree.push_back(level);
            level.clear();
            for (auto child : tree[i])
                if (child == NULL)
                {
                    level.push_back(NULL);
                    level.push_back(NULL);
                } else {
                    level.push_back(child->left);
                    level.push_back(child->right);
                }
        }

        std::vector<std::string> tree_shape;
        int layers_added = 0;

        for (lli i=tree_height - 1; i>=0; i--)
        {
            lli j=0;
            tree_shape.push_back("");
            for (auto child : tree[i])
            {
                if (child == NULL)
                {
                    tree_shape[tree_height-i-1+layers_added] += " *";
                } else {
                    if (tree_height-i-1+layers_added != 0)
                    {
                        while (tree_shape[tree_height-i-2+layers_added][j + 1] != '\\')
                        {
                            tree_shape[tree_height-i-1+layers_added] += " ";
                            j++;
                        }
                        j++;
                    } else
                        tree_shape[tree_height-i-1+layers_added] += ' ';
                    tree_shape[tree_height-i-1+layers_added] += std::to_string(child->data);
                }
            }
            
                    if (i == 0)
                        break;

            tree_shape.push_back("");
            bool is_left = true;
            for (lli j=0; j<tree_shape[tree_height-i-1+layers_added].size(); j++)
            {
                if (tree_shape[tree_height-i-1+layers_added][j] != ' ')
                {
                    if (is_left)
                        tree_shape[tree_height-i+layers_added].push_back('/');
                    else
                        tree_shape[tree_height-i+layers_added].push_back('\\');
                    is_left = !is_left;
                } else
                    tree_shape[tree_height-i+layers_added].push_back(' ');
            }
            
            bool need_to_add_more_layers = false;
            do
            {
                for (lli j=0; j<tree_shape[tree_height-i+layers_added].size(); j++)
                {
                    if (tree_shape[tree_height-i+layers_added][j] == '/')
                    {
                        if (tree_shape[tree_height-i+layers_added][j+2] != '\\')
                            need_to_add_more_layers = true;
                        else {
                            need_to_add_more_layers = false;
                            break;
                        }
                    }
                }

                if (need_to_add_more_layers)
                {
                    tree_shape.push_back("");
                    for (lli j=0; j<tree_shape[tree_height-i+layers_added].size(); j++)
                    {
                        if (tree_shape[tree_height-i+layers_added][j - 1] == '/')
                            tree_shape[tree_height-i+layers_added+1].push_back('/');
                        else if (tree_shape[tree_height-i+layers_added][j + 1] == '\\')
                            tree_shape[tree_height-i+layers_added+1].push_back('\\');
                        else
                            tree_shape[tree_height-i+layers_added+1].push_back(' ');
                    }
                }
                layers_added++;
            } while (need_to_add_more_layers);

        }

        for (lli i=tree_shape.size() - 1; i>=0; i--)
            std::cout<<tree_shape[i]<<std::endl;
    }

    bool identical(BTree* a, BTree* b)
    {
        if (a == NULL && b == NULL)
            return true;
        if (a != NULL && b != NULL)
            return a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right);
        return false;
    }

    bool is_complete(BTree* r)
    {
        if (r == NULL)
            return true;

        BTree* t;
        Queue<BTree*> q(numof_nodes(r));
        q.add(r);

        bool flag = false;
        while (q.size() != 0)
        {
            t = q.del();
            if (t->left)
            {
                if (flag == true)
                    return false;
                q.add(t->left);
            } else
                flag = true;
            
            if (t->right)
            {
                if (flag == true)
                    return false;
                q.add(t->right);
            } else
                flag = true;
        }

        return true;
    }

    lli find_level(BTree* t, const lli& item, const lli& level)
    {
        if (t == NULL)
            return 0;
        
        if (t->data == item)
            return level;

        lli d = find_level(t->left, item, level + 1);
        if (d != 0)
            return d;
        d = find_level(t->right, item, level + 1);
        return d;
    }

    BTree* LCA(BTree* r, const lli& a, const lli& b)
    {
        if (r == NULL)
            return NULL;
        
        if (r->data == a)
            return r;

        if (r->data == b)
            return r;

        BTree *l_lca, *r_lca;
        l_lca = LCA(r->left, a, b);
        r_lca = LCA(r->right, a, b);

        if (r_lca && l_lca)
            return r;

        return (l_lca != NULL) ? l_lca : r_lca;
    }

    void deleteTree(BTree* t)
    {
        if (t == NULL)
            return;
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
};