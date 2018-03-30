// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene

// コンストラクタCScene
CScene::CScene(){

	// メンバの初期化.
	m_pMainWnd = NULL;	// m_pMainWndをNULLで初期化.

}

// コンストラクタCScene(const CWindow *pWnd)
CScene::CScene(const CWindow *pWnd){

	// メンバの初期化.
	m_pMainWnd = pWnd;	// m_pMainWndをpWndで初期化.

}

// デストラクタ~CScene
CScene::~CScene(){

}

// シーン初期化InitScene.
int CScene::InitScene(){

	// 成功なら0.
	return 0;	// 0を返す.

}

// シーン処理中RunScene.
int CScene::RunScene(){

	// SPACEキーを押したら抜ける.
	if (GetAsyncKeyState(VK_SPACE)){	// GetAsyncKeyStateでSPACEが押されていたら.
		MessageBox(NULL, _T("SPACE"), _T("Haiiro"), MB_OK);	// MessageBoxで"SPACE"と表示.(長く押すと, 2回以上分になってしまう.)
		return 1;	// 1を返す.
	}

	// ESCAPEキーを押したら抜ける.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyStateでESCAPEが押されていたら.
		MessageBox(NULL, _T("ESCAPE"), _T("Haiiro"), MB_OK);	// MessageBoxで"ESCAPE"と表示.(長く押すと, 2回以上分になってしまう.)
		return 2;	// 2を返す.
	}

	// 継続なら0.
	return 0;	// 0を返す.

}

// シーン終了処理ExitScene.
int CScene::ExitScene(){

	// 継続なら0.
	return 0;	// 0を返す.

}