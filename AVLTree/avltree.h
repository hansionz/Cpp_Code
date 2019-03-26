#pragma once 

#include <assert.h>
#include <iostream>

template<class K, class V>
struct AVLTreeNode
{
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;

    K _key;
    V _value;

    int _bf; // 定义的平衡因子

    AVLTreeNode(const K& key, const V& value)
        :_key(key)
        ,_value(value)
        ,_bf(0)
    {}
};

template<class K, class V>
class AVLTree 
{
    public:
        typedef AVLTreeNode<K, V> Node;
    public: 
        AVLTree()
            :_root(nullptr)
        {}

        // 平衡树的插入(平衡因子=右子树高度-左子树高度)
        // 1.按照搜索树的规则插入结点
        // 2.更新平衡因子
        // 3.检查平衡因子,不平衡则旋转(平衡因子更新为2,则需要旋转)
        // 平衡因子的更新规则
        // 1.高度变化在parent的左边 parent->bf--
        // 2.高度变化在parent的右边 parent->bf++
        // 3.parent->bf == 0, 说明树的高度不变,更新完成
        // 4.parent->bf == 1 ,说明树的高度边了,继续往上更新
        // 5.parent->bf == 2, 说明树违反规则,需要旋转处理
        bool Insert(const K& key, const V& value)
        {
            // 1.按照平衡树的插入规则插入
            if(_root == nullptr)
            {
                _root = new Node(key, value);
                return true;
            }

            Node* cur = _root;
            Node* parent = nullptr;
            while(cur)
            {
                if(cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if(cur->_key < key)
                {
                    cur = parent;
                    cur = cur->_right;
                }
                else 
                {
                    return false;
                }
            }

            cur = new Node(key, value);
            if(parent->_key < key)
            {
                parent->_right = cur;
                cur->parent = parent;
            }
            else 
            {
                parent->_left = cur;
                cur->parent = parent;
            }

            // 2.更新平衡因子
            while(parent)
            {
                if(cur == parent->_right)
                    parent->_bf++;
                else 
                    parent->_bf--;

                // 不用再继续更新
                if(parent->_bf == 0)
                {
                    break;
                }
                // 高度改变,继续更新
                else if(abs(parent->_bf) == 1)
                {
                    cur = parent;
                    parent = parent->_parent;
                }
                // 不满足规则,需要旋转
                else if(abs(parent->_bf) == 2)
                {

                }
                // 其他地方出现问题
                else 
                {
                    assert(false);
                }
            }

            return true;
        }
        void RotateR(Node* parent)
        {

        }
        void RotateL(Node* parent)
        {
            Node* subR = parent->_right;
            Node* subRL = subR->_left;

            parent->_right = subRL;
            if(subRL)
            {
                subRL->_parent = parent;
            }

            subR->_left = parent;
            Node* ppNode = parent->_parent; 
            parent->_parent = subR;

            if(parent == _root)
            {
                _root = subR;
                _root->_parent = nullptr;
            }
            else 
            {
                if(parent == ppNode->_left)
                {
                    ppNode->_left = subR;
                }
                else 
                {
                    ppNode->_right = subR;
                }
                subR->_bf = ppNode;
            }
        }

        ~AVLTree()
        {}

    private:
        Node* _root;
};
