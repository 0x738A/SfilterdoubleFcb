#include "MySTL.h"
#if 0
#pragma once
#ifndef __POLICYCONF_H__
#define __POLICYCONF_H__

#include "BaseTypes.h"

#define	ISAFE_POLICY_VERSION		0x0001

#define PRODUCT_TYPE_SAFEFILE			0x00000001
#define PRODUCT_TYPE_SAFEFILE_CONTROL	0x00000002
#define PRODUCT_TYPE_SAFEFILE_FLOW		0x00000004
#define PRODUCT_TYPE_DEVICE				0x00000100
#define PRODUCT_TYPE_NET				0x00000200
#define PRODUCT_TYPE_AUDIT				0x00001000
#define PRODUCT_TYPE_MONITOR			0x00010000
#define PRODUCT_TYPE_DEFENCE			0x00100000
#define PRODUCT_TYPE_PATCHER			0x00200000
#define PRODUCT_TYPE_VIRUS				0x00400000
#define PRODUCT_TYPE_FIREWALL			0x00800000
#define PRODUCT_TYPE_ACCESSGATE			0x01000000
#define PRODUCT_TYPE_SAFEGATE			0x02000000

#define OPER_TYPE_CREATE			0x00000001
#define OPER_TYPE_OPEN				0x00000002
#define OPER_TYPE_DELETE			0x00000004
#define OPER_TYPE_ZIP				0x00000008
#define OPER_TYPE_COPY				0x00000010
#define OPER_TYPE_HTTP				0x00000020
#define OPER_TYPE_HTTPFILE			0x00000040
#define OPER_TYPE_FTP				0x00000080
#define OPER_TYPE_EXECUTE			0x00000100
#define OPER_TYPE_SCREENSHOT        0x00000200
#define OPER_TYPE_MAIL		        0x00000400
#define OPER_TYPE_QQ				0x00000800
#define OPER_TYPE_MSN				0x00001000
#define OPER_TYPE_WANGWANG			0x00002000
#define OPER_TYPE_YY				0x00004000
#define OPER_TYPE_SKYPE				0x00008000

#define DEVICE_AUTH_OPEN			0x00000001
#define DEVICE_AUTH_READ			0x00000002
#define DEVICE_AUTH_WRITE			0x00000004
#define DEVICE_AUTH_EXECUTE			0x00000008

enum PolicyScriptType
{
	POLICY_NONE = 0,

	// �������ܲ���
	POLICY_ENCRYPT,					// ���ܲ���
	POLICY_GLOBAL_ENCRYPT,			// ��ؼ���

	// ������
	POLICY_PASS_PATH,				// ·��������
	POLICY_PASS_FILE,				// �ļ�������
	POLICY_PASS_PROCESS,			// ���̰�����
	POLICY_PASS_DLL,				// ģ�������

	// ����
	POLICY_NET_OPEN_PORTS,			// ��������˿�
	POLICY_NET_ACCESS_GATE,			// ׼������

	POLICY_END,
};

#pragma pack(push,1)
#pragma warning(push)
#pragma warning(disable:4200)

struct tagPolicyHead
{
	unsigned short	nVersion;							// �汾��
	unsigned short	nSubVersion;						// �Ӱ汾��
	bool			bEncryptFlag;						// �Ƿ����
	unsigned int	nCrc32;								// CRCУ��
	int				nKey;								// ����Key
};

struct tagProductInfo
{
	unsigned char	nLicenseType;						// ��Ȩ���� �˻���Ȩ ������Ȩ
	unsigned int	nProductType;						// ��Ʒ���� ֧��32��ģ��
	unsigned char	nProductLevel;						// �����ȼ�
	unsigned int	nBeginTime;							// ��Ȩ��ʼʱ��
	unsigned int	nEndTime;							// ��Ȩ��ֹʱ��

	unsigned short	nPolicyUpdateInterval;				// ���Ը��¼�������ӣ�

	unsigned int	nHeartBeatInterval;					// ������ʱ���������ӣ�
	unsigned int	nOfflineAddTime;					// ���߲�ʱ��Сʱ��
};

struct tagBaseAuth
{
	// �豸�ܿ� x7 x6 x5 x4 x3 (�豸��ִ��) x2���豸��д�� x1���豸�ɶ��� x0���豸������
	unsigned char	bUDiskFlag;							// U���豸 
	unsigned char	bCDROMFlag;							// �����豸
	unsigned char	bFloppyFlag;						// �����豸

	unsigned char	bComFlag;							// �����豸
	unsigned char	bInfraredFlag;						// �����豸

	unsigned char	bBluetoothFlag;						// �����豸	
	unsigned char	bWifiFlag;							// Wifi�豸

	unsigned char	bDevice1Flag;						// �豸Ԥ��
	unsigned char	bDevice2Flag;						// �豸Ԥ��
	unsigned char	bDevice3Flag;						// �豸Ԥ��
	unsigned char	bDevice4Flag;						// �豸Ԥ��
	unsigned char	bDevice5Flag;						// �豸Ԥ��

	bool			bPrinterFlag;						// ��ӡ���豸
	bool			bWatermarkFlag;						// ��ӡˮӡ
	unsigned char	nWatermarkLevel;					// ˮӡ��ɫ��ǳ 0-10 Խ��Խ��
	bool			bWatermarkPicFlag;					// �Ƿ��ӡͼƬ
	wchar_t			wszWatermarkText[SIZE_256];			// ˮӡ����
	wchar_t			wszWatermarkURL[SIZE_256];			// ˮӡͼƬ��ַ

	// ��������
	bool			bSelfProtectFlag;					// ������ ���̷�ɱ Ŀ¼��������ɾ��
	bool			bProcessSigFlag;					// ����ǩ��
	bool			bModuleSigFlag;						// ģ��ǩ��
	bool			bDriverSigFlag;						// ����ǩ��

	// ��Ϊ��� ���ݼ��
	bool			bAuditFlag;							// ��Ϊ���
	unsigned int	nAuditType;							// ��Ϊ�������
	bool			bMonitorFlag;						// ���ݼ��
	unsigned int	nMonitorType;						// ���ݼ������

	bool			bScreenShotUploadFlag;				// ��������
	unsigned int	nScreenShotUploadInterval;			// �������
};

struct tagUserAuth
{
	tagBaseAuth		BaseAuth;

	wchar_t			wszUserName[SIZE_32];
	unsigned int	nUserID;
	unsigned char	nNodeID1;							// ��ID 0-255
	unsigned char	nNodeID2;
	unsigned char	nNodeID3;
	unsigned char	nNodeID4;

	bool			bModeModifyFlag;					// �Ƿ������û��ı�ģʽ
	unsigned char	nSecretDegree;						// �ܼ�	0-15  0 ��ͨ  1 ���� 2 ���� 3 ����

	unsigned short	nCryptIndex;						// �����㷨����
	bool			bCrc32Flag;							// �Ƿ���CRC������У��

	bool			bGroupOnlyFlag;						// Ĭ����Ȩ��
	bool			bGroupKeyFlag;						// ����Կ

	bool			bTrayFlag;							// ����ͼ����ʾ
	bool			bMainFormFlag;						// ��������ʾ
	bool			bQuitFlag;							// �Ƿ�����˳�
	bool			bSyncServerTimeFlag;				// �Ƿ�ͬ��������ʱ��

	bool			bBackupFlag;						// �Ƿ񱸷�
	bool			bBackupAskFlag;						// �Ƿ�ѯ���û��Ƿ񱸷�
	unsigned char	nBackupInterval;					// ���ݼ����Сʱ��
	wchar_t			wszBackupPath[SIZE_256];			// ����·��

	bool			bBackupDeleteFlag;					// �Ƿ񱸷�ɾ���ļ�
	wchar_t			wszBackupDeletePath[SIZE_256];		// ɾ���ļ�����·��

	bool			bPopWindowFlag;						// �Ƿ񵯴�
	bool			bScreenShotFlag;					// ��������

	bool			bLockScreenFlag;					// �Ƿ��Զ�����
	unsigned int	nLockScreenValue;					// �Զ������޶���ʱ�䣨���ӣ�

	bool			bOfflineFlowFlag;					// ��������
	bool			bOutFlowFlag;						// �ⷢ����
	bool			bDecryptFlowFlag;					// ��������
	bool			bUninstallFlowFlag;					// ж������

	bool			bDecryptManageFlag;					// ��������
	bool			bOutManageFlag;						// �ⷢ����
	bool			bOfflineManageFlag;					// ��������
	bool			bUninstallManageFlag;				// ж������

	bool			bPublisherToolFlag;					// �ⷢ��������
	bool			bProcessSignatureToolFlag;			// ����ǩ������
	bool			bModuleSignatureToolFlag;			// ģ��ǩ������
	bool			bDriverSignatureToolFlag;			// ����ǩ������
	bool			bDecryptToolFlag;					// �ĵ����ܹ���
	bool			bOfflineToolFlag;					// ������Ȩ����
	bool			bUninstallToolFlag;					// ж����Ȩ����	

	bool			bReservedToolFlag2;
	bool			bReservedToolFlag3;
	bool			bReservedToolFlag4;
	bool			bReservedToolFlag5;
	bool			bReservedToolFlag6;
};

struct tagKeyItem
{
	unsigned char	nKeyIndex;
	unsigned int	nNodeID;
	unsigned int	nKey;
	unsigned short	nKeyLen;
	unsigned short	nKeyDegree;
	bool			IsActiveFlag;
};

struct tagKeyList
{
	unsigned char	nKeyNums;							// ��Կ��Ŀ
	tagKeyItem		KeyItem[KEY_NUMS];
};

struct tagScriptItem
{
	unsigned char	nItemNums;							// �ű���Ŀ
	wchar_t			wszContent[POLICY_ITEM_NUMS][SIZE_256];
};

struct tagPolicyScriptItem
{
	unsigned char	nScriptType;						// ��������ID
	tagScriptItem	ContentList;						// ��������
	tagScriptItem	ProcessList;						// ���Թ�������
};

struct tagPolicyScriptList
{
	unsigned char	nPolicyNums;						// ������Ŀ
	tagPolicyScriptItem	PolicyItem[POLICY_NUMS];
};

struct tagSigItem
{
	wchar_t			wszName[SIZE_32];					// ����
	unsigned int	nSize;								// �ļ���С
	unsigned char	szSignature[SIZE_16];				// MD5ǩ��
};

struct tagSigList
{
	unsigned char	nSigNums;							// ǩ����Ŀ
	tagSigItem		SigItem[SIG_NUMS];
};

struct tagPolicy
{
	tagPolicyHead		PolicyHead;
	tagProductInfo		ProductInfo;
	tagBaseAuth			GlobalAuth;
	tagUserAuth			UserAuth;
	tagKeyList			KeyList;
	tagPolicyScriptList	PolicyScriptList;
	tagSigList			ProcessSigList;
};

#pragma warning(pop)
#pragma pack(pop)

#endif //__POLICYCONF_H__

#endif
#pragma once
#ifndef __POLICYCONF_H__
#define __POLICYCONF_H__

#include "BaseTypes.h"

#define	ISAFE_POLICY_VERSION			0x0001		//���԰汾
#define	ISAFE_TEMP_POLICY_VERSION		0x0000		//���԰汾

#define PRODUCT_TYPE_SAFEFILE			0x00000001	//�ļ�����
#define PRODUCT_TYPE_SAFEFILE_CONTROL	0x00000002	//Ȩ�޿���
#define PRODUCT_TYPE_SAFEFILE_FLOW		0x00000004	//��������
#define PRODUCT_TYPE_DEVICE				0x00000100	//�豸�ܿ�
#define PRODUCT_TYPE_NET				0x00000200	//�����ܿ�
#define PRODUCT_TYPE_AUDIT				0x00001000	//��Ϊ���
#define PRODUCT_TYPE_MONITOR			0x00010000	//���ݼ��
#define PRODUCT_TYPE_DEFENCE			0x00100000	//��������
#define PRODUCT_TYPE_PATCHER			0x00200000	//��������
#define PRODUCT_TYPE_VIRUS				0x00400000	//ɱ��
#define PRODUCT_TYPE_FIREWALL			0x00800000	//����ǽ
#define PRODUCT_TYPE_ACCESSGATE			0x01000000	//׼������
#define PRODUCT_TYPE_SAFEGATE			0x02000000	//��ȫ����

#define OPER_TYPE_CREATE			0x00000001
#define OPER_TYPE_OPEN				0x00000002
#define OPER_TYPE_DELETE			0x00000004
#define OPER_TYPE_ZIP				0x00000008
#define OPER_TYPE_COPY				0x00000010
#define OPER_TYPE_HTTP				0x00000020
#define OPER_TYPE_HTTPFILE			0x00000040
#define OPER_TYPE_FTP				0x00000080
#define OPER_TYPE_EXECUTE			0x00000100
#define OPER_TYPE_SCREENSHOT        0x00000200
#define OPER_TYPE_MAIL		        0x00000400
#define OPER_TYPE_QQ				0x00000800
#define OPER_TYPE_MSN				0x00001000
#define OPER_TYPE_WANGWANG			0x00002000
#define OPER_TYPE_YY				0x00004000
#define OPER_TYPE_SKYPE				0x00008000

#define DEVICE_AUTH_OPEN			0x00000001
#define DEVICE_AUTH_READ			0x00000002
#define DEVICE_AUTH_WRITE			0x00000004
#define DEVICE_AUTH_EXECUTE			0x00000008

enum PolicyScriptType
{
	POLICY_NONE = 0,

	// �������ܲ���
	POLICY_ENCRYPT,					// ���ܲ���
	POLICY_GLOBAL_ENCRYPT,			// ��ؼ���

	// ������
	POLICY_PASS_PATH,				// ·��������
	POLICY_PASS_FILE,				// �ļ�������
	POLICY_PASS_PROCESS,			// ���̰�����
	POLICY_PASS_DLL,				// ģ�������

	// ����
	POLICY_NET_OPEN_PORTS,			// ��������˿�
	POLICY_NET_ACCESS_GATE,			// ׼������

	POLICY_END,
};

#pragma pack(push,1)
#pragma warning(push)
#pragma warning(disable:4200)

struct tagPolicyHead
{
	unsigned short	nVersion;							// �汾��
	unsigned short	nSubVersion;						// �Ӱ汾��
	bool			bEncryptFlag;						// �Ƿ����
	unsigned int	nCrc32;								// CRCУ��
	int				nKey;								// ����Key
};

struct tagProductInfo
{
	unsigned char	nLicenseType;						// ��Ȩ���� �˻���Ȩ ������Ȩ
	unsigned int	nProductType;						// ��Ʒ���� ֧��32��ģ��
	unsigned char	nProductLevel;						// �����ȼ�
	unsigned int	nBeginTime;							// ��Ȩ��ʼʱ��
	unsigned int	nEndTime;							// ��Ȩ��ֹʱ��

	unsigned short	nPolicyUpdateInterval;				// ���Ը��¼�������ӣ�

	unsigned int	nHeartBeatInterval;					// ������ʱ���������ӣ�
	unsigned int	nOfflineAddTime;					// ���߲�ʱ��Сʱ��
};

struct tagBaseAuth
{
	// �豸�ܿ� x7 x6 x5 x4 x3 (�豸��ִ��) x2���豸��д�� x1���豸�ɶ��� x0���豸������
	unsigned char	bUDiskFlag;							// U���豸 
	unsigned char	bCDROMFlag;							// �����豸
	unsigned char	bFloppyFlag;						// �����豸

	unsigned char	bComFlag;							// �����豸
	unsigned char	bInfraredFlag;						// �����豸

	unsigned char	bBluetoothFlag;						// �����豸	
	unsigned char	bWifiFlag;							// Wifi�豸

	unsigned char	bDevice1Flag;						// �豸Ԥ��
	unsigned char	bDevice2Flag;						// �豸Ԥ��
	unsigned char	bDevice3Flag;						// �豸Ԥ��
	unsigned char	bDevice4Flag;						// �豸Ԥ��
	unsigned char	bDevice5Flag;						// �豸Ԥ��

	bool			bPrinterFlag;						// ��ӡ���豸
	bool			bWatermarkFlag;						// ��ӡˮӡ
	unsigned char	nWatermarkLevel;					// ˮӡ��ɫ��ǳ 0-10 Խ��Խ��
	bool			bWatermarkPicFlag;					// �Ƿ��ӡͼƬ
	wchar_t			wszWatermarkText[SIZE_256];			// ˮӡ����
	wchar_t			wszWatermarkURL[SIZE_256];			// ˮӡͼƬ��ַ

	// ��������
	bool			bSelfProtectFlag;					// ������ ���̷�ɱ Ŀ¼��������ɾ��
	bool			bProcessSigFlag;					// ����ǩ��
	bool			bModuleSigFlag;						// ģ��ǩ��
	bool			bDriverSigFlag;						// ����ǩ��

	// ��Ϊ��� ���ݼ��
	bool			bAuditFlag;							// ��Ϊ���
	unsigned int	nAuditType;							// ��Ϊ�������
	bool			bMonitorFlag;						// ���ݼ��
	unsigned int	nMonitorType;						// ���ݼ������

	bool			bScreenShotUploadFlag;				// ��������
	unsigned int	nScreenShotUploadInterval;			// �������
};

struct tagUserAuth
{
	tagBaseAuth		BaseAuth;

	wchar_t			wszUserName[SIZE_32];
	unsigned int	nUserID;
	unsigned char	nNodeID1;							// ��ID 0-255
	unsigned char	nNodeID2;
	unsigned char	nNodeID3;
	unsigned char	nNodeID4;

	bool			bModeModifyFlag;					// �Ƿ������û��ı�ģʽ
	unsigned char	nSecretDegree;						// �ܼ�	0-15  0 ��ͨ  1 ���� 2 ���� 3 ����

	unsigned short	nCryptIndex;						// �����㷨����
	bool			bCrc32Flag;							// �Ƿ���CRC������У��

	bool			bGroupOnlyFlag;						// Ĭ����Ȩ��
	bool			bGroupKeyFlag;						// ����Կ

	bool			bTrayFlag;							// ����ͼ����ʾ
	bool			bMainFormFlag;						// ��������ʾ
	bool			bQuitFlag;							// �Ƿ�����˳�
	bool			bSyncServerTimeFlag;				// �Ƿ�ͬ��������ʱ��

	bool			bBackupFlag;						// �Ƿ񱸷�
	bool			bBackupAskFlag;						// �Ƿ�ѯ���û��Ƿ񱸷�
	unsigned char	nBackupInterval;					// ���ݼ����Сʱ��
	wchar_t			wszBackupPath[SIZE_256];			// ����·��

	bool			bBackupDeleteFlag;					// �Ƿ񱸷�ɾ���ļ�
	wchar_t			wszBackupDeletePath[SIZE_256];		// ɾ���ļ�����·��

	bool			bPopWindowFlag;						// �Ƿ񵯴�
	bool			bScreenShotFlag;					// ��������

	bool			bLockScreenFlag;					// �Ƿ��Զ�����
	unsigned int	nLockScreenValue;					// �Զ������޶���ʱ�䣨���ӣ�

	bool			bOfflineFlowFlag;					// ��������
	bool			bOutFlowFlag;						// �ⷢ����
	bool			bDecryptFlowFlag;					// ��������
	bool			bUninstallFlowFlag;					// ж������

	bool			bDecryptManageFlag;					// ��������
	bool			bOutManageFlag;						// �ⷢ����
	bool			bOfflineManageFlag;					// ��������
	bool			bUninstallManageFlag;				// ж������

	bool			bPublisherToolFlag;					// �ⷢ��������
	bool			bProcessSignatureToolFlag;			// ����ǩ������
	bool			bModuleSignatureToolFlag;			// ģ��ǩ������
	bool			bDriverSignatureToolFlag;			// ����ǩ������
	bool			bDecryptToolFlag;					// �ĵ����ܹ���
	bool			bOfflineToolFlag;					// ������Ȩ����
	bool			bUninstallToolFlag;					// ж����Ȩ����	

	bool			bReservedToolFlag2;
	bool			bReservedToolFlag3;
	bool			bReservedToolFlag4;
	bool			bReservedToolFlag5;
	bool			bReservedToolFlag6;
};

struct tagKeyItem
{
	unsigned char	nKeyIndex;			//��Կ����
	unsigned int	nNodeID;			//��id
	unsigned int	nKey;				//��Կ����
	unsigned short	nKeyLen;			//��Կ����
	unsigned short	nKeyDegree;
	bool			IsActiveFlag;
};

struct tagKeyList
{
	unsigned char	nKeyNums;							// ��Կ��Ŀ
	tagKeyItem		KeyItem[KEY_NUMS];
};

struct tagScriptItem
{
	unsigned char	nItemNums;							// �ű���Ŀ
	wchar_t			wszContent[POLICY_ITEM_NUMS][SIZE_256];
};

struct tagPolicyScriptItem
{
	unsigned char	nScriptType;						// ��������ID
	tagScriptItem	ContentList;						// ��������
	tagScriptItem	ProcessList;						// ���Թ�������
};

struct tagPolicyScriptList
{
	unsigned char	nPolicyNums;						// ������Ŀ
	tagPolicyScriptItem	PolicyItem[POLICY_NUMS];
};

struct tagSigItem
{
	wchar_t			wszName[SIZE_32];					// ����
	unsigned int	nSize;								// �ļ���С
	unsigned char	szSignature[SIZE_16];				// MD5ǩ��
};

struct tagSigList
{
	unsigned char	nSigNums;							// ǩ����Ŀ
	tagSigItem		SigItem[SIG_NUMS];
};

struct tagPolicy
{
	tagPolicyHead		PolicyHead;
	tagProductInfo		ProductInfo;
	tagBaseAuth			GlobalAuth;
	tagUserAuth			UserAuth;
	tagKeyList			KeyList;
	tagPolicyScriptList	PolicyScriptList;
	tagSigList			ProcessSigList;
};

/************************************
 * Temp Policy start
 *************************************/

class tagFileTempPolicyItem {
public:
	int nodeID;								//�ڵ�ID
	int fileKey;							//�ļ�key
	char UUID[UUID_LEN];					//UUID
};

class tagProcessPolicyBlacklistItem {
public:
	CArray<int> processList;				//�����б� ���ǩ��ID
	PWCHAR alert;							//��ʾ��Ϣ
};

class tagNetPolicyBlacklistItem {
public:
	CArray<USHORT> port;					//�˿��б�
	CArray<int> processList;				//�����б� ���ǩ��ID
	CArray<unsigned char[4]> ip;			//ip�б�  תΪHex��ʽ
	int protocal;							//Э������ 0��ALL 1��UDP 2��TCP
};

class tagProcessPolicy {
public:
	CArray<tagProcessPolicyBlacklistItem> blacklist;	//���̺�����
};

class tagNetPolicy {
public:
	CArray<tagNetPolicyBlacklistItem> blacklist;		//���������
	CArray<tagNetPolicyBlacklistItem> whitelist;		//���������
};

class tagEncryptPolicyItem
{
public:
	CArray<PWCHAR>	wszContent;
	CArray<int> processList;
};

class tagAuth {
public:
	int blockingNetWhenRelated;
};

class tagUserPolicy {
public:
	CArray<tagFileTempPolicyItem> fileTempPolicy;		//�ļ���ʱ����
	tagProcessPolicy	processPolicy;					//���̲���
	tagNetPolicy		netPolicy;						//�������
	CArray<tagEncryptPolicyItem>	encryptPolicy;
	tagAuth	auth;
};


class tagSignItem
{
public:
	int				id;							// ǩ��ID
	PWCHAR			fileName;					// ����
	unsigned int	fileSize;					// �ļ���С
	UCHAR			hash[SIZE_16];				// MD5ǩ��
};

class tagSignature {
public:
	CArray<tagSignItem> processSignList;		//����ǩ���б�
};

class tagTempPolicyHead {
public:
	unsigned short	nVersion;							// �汾��
	unsigned short	nSubVersion;						// �Ӱ汾��
	bool			bEncryptFlag;						// �Ƿ����
	unsigned int	nCrc32;								// CRCУ��
	int				nKey;								// ����Key
	int				bodyLen;
};

class tagNodesItem {
public:
	int nodeId;										//�ڵ�ID
	int isAdmin;									//�Ƿ���� 1���� 0����
};

class tagKeyItemNew
{
public:
	unsigned int	nKeyIndex;
	unsigned int	nNodeID;
	unsigned int	nKey;
	unsigned short	nKeyLen;
	unsigned short	nKeyDegree;
	bool			IsActiveFlag;
};

class tagUserConfig {
public:
	CArray<tagNodesItem>		nodeList;		//�ڵ���Ϣ
	CArray<tagKeyItemNew>		keyList;
};

class tagTempPolicy {
public:
	tagTempPolicyHead		PolicyHead;
	tagUserPolicy			userPolicy;			//�û�����
	tagUserConfig			userConfig;			//�û���Ϣ
	tagSignature			signature;			//ǩ��
};

#pragma warning(pop)
#pragma pack(pop)

#endif //__POLICYCONF_H__
