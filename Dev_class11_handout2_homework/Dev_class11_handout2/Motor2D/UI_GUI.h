#ifndef _UI_GUI__H
#define _UI_GUI__H

#include "j1Module.h"

enum UI_Type 
{
LABEL=0,
SPRITE,
BUTTON
};


class UI_GUI : public j1Module
{
public:
	UI_GUI() {};
	~UI_GUI() {};

protected:
	UI_Type type;
	int     pos_x = 0;
	int     pos_y = 0;





};




#endif  // !_UI_GUI__H
