#include "pch.h"
#include "KeyPoint.h"

KeyPoint::KeyPoint()
{
	this->base_flag = BASEP_LEFT_TOP;
	this->color = 0;
	this->point.x = 0;
	this->point.y = 0;
}

KeyPoint::KeyPoint(POINT point, COLORREF color, int base_flag)
{
	this->point = point;
	this->color = color;
	this->base_flag = base_flag;
	
}

KeyPoint::KeyPoint(int x, int y, COLORREF color, int base_flag)
{
	this->point.x =x;
	this->point.y = y;
	this->color = color;
	this->base_flag = base_flag;

}

POINT KeyPoint::getAbsoluteXY(HWND hwnd)
{
	BaseAPI api;
	POINT basepoint = getBasePoint(this->base_flag, hwnd);
	RECT start = api.getProcessClient(hwnd);
	basepoint.x = start.left+basepoint.x+this->point.x;
	basepoint.y = start.top+basepoint.y+this->point.y;
	return basepoint;
}

int KeyPoint::getX(HWND hwnd)
{
	POINT basepoint = getBasePoint(this->base_flag, hwnd);
	return basepoint.x+point.x;
}

int KeyPoint::getY(HWND hwnd)
{
	POINT basepoint = getBasePoint(this->base_flag, hwnd);
	return basepoint.y + point.y;
}

POINT KeyPoint::getXY(HWND hwnd)
{
	POINT basepoint = getBasePoint(this->base_flag, hwnd);
	basepoint.x += this->point.x;
	basepoint.y += this->point.y;
	return basepoint;
}

int KeyPoint::getOffsetX()
{
	return this->point.x;
}

int KeyPoint::getOffsetY()
{
	return this->point.y;
}

POINT KeyPoint::getBasePoint(int base_flag, HWND hwnd)
{
	RECT client;
	GetClientRect(hwnd, &client);
	POINT result;
	switch (base_flag) {
	case BASEP_LEFT_TOP:
		result.x = 0;
		result.y = 0;
		break;
	case BASEP_RIGHT_TOP:
		result.x = client.right;
		result.y = 0;
		break;
	case BASEP_LEFT_BOTTOM:
		result.x = 0;
		result.y = client.bottom;
		break;
	case BASEP_RIGHT_BOTTOM:
		result.x = client.right;
		result.y = client.bottom;
		break;
	case BASEP_CENTER:
		result.x = client.right / 2;
		result.y = client.bottom / 2;
		break;
	case BASEP_CENTER_TOP:
		result.x = client.right / 2;
		result.y = 0;
		break;
	case BASEP_CENTER_BOTTOM:
		result.x = client.right / 2;
		result.y = client.bottom;
		break;
	default:
		result.x = 0;
		result.y = 0;
		break;
	}
	return result;
}
