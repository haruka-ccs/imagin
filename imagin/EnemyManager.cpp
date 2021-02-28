#include"EnemyManager.h"

void EnemyManager::Update() {
	for (auto& iter : enemies) {
		iter->Update();
	}
}

void EnemyManager::Draw() {
	for (auto iter : enemies) {
		iter->Draw();
	}
}

void EnemyManager::Add(std::shared_ptr<EnemyBase> e) {
	enemies.push_back(e);
}