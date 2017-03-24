/***************************************************************************************************
*Copyright(C),2017-2020,
*FileName	:  ToolsContainer
*Author	:  Givins.zhu
*Version	:  1.0
*Date		:  2017/02/22
*Desc		:  QB可能用到的工具集合
*Relation :
*Module   :
*Others   :
*Function :
*History	:
*Email    :  zhumushun3550@163.com
***************************************************************************************************/
#pragma once
#include "NetModel.h"
#include <afxinet.h>

#define  FTPMANAGER CFTPManager::GetInstance()
//class CFTPSeverInfo;
class FTP_API CFTPManager{
public:
	/************************************************************************/
	/* 获取唯一实例                                                           */
	/************************************************************************/
	static CFTPManager& GetInstance();

	/************************************************************************/
	/* 重新拉取FTP信息 增量                                                    */
	/************************************************************************/
	void ReloadTFPData();

	/************************************************************************/
	/* 获取服务器信息                                                            */
	/************************************************************************/
	CFTPSeverInfo& GetFtpServerInfo();

	/************************************************************************/
	/* 获取数据信息                                                           */
	/************************************************************************/
	CFTPDataInfo& GetFtpData();
private:
	CFTPManager();
	~CFTPManager();

	/************************************************************************/
	/* 初始化                                                                */
	/************************************************************************/
	void InitialFTP();

	/************************************************************************/
	/* 获取服务器信息                                                          */
	/************************************************************************/
	BOOL InitialSever();

	/************************************************************************/
	/* 断开连接                                                               */
	/************************************************************************/
	void CloseConnection();

private:
	/************************************************************************/
	/* 服务器信息                                                             */
	/************************************************************************/
	CFTPSeverInfo m_SeverInfo;

	/************************************************************************/
	/*  所有相关数据列表                                                       */
	/************************************************************************/
	CFTPDataInfo  m_FtpData;

	//// 创建并初始化一个或多个同时的Internet 会话    
	CInternetSession m_cInetSession;


	//// 管理与Internet服务器的FTP连接并允许直接操纵服务器中的目录和文件    
	CFtpConnection *m_pFtpConn;

};