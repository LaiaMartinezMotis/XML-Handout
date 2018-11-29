#ifndef _UI_SPRITE__H
#define _UI_SPRITE__H

#include "p2Defs.h"
#include "UI_GUI.h"


class UI_Sprite: public UI_GUI
{
public:
	UI_Sprite();
	~UI_Sprite() {};

	void Draw() const;

private:
	// SDL_RECT sprte_rect;
	
};




#endif  // !_UI_SPRITE__H
