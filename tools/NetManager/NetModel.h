#include <list>
#include <afxstr.h>

/************************************************************************/
/*      服务器信息 网址 路径 用户名 密码                                      */
/************************************************************************/

class FTP_API CFTPSeverInfo{
public:
	char m_cAddress[256];//服务器地址
	char m_cUserName[64];//用户名
	char m_cPassword[64];//密码
	char m_cVersion[64];//版本号

	CFTPSeverInfo(){
		strcpy_s(m_cAddress, sizeof(m_cAddress),"");
		strcpy_s(m_cUserName, sizeof(m_cUserName), "");
		strcpy_s(m_cPassword, sizeof(m_cPassword), "");
	}
};


/*每一个压缩包信息*/
class FTP_API CPackageInfo{
public:
	int     m_nTime;//时间
	DWORD   m_nFileType;//文件类型
	char    m_cRarName[256];//文件名
	char    m_cFileName[256];//解压后文件名
	std::list<CPackageInfo> m_listChild;//如果是文件夹 m_nfiletype是文件夹 就有子节点
	CPackageInfo(){
		m_nTime = 0;
		m_nFileType = FILE_ATTRIBUTE_NORMAL;
		strcpy_s(m_cRarName, sizeof(m_cRarName), "");
		strcpy_s(m_cFileName, sizeof(m_cFileName), "");
	}
};

/*
  服务器数据 压缩包列表
*/
class FTP_API CFTPDataInfo{
public:
	std::list<CPackageInfo> m_lstPackage;
};