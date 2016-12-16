#pragma once
#ifndef __NETCONF_INCLUDED
#define __NETCONF_INCLUDED

#include "BaseTypes.h"

/*
 * ���ݼ�����ýṹ
 */
enum PROTOCAL
{
	PROTOCAL_ALL = 0,
	PROTOCAL_UDP = 1,
	PROTOCAL_TCP = 2
};

struct tagNetPolicyOld
{
	char			szAccessGateAddr[SIZE_512];			// ׼����ʵ�ַ�б��ָ���|��
	unsigned short	nPortList[SIZE_32];
	WCHAR			process[SIZE_512];
	PROTOCAL		protocal;
};

struct tagNetControl
{
	int				NetPolicySize;
	tagNetPolicyOld (*NetPolicy);
	bool			bNetFlag;							// �Ƿ���������
	unsigned int	nPortList[SIZE_32];					// ����˿��б�

	bool			bAccessGateFlag;					// ׼������
	char			szAccessGateAddr[SIZE_512];			// ׼����ʵ�ַ�б��ָ���|��
};

#endif //__NETCONF_H__
