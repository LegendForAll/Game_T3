#pragma once
#include "State.h"

class StateOne : public CState
{

public:
	StateOne();
	~StateOne();

	virtual void Init_Map(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb);
	virtual void LoadResource_State();
	virtual void Update_State(DWORD dt);
	virtual void Render_State(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler);
};