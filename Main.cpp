# include <Siv3D.hpp> // OpenSiv3D v0.6.10
# include "Player.h"
# include "Enemy.h"

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(Palette::Lightgray);

	TextureAsset::Register(U"PLAYER", U"🤩"_emoji);
	TextureAsset::Register(U"ENEMY", U"👹"_emoji);

	Player player({ 32, 32 });
	Enemy enemy(Scene::Center(), 30, {0, -1});

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };



	while (System::Update())
	{
		player.Update();
		if (player.IsMyRectHit(enemy.GetRect()))
			enemy.KillEnemy();
			//Print << U"HIT";
		player.Draw();
		enemy.Update();
		enemy.Draw();
	}
}


