#pragma once
#include <objbase.h>

#define FNAME L"Shk.CA.COM"
#define VINDX L"Shk.CA.1"
#define PRGID L"Shk.CA"

// {23C2726C-4096-42FA-97D9-F0A3EEBC2657}
static const GUID CLSID_CA =
{ 0x23c2726c, 0x4096, 0x42fa, { 0x97, 0xd9, 0xf0, 0xa3, 0xee, 0xbc, 0x26, 0x57 } };

// {5580830F-FC02-44FE-8E4E-50E435462839}
static const GUID IID_IAdder =
{ 0x5580830f, 0xfc02, 0x44fe, { 0x8e, 0x4e, 0x50, 0xe4, 0x35, 0x46, 0x28, 0x39 } };

interface IAdder :IUnknown {
    STDMETHOD(Add(const double, const double, double*)) PURE;
    STDMETHOD(Sub(const double, const double, double*)) PURE;
};


// {FA1A057A-08CF-4954-8A50-BED22C68D113}
static const GUID IID_IMultiplier =
{ 0xfa1a057a, 0x8cf, 0x4954, { 0x8a, 0x50, 0xbe, 0xd2, 0x2c, 0x68, 0xd1, 0x13 } };

interface IMultiplier :IUnknown {
    STDMETHOD(Mul(const double, const double, double*))  PURE;
    STDMETHOD(Div(const double, const double,  double*)) PURE;
};
