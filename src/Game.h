#pragma once

class Game {
public:
	Game();
	~Game();

	void Run();

private:
	bool InitializeSystems();
	void ShutdownSystems();

private:
	bool m_Run;
};

