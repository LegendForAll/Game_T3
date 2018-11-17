#include "TileMap.h"

//TileMap::TileMap(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb, LPCWSTR filename)
//{
//	d3ddv = dv;
//	backBuffer = bb;
//	tiles = LoadSurface(filename);
//	if (!tiles) return;
//
//	//create the scroll buffer surface in memory, slightly bigger 
//	//than the screen
//	int SCROLLBUFFERWIDTH = SCREEN_WIDTH + TILEWIDTH * 2;
//	int SCROLLBUFFERHEIGHT = SCREEN_HEIGHT + TILEHEIGHT * 2;
//
//	HRESULT result = dv->CreateOffscreenPlainSurface(
//		SCROLLBUFFERWIDTH, SCROLLBUFFERHEIGHT,
//		D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT,
//		&scrollbuffer,
//		NULL);
//	if (result != S_OK) return;
//
//
//}
//
//TileMap::TileMap(LPCWSTR filename)
//{
//	tiles = LoadSurface(filename);
//	if (!tiles) return;
//
//	//create the scroll buffer surface in memory, slightly bigger 
//	//than the screen
//	int SCROLLBUFFERWIDTH = SCREENW + TILEWIDTH * 2;
//	int SCROLLBUFFERHEIGHT = SCREENH + TILEHEIGHT * 2;
//
//	HRESULT result = d3ddv->CreateOffscreenPlainSurface(
//		SCROLLBUFFERWIDTH, SCROLLBUFFERHEIGHT,
//		D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT,
//		&scrollbuffer,
//		NULL);
//	if (result != S_OK) return;
//}

TileMap::TileMap()
{

}

TileMap::TileMap(LPCWSTR filename)
{
	//load resource candle
	textures = CTextures::GetInstance();
	//textures->Add(ID_TEX_MAP1, L"textures\\mapA.bmp", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_MAP1, L"textures\\lv1.png", D3DCOLOR_XRGB(255, 0, 255));

}

TileMap::~TileMap()
{

}

//void TileMap::DrawTile(LPDIRECT3DSURFACE9 source, int tilenum, int width, int height, int columns, LPDIRECT3DSURFACE9 dest, int destx, int desty)
//{
//	RECT r1;
//	r1.left = (tilenum % columns) * width;
//	r1.top = (tilenum / columns) * height;
//	r1.right = r1.left + width;
//	r1.bottom = r1.top + height;
//
//	//set destination rect
//	RECT r2 = { destx,desty,destx + width,desty + height };
//
//	//draw the tile 
//	d3ddv->StretchRect(source, &r1, dest, &r2, D3DTEXF_NONE);
//}
//
//LPDIRECT3DSURFACE9 TileMap::LoadSurface(LPCWSTR filename)
//{
//	LPDIRECT3DSURFACE9 image = NULL;
//	//get width and height from bitmap file
//	D3DXIMAGE_INFO info;
//	HRESULT result = D3DXGetImageInfoFromFile(filename, &info); //LPCWSTR
//	if (result != D3D_OK) return NULL;
//	//create surface
//	result = d3ddv->CreateOffscreenPlainSurface(
//		info.Width, //width of the surface
//		info.Height, //height of the surface
//		D3DFMT_X8R8G8B8, //surface format
//		D3DPOOL_DEFAULT, //memory pool to use
//		&image, //pointer to the surface
//		NULL); //reserved (always NULL)
//	if (result != D3D_OK) return NULL;
//	//load surface from file into newly created surface
//	result = D3DXLoadSurfaceFromFile(
//		image, //destination surface
//		NULL, //destination palette
//		NULL, //destination rectangle
//		filename,//.c_str(), //source filename
//		NULL, //source rectangle
//		D3DX_DEFAULT, //controls how image is filtered
//		D3DCOLOR_XRGB(0, 0, 0), //for transparency (0 for none)
//		NULL); //source image info (usually NULL)
//			   //make sure file was loaded okay
//	if (result != D3D_OK) return NULL;
//	return image;
//}

void TileMap::DrawTiles(LPD3DXSPRITE spriteHandler)
{
	int tilex, tiley;
	//int columns, rows;
	int x, y;
	int tilenum;

	tilex = 0;
	tiley = 0;

	//calculate starting tile position
	//tilex = ViewPortX / TILEWIDTH;
	//tiley = ViewPortY / TILEHEIGHT;

	//calculate the number of columns and rows
	//columns = WINDOWWIDTH / TILEWIDTH <= MAPWIDTH ? WINDOWWIDTH / TILEWIDTH : MAPWIDTH;
	//rows = WINDOWHEIGHT / TILEHEIGHT <= MAPHEIGHT ? WINDOWHEIGHT / TILEHEIGHT : MAPHEIGHT;

	RECT r1;
	D3DXVECTOR3 pos;
	LPDIRECT3DTEXTURE9 texBG = textures->Get(ID_TEX_MAP1);

	//int rowStart = abs(480 - ViewPortY) / 64 - 2 < 0 ? 0 : abs(480 - ViewPortY) / 64 - 2;
	//int rowEnd = (ViewPortY / 64) > rows ? rows : (ViewPortY / 64);
	//int start = rows - rowEnd;
	//int end = rows - rowStart;
	//int colEnd = (ViewPortX / 64 + 640 / 64 + 1) > columns ? columns : (ViewPortX / 64 + 640 / 64 + 1);
	//int colStart = ViewPortX / 64;

	for (y = 0; y <  6; y++)
	{
		for (x = 0; x < 24; x++)
		{
			//retrieve the tile number from this position
			tilenum = MAPDATA[((tiley + y) * MAPWIDTH + (tilex + x))];
			
			r1.left = (tilenum % 24) * TILEWIDTH;
			r1.top = (tilenum / 24) * TILEHEIGHT;
			r1.right = r1.left + TILEWIDTH;
			r1.bottom = r1.top + TILEHEIGHT;

			pos.x = x * TILEWIDTH;
			pos.y = y * TILEHEIGHT;
			pos.z = 0;

			matrix[y][x] = r1;
			/*spriteHandler->Draw(texBG, &r1, NULL, &pos, D3DCOLOR_XRGB(255, 255, 255));*/
		}
	}
}

//void TileMap::DrawScrollWindow(LPD3DXSPRITE spriteHandler, bool scaled )
//{
//	this->DrawTiles(spriteHandler);
//	//bool scaled = false;
//	//calculate the partial sub-tile lines to draw using modulus
//	int partialx = ViewPortX % TILEWIDTH;
//	int partialy = ViewPortY % TILEHEIGHT;
//
//	////set dimensions of the source image as a rectangle
//	D3DXVECTOR3 p(partialx, partialy, 0);
//	RECT r1 = { partialx,partialy,partialx + WINDOWWIDTH - 1,partialy + WINDOWHEIGHT - 1 };
//	spriteHandler->Draw(NULL, &r1, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
//	////set the destination rectangle
//	//RECT r2;
//	//if (scaled) {
//	//	//use this line for scaled display
//	//	RECT r = { 0, 0, WINDOWWIDTH - 1, WINDOWHEIGHT - 1 };
//	//	r2 = r;
//	//}
//	//else {
//	//	//use this line for non-scaled display
//	//	RECT r = { 0, 0, SCREENW - 1, SCREENH - 1 };
//	//	r2 = r;
//	//}
//
//	//draw the "partial tile" scroll window onto the back buffer
//	//d3ddv->StretchRect(scrollbuffer, &r1, backBuffer, NULL, D3DTEXF_NONE);
//}

void TileMap::LoadMap()
{

}

void TileMap::Render(LPD3DXSPRITE spriteHandler)
{

	float colStart = ViewPortX / 64.0f;
	float colEnd = (ViewPortX / 64 + 640 / 64 + 1) > 24 ? 24 : (ViewPortX / 64 + 640 / 64 + 1);
	D3DXVECTOR3 pos(0,0,0);
	LPDIRECT3DTEXTURE9 texBG = textures->Get(ID_TEX_MAP1);

	for (int y = 0; y <= 5;y++)
	{
		for (int i = colStart; i < colEnd;i++)
		{
			pos.x = i * 64 - ViewPortX;
			pos.y = y * 64 - ViewPortY;
			pos.z = 0;
			spriteHandler->Draw(texBG, &matrix[y][i], NULL, &pos, D3DCOLOR_XRGB(255, 255, 255));
		}
	}
}

void TileMap::UpdateScrollPosition()
{
	const int GAMEWORLDWIDTH = TILEWIDTH * MAPWIDTH;
	const int GAMEWORLDHEIGHT = TILEHEIGHT * MAPHEIGHT;

	//update horizontal scrolling position and speed
	ViewPortX += SpeedX;

	if (ViewPortX < 0)
	{
		ViewPortX = 0;
		SpeedX = 0;
	}
	else if (ViewPortX > GAMEWORLDWIDTH - WINDOWWIDTH)
	{
		ViewPortX = GAMEWORLDWIDTH - WINDOWWIDTH;
		SpeedX = 0;
	}

	//update vertical scrolling position and speed
	ViewPortY += SpeedY;
	if (ViewPortY < 0)
	{
		ViewPortY = 0;
		SpeedY = 0;
	}
	else if (ViewPortY > GAMEWORLDHEIGHT - WINDOWHEIGHT)
	{
		ViewPortY = GAMEWORLDHEIGHT - WINDOWHEIGHT;
		SpeedY = 0;
	}
}
