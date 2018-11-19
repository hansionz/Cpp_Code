#include "String.h"

//const size_t zsc::String::npos = -1;

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
  //size_t len = _size;
  //size_t i = pos;
  //for(;i < len ;i++)
  //{
  //  if(_str[i] == ch)
  //  {
  //    return i;
  //  }
  //}
  while(pos < _size)
  {
    if(_str[pos] == ch)
      return pos;
    ++pos;
  }
  return zsc::String::npos;
}

size_t zsc::String::RFind(char ch,size_t pos)
{ 
  int end = _size - 1;
  if(pos != zsc::String::npos)
  {
    end = pos;
  }
  while(end >= 0)
  {
    if(_str[end] == ch)
    {
      return end;
    }
    --end;
  }
  return zsc::String::npos;
}

zsc::String zsc::String::Substr(size_t pos, size_t len)
{
  if(_size - pos < len) //后边的字符不够len个
  {
    len = _size - pos;
  }
  zsc::String sub; //子串
  sub.Reserve(len);
  //strncpy也可以直接拷贝，但是_size等不好改变
  for(size_t i = pos; i < pos + len; i++)
  {
    sub += _str[i];
  }
  return sub;
}

void zsc::String::Insert(char ch, size_t pos)
{
  assert(pos <= _size);
  //增容
  if((_size+1) > _capacity)
  {
    Reserve(_capacity * 2);
  }
  int i = _size;
  for(;i >= (int)pos;i--)
  {
    _str[i+1] = _str[i];
  }
  _str[pos] = ch;
  _size++;
}

void zsc::String::Insert(const char* str,size_t pos)
{
  assert(pos < _size);
  int len = strlen(str);
  //扩容
  if((_size+len) > _capacity)
  {
    Reserve(_size+len);
  }
  int i = _size;
  for(; i >= (int)pos; i--)
  {
    _str[i+len] = _str[i];
  }
  for(i = 0;i < len;i++)
  {
    _str[i+pos] = str[i];
  }
  _size += len;
}

void zsc::String::Erase(size_t pos, size_t len)
{
  assert(pos < _size);
  if((len == npos) || (pos + len >= _size))
  {
    _str[pos] = '\0';
    _size = pos;
  }
  else 
  {
    for(size_t i = 0;i < len; i++)
    {
      _str[pos] = _str[pos + len];
      pos++;
    }
    _size -= len;
    _str[_size] = '\0';
  }
  //size_t i = pos + len + 1;
  //for(; i <= _size; i++ )
  //{
  //  _str[i-len] = _str[i];
  //}
  //_size -= len;
}
size_t zsc::String::Find(const char* str, size_t pos)
{
  assert(pos < _size);
  char* pmatch = strstr(_str + pos, str);
  if(pmatch == nullptr)
  {
    return zsc::String::npos;
  }
  else 
  {
    return pmatch - _str;
  }
  //自己实现strstr
  //扩展学习：KMP匹配算法(了解)、后缀树、BM算法
  //char* parent = _str;
  //const char* sub = str;
  //while(*parent!='\0')
  //{
  //  char* cur = parent;
  //  const char* start = sub;
  //  while(*sub && *cur && (*sub == *cur))
  //  {
  //    ++sub;
  //    ++cur;
  //  }
  //  if(*sub == '\0')
  //  {
  //    return (char*)start; 
  //  }
  //  else 
  //  {
  //    sub = start;
  //  }
  //  ++parent;
  //}
  //return NULL;
}
//重载输入
istream& zsc::operator>>(istream& _cin, String& s)
{
  _cin >> s._str;
  return _cin;
}
//重载输出
ostream& zsc:: operator<<(ostream& _cout,const String& s)
{
  _cout << s._str;
  return _cout;
}
void testErase()
{
  zsc::String s;
  s = "helllo";
  s.Erase(4, 2);
  cout << s << endl;
}
int main()
{
  testErase();
  // zsc::String s;
  //s = "hello world";
  //cout << s << '\n';
  //while(cin >> s)
  //  cout << s << endl;
  //cout << s << endl;
  //char* ret = s.Find("wo",0);
  //cout << *ret << endl;
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
