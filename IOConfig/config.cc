#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;
class ConfigInfo
{
public:
  int port;
  char ip[32];
};
class ConfigManager 
{
public:
  ConfigManager(const char* file = "test.config")
    :configfile(file)
    {}
  //二进制读写
  void WriteBinary(const ConfigInfo& info)
  {
    ofstream ofile(configfile, ofstream::binary | ofstream::out);
    ofile.write((const char*)&info, sizeof(info));
    ofile.close();
  }
  void ReadBinary(ConfigInfo& info)
  {
    ifstream ifile(configfile, ifstream::binary | ifstream::in);
    ifile.read((char*)&info, sizeof(info));
    ifile.close();
  }
  //文本读写
  void WriteText(const ConfigInfo& info)
  {
    ofstream ofile(configfile);
    ofile << info.port << endl; 
    ofile << info.ip << endl;
    ofile.close();
  }
  void ReadText(ConfigInfo& info)
  {
    ifstream ifile(configfile);
    ifile >> info.port;
    ifile >> info.ip;
    ifile.close();
  }
private:
  string configfile;
};
int main()
{
  ConfigManager man;
  ConfigInfo rinfo;
  ConfigInfo winfo;

  winfo.port = 80;
  strcpy(winfo.ip,"127.0.0.1");

  //二进制读写
  man.WriteBinary(winfo);
  man.ReadBinary(rinfo);
  cout << rinfo.port << endl;
  cout << rinfo.ip << endl;

  //文本读写
  man.WriteText(winfo);
  man.ReadText(rinfo);
  cout << rinfo.ip << endl;
  cout << rinfo.port <<endl;

  return 0;
}
