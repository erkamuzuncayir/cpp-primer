// -----------------------------------------------------------------------------
// File:        ex_28.cpp
// Author:      Erkam Uzuncayir
// Date:        15/06/2025
// -----------------------------------------------------------------------------

#include <string>

class TreeNode
{
public:
    TreeNode() : value(), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &other) : value(other.value), count(other.count), left(other.left), right(other.right)
    {
        ++*count;
    };
    TreeNode &operator=(const TreeNode &rhs)
    {
        if (this == &rhs)
            return *this;

        ++*rhs.count;
        if (--*count == 0)
        {
            delete left;
            delete right;
            delete count;
        }
        left  = rhs.left;
        right = rhs.right;
        value = rhs.value;
        count = rhs.count;
        return *this;
    }
    ~TreeNode()
    {
        if (--*count == 0)
        {
            delete left;
            delete right;
            delete count;
        }
    }

private:
    std::string value;
    int        *count;
    TreeNode   *left;
    TreeNode   *right;
};


class BinStrTree
{
    public:
    BinStrTree() : root(nullptr), count(new int(1)) {}
    BinStrTree(const BinStrTree &other) : root(other.root), count(other.count) { ++*count; }
    BinStrTree &operator=(const BinStrTree &rhs)
    {
        if (this == &rhs)
            return *this;

        ++*rhs.count;
        if (--*count == 0)
        {
            delete root;
            delete count;
        }
        root = rhs.root;
        count = rhs.count;
        return *this;
    }
    ~BinStrTree()
    {
        if (--*count == 0)
        {
            delete root;
            delete count;
        }
    }
private:
    TreeNode *root;
    int *count;
};
