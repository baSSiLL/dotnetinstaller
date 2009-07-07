#pragma once

class InstallerLog
{
public:
	InstallerLog(void);
	~InstallerLog(void);
	void DisableLog() { m_enabled = false; }
	bool IsEnableLog() const { return m_enabled; }
    void EnableLog() { m_enabled = true; }
	const std::wstring& GetLogFile() const { return m_logfile; }
	void SetLogFile(const std::wstring& filename) { m_logfile = filename; }
	void Write(const std::wstring& message);
	void Write(const std::wstring& message, const std::wstring& appendMessage);
private:
	bool m_enabled;
	std::wstring m_logfile;
    HANDLE m_hFile;
};

extern InstallerLog ApplicationLog;