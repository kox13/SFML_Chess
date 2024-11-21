#pragma once

#include "Context.h"

class Game {
public:
	Game();
	~Game() = default;

	void Run();
private:
	bool m_Run;
	Context m_Context;
};

