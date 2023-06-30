#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring> // string
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <io.h>
#include <list> 
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <io.h>
#include <ios>
#include <iosfwd>
#include <iostream> // cin / cout
#include <istream>
#include <ostream> // file in / out
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <Urlmon.h>
#include <windows.h> // cmd
#include <cstdio> // scanf / printf
#include <conio.h>
#include <Urlmon.h>
#pragma comment(lib, "Urlmon.lib")
using namespace std;

ifstream fin;
ofstream fout;

int NodeLen = 0;
struct Node
{
	string name, IP;
}NodeList[10000010];

inline string LTS(string s); // 大写转小写
int main()
{
	int Temp2;
	string Temp;
	cout << "软件加载中，请稍后...";
	URLDownloadToFile(nullptr, L"https://cloud.rgiss.com/d/RGISS%20Configuration%20file/TEMP?sign=sk_sUkUBi4AwZM6P-6Y-FoiiOgWPWFdM3K7YwW79Hvk=:0", L"TEMP", 0, nullptr); // 下载
	fin.open("TEMP");
	fin >> NodeLen;
	for (int i = 0; i < NodeLen; i++)
	{
		fin >> NodeList[i].name >> NodeList[i].IP;
	}
	fin.close();
	system("cls");
	cout << "欢迎使用瑞斯穿透！\n";
	cout << "========================\n";
	int temp = 1;
	for (int i = 0; i < NodeLen; i++)
	{
		cout << temp++ << ". " << NodeList[i].name << " -> " << NodeList[i].IP << "\n";
	}
	cout << "========================\n";
	cout << "本软件所有权为瑞斯科技！\n";
	cout << "技术支持：Zhiyuan\n";
	cout << "Version: Release 1.0 Beta\n";
	cout << "详细信息请访问 www.rgiss.com\n";
	cout << "========================\n";
	cout << "要启动的隧道的序号（输入 76 调用已有 frpc.ini）：";
	fout.open("frpc.ini");
	cin >> Temp2;
	if (Temp2 == 76)
	{
		goto Go;
	}
	fout << "[common]\n";
	fout << "server_addr = " << NodeList[Temp2 - 1].IP << "\n";
	fout << "server_port = 7000\n";
	fout << "tcp_mux = true\n";
	cout << "访问密钥：";
	cin >> Temp;
	fout << "user = " << Temp << "\n";
	fout << "token = 13969060123\n";
	fout << "dns_server = 114.114.114.114\n\n";
	cout << "隧道名称：";
	cin >> Temp;
	fout << "[" << Temp << "]\n";
	fout << "privilege_mode = true\n";
	cout << "隧道协议：";
	cin >> Temp;
	fout << "type = " << LTS(Temp) << "\n";
	cout << "内网 IP：";
	cin >> Temp;
	fout << "local_ip = " << Temp << "\n";
	cout << "内网端口：";
	cin >> Temp2;
	fout << "local_port = " << Temp2 << "\n";
	cout << "外网端口：";
	cin >> Temp2;
	fout << "remote_port = " << Temp2 << "\n";
	cout << "是否加密：";
	cin >> Temp;
	fout << "use_encryption = ";
	if (Temp == "是")
	{
		fout << "true\n";
	}
	else {
		fout << "false\n";
	}
	cout << "是否压缩：";
	cin >> Temp;
	fout << "use_compression = ";
	if (Temp == "是")
	{
		fout << "true\n";
	}
	else {
		fout << "false\n";
	}
	fout.close();
	Go:;
	system("cls");
	cout << "正在启动中......\n";
	system("Frpc -c frpc.ini");
	cout << "Frp 已退出！按任意键退出此程序！";
	while (true)
	{
		if (_kbhit()) // 判断是否有按按键
		{
			return 0;
		}
		Sleep(20); // 防止卡 / 占用过多资源
	}
	return 0;
}
inline string LTS(string s) // 大写 -> 小写
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
	return s;
}