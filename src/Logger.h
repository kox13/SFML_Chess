#pragma once
#include <streambuf>

class Logger : public std::streambuf {
public:
	Logger();
	~Logger() = default;

	static Logger& Instance();

	static bool Initialize();
	static void Shutdown();

	virtual int overflow(int c) override;
};

