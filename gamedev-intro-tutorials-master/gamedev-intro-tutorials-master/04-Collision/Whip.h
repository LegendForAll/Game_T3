#pragma once
#include "GameObject.h"
#include "define.h"
#include "Candle.h"
#include "Items.h"


class Whip : public CGameObject
{
	float curX;
	float curY;

	bool isLeft = false;
	int currentAni = WP_WHIP_STAND_LEFT;
	bool oneHIT = false;

	Items *itemSimon;
	int levelWhip = 0;

public:
	Whip();
	~Whip();
	
	virtual void LoadResource();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects , vector<LPGAMEOBJECT> *coObjectStatic );
	virtual void Render(float xViewport, float yViewport);

	void SetPositionLR(float _x, float _y, int _isStand, bool _isLeft, Items *_itemSimon);
	int GetLevel() { return this->levelWhip; }
	void SetLevel(int _lv) { this->levelWhip = _lv; }
	void ChangeWhip();
};