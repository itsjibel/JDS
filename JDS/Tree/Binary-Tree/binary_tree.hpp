#include <iostream>
#include <vector>
#include <math.h>
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

    void draw_tree(BTree* t)
    {
        // Put each level of tree into a std::vector<std::vector<BTree*>>, and each node in a std::vector<BTree*>
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

        // Start scanning the tree from the tail to get the shape of tree
        std::vector<std::string> tree_shape;
        int layers_added = 0;
        for (lli i=tree_height-1; i>=0; i--)
        {
            lli j=0;
            tree_shape.push_back("");

            // Nodes of each level named child
            for (auto child : tree[i])
            {
                lli numof_chid_number_size = child != NULL ? (log10((child->data == 0 ? 1 : child->data)) + 1) : 1;
                // While the next character of the under-layer is not '\', we have not reached a connection,
                // so we iterate more to reach a connection and cout white space
                if (tree_height-i-1+layers_added != 0)
                {
                    while (tree_shape[tree_height-i-2+layers_added][j + 1 + numof_chid_number_size] != '\\')
                    {
                        tree_shape[tree_height-i-1+layers_added] += " ";
                        j++;
                    }
                    j += 2 + numof_chid_number_size;
                } else
                    tree_shape[tree_height-i-1+layers_added] += ' ';

                // When we reach a connection at the under-layer, so we add node data at this position
                if (child == NULL)
                    tree_shape[tree_height-i-1+layers_added] += "(*)";
                else
                    tree_shape[tree_height-i-1+layers_added] += '(' + std::to_string(child->data) + ')';
            }
            
            // Because we iterate from the tail of the tree is necessary to break the for loop when we reach the root of the tree,
            // so we don't get any segmentation faults for making connections for more
            if (i == 0)
                break;

            // Make a connection with this logic that if the under-layer character is a number,
            // if it is time to make the left connection we push back '/' else we push back '\'
            tree_shape.push_back("");
            bool is_left = true;
            for (lli j=0; j<tree_shape[tree_height-i-1+layers_added].size(); j++)
            {
                if (tree_shape[tree_height-i-1+layers_added][j] == ')')
                {
                    if (is_left)
                        tree_shape[tree_height-i+layers_added].push_back('/');
                    else {
                        tree_shape[tree_height-i+layers_added].pop_back();
                        tree_shape[tree_height-i+layers_added].push_back('\\');
                        tree_shape[tree_height-i+layers_added].push_back(' ');
                    }
                    is_left = !is_left;
                } else
                    tree_shape[tree_height-i+layers_added].push_back(' ');
            }

            // If the connection characters (/ and \) have more than 1 distance,
            // we make one more layer on this layer to get 1 space between the '/' and '\' characters.
            bool need_to_add_more_layers = false;
            do
            {
                for (lli j=0; j<tree_shape[tree_height-i+layers_added].size(); j++)
                {
                    if (tree_shape[tree_height-i+layers_added][j] == '/')
                    {
                        if (tree_shape[tree_height-i+layers_added][j+2] != '\\' && tree_shape[tree_height-i+layers_added][j+1] != '\\')
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
                        else if (tree_shape[tree_height-i+layers_added][j + 1] == '\\' || (tree_shape[tree_height-i+layers_added][j] == '\\' && tree_shape[tree_height-i+layers_added][j - 1] == '/'))
                            tree_shape[tree_height-i+layers_added+1].push_back('\\');
                        else
                            tree_shape[tree_height-i+layers_added+1].push_back(' ');
                    }
                }
                layers_added++;
            } while (need_to_add_more_layers);
        }

        // Cut the NULL nodes connections with other nodes
        for (lli i=0; i<tree_shape.size(); i++)
            for (lli j=0; j<tree_shape[i].size(); j++)
            {
                if (tree_shape[i][j] == '*')
                    tree_shape[i][j] = tree_shape[i][j-1] = tree_shape[i][j+1] = ' ';
                else if (tree_shape[i][j] == '/' && tree_shape[i-1][j-1] == ' ')
                    tree_shape[i][j] = ' ';
                else if (tree_shape[i][j] == '\\' && tree_shape[i-1][j+1] == ' ')
                    tree_shape[i][j] = ' ';
            }

        // Print the shape of tree
        for (lli i=tree_shape.size() - 1; i>=0; i--)
            std::cout<<tree_shape[i]<<std::endl;
    }
};