#pragma once
#include <windows.h>
#pragma pack(1)
#define DLLTMP "C:\\Users\\Administrator\\AppData\\Local\\Temp\\copyDllHook.dll"
#define RARTMP "C:\\Users\\Administrator\\AppData\\Local\\Temp\\Rar.exe "
#define UNRARTMP "C:\\Users\\Administrator\\AppData\\Local\\Temp\\UnRAR.exe"
#define TMPDIR "C:\\Users\\Administrator\\AppData\\Local\\Temp\\RJUNCOMOUTGONINGFILETOOL__"
#define E_TMPDIR "E:\\XUJYALDSKFJLSKDFJKLSDFJALSDKFJLKSD"

#define EncryptHeader (LONGLONG)0xA1F0B4CF378EB4C8

typedef struct _Time {
	char startuserTime[20] ;
	char stopuserTime[20] ;
}Time,*PTime;

//����Ǽ��ܺ���ļ�д���ļ�ͷ���information
typedef struct _RjFileSrtuct {
	LONGLONG EncryptHead; //�ļ�ͷ������
	LONGLONG FileSize;
	LONGLONG ValidDataLength;
	LONGLONG AllocationSize;
	char FileSrcName [60];  //ԭ���ļ�������
	Time Outgoingfiletime; //�ļ��ⷢʱ���¼
	INT Count;//ʹ�ô���
	BOOLEAN forbidensaveas;//�Ƿ�������Ϊ
	BOOLEAN onlyread;//�Ƿ�ֻ��
	ULONG length; //����buffter�ĳ��ȣ�
}RjFileSrtuct, *pRjFileSrtuct;

//Ŀ������ļ���ӵ�е���Ϣ
typedef struct  _rjFileInfo {
	RjFileSrtuct encryptHead;
	char *  EncryptBuffer; //���ܺ��buffer  //����Ҳ�����ֽڶ�����
}rjFileInfo,*prjFileInfo;









