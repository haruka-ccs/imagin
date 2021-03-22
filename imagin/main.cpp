#include <DxLib.h>
#include"Input.h"
#include"SceneManager.h"
#include"SSManager.h"


//#include"Image.h"
//#include"Sound.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//SetWindowIcsonID(334);
	SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(1200, 900, 32);//��ʃT�C�Y�w��
	SetMainWindowText("Imaginary");//�E�C���h�E�ɕ\�������^�C�g�����w��
	SetAlwaysRunFlag(TRUE);//��A�N�e�B�u���������𑱍s
	if (DxLib_Init() == -1) { return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
	SetBackgroundColor(0, 0, 0);
	//SetMouseDispFlag(FALSE);//�}�E�X�J�[�\����\����

	SceneManager scenemanager;

	SSManager ssmanager;

	//Image::Get().Load();
	//Sound::Get().Load();	

	while (ProcessMessage() == 0 && Input::Get().keystate[KEY_INPUT_ESCAPE] == 0)
	{
		ClearDrawScreen();//����ʏ���
		
		Input::Get().Update();
		
		scenemanager.Update();
		scenemanager.Draw();

		ssmanager.Update();
		
		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}