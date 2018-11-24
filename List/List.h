#ifndef __LIST_H__
#define __LIST_H__ 

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
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
    //构造函数(T()相当于是一个匿名对象)
    ListNode(const T& data = T())
     :_data(data)
     ,_next(nullptr)
     ,_prev(nullptr)
    {}

    T _data; //数据域
    ListNode<T>* _next;//指向前一个结点的指针
    ListNode<T>* _prev;//指向回一个结点的指针
  };
  /**
   * 模拟实现list的迭代器类
   */ 
  template<class T>
  struct ListIterator
  {
    typedef ListNode<T> Node;
    //迭代器定义为和库一样的名字可以支持语法糖
    typedef ListIterator<T> iterator;

    //构造
    ListIterator(Node* node)
      :_node(node)
    {}
    //拷贝构造
    ListIterator(const iterator& i)
      :_node(i._node)
    {}

    /**
     * 重载迭代器的解引用、++、!=、==
     */ 
    // *it
    T& operator*()
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
    // it1 == it2
    bool operator==(const iterator& it)
    {
      return _node == it._node;
    }
    Node* _node;
  };
  /**
   * 模拟实现list类
   */ 
  template<class T>
  class List 
  {
    typedef ListNode<T> Node;

  public:
    typedef ListIterator<T> iterator;
    /**
     * 构造函数
     */ 

    //无参构造函数，构造一条只有头结点的空链表
    List()
      :_head(new Node)
    {
      _head -> _next = _head;
      _head -> _prev = _head;
    }
    //构造一条含有n个值为data的结点的链表
    List(int n, const T& data = T())
      :_head(new Node)
    {
      _head -> _next = _head;
      _head -> _prev = _head;

      for(int i = 0;i < n;i++)
      {
        PushBack(data);
      }
    }
    //迭代器区间构造
    template<class InputIterator>
    List(InputIterator first,InputIterator last)
      :_head(new Node)
    {
      _head -> _next = _head;
      _head -> _prev = _head;

      while(first != last)
      {
        PushBack(*first);
        ++first;
      }
    }
    //拷贝构造(现代方法)
    List(List<T>& l)
      :_head(new Node)
    {
      _head -> _next = _head;
      _head -> _prev = _head;

      List<T> tmp(l.begin(),l.end());
      swap(_head, tmp._head);
    }
    //赋值运算符重载
    List<T>& operator=(List<T>& l)
    {
      if(this != &l)
      {
        List<T> tmp(l);
        swap(_head, l._head);
      }
      return *this;
    }
    //析构函数
    ~List()
    {
      Clear();
      delete _head;
      _head = nullptr;
    }
    //清空链表
    void Clear()
    {
      Node* cur = _head -> _next;
      while(cur != _head)
      {
        _head = cur -> _next;
        delete cur;
        cur = _head;
      }
      _head -> _next = _head;
      _head -> _prev = _head;
    }
    /**
     * 迭代器
     */ 
    iterator begin()
    {
      return iterator(_head -> _next);
    }
    iterator end()
    {
      return iterator(_head);
    }
    /**
     * List Modify
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
    void PopBack()
    {
      Node* del = _head -> _prev;
      if(del != _head)
      {
        _head -> _prev = del -> _prev;
        del -> _prev -> _next = _head;
        delete del;
        del = nullptr;
      }
    }
    void PushFront(const T& data)
    {
      Node* first = _head -> _next;
      Node* newnode = new Node(data);
      
      // _head newnode first 
      _head -> _next = newnode;
      newnode -> _prev = _head;
      newnode -> _next = first;
      first -> _prev = newnode;
    }
    void PopFront()
    {
      Node* second = _head -> _next -> _next;
      _head -> _next = second;
      delete second -> _prev;
      second -> _prev = _head;
    }
    void Insert(iterator pos, const T& data)
    {
      Node* cur = pos._node;
      Node* pre = cur -> _prev;
      Node* newnode = new Node(data);
      
      // pre newnode cur 
      cur -> _prev = newnode;
      newnode -> _next = cur;
      newnode -> _prev = pre;
      pre -> _next = newnode;
      
    }
    void Erase(iterator pos)
    {
      Node* del = pos._node;
      Node* next = del -> _next;
      Node* pre = del -> _prev;

      pre -> _next = next;
      next -> _prev = pre;
      delete del;
      del = nullptr;
    }
    /**
     * List Access
     */ 
    T& Front()
    {
      return _head -> _next -> _data;
    }
    const T& Front() const 
    {
      return _head -> _next -> _data;
    }
    T& Back()
    {
      return _head -> _prev -> _data;
    }
    const T& Back() const 
    {
      return _head -> _prev -> _data;
    }

    /**
     * 返回值为val结点的迭代器
     */ 
    iterator Find(const T& data)
    {
      Node* cur = _head -> _next;
      while(cur != _head)
      {
        if(cur->_data == data)
          return iterator(cur);
        cur = cur -> _next;
      }
    }
    /**
     * List capacity
     */ 

    //链表的长度
    size_t Size() const 
    {
      size_t count = 0;
      Node* cur = _head -> _next;
      while(cur != _head)
      {
        ++count;
        cur = cur -> _next;
      }
      return count;
    }
    // 判断链表是否为空
    bool Empty()
    {
      return _head -> _next == _head;
    }
    //调整链表的有效长度
    void Resize(int newsize, const T& data = T())
    {
      int oldsize = Size();
      if(newsize < oldsize)
      {
        for(int i = 0;i < (oldsize - newsize);i++)
        {
          PopBack();
        }
      }
      else 
      {
        for(int i = 0;i < (newsize - oldsize);i++)
        {
          PushBack(data);
        }
      }
    }
  private:
    Node* _head;
  };
}
#endif //__LIST_H__
