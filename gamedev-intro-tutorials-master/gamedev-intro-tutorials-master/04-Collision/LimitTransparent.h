#pragma once
#include "GameObject.h"

#define LIMIT_BBOX_WIDTH  20
#define LIMIT_BBOX_HEIGHT 480

class CLimit : public CGameObject
{
	//int currentAni = LM_LEFT_1;

public:
	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};