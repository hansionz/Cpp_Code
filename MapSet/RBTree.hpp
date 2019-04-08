#pragma once 

#include <iostream>

// 枚举颜色
enum color 
{
  RED,
  BLACK
};

// 红黑树结点(三叉链)
template<class K, class V>
struct RBTreeNode 
{
  struct RBTreeNode<K, V>* _left;
  struct RBTreeNode<K, V>* _right;
  struct RBTreeNode<K, V>* _parent;
  enum color _color;

  K _key;
  V _value;
};

// 红黑树
template<class K, class V>
class RBTree 
{
public:
  typedef struct RBTreeNode<K, V> Node;

  RBTree()
      :_root(nullptr)
  {}

  ~RBTree()
  {}

  // 红黑树的插入
  bool Insert(const K& key, const V& value)
  {
    // 1.按照搜索树的规则进行插入   
    if (_root == nullptr) 
    {
      Node* tmp = new Node(key, value);
      _root = tmp;
      return true;
    }

    Node* parent = nullptr;
    Node* cur = _root;
    Node* insert_node = new Node(key, value);
    while (cur)
    {
      if (cur->_val == key)
      {
        return true;
      }
      else if (cur->_val > key)
      {
        parent = cur;
        cur = cur->_left;
      }
      else 
      {
        parent = cur;
        cur = cur->_right;
      }
    }

    if (parent->_key > key)
    {
      parent->_left = insert_node;
      insert_node->_parent = parent;
    }
    else 
    {
      parent->_right = insert_node;
      insert_node->_parent = parent;
    }

    while (insert_node == parent->_left && parent->_color == RED)
    {
      Node* grandfather = parent->_parent;
      if (parent == grandfather->_left)
      {}
      else  
      {
        if (insert_node == parent->_left)
        {}
      }
    }

    _root->_color = BLACK;
  }

private:
  Node* _root;
};
