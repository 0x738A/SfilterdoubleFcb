#pragma once
#ifndef __FILECONF_INCLUDED
#define __FILECONF_INCLUDED

#include "BaseTypes.h"

#define	ISAFE_FILE_VERSION				0x0001

#pragma pack(push,1)
#pragma warning(push)
#pragma warning(disable:4200)

enum FILE_STATUS {
	FILE_STATUS_BROKEN,
	FILE_STATUS_NORMAL,
	FILE_STATUS_PENDING,
	FILE_STATUS_DELETED,
	FILE_STATUS_TEMP
};

#define FILE_STATUS_SIGN_NORMAL		"v2Tgz69Ef8l4p[1"
#define FILE_STATUS_SIGN_DELETED	"H5Z.Wz8Fr8W4b7Q"
#define FILE_STATUS_SIGN_PENDING	"uIe6Dhv5^Yh3kLB"
#define FILE_STATUS_SIGN_TEMP		"4e[Wg*jo4R68^1;"
#define FILE_STATUS_SIGN_LEN 16
#define HEAD_WARNING "���棡�����Ż����ݰ�ȫϵͳ���ܵ��ļ�����ֱ���޸����ݽ�����ļ��𻵣�����"

#define FILE_CRYPT_BLOCK_SIZE  512 //�ļ����ܿ��С

#define	PEER_KEY_LEN	32

struct tagFileHead
{
	char			szHeadSig[10];				// �ļ���־
	char			szStatusSig[16];			// ���ͱ�ʶ
	char			szWarning[80];				// �ļ���־
	unsigned short	nVersion;					// �汾

	unsigned int	nHeadCrc32;					// �ļ�ͷCRC

	unsigned char	bHeadEncryptFlag;			// ���ܱ�־
	unsigned int	nHeadKey;					// �ļ�ͷ��Կ
};

struct tagFileInfo
{
	tagFileHead		FileHead;

	unsigned short	nHeadLen;					// �ļ�ͷԭ����
	unsigned short	nHeadDataLen;				// �ļ�ͷѹ���󳤶�

	unsigned long long llFileSize;				// �ļ���С
	unsigned int	nFileCrc32;					// �ļ�CRCУ����

	unsigned char	nSecretDegree : 3;			// �ܼ�	0-15  0 ��ͨ  1 ���� 2 ���� 3 ����

	unsigned char   bCryptIndex : 4;			// �����㷨���� 0-15
	unsigned char	bKeyFlag : 1;				// 0:��Կ���� 1:��ʵ��Կ
	unsigned int	nKeyIndex;					// ��Կ����

	unsigned char	bTagFlag;					// �Ƿ�ʹ�ñ�ǩ�ļ�

	unsigned int    nKey;						// ��ʵ��Կ
	unsigned short	nKeyLen;					// ��Կ����

	unsigned int	nUserID;					// ������ID

	unsigned char	bFileControlFlag;		// �ļ�Ȩ�޿��Ʊ�־

	unsigned char   bGroupOnlyFlag : 1;			// �����ڳ�Ա
	unsigned char	bModifyFlag : 1;			// �޸�Ȩ��
	unsigned char	bCopyFlag : 1;				// ����Ȩ��
	unsigned char	bPrintFlag : 1;				// ��ӡȨ��
	unsigned char	bPrintTimesFlag : 1;		// ��ӡ��������
	unsigned char	bReadTimesFlag : 1;			// ���ܴ���
	unsigned char	bLifeCycleFlag : 1;			// �������ڿ���

	unsigned char	bFileCrcFlag : 1;			// �����ļ�������У��
	unsigned char	bModifyAuthFlag : 1;		// �Ƿ������޸�Ȩ��
	unsigned char	bSelfDestoryFlag : 1;		// �Ƿ��Զ�����
	unsigned char	bPasswordFlag : 1;			// ��������������ݸ���Ȩ��

	unsigned char	bGroupID_1_InheritFlag : 1;	// ��֯�ṹ�̳й�ϵ
	unsigned char	bGroupID_2_InheritFlag : 1;	// ��֯�ṹ�̳й�ϵ
	unsigned char	bGroupID_3_InheritFlag : 1;	// ��֯�ṹ�̳й�ϵ
	unsigned char	bGroupID_4_InheritFlag : 1;	// ��֯�ṹ�̳й�ϵ

	unsigned char	nNodeID_1;					// �û���ID 0-255
	unsigned char	nNodeID_2;					// �û���ID 0-255
	unsigned char	nNodeID_3;					// �û���ID 0-255
	unsigned char	nNodeID_4;					// �û���ID 0-255

	unsigned char	nPrintTimes;				// �����ӡ���� 0-255
	unsigned char	nReadTimes;					// ������ܴ���	0-255

	unsigned int	nBeginTime;					// ��ʼʱ��
	unsigned int	nEndTime;					// ��ֹʱ��

	unsigned int	nPassword;					// ����

	unsigned char	uuid[UUID_LEN];				// �ļ�UUID

	unsigned int	publicKeyId;				// ��ȫ��Կ���

	unsigned char	peerKey[PEER_KEY_LEN];		// ��ȫ��Կ
	
	unsigned char	shareKeyType;				// 0��δ���� 1���Ѽ���

	unsigned char	shareKey[PEER_KEY_LEN];		// �����ڴ������ݣ�����¼���ļ�����
};
typedef struct tagFileInfo *pTagFileInfo;

#pragma warning(pop)
#pragma pack(pop)

#define FILEHEAD_HEAD_LEN	sizeof(tagFileHead)
#define FILEHEAD_INFO_LEN	sizeof(tagFileInfo)
#define FILEHEAD_BODY_LEN	(FILEHEAD_INFO_LEN - FILEHEAD_HEAD_LEN)

#endif