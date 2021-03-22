#include <DxLib.h>
#include"Input.h"
#include"SceneManager.h"
#include"SSManager.h"


//#include"Image.h"
//#include"Sound.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//SetWindowIcsonID(334);
	SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(1200, 900, 32);//画面サイズ指定
	SetMainWindowText("Imaginary");//ウインドウに表示されるタイトルを指定
	SetAlwaysRunFlag(TRUE);//非アクティブ時も処理を続行
	if (DxLib_Init() == -1) { return -1; }//初期化に失敗時にエラーを吐かせて終了
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
	SetBackgroundColor(0, 0, 0);
	//SetMouseDispFlag(FALSE);//マウスカーソル非表示化

	SceneManager scenemanager;

	SSManager ssmanager;

	//Image::Get().Load();
	//Sound::Get().Load();	

	while (ProcessMessage() == 0 && Input::Get().keystate[KEY_INPUT_ESCAPE] == 0)
	{
		ClearDrawScreen();//裏画面消す
		
		Input::Get().Update();
		
		scenemanager.Update();
		scenemanager.Draw();

		ssmanager.Update();
		
		ScreenFlip();//裏画面を表画面にコピー
	}

	DxLib_End();
	return 0;
}