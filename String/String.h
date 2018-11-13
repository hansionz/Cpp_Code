#pragma once 

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace zsc
{
  class String
  {
  public:
    String(const char* str = "")
    {
      _size = strlen(str);
      _capacity = _size;
      _str = new char[_capacity + 1];
      strcpy(_str, str);
    }
    ~String()
    {
      delete [] _str;
      _str = nullptr;
      _size = _capacity = 0;
    }
    void Swap(String& s)
    {
      swap(_str, s._str);
      swap(_capacity, s._capacity);
      swap(_size, s._size);
    }
    String(String const& s)
      :_str(nullptr)
      ,_size(0)
      ,_capacity(0)
    {
      String tmp(s._str);
      this->Swap(tmp);
    }
    String& operator=(String s)
    {
      Swap(s);
      return *this;
    }
    char& operator[](size_t pos)
    {
      assert(pos < _size);
      return _str[pos];
    }
    const char& operator[](size_t pos) const 
    {
      assert(pos < _size);
      return _str[pos];
    }
    size_t Size() const 
    {
      return _size;
    }
    size_t Capacity() const 
    {
      return _capacity;
    }
    const char* c_str()
    {
      return _str;
    }
    void Reserve(size_t n);
    void Resize(size_t n,char ch);
    void PushBack(char ch);
    void Append(const char* str);
    String& operator+=(char ch);
    String& operator+=(const char* str);
    size_t Find(char ch,size_t pos = 0);
    char* Find(const char* str, size_t pos = 0);
    void Insert(char ch, size_t pos);
    void Insert(const char* str,size_t pos);
    void Erase(size_t pos, size_t len = npos);
    friend ostream& operator<<(ostream& _cout,const String& s);
    friend istream& operator>>(istream& _cin,const String& s);
  private:
    char* _str;
    size_t _size;
    size_t _capacity;

    static const size_t npos;
  };
  istream& operator>>(istream& _cin,const String& s)
  {
    _cin >> s._str;
    return _cin;
  }
  
  ostream& operator<<(ostream& _cout,const String& s)
  {
    _cout << s._str;
    return _cout;
  }
}
