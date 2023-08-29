#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	pos = { 0,0 };
	speed = 100;
	moveDir = { 0,0 };
	tex = TextureAsset(U"PLAYER");
}

Player::Player(Vec2 _pos)
{
	pos = _pos;
	speed = 100;
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
//キャラクタのパラメータの更新用関数
void Player::Update()
{
	moveDir = { 1.0, 0.0 };
	pos = pos + speed * Scene::DeltaTime() * moveDir;
	SetMyRect(48);
}

//キャラクタの現在の状態の描画関数
void Player::Draw()
{
	tex.resized(PLAYER_SIZE).drawAt(pos);
	myRect.drawFrame(1, 1, Palette::Red);
}
