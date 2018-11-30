#include "j1App.h"
#include "UI_Sprite.h"
#include "j1Render.h"
#include "j1Gui.h"


UI_Sprite::UI_Sprite(SDL_Rect rect)
{
	sprite_rect = rect;
}

void UI_Sprite::Draw() const
{
	App->render->Blit(App->gui->GetAtlas(), pos_x, pos_y, &sprite_rect);
}