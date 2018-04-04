// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"	// リソース
#include "TitleScene.h"	// CTitleScene

// コンストラクタCTitleScene
CTitleScene::CTitleScene() : CScene(){

	// メンバの初期化.
	m_pBackground = NULL;	// m_pBackgroundをNULLで初期化.

}

// コンストラクタTitleCScene(const CWindow *pWnd)
CTitleScene::CTitleScene(const CWindow *pWnd) : CScene(pWnd){

	// メンバの初期化.
	m_pBackground = NULL;	// m_pBackgroundをNULLで初期化.

}

// デストラクタ~CTitleScene
CTitleScene::~CTitleScene(){

}

// ゲームオブジェクトの初期化.
int CTitleScene::InitGameObjects(){

	// 背景の作成.
	m_pBackground = new CBackground(this);	// CBackgroundオブジェクトを生成(thisを渡す.)し, ポインタをm_pBackgroundに格納.
	m_pBackground->Create(0, 0, m_iScreenWidth, m_iScreenHeight, m_pMainWnd->m_hWnd, IDB_BACKGROUND1);	// m_pBackground->Createで背景オブジェクトを作成.

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キーボードの初期化.
int CTitleScene::InitKeyboard(){

	// キーボードオブジェクトの作成.
	m_pKeyboard = new CKeyboard();	// CKeyboardオブジェクトを作成し, ポインタをm_pKeyboardに格納.

	// 監視キーの追加.
	m_pKeyboard->AddKey(VK_ESCAPE);	// ESCキーを追加.

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キーボードのチェック.
int CTitleScene::CheckKeyboard(){

	// キー状態の取得.
	m_pKeyboard->Check();	// m_pKeyboard->Checkで状態確認.

	// 0番目のキー(ここではESCキー.)が押された時.
	if (m_pKeyboard->IsPress(0)){	// m_pKeyboard->IsPress(0)がTRUEなら.
		SendMessage(m_pMainWnd->m_hWnd, WM_CLOSE, 0, 0);	// SendMessageでWM_CLOSEを送信.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キー入力や時間などから処理を計算.
int CTitleScene::RunProc(){

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの描画.
int CTitleScene::DrawGameObjects(){

	// 背景の描画.
	if (m_pBackground != NULL){	// m_pBackgroundがNULLでない時.
		m_pBackground->DrawRect(0, 0);	// m_pBackground->DrawRectで(0, 0)の位置に描画.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの終了処理.
int CTitleScene::ExitGameObjects(){

	// 背景の破棄.
	if (m_pBackground != NULL){	// m_pBackgroundがNULLでない時.
		m_pBackground->Destroy();	// m_pBackground->Destroyで破棄.
		delete m_pBackground;	// deleteでm_pBackgroundを解放.
		m_pBackground = NULL;	// m_pBackgroundにNULlをセット.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}