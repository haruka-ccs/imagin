#include"DxLib.h"
#include"Player.h"
#include"Input.h"
#include"GameScene.h"

Player::Player() {
	pos = Vec2d(GameSceneDefine::MARGIN + GameSceneDefine::PLAYAREA_WIDTH / 2, 700);
	r = 3;
}

void Player::Draw() {
	DrawCircleAA(pos.GetX(), pos.GetY(), r, 64, GetColor(200, 200, 200));
	if (isInvincible == false) {
		DrawCircleAA(pos.GetX(), pos.GetY(), 12 + 3.0 * sin(count * DX_PI / 60), 32, GetColor(255, 255, 255), 0);
	}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", isInvincible);
}

void Player::Update() {
	int x = 0, y = 0;
	double v = V;
	if (Input::Get().buttonstate[Button::UP] > 0 && pos.GetY() > GameSceneDefine::MARGIN+10) {
		--y;
	}
	if (Input::Get().buttonstate[Button::DOWN] > 0 && pos.GetY() < GameSceneDefine::MARGIN + GameSceneDefine::PLAYAREA_HEIGHT-10) {
		++y;
	}
	if (Input::Get().buttonstate[Button::LEFT] > 0&& pos.GetX() > GameSceneDefine::MARGIN+10) {
		--x;
	}
	if (Input::Get().buttonstate[Button::RIGHT] > 0 && pos.GetX() < GameSceneDefine::MARGIN + GameSceneDefine::PLAYAREA_WIDTH-10) {
		++x;
	}
	if (Input::Get().buttonstate[Button::R] > 0) {
		v *= 0.5;
	}
	if ((x != 0) && (y != 0)) {
		v *= 1 / sqrt(2);
	}
	SetPos(this->pos + Vec2d(x * v, y * v));

	if (isInvincible == true) {
		++invinciblecount;
	}
	if (invinciblecount > 60) {
		invinciblecount = 0;
		isInvincible = false;
	}

	++count;
}