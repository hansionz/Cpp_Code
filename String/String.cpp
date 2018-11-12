#include "String.h"

const size_t zsc::String::npos = -1;

void zsc::String::Reserve(size_t n)
{
  if(n > _capacity)
  {
    char* newstr = new char[n+1];
    strcpy(newstr, _str);
    delete[] _str;
    _str = newstr;
    _capacity = n;
  }
}
void zsc::String::Resize(size_t n, char ch)
{
  if(n < _size)
  {
    _str[n] = '\0';
  }
  else 
  {
    if(n > _capacity)
    {
      Reserve(n);
    }
    size_t pos = _size;
    while(pos < n)
    {
      _str[pos] = ch;
      ++pos;
    }
    _str[pos] = '\0';
    _size = n;
  }
}
void zsc::String::PushBack(char ch)
{
  //1.扩容
  if(_size == _capacity)
  {
    Reserve(2*_capacity);
  }
  //2.插入元素
  _str[_size] = ch;
  _size++;
}
void zsc::String::Append(const char* str)
{
  size_t len = strlen(str);
  if((len + _size) > _capacity)
  {
    Reserve(_size+len);
  }
  strcpy(_str+_size,str);
  _size += len;
}
zsc::String& zsc::String::operator+= (char ch)
{
  this->PushBack(ch);
  return *this;
}
zsc::String& zsc::String::operator+=(const char* str)
{
  this->Append(str);
  return *this;
}
size_t zsc::String::Find(char ch,size_t pos)
{
  assert(pos >= 0);
  size_t len = _size;
  size_t i = pos;
  for(;i < len ;i++)
  {
    if(_str[i] == ch)
    {
      return i;
    }
  }
  return npos;
}
void zsc::String::Insert(char ch, size_t pos)
{
  assert(pos >= 0);
  if((_size+1) > _capacity)
  {
    this->Reserve(_size+1);
  }
  size_t i = _size;
  for(;i >= pos;i--)
  {
    _str[i+1] = _str[i];
  }
  _str[pos] = ch;
}
void zsc::String::Insert(const char* str,size_t pos)
{
  size_t len = strlen(str);
  if((_size+len) > _capacity)
  {
    this->Reserve(_size+len);
  }
  size_t i = pos;
  for(; i >= pos; i--)
  {
    _str[i+len] = _str[i];
  }
  for(i = 0;i < len;i++)
  {
    _str[i+pos] = str[i];
  }
}

void zsc::String::Erase(size_t pos, size_t len)
{
  assert(len > 0);
  size_t i = pos + len +1;
  for(; i <= _size; i++ )
  {
    _str[i-len] = _str[i];
  }
}
char* zsc::String::Find(const char* str, size_t pos)
{
  char* parent = _str;
  const char* sub = str;
  while(*parent!='\0')
  {
    char* cur = parent;
    const char* start = sub;
    while(*sub && *cur && (*sub == *cur))
    {
      ++sub;
      ++cur;
    }
    if(*sub == '\0')
    {
      return (char*)start; 
    }
    else 
    {
      sub = start;
    }
    ++parent;
  }
  return NULL;
}
int main()
{
  zsc::String s("hello world");
  char* ret = s.Find("wo",0);
  cout << *ret << endl;
  //cout << s.Find('o',0) << endl;
  //s.Insert('B',1);
  //cout << s.c_str() << endl;
  //s.Erase(9,1);
  //cout << s.c_str() << endl;
 // cout << s.Capacity() << endl;
 // s.zsc::String::Reserve(100);
 // s.Resize(20,'a');
 // s.PushBack('E');
 // cout << s.c_str() << endl;
 // cout << s.Capacity() <<endl;
  return 0;
}
