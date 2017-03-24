#include "stdafx.h"
#include "FTPManager.h"

static CFtpConnection * m_pFtpConn = NULL;
CFTPManager& CFTPManager::GetInstance()
{
	static CFTPManager FTPManager;
	return FTPManager;
}

CFTPManager::CFTPManager()
{
	InitialFTP();
}

CFTPManager::~CFTPManager()
{

}

void CFTPManager::InitialFTP()
{
	int nIni = 0;
	BOOL bInit = FALSE;
	while (!bInit && nIni < 10){
		bInit = InitialSever();
		nIni++;
		if (!bInit) Sleep(500);
	}
	ReloadTFPData();
}

void CFTPManager::ReloadTFPData()
{
	if (!m_pFtpConn) return;

	//vctFileList.empty();
	m_FtpData.m_lstPackage.clear();
	CFtpFileFind cFtpFileFind(m_pFtpConn);
	// 查找指定目录    
	CString strPath;
	USES_CONVERSION;
	//strPath.Format(_T("%s\\%s"), A2W(m_SeverInfo.m_cAddress), A2W(m_SeverInfo.m_cVersion));
	strPath.Format(_T("%s"), A2W(m_SeverInfo.m_cVersion));
	BOOL bWorking = cFtpFileFind.FindFile(strPath);
	while (bWorking)
	{
		bWorking = cFtpFileFind.FindNextFile();
		// .或者..    
		if (cFtpFileFind.IsDots())
			continue;

		CPackageInfo packInfo;
		strcpy_s(packInfo.m_cRarName, sizeof(packInfo.m_cRarName), W2A(cFtpFileFind.GetFileName()));
		packInfo.m_nFileType = 0;
		// 文件夹    
		if (cFtpFileFind.IsDirectory())
			packInfo.m_nFileType |= FILE_ATTRIBUTE_DIRECTORY;
		else
			packInfo.m_nFileType |= FILE_ATTRIBUTE_NORMAL;   // 普通文件    

		m_FtpData.m_lstPackage.push_back(packInfo);
	}
}

BOOL CFTPManager::InitialSever()
{
	strcpy_s(m_SeverInfo.m_cAddress, sizeof(m_SeverInfo.m_cAddress), "172.16.16.36");
	strcpy_s(m_SeverInfo.m_cUserName, sizeof(m_SeverInfo.m_cUserName), "");
	strcpy_s(m_SeverInfo.m_cPassword, sizeof(m_SeverInfo.m_cPassword), "");
	strcpy_s(m_SeverInfo.m_cVersion, sizeof(m_SeverInfo.m_cVersion), "V3.1");
	try
	{
		CloseConnection();
		// m_bInitiativeMode = TRUE 为被动模式    
		USES_CONVERSION;
		m_pFtpConn = m_cInetSession.GetFtpConnection(A2W(m_SeverInfo.m_cAddress),
			A2W(m_SeverInfo.m_cUserName), A2W(m_SeverInfo.m_cPassword));
		if (NULL != m_pFtpConn)
			return TRUE;
	}
	catch (CInternetException *e)
	{
		e->Delete();
	}
	return FALSE;
}

void CFTPManager::CloseConnection()
{

}

CFTPSeverInfo& CFTPManager::GetFtpServerInfo()
{
	return m_SeverInfo;
}

CFTPDataInfo& CFTPManager::GetFtpData()
{
	return m_FtpData;
}
