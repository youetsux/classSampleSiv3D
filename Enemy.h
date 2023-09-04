#pragma once
const int ENEMY_SIZE{64};
const int ENEMY_RECT_SIZE{ 48 };

class Enemy
{
//何も書かないとprivate
	//メンバ変数
	Vec2 pos;
	double speed;
	Vec2 moveDir;
	Texture tex;
	RectF myRect;//バウンディングボックス
	bool isAlive;
	bool isTimerON;
	double myTimer;
	int killCount;
public:
	Enemy();
	Enemy(Vec2 _pos, double _speed, Vec2 _dir);
	~Enemy();
	void SetMyRect(double _size);
	RectF GetRect();
	//メンバ関数
	void KillEnemy();
	void Update();
	void Draw();
	int GetKillCount();
};

