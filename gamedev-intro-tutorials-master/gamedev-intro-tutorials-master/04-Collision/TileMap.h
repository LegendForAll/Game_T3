#pragma once
#include<d3dx9.h>
#include<d3d9.h>
#include"define.h"
#include"Sprites.h"

#define ID_TEX_MAP1  100

class TileMap
{
	int SCREENW = SCREEN_WIDTH;
	int SCREENH = SCREEN_HEIGHT;

	//settings for the scroller
	const int TILEWIDTH = 64;
	const int TILEHEIGHT = 64;
	const int MAPWIDTH = 24;
	const int MAPHEIGHT = 6;

	RECT matrix[6][24];

	//scrolling window size
	const int WINDOWWIDTH = (SCREENW / TILEWIDTH) * TILEWIDTH;
	const int WINDOWHEIGHT = (SCREENH / TILEHEIGHT) * TILEHEIGHT;
	LPCWSTR filename;
	float ViewPortX, ViewPortY;
	int SpeedX, SpeedY;
	long start;

	CTextures *textures;
	//LPDIRECT3DSURFACE9 scrollbuffer = NULL;
	//LPDIRECT3DSURFACE9 tiles = NULL;
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	//LPDIRECT3DSURFACE9 backBuffer = NULL;
	

	int MAPDATA[24 * 6] = {
	//1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1,
	//1, 1, 1, 1, 3, 4, 4, 5,
	//6, 7, 7, 7, 7, 7, 8, 8, 6, 7, 7, 7, 7, 7, 8, 8,
	//8, 8, 8, 8, 9, 10, 10, 11,
	//12, 13, 12, 12, 12, 12, 7, 7, 12, 13, 12, 12, 12, 12, 7, 7,
	//7, 7, 14, 14, 15, 16, 17, 18,
	//13, 19, 13, 13, 13, 13, 13, 13, 13, 19, 13, 13, 13, 13, 13, 13,
	//13, 13, 19, 20, 21, 22, 17, 11,
	//23, 24, 25, 23, 23, 25, 23, 25, 23, 24, 25, 23, 23, 25, 23, 25,
	//25, 26, 24, 27, 28, 29, 30, 31,
	//32, 33, 34, 32, 32, 34, 32, 34, 32, 33, 34, 32, 32, 34, 32, 34,
	//34, 35, 33, 36, 37, 38, 39, 40
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,
	24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
	48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,
	72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,
	96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
	120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143
	};

public:

	TileMap();
	TileMap(LPCWSTR filename);

	//TileMap(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb, LPCWSTR filename);
	//TileMap(LPCWSTR filename);
	~TileMap();
	//void DrawTile(LPDIRECT3DSURFACE9 source, // source surface image
	//	int tilenum, // tile #
	//	int width, // tile width
	//	int height, // tile height
	//	int columns, // columns of tiles
	//	LPDIRECT3DSURFACE9 dest, // destination surface
	//	int destx, // destination x
	//	int desty // destination y
	//);
	//LPDIRECT3DSURFACE9 LoadSurface(LPCWSTR filename);
	void DrawTiles(LPD3DXSPRITE spriteHandler);

	//void DrawScrollWindow(LPD3DXSPRITE spriteHandler, bool scaled = false);

	void LoadMap();
	void Render(LPD3DXSPRITE spriteHandler);

	void ViewPort() { ViewPortX = 0; ViewPortY = 0; }
	void UpdateScrollPosition();
	void SetViewPortY(float y) { ViewPortY += y; }
	void SetViewportX(float x) { ViewPortX += x; }
	float GetViewportX() { return ViewPortX; }
	float GetViewPortY() { return ViewPortY; }
};

