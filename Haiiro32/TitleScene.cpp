// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"	// リソース
#include "TitleScene.h"	// CTitleScene

// コンストラクタCTitleScene
CTitleScene::CTitleScene() : CScene(){

	// メンバの初期化.
	m_pBackground = NULL;	// m_pBackgroundをNULLで初期化.
	m_pTitle = NULL;	// m_pTitleをNULLで初期化.
	m_pSelectBox = NULL;	// m_pSelectBoxをNULLで初期化.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.

}

// コンストラクタTitleCScene(const CWindow *pWnd)
CTitleScene::CTitleScene(const CWindow *pWnd) : CScene(pWnd){

	// メンバの初期化.
	m_pBackground = NULL;	// m_pBackgroundをNULLで初期化.
	m_pTitle = NULL;	// m_pTitleをNULLで初期化.
	m_pSelectBox = NULL;	// m_pSelectBoxをNULLで初期化.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.

}

// コンストラクタCTitleScene(const CWindow *pWnd, CGameTime *pTime)
CTitleScene::CTitleScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// メンバの初期化.
	m_pBackground = NULL;	// m_pBackgroundをNULLで初期化.
	m_pTitle = NULL;	// m_pTitleをNULLで初期化.
	m_pSelectBox = NULL;	// m_pSelectBoxをNULLで初期化.
	m_pGameTimeBox = NULL;	// m_pGameTimeBoxをNULLで初期化.

}

// デストラクタ~CTitleScene
CTitleScene::~CTitleScene(){

}

// ゲームオブジェクトの初期化.
int CTitleScene::InitGameObjects(){

	// 背景の作成.
	m_pBackground = new CBackground(this);	// CBackgroundオブジェクトを生成(thisを渡す.)し, ポインタをm_pBackgroundに格納.
	m_pBackground->Create(0, 0, m_iScreenWidth, m_iScreenHeight, m_pMainWnd->m_hWnd, IDB_BACKGROUND1);	// m_pBackground->Createで背景オブジェクトを作成.

	// タイトルの作成.
	m_pTitle = new CTitle(this);	// CTitleオブジェクトを生成(thisを渡す.)し, ポインタをm_pTitleに格納.
	m_pTitle->Create(160, 60, 320, 240, m_pMainWnd->m_hWnd, IDB_TITLE1, 48, _T("ＭＳ 明朝"));	// m_pTitle->Createでタイトルオブジェクトを作成.

	// セレクトボックスの作成.
	m_pSelectBox = new CSelectBox(this);	// CSelectBoxオブジェクトを生成(thisを渡す.), ポインタをm_pSelectBoxに格納.
	m_pSelectBox->Create(160, 300, 320, 120, m_pMainWnd->m_hWnd, IDB_SELECTBOX1, 24, _T("ＭＳ ゴシック"), 20, 32, 32, IDB_CURSOR1);	// m_pSelectBox->Createでセレクトボックスオブジェクトを作成.
	m_pSelectBox->AddSelectItem(_T("NEW GAME"));	// "NEW GAME"を追加.
	m_pSelectBox->AddSelectItem(_T("CONTINUE"));	// "CONTINUE"を追加.
	m_pSelectBox->AddSelectItem(_T("SETTING"));	// "SETTING"を追加.

	// ゲームタイムボックスの描画.
	m_pGameTimeBox = new CGameTimeBox(this);	// CGameTimeBoxオブジェクトを生成(thisを渡す.), ポインタをm_pGameTimeBoxに格納.
	m_pGameTimeBox->Create(0, 0, 160, 30, 36, _T("ＭＳ ゴシック"));	// m_pGameTimeBox->Createで作成.

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キーボードの初期化.
int CTitleScene::InitKeyboard(){

	// キーボードオブジェクトの作成.
	m_pKeyboard = new CKeyboard();	// CKeyboardオブジェクトを作成し, ポインタをm_pKeyboardに格納.

	// 監視キーの追加.
	m_pKeyboard->AddKey(VK_ESCAPE);	// ESCキーを追加.
	m_pKeyboard->AddKey(VK_DOWN);	// 下キーを追加.
	m_pKeyboard->AddKey(VK_UP);	// 上キーを追加.
	m_pKeyboard->AddKey(VK_RETURN);	// リターンキーを追加.

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キーボードのチェック.
int CTitleScene::CheckKeyboard(){

	// セレクトボックスの入力状態クリア.
	m_pSelectBox->ClearInput();	// 入力クリア.

	// キー状態の取得.
	m_pKeyboard->Check();	// m_pKeyboard->Checkで状態確認.

	// 0番目のキー(ここではESCキー.)が押された時.
	if (m_pKeyboard->IsPress(0)){	// m_pKeyboard->IsPress(0)がTRUEなら.
		SendMessage(m_pMainWnd->m_hWnd, WM_CLOSE, 0, 0);	// SendMessageでWM_CLOSEを送信.
	}

	// 1番目のキー(ここでは下キー.)が押された時.
	if (m_pKeyboard->IsPress(1)){	// m_Keyboard->IsPress(1)がTRUEなら.
		m_pSelectBox->Down();	// カーソルを下に.
	}

	// 2番目のキー(ここでは上キー.)が押された時.
	if (m_pKeyboard->IsPress(2)){	// m_pKeyboard->IsPress(2)がTRUEなら.
		m_pSelectBox->Up();	// カーソルを上に.
	}

	// 3番目のキー(ここではリターンキー.)が押された時.
	if (m_pKeyboard->IsPress(3)){	// m_pKeyboard->IsPress(3)がTRUEなら.
		m_pSelectBox->Return();	// カーソル決定.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キー入力や時間などから処理を計算.
int CTitleScene::RunProc(){

	// セレクトボックス処理.
	if (m_pSelectBox != NULL){	// m_pSelectBoxがNULLでない時.
		m_pSelectBox->Proc();	// m_pSelectBox->Procで処理.
	}

	// ゲームタイムボックス処理.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBoxがNULLでない時.
		m_pGameTimeBox->Proc();	// m_pGameTimeBox->Procで処理.
	}
	
	// 常に成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの描画.
int CTitleScene::DrawGameObjects(){

	// 背景の描画.
	if (m_pBackground != NULL){	// m_pBackgroundがNULLでない時.
		m_pBackground->DrawRect(0, 0);	// m_pBackground->DrawRectで(0, 0)の位置に描画.
	}

	// タイトルの描画.
	if (m_pTitle != NULL){	// m_pTitleがNULLでない時.
		m_pTitle->DrawRect(160, 60);	// m_pTitle->DrawRectで(160, 60)の位置に描画.
		m_pTitle->DrawText(160, 60, 320, 240, _T("Haiiro"), RGB(0xff, 0xff, 0xff));	// m_pTitle->DrawTextでタイトルテキストの描画.
	}

	// セレクトボックスの描画.
	if (m_pSelectBox != NULL){	// m_pSelectBoxがNULLでない時.
		m_pSelectBox->DrawRect(160, 300);	// m_pSelectBox->DrawRectで(160, 300)の位置に描画.
		m_pSelectBox->DrawSelectItemList(115, 0, RGB(0xff, 0xff, 0xff));	// m_pSelectBox->DrawSelectItemListでリスト描画.
		m_pSelectBox->DrawCursor(80, 0);	// m_pSelectBox->DrawCursorで(80, 0)の位置に描画.
	}

	// ゲームタイムボックスの描画.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBoxがNULLでない時.
		m_pGameTimeBox->DrawTime(0, 0, 160, 30, RGB(0xff, 0xff, 0xff));	// m_pGameTimeBox->DrawTimeで時刻を描画.
		m_pGameTimeBox->DrawFPS(0, 30, 160, 30, RGB(0xff, 0xff, 0xff));	// m_pGameTimeBox->DrawFPSでFPSを描画.
		m_pGameTimeBox->DrawRunFPS(0, 60, 160, 30, RGB(0xff, 0xff, 0xff));	// m_pGameTimeBox->DrawRunFPSで実行PFSを描画.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの終了処理.
int CTitleScene::ExitGameObjects(){

	// ゲームタイムボックスの破棄.
	if (m_pGameTimeBox != NULL){	// m_pGameTimeBoxがNULLでない時.
		m_pGameTimeBox->Destroy();	// m_pGameTimeBox->Destroyで廃棄.
		delete m_pGameTimeBox;	// deleteでm_pGameTimeBoxを解放.
		m_pGameTimeBox = NULL;	// m_pGameTimeBoxにNULLをセット.
	}

	// セレクトボックスの破棄.
	if (m_pSelectBox != NULL){	// m_pSelectBoxがNULLでない時.
		m_pSelectBox->Destroy();	// m_pSelectBox->Destroyで破棄.
		delete m_pSelectBox;	// deleteでm_pSelectBoxを解放.
		m_pSelectBox = NULL;	// m_pSelectBoxにNULLをセット.
	}

	// タイトルの破棄.
	if (m_pTitle != NULL){	// m_pTitleがNULLでない時.
		m_pTitle->Destroy();	// m_pTitle->Destroyで破棄.
		delete m_pTitle;	// deleteでm_pTitleを解放.
		m_pTitle = NULL;	// m_pTitleにNULLをセット.
	}

	// 背景の破棄.
	if (m_pBackground != NULL){	// m_pBackgroundがNULLでない時.
		m_pBackground->Destroy();	// m_pBackground->Destroyで破棄.
		delete m_pBackground;	// deleteでm_pBackgroundを解放.
		m_pBackground = NULL;	// m_pBackgroundにNULlをセット.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}