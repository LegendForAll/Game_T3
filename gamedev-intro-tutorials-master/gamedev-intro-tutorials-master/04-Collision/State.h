#pragma once
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Mario.h"
#include "Brick.h"
#include "Goomba.h"
#include "Candle.h"
#include "Items.h"
#include "LimitTransparent.h"

class CState
{
public:

	//CGame *game;
	CMario *simon;

	TileMap *tilemap;
	bool marioInView = false;

	DWORD dt;
	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> objecttsStatic;

public:

	CState();
	~CState();

	virtual void Init_Map(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb);
	virtual void LoadResource_State();
	virtual void Update_State(DWORD dt);
	virtual void Render_State(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler);
};