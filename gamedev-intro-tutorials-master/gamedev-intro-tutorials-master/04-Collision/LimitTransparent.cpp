#include "LimitTransparent.h"

void CLimit::LoadResource()
{

}

void CLimit::Render(float xViewport, float yViewport)
{

}

void CLimit::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x;
	t = y;
	r = x + LIMIT_BBOX_WIDTH;
	b = y + LIMIT_BBOX_HEIGHT;
}
