#pragma once
class SSManager
{
private:
	char filename[64]="ss/ss00.png";

	int num = 0;

	int aaa;
	int count;
public:
	SSManager();
	~SSManager();

	void Update();

	void Init();
};

