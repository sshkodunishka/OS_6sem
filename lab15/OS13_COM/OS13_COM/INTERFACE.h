#pragma once
#include <objbase.h>
#include "OS11_HTAPI.h"

#define FNAME L"SLab15.CA.COM"
#define VINDX L"SLab15.CA.1"
#define PRGID L"SLab15.CA"

// {A87118BB-A1E7-4499-933C-0A354893E749}
static const GUID CLSID_CA =
{ 0xa87118bb, 0xa1e7, 0x4499, { 0x93, 0x3c, 0xa, 0x35, 0x48, 0x93, 0xe7, 0x49 } };

// {8B8976E6-9974-4B73-AC1A-10C1E4364430}
static const GUID IID_IOS13 =
{ 0x8b8976e6, 0x9974, 0x4b73, { 0xac, 0x1a, 0x10, 0xc1, 0xe4, 0x36, 0x44, 0x30 } };


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

