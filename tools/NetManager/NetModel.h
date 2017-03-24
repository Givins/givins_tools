#include <list>
#include <afxstr.h>

/************************************************************************/
/*      ��������Ϣ ��ַ ·�� �û��� ����                                      */
/************************************************************************/

class FTP_API CFTPSeverInfo{
public:
	char m_cAddress[256];//��������ַ
	char m_cUserName[64];//�û���
	char m_cPassword[64];//����
	char m_cVersion[64];//�汾��

	CFTPSeverInfo(){
		strcpy_s(m_cAddress, sizeof(m_cAddress),"");
		strcpy_s(m_cUserName, sizeof(m_cUserName), "");
		strcpy_s(m_cPassword, sizeof(m_cPassword), "");
	}
};


/*ÿһ��ѹ������Ϣ*/
class FTP_API CPackageInfo{
public:
	int     m_nTime;//ʱ��
	DWORD   m_nFileType;//�ļ�����
	char    m_cRarName[256];//�ļ���
	char    m_cFileName[256];//��ѹ���ļ���
	std::list<CPackageInfo> m_listChild;//������ļ��� m_nfiletype���ļ��� �����ӽڵ�
	CPackageInfo(){
		m_nTime = 0;
		m_nFileType = FILE_ATTRIBUTE_NORMAL;
		strcpy_s(m_cRarName, sizeof(m_cRarName), "");
		strcpy_s(m_cFileName, sizeof(m_cFileName), "");
	}
};

/*
  ���������� ѹ�����б�
*/
class FTP_API CFTPDataInfo{
public:
	std::list<CPackageInfo> m_lstPackage;
};