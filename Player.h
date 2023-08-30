#pragma once
const int PLAYER_SIZE{ 64 };
const int PLAYER_RECT_SIZE{ 48 };
enum direction
{
	UP, LEFT, DOWN, RIGHT, NONE
};


class Player
{
//何も書かないとprivate
	//メンバ変数
	Vec2 pos;
	double speed;
	Vec2 moveDir;
	Texture tex;
	RectF myRect;//バウンディングボックス
	direction GetDirection();
public:
	Player(); //コンストラクタ
	Player(Vec2 _pos);
	~Player(); //デストラクタ
	void SetMyRect(double _size);
	bool IsMyRectHit(RectF _rect);
	//メンバ関数
	void Update();
	void Draw();
};

