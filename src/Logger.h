#pragma once
#include <streambuf>
#include <cstdio>
#include <cstring>
#include <mutex>

#define FILE_NAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))
#define LOG_MESSAGE(format, ...)  Logger::Message(format, __VA_ARGS__)
#define LOG_CMESSAGE(color, format, ...) Logger::Message(color, format, __VA_ARGS__)
#define LOG_WARNING(format, ...)  Logger::Warning(FILE_NAME, __LINE__, format, __VA_ARGS__)
#define LOG_ERROR(format, ...)	  Logger::Error(FILE_NAME, __LINE__, format, __VA_ARGS__)

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

	// Initialization creates a Logger instance to redirect the SFML err stream to it, 
	// but other than that the instance won't be used
	static void Initialize();
	static void Shutdown();

	template<typename... Args>
	static void Message(const char* message, Args... args) {
		std::lock_guard<std::mutex> lock(s_Lock);
		std::printf("[MESSAGE]: ");
		std::printf(message, args...);
		std::printf("\n");
	}

	template<typename... Args>
	static void Message(Color color, const char* message, Args... args) {
		std::lock_guard<std::mutex> lock(s_Lock);
		std::printf("\033[%im[MESSAGE]: ", (int)color);
		std::printf(message, args...);
		std::printf("\033[0m\n");
	}

	template<typename... Args>
	static void Warning(const char* file, unsigned int line, const char* message, Args... args) {
		std::lock_guard<std::mutex> lock(s_Lock);
		std::printf("\033[%im[WARNING]: ", (int)Color::YELLOW);
		std::printf(message, args...);
		std::printf("\033[0m <in %s at %i> \n", file, line);
	}

	template<typename... Args>
	static void Error(const char* file, unsigned int line, const char* message, Args... args) {
		std::lock_guard<std::mutex> lock(s_Lock);
		std::printf("\033[%im[ERROR]: ", (int)Color::RED);
		std::printf(message, args...);
		std::printf("\033[0m <in %s at %i> \n", file, line);
	}

	virtual int overflow(int c) override;

private:
	Logger();
	~Logger() = default;

	static std::mutex s_Lock;
};

