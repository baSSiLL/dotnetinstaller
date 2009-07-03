#pragma once
namespace DVLib
{
	inline CString FormatNumber(ULONG p_Number)
	{
		CString tmp;
		tmp.Format(TEXT("%lu"), p_Number);
		return tmp;
	}

	inline CString FormatHexNumber(ULONG p_Number)
	{
		CString tmp;
		tmp.Format(TEXT("0x%x"), p_Number);
		return tmp;
	}

	//Equivalente di StrFormatByteSizeA (che per� non � supportata in Win95)
	//       532 -> 532 bytes
	//      1340 -> 1.3KB
	//     23506 -> 23.5KB
	//   2400016 -> 2.4MB
	//2400000000 -> 2.4GB
	inline CString FormatNumberToBytes(ULONG p_Bytes)
	{
		CString tmp;
		if (p_Bytes == 1) //bytes
			tmp.Format(TEXT("%lu byte"), p_Bytes);
		else if (p_Bytes < 1024) //bytes
			tmp.Format(TEXT("%lu bytes"), p_Bytes);
		else if (p_Bytes < (1048576) ) //Kb
			tmp.Format(TEXT("%.2fKB"), (double)p_Bytes/1024.0 );
		else if (p_Bytes < (1073741824) ) //Mb
			tmp.Format(TEXT("%.2fMB"), (double)p_Bytes/1048576.0 );
		else if (p_Bytes < (1099511627776) ) //GB
			tmp.Format(TEXT("%.2fGB"), (double)p_Bytes/1073741824.0 );
		else
			tmp.Format(TEXT("%lu bytes"), p_Bytes);

		return tmp;
	}

	inline CString FormatDateTime(const CTime& ts)
	{
		return ts.Format(_T("%Y-%m-%d %H:%M:%S"));
	}

	inline CString FormatCurrentDateTime()
	{
		return FormatDateTime(CTime::GetCurrentTime());
	}

	//! format an ANSI message from an HRESULT
	std::string FormatMessageFromHRA(HRESULT hr);
	//! format an ANSI message from a Win32 error code
	std::string FormatMessageFromLastErrorCodeA(DWORD);
	//! format a UNICODE message from an HRESULT
	std::wstring FormatMessageFromHRW(HRESULT hr);
	//! format a UNICODE message from a Win32 error code
	std::wstring FormatMessageFromLastErrorCodeW(DWORD);
	//! format a message with a list of arguments (printf-style)
	std::string FormatMessageFromVArgs(char *, va_list&);
	//! format a message with a list of arguments (printf-style)
	std::wstring FormatMessageFromVArgs(wchar_t *, va_list&);
	//! format a message with a list of arguments (printf-style)
	std::string FormatMessage(char *, ...);
	//! format a message with a list of arguments (printf-style)
	std::wstring FormatMessage(wchar_t *, ...);
}