#pragma once
#include <objbase.h>
#include "OS11_HTAPI.h"

#define FNAME L"Skm13.CA.COM"
#define VINDX L"Skm13.CA.1"
#define PRGID L"Skm13.CA"

// {1CB85228-E5EF-4CD6-9BD2-D45CFEFD2034}
static const GUID CLSID_CA =
{ 0x1cb85228, 0xe5ef, 0x4cd6, { 0x9b, 0xd2, 0xd4, 0x5c, 0xfe, 0xfd, 0x20, 0x34 } };

// {68F60FCB-0F40-46ED-B401-28B6C4F22384}
static const GUID IID_IOS13 =
{ 0x68f60fcb, 0xf40, 0x46ed, { 0xb4, 0x1, 0x28, 0xb6, 0xc4, 0xf2, 0x23, 0x84 } };

interface IOS13 :IUnknown {
    STDMETHOD(Add(const double, const double, double*)) PURE;
    
	STDMETHOD(Sub(const double, const double, double*)) PURE;

	STDMETHOD(Create   //  ������� HT             
	(
		int	  Capacity,					   // ������� ���������
		int   SecSnapshotInterval,		   // ������������� ���������� � ���.
		int   MaxKeyLength,                // ������������ ������ �����
		int   MaxPayloadLength,            // ������������ ������ ������
		const wchar_t  FileName[512],          // ��� ����� 
		const wchar_t  HTUsersGroup[512],          // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ����������  

	STDMETHOD(Open     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(Open     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		const wchar_t    userName[512],         // ��� ����� 
		const wchar_t    password[512],         // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ����������  

	STDMETHOD(Close     //  ������� HT             
	(
		HT::HTHANDLE** hthandle           // ���������� HT (File, FileMapping)
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(OpenExist     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(Snap     //  ������� HT             
	(
		HT::HTHANDLE** hthandle
	)) PURE; 	// != NULL �������� ���������� 

	STDMETHOD(Insert     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** element              // �������
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(Get     //  ������� HT             
	(
		HT::Element** result,
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** element              // ������� 
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(Delete     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT (����)
		HT::Element** element              // ������� 
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(Update     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** oldelement,          // ������ ������� (����, ������ �����)
		void** newpayload,          // ����� ������  
		int*   newpayloadlength     // ������ ����� ������
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(GetLastErrorProg     //  ������� HT             
	(
		std::string& error,
		HT::HTHANDLE** ht                         // ���������� HT
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(CreateElement     //  ������� HT             
	(
		std::string* key,
		HT::Element** el                         // ���������� HT
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(CreateElement     //  ������� HT             
	(
		std::string* key,
		std::string* payload,
		HT::Element** el                         // ���������� HT
	)) PURE; 	// != NULL �������� ����������

	STDMETHOD(print     //  ������� HT             
	(
		HT::Element** element              // ������� 
	)) PURE; 	// != NULL �������� ����������
};

