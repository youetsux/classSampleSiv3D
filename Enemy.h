#pragma once

class Enemy
{
//何も書かないとprivate
	//メンバ変数
	Vec2 pos;
	double speed;
	Vec2 moveDir;
	Texture tex;
	RectF myRect;//バウンディングボックス
public:
	Enemy();
	Enemy(Vec2 _pos, double _speed, Vec2 _dir);
	~Enemy();
	void SetMyRect(double _size);
	//メンバ関数
	void Update();
	void Draw();
};

