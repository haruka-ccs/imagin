#include"BulletManager.h"
#include"BulletBase.h"
#include<algorithm>

void BulletManager::Add(std::shared_ptr<BulletBase> b) {
	bullets.push_back(b);
}

void BulletManager::Update() {
	for (auto &iter : bullets) {
		iter->Update();
	}

	Erase();
}

void BulletManager::Draw() {
	for (auto iter : bullets) {
		iter->Draw();
	}
}

int BulletManager::GetSize() {
	return bullets.size();
}

void BulletManager::Erase() {
	auto rmviter = std::remove_if(bullets.begin(), bullets.end(), [](std::shared_ptr<BulletBase> b) {return (b->isinArea() == false); });
	bullets.erase(rmviter, bullets.end());
}

bool BulletManager::Collision(Object& obj)
{
	for (auto iter : bullets) {
		if (Vec2d(obj.GetPos() - iter->GetPos()).Mag()<obj.GetRadius()+iter->GetRadius()) {
			return true;
		}
	}
	return false;
}