
//there alreadu stdint.h i think but is kinda refrence to me

#pragma once

// Constants and macros
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define TRUE 1
#define FALSE 0
#define NULL 0 //couases wanrning but its okay

// Type aliases

// Standard Windows types
typedef char CHAR;
typedef wchar_t WCHAR;
typedef short SHORT;
typedef int INT;
typedef long LONG;
typedef __int64 LONGLONG;

typedef unsigned char BYTE, UCHAR;
typedef unsigned short WORD, USHORT;
typedef unsigned int UINT;
typedef unsigned long DWORD, ULONG;
typedef unsigned __int64  ULONGLONG, FILETIME, QWORD;

// Sized integer types
typedef char int8;
typedef short int16, int16_t;
typedef int int32, int32_t;
typedef __int64 int64, int64_t;

typedef unsigned char uint8, uint8_t;
typedef unsigned short uint16, uint16_t;
typedef unsigned int uint32, uint32_t;
typedef unsigned __int64 uint64, uint64_t;

struct GUID
{
	unsigned long  Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char  Data4[8];
};

// Expression type, as returned by built-in type() function
enum
{
	BooleanType,
	IntegerType,
	FloatingPointType,
	StringType,
	ReferenceType
};

typedef DWORD COLORREF;
// typedef float	FLOAT;
// typedef double	DOUBLE;