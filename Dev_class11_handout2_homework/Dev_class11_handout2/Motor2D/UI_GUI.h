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

	bool Start();
	bool PreUpdate();
	bool Update(float dt);


	virtual void Draw() {};




public: 
	UI_Type type;
	int     pos_x = 0;
	int     pos_y = 0;

};




#endif  // !_UI_GUI__H
