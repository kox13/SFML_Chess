#pragma once
#include <streambuf>
#include <string>

#define LOG_ERROR(error) Logger::Instance().LogError(error, __FILE__, __LINE__)
#define LOG_WARNING(warning) Logger::Instance().LogWarning(warning, __FILE__, __LINE__)
#define LOG_MESSAGE(message) Logger::Instance().LogMessage(message)
#define LOG_CMESSAGE(message, color) Logger::Instance().LogMessage(message, color)

class Logger : public std::streambuf {
public:
	enum class Color {
		BLACK = 30,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE
	};

	static Logger& Instance();

	static bool Initialize();
	static void Shutdown();

	void LogError(const std::string&, const char* file, unsigned int line);
	void LogWarning(const std::string& warning, const char* file, unsigned int line);
	void LogMessage(const std::string& message, Color color = Color::WHITE);

	virtual int overflow(int c) override;

private:
	Logger();
	~Logger() = default;
};

