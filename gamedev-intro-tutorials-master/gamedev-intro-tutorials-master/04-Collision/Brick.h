#pragma once
#include "GameObject.h"
#include "define.h"


class CBrick : public CGameObject
{
public:
	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};