#ifndef __VECTOR_H__
#define __VECTOR_H__ 

#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;
namespace zsc
{
  template<class T>
  class Vector 
  {
  public:
    /**
     * 模拟实现迭代器核心接口(使用大写和vector区分)
     */  
    typedef T* Iterator;
    typedef const T* Const_Iterator;
    Iterator Begin()
    {
      return _start;
    }
    Iterator End()
    {
      return _finish;
    }
    Const_Iterator CBegin() const
    {
      return _start;
    }
    Const_Iterator CEnd() const 
    {
      return _finish;
    }
    /**
     * 容量核心接口的模拟实现
     */  
    size_t Size() const 
    {
      return _finish - _start;
    }
    size_t Capacity() const 
    {
      return _endofstorage - _start;
    }
    void Reserve(size_t n)
    {
      if(n > Capacity())
      {
        size_t size =Size();
        T* tmp = new T[n];
        //使用memcpy会出现问题，当vector内如果存的是char*的情况
        //memcpy按照字节拷贝，只是简单的把指向字符串的char*拷贝过来
        //在释放原来的空间时，字符串已经被销毁了
        //if(_start)
        //  memcpy(tmp, _start, sizeof(T)*size);
        if(_start)//第一次扩容时，_start为空
        {
          for(size_t i =0; i < size; i++)
            tmp[i] = _start[i];
        }
        delete[] _start;
        _start = tmp;
        _finish = _start + size;
        _endofstorage = _start + n;
      }
    }
    void Resize(size_t n, const T& val = T())
    {
      //1.n小于等于当前vector的size,则在n的地方截断，有效数据为前n个
      if(n < Size())
      {
        _finish = _start + n;
      }
      else
      {
        //如果n大于当前容量，考虑扩容问题
        if(n > Capacity())
        {
          Reserve(n);
        }
        Iterator it = _finish;
        _finish = _start + n;
        //把大于size那部分填充成val
        while(it < _finish)
        {
          *it = val;
          ++it;
        }
      }
    }
    /**
     * 增删改查等核心接口的模拟实现
     */ 
    Iterator Insert(Iterator pos, const T& val)
    {
      assert(pos <= _finish);
      //检查容量，不够则扩容
      if(_finish == _endofstorage)
      {
        size_t offset = pos - _start;
        size_t newcapacity = Capacity() == 0 ? 2 : Capacity()*2;

        Reserve(newcapacity);
        //增容需要重置pos
        pos = _start + offset;
      }
      Iterator end = _finish - 1;
      while(end >= pos)
      {
        *(end+1) = *end;
        --end;
      }
      *pos = val;
      ++ _finish;
      return pos;
    }
    //Erase删除一个数据后，返回下一个数据的迭代器
    Iterator Erase(Iterator pos)
    {
      assert(pos < _finish);
      Iterator begin = pos + 1;
      while(begin < _finish)
      {
        *(begin - 1) = *begin;
        ++begin;
      }

      --_finish;
      return pos;
    }
    void PushBack(const T& val)
    {
      Insert(End(), val);
    }
    void PopBack()
    {
      Erase(--End());
    }
    /**
     * 各类构造函数的模拟实现
     */  
    //无参构造
    Vector()
      :_start(nullptr)
       ,_finish(nullptr)
       ,_endofstorage(nullptr)
    {}
    //构造n个val
    Vector(size_t n, const T& val = T())
      :_start(nullptr)
       ,_finish(nullptr)
       ,_endofstorage(nullptr)
    {
      Reserve(n);//先将容量增加到n,可以减少多次增容带来的代价
      while(n--)
      {
        PushBack(val);
      }
    }
    //迭代器区间构造
    //template<class InputIterator>
    Vector(Iterator begin, Iterator last)
    {
      Reserve(last - begin);
     
      while(begin != last)
      {
        PushBack(*begin);
        ++begin;
      }
    }
    void Swap(Vector& v1)
    {
      swap(_start, v1._start);
      swap(_finish, v1._finish);
      swap(_endofstorage, v1._endofstorage);
    }
    Vector<T>& operator=(Vector<T> v)
    {
      Swap(v);
      return *this;
    }
    T& operator[](size_t pos)
    {
      assert(pos < Size());
      return _start[pos];
    }
    //拷贝构造
    Vector(const Vector<T>& v)
      :_start(nullptr)
       ,_finish(nullptr)
       ,_endofstorage(nullptr)
    {
      Reserve(v.Capacity());
      Iterator it = Begin();
      Const_Iterator cit = v.CBegin();
      while(cit != v.CEnd())
      {
        *it = *cit;
        ++it;
        ++cit;
      }
      _finish = _start + v.Size();
      _endofstorage = _start + v.Capacity();
    }
    ~Vector()
    {
      if(_start)
      {
        delete[] _start;
        _start = _finish = _endofstorage = nullptr;
      }
    }
    /**
     * 返回val位置的迭代器
     */ 
    Iterator Find(const T& val)
    {
      Iterator it1 = Begin();
      while(it1 != End())
      {
        if(*it1 == val)
          return it1;
        ++it1;
      }
    }
  private:
    T* _start;
    T* _finish;
    T* _endofstorage;
  };
}
#endif //__VECTOR_H__
