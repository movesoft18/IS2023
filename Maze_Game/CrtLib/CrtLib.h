#pragma once

// константы цветов

namespace crt
{
	const int COLOR_BLACK = 0;
	const int COLOR_BLUE = 1;
	const int COLOR_GREEN = 2;
	const int COLOR_CYAN = 3;
	const int COLOR_RED = 4;
	const int COLOR_MAGENTA = 5;
	const int COLOR_BROWN = 6;
	const int COLOR_GRAY = 7;
	const int COLOR_DARK_GRAY = 8;
	const int COLOR_LIGHT_BLUE = 9;
	const int COLOR_LIGHT_GREEN = 10;
	const int COLOR_LIGHT_CYAN = 11;
	const int COLOR_LIGHT_RED = 12;
	const int COLOR_LIGHT_MAGENTA = 13;
	const int COLOR_YELLOW = 14;
	const int COLOR_WHITE = 15;

	void SetTextColor(int color);
	void SetTextBackground(int color);
	void GotoXY(int x, int y);
	void SetCursorVisibility(bool visible);
	void ShowCursor();
	void HideCursor();
}

