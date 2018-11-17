//#include "State.h"
//
//
//
//CState::CState()
//{
//
//}
//
//CState::~CState()
//{
//
//}
//
//void CState::Init_Map(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb)
//{
//	//tilemap = new TileMap(game->GetDirect3DDevice(), game->GetBackBuffer(), L"textures\\mapA.bmp");
//}
//
//void CState::LoadResource_State()
//{
//	CTextures * textures = CTextures::GetInstance();
//	textures->loadResources();
//	CSprites * sprites = CSprites::GetInstance();
//	CAnimations * animations = CAnimations::GetInstance();
//}
//
//void CState::Update_State(DWORD dt)
//{
//	//Update collision event
//	vector<LPGAMEOBJECT> coObjects;
//	vector<LPGAMEOBJECT> coObjectsStatic;
//
//	for (int i = 1; i < objects.size(); i++)
//	{
//		coObjects.push_back(objects[i]);
//	}
//	for (int i = 0; i < objecttsStatic.size();i++)
//	{
//		coObjectsStatic.push_back(objecttsStatic[i]);
//	}
//	for (int i = 0; i < objects.size(); i++)
//	{
//		objects[i]->Update(dt, &coObjects, &coObjectsStatic);
//	}
//
//	//keep simon center view port
//	if (simon->x > SCREEN_WIDTH / 2 && !marioInView)
//	{
//		tilemap->SetViewportX(simon->x - SCREEN_WIDTH / 2);
//		marioInView = true;
//	}
//	if (marioInView)
//	{
//		tilemap->SetViewportX(simon->x - SCREEN_WIDTH / 2);
//	}
//
//	//Check status keyboard
//	PollKeyboard();
//	simon->KeyEventHandler();
//}
//
//void CState::Render_State(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
//{
//	//LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
//	//LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
//	//LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();
//
//
//
//	//render
//	if (d3ddv->BeginScene())
//	{
//		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
//		//tilemap->DrawScrollWindow();
//
//		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
//
//		//Render object normal
//		for (int i = 1; i < objects.size(); i++)
//		{
//			objects[i]->Render(tilemap->GetViewportX(), tilemap->GetViewPortY());
//		}
//			
//		//Render object static
//		for (int i = 0; i < objecttsStatic.size(); i++)
//		{
//			objecttsStatic[i]->Render(tilemap->GetViewportX(), tilemap->GetViewPortY());
//		}
//
//		//Render simon
//		objects[0]->Render(tilemap->GetViewportX(), tilemap->GetViewPortY());
//
//		spriteHandler->End();
//		d3ddv->EndScene();
//
//		d3ddv->Present(NULL, NULL, NULL, NULL);
//	}
//}
