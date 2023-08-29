#pragma once
const int PLAYER_SIZE = 64;

class Player
{
//何も書かないとprivate
	//メンバ変数
	Vec2 pos;
	double speed;
	Vec2 moveDir;
	Texture tex;
	RectF myRect;//バウンディングボックス
public:
	Player(); //コンストラクタ
	Player(Vec2 _pos);
	~Player(); //デストラクタ
	void SetMyRect(double _size);
	//メンバ関数
	void Update();
	void Draw();
};

