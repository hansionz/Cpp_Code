#ifndef __LIST_H__
#define __LIST_H__ 

#include <iostream>
#include <assert.h>
/**
 * 模拟实现STL中的list(双向带头循环链表)
 */ 
namespace zsc
{
  template<class T>
  //为什么不用struct而用class？
  //如果不使用访问限定符使用struct,struct默认访问限定符为public
  //如果使用访问此限定符使用class,class默认访问限定符为class
  struct ListNode
  {
    T _data;
    ListNode<T>* _next;
    ListNode<T>* _prev;

    //构造函数(T())
    ListNode(const T& data = T())
     :_data(data)
     ,_next(nullptr)
     ,_prev(nullptr)
    {}
  };

  template<class T>
  struct ListIterator
  {
    typedef ListNode<T> Node;
    //迭代器定义为和库一样的名字可以支持语法糖
    typedef ListIterator<T> iterator;
    Node* _node;

    ListIterator(Node* node)
      :_node(node)
    {}

    /**
     * 重载迭代器的解引用、++、!=
     */ 
    // *it
    T operator*()
    {
      return _node -> _data;
    }
    // ++it 
    iterator operator++()
    {
      _node = _node -> _next;
      return *this;
    }
    // it1 != it2
    bool operator!=(const iterator& it)
    {
      return _node != it._node;
    }
  };

  template<class T>
  class List 
  {
    typedef ListNode<T> Node;
  public:
    /**
     * 模拟实现迭代器
     */ 
    typedef ListIterator<T> iterator;
    iterator begin()
    {
      return iterator(_head -> _next);
    }
    iterator end()
    {
      return iterator(_head);
    }
    /**
     * 各类构造函数的模拟实现
     */ 

    //List的构造函数,创建头结点
    List()
      :_head(new Node)
    {
      _head -> _next = _head;
      _head -> _prev = _head;
    }
    //拷贝构造函数
    List(const List<T>& l);
    //赋值运算符重载
    List<T>& operator=(List<T> l);
    //赋值运算符重载
    //~List();

    /**
     * 增删改查核心接口的模拟实现
     */ 
    void PushBack(const T& data)
    {
      Node* tail = _head -> _prev;
      Node* newnode = new Node(data);

      //_head tail newnode 
      tail -> _next = newnode;
      newnode -> _prev = tail;
      newnode -> _next = _head;
      _head -> _prev = newnode;
    }
    void PopBack();
    void PushFront(const T& data);
    void PopFront();
    void Insert(iterator pos, const T& data);
    void Erase(iterator pos);
    /**
     * 链表结点个数和判空的模拟实现
     */ 
    size_t Size();
    bool Empty();

  private:
    Node* _head;
  };
}
#endif //__LIST_H__
