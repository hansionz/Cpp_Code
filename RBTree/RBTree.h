#pragma once 


enum Color 
{
    RED,
    BLACK
};

template<class K, class V>
struct RBTreeNode
{
    RBTreeNode* _left;
    RBTreeNode* _right;
    RBTreeNode* _parent;

    K _key;
    V _value;

    // 结点的颜色
    Color _color;
};

template<class K, class V>
class RBTree 
{
    public:
        typedef RBTreeNode<K, V> Node;
    public:
        RBTree()
            :_root(nullptr)
        {}

        // 1.空树,插入黑色结点
        // 2.插入红结点,如果父亲是黑色,则满足条件
        // 3.插入红结点,如果父亲也是红色,违反规则
        // 红黑树必须要使用三叉链
        bool Insert(const K& key, const V& value)
        {
            if()
            {

            }
            else // parent == grandfather->_right 
            {
                Node* grandfater = cur->_parent;
                Node* uncle = grandfater->_right;
                if()
            }
        }

        ~RBTree()
        {}

    private:
        Node* _root;
};
