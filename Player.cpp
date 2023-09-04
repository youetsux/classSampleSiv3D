#include "stdafx.h"
#include "Player.h"

//プレイヤーをアローキーとwasdで移動


Player::Player()
{
	pos = { 0,0 };
	speed = 200;
	moveDir = { 0,0 };
	tex = TextureAsset(U"PLAYER");
}

Player::Player(Vec2 _pos)
{
	pos = _pos;
	speed = 250;
	moveDir = { 0,0 };
	tex = TextureAsset(U"PLAYER");
}

Player::~Player()
{
	//なにもしないよ
}
void Player::SetMyRect(double _size)
{
	Vec2 hosei = { _size / 2, _size / 2 };
	myRect = { pos - hosei, _size, _size };
}

bool Player::IsMyRectHit(RectF _rect) //引数の_rectは相手のmyRect
{
	float wAB = myRect.w / 2.0 + _rect.w / 2.0;
	float hAB = myRect.h / 2.0 + _rect.h / 2.0;
	float distx = abs(myRect.center().x - _rect.center().x);
	float disty = abs(myRect.center().y - _rect.center().y);
	if (wAB > distx && hAB > disty)
		return true;
	else
		return false;
}

direction Player::GetDirection()
{
	if ((KeyUp | KeyW).pressed())
	{
		return UP;
	}
	else if ((KeyLeft | KeyA).pressed())
	{
		return LEFT;
	}
	else if ((KeyDown | KeyS).pressed())
	{
		return DOWN;
	}
	else if ((KeyRight | KeyD).pressed())
	{
		return RIGHT;
	}
	else
		return NONE;
}

//キャラクタのパラメータの更新用関数
void Player::Update()
{
	direction d = GetDirection();
	Vec2 dirs[5] =
	{
		{0,-1}, {-1,0}, {0,1}, {1,0}, {0,0}
	};
	moveDir = dirs[d];
	pos = pos + speed * Scene::DeltaTime() * moveDir;
	pos.x = Clamp(pos.x, PLAYER_RECT_SIZE / 2.0, Scene::Width() - PLAYER_RECT_SIZE / 2.0);
	pos.y = Clamp(pos.y, PLAYER_RECT_SIZE / 2.0, Scene::Height() - PLAYER_RECT_SIZE / 2.0);

	SetMyRect(PLAYER_RECT_SIZE);
}

//キャラクタの現在の状態の描画関数
void Player::Draw()
{
	tex.resized(PLAYER_SIZE).drawAt(pos);
	//myRect.drawFrame(1, 1, Palette::Red);
}
