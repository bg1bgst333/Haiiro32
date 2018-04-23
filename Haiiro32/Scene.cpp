// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene

// コンストラクタCScene
CScene::CScene(){

	// メンバの初期化.
	m_pMainWnd = NULL;	// m_pMainWndをNULLで初期化.
	m_pGameTime = NULL;	// m_pGameTimeをNULLで初期化.
	m_pGameSystem = NULL;	// m_pGameSystemをNULLで初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
	m_iScreenWidth = 0;	// m_iScreenWidthを0で初期化.
	m_iScreenHeight = 0;	// m_iScreenHeightを0で初期化.
	m_pKeyboard = NULL;	// m_pKeyboardをNULLで初期化.
	m_pTest = NULL;	// m_pTestをNULLで初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.

}

// コンストラクタCScene(const CWindow *pWnd)
CScene::CScene(const CWindow *pWnd){

	// メンバの初期化.
	m_pMainWnd = pWnd;	// m_pMainWndをpWndで初期化.
	m_pGameTime = NULL;	// m_pGameTimeをNULLで初期化.
	m_pGameSystem = NULL;	// m_pGameSystemをNULLで初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
	m_iScreenWidth = 0;	// m_iScreenWidthを0で初期化.
	m_iScreenHeight = 0;	// m_iScreenHeightを0で初期化.
	m_pKeyboard = NULL;	// m_pKeyboardをNULLで初期化.
	m_pTest = NULL;	// m_pTestをNULLで初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.

}

// コンストラクタCScene(const CWindow *pWnd, CGameTime *pTime)
CScene::CScene(const CWindow *pWnd, CGameTime *pTime){

	// メンバの初期化.
	m_pMainWnd = pWnd;	// m_pMainWndをpWndで初期化.
	m_pGameTime = pTime;	// m_pGameTimeをpTimeで初期化.
	m_pGameSystem = NULL;	// m_pGameSystemをNULLで初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
	m_iScreenWidth = 0;	// m_iScreenWidthを0で初期化.
	m_iScreenHeight = 0;	// m_iScreenHeightを0で初期化.
	m_pKeyboard = NULL;	// m_pKeyboardをNULLで初期化.
	m_pTest = NULL;	// m_pTestをNULLで初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.

}

// コンストラクタCScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CScene::CScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem){

	// メンバの初期化.
	m_pMainWnd = pWnd;	// m_pMainWndをpWndで初期化.
	m_pGameTime = pTime;	// m_pGameTimeをpTimeで初期化.
	m_pGameSystem = pSystem;	// m_pGameSystemをpSystemで初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
	m_iScreenWidth = 0;	// m_iScreenWidthを0で初期化.
	m_iScreenHeight = 0;	// m_iScreenHeightを0で初期化.
	m_pKeyboard = NULL;	// m_pKeyboardをNULLで初期化.
	m_pTest = NULL;	// m_pTestをNULLで初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.

}

// デストラクタ~CScene
CScene::~CScene(){

}

// シーン初期化InitScene.
int CScene::InitScene(){

	// ウィンドウのリサイズ.
	ResizeWindow(640, 480);	// ResizeWindowで(640, 480)にリサイズ.

	// スクリーンの作成.
	CreateScreen(640, 480);	// CreateScreenで(640, 480)のサイズのスクリーンを作成.

	// ゲームオブジェクトの初期化.
	int iRetGO = InitGameObjects();	// InitGameObjectsで初期化.
	if (iRetGO != 0){	// 0でなければ.
		return -1;	// -1を返して強制終了.
	}

	// キーボードの初期化.
	int iRetKeys = InitKeyboard();	// InitKeyboardで初期化.
	if (iRetKeys != 0){	// 0でなければ.
		return -1;	// -1を返して強制終了.
	}

	// 成功なら0.
	return 0;	// 0を返す.

}

// シーン処理中RunScene.
int CScene::RunScene(){

	// この方法は中止.
#if 0
	// 閉じるボタンのチェック.
	int iRetClose = CheckClose();	// CheckCloseで閉じるボタンが押されたかをチェック.
	if (iRetClose == 1){	// iRetCloseが1なら.
		return 2;	// 2を返してアプリを終了.
	}

	// FPS調整判定.
	if (m_pGameTime->IsProc()){	// m_pGameTime->IsProcがTRUE.

		// キー状態の取得.
		CheckKeyboard();	// CheckKeyboardでキーボードのチェック.

		// 入力や状態から次の状態を計算.
		RunProc();	// RunProcで計算処理.

		// ゲームオブジェクトの描画.
		DrawGameObjects();	// DrawGameObjectsでバックバッファへ描画処理.	

		// フロントバッファに転送.
		Present();	// Presentでバックバッファからフロントバッファへ転送.

	}

	// フレームカウントの計測.
	m_pGameTime->CountFrame();	// m_pGameTime->CountFrameでフレームを1つ増やす.

	// 1秒経過したら, リセット.
	if (m_pGameTime->IsNextSecond()){	// 次の秒なら.
		m_pGameTime->ResetFrame();	// m_pGameTime->ResetFrameでフレームカウントをリセット.
	}
#else	// こちらの方法に変更.
	// 閉じるボタンのチェック.
	int iRetClose = CheckClose();	// CheckCloseで閉じるボタンが押されたかをチェック.
	if (iRetClose == 1){	// iRetCloseが1なら.
		return 2;	// 2を返してアプリを終了.
	}

	// FPSのさらなる調整(FPSはぴったり60にならないので.)
	if (m_pGameTime->m_dwFrame % 3 == 1){	// 3の余りが1の時.
		Sleep(1);	// 1ミリ秒休止.
	}

	// 1秒経過したら, リセット.
	if (m_pGameTime->IsNextSecond()){	// 次の秒なら.
		m_pGameTime->ResetFrame();	// m_pGameTime->ResetFrameでフレームカウントをリセット.
	}

	// キー状態の取得.
	CheckKeyboard();	// CheckKeyboardでキーボードのチェック.

	// 入力や状態から次の状態を計算.
	int iRet = RunProc();	// RunProcで計算処理し, 戻り値をiRetに格納.

	// ゲームオブジェクトの描画.
	DrawGameObjects();	// DrawGameObjectsでバックバッファへ描画処理.	

	// フロントバッファに転送.
	Present();	// Presentでバックバッファからフロントバッファへ転送.

	// フレームカウントの計測.
	m_pGameTime->CountFrame();	// m_pGameTime->CountFrameでフレームを1つ増やす.

	// RunProcの値によって, シーンを変えるか判断.
	if (iRet == 1){	// 1なら次のシーン.
		return 1;	// 1を返す.
	}
#endif

	// 継続なら0.
	return 0;	// 0を返す.

}

// シーン終了処理ExitScene.
int CScene::ExitScene(){

	// キーボードの終了処理.
	ExitKeyboard();	// ExitKeyboardでキーボードの終了処理.
	
	// ゲームオブジェクトの終了処理.
	ExitGameObjects();	// ExitGameObjectsでゲームオブジェクトの終了処理.

	// スクリーンの破棄.
	DestroyScreen();	// DestroyScreenでスクリーンを破棄.

	// 継続なら0.
	return 0;	// 0を返す.

}

// ウィンドウのリサイズResizeWindow.
void CScene::ResizeWindow(int iWidth, int iHeight){

	// ウィンドウサイズをクライアント領域のサイズが(iWidth, iHeight)になるようなサイズにする.
	RECT rc = {0, 0, iWidth, iHeight};	// RECT型rcを{0, 0, iWidth, iHeight}で初期化.
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, TRUE);	// AdjustWindowRectで適切なウィンドウサイズを取得.
	RECT rcWnd = {0};	// ウィンドウ矩形領域rcWndを{0}で初期化.
	GetWindowRect(m_pMainWnd->m_hWnd, &rcWnd);	// GetWindowRectでrcWndを取得.
	MoveWindow(m_pMainWnd->m_hWnd, rcWnd.left, rcWnd.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);	// MoveWindowでリサイズ.

}

// スクリーンの作成CreateScreen.
void CScene::CreateScreen(int iWidth, int iHeight){

	// スクリーンサイズのセット.
	m_iScreenWidth = iWidth;	// m_iScreenWidthにiWidthをセット.
	m_iScreenHeight = iHeight;	// m_iScreenHeightにiHeightをセット.

	// デバイスコンテキストの取得.
	m_hDC = GetDC(m_pMainWnd->m_hWnd);	// GetDCでm_hDCを取得.

	// メモリデバイスコンテキストの生成.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDCでm_hMemDCを生成.

	// メモリビットマップの生成.
	m_hMemBitmap = CreateCompatibleBitmap(m_hDC, m_iScreenWidth, m_iScreenHeight);	// CreateCompatibleBitmapでm_hMemBitmapを生成.

	// メモリデバイスコンテキストの選択.
	m_hOldMemBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hMemBitmap);	// SelectObjectでm_hMemBitmapを選択.

}

// バックバッファからフロントバッファへ転送することで画面を描画するPresent.
void CScene::Present(){

	// 前面に転送.
	if (m_hDC != NULL){	// m_hDCがNULLでない時.
		BitBlt(m_hDC, 0, 0, m_iScreenWidth, m_iScreenHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBltでm_hMemDCからm_hDCに転送.
	}

}

// スクリーンの破棄DestroyScreen.
void CScene::DestroyScreen(){

	// メモリデバイスコンテキストを戻す.
	if (m_hOldMemBitmap != NULL){	// m_hOldMemBitmapがNULLでない時.
		SelectObject(m_hMemDC, m_hOldMemBitmap);	// SelectObjectでm_hOldMemBitmapを選択.
		m_hOldMemBitmap = NULL;	// m_hOldMemBitmapにNULLをセット.
	}

	// メモリビットマップの削除.
	if (m_hMemBitmap != NULL){	// m_hMemBitmapがNULLでない時.
		DeleteObject(m_hMemBitmap);	// DeleteObjectでm_hMemBitmapを削除.
		m_hMemBitmap = NULL;	// m_hMemBitmapにNULLをセット.
	}

	// メモリデバイスコンテキストの削除.
	if (m_hMemDC != NULL){	// m_hMemDCがNULLでない時.
		DeleteDC(m_hMemDC);	// DeleteDCでm_hMemDCを削除.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
	}

	// デバイスコンテキストの解放.
	if (m_hDC != NULL){	// m_hDCがNULLでない時.
		ReleaseDC(m_pMainWnd->m_hWnd, m_hDC);	// ReleaseDCでm_hDCを解放.
		m_hDC = NULL;	// m_hDCにNULLをセット.
	}

}

// ゲームオブジェクトの初期化.
int CScene::InitGameObjects(){

	// シェアードイメージバッファの生成.
	m_pSharedImageBuffer = new CSharedImageBuffer(m_pGameSystem->m_pSharedResources, m_hDC);	// 生成.

	// テストオブジェクトの作成.
#if 0
	m_pTest = new CGameObject(this);	// CGameObjectオブジェクトを生成(thisを渡す.)し, ポインタをm_pTestに格納.
	if (m_pGameSystem->GetMode() == 1){	// m_pGameSystem->GetModeが1の時.
		m_pTest->Create(0, 0, m_iScreenWidth, m_iScreenHeight, RGB(0xff, 0x0, 0x0), RGB(0x7f, 0x0, 0x0));	// m_pTest->Createでテストオブジェクトを作成.
	}
	else if (m_pGameSystem->GetMode() == 2){	// m_pGameSystem->GetModeが2の時.
		m_pTest->Create(0, 0, m_iScreenWidth, m_iScreenHeight, RGB(0x0, 0xff, 0x0), RGB(0x0, 0x7f, 0x0));	// m_pTest->Createでテストオブジェクトを作成.
	}
	else if (m_pGameSystem->GetMode() == 3){	// m_pGameSystem->GetModeが3の時.
		m_pTest->Create(0, 0, m_iScreenWidth, m_iScreenHeight, RGB(0x0, 0x0, 0xff), RGB(0x0, 0x0, 0x7f));	// m_pTest->Createでテストオブジェクトを作成.
	}
#endif

	// 成功なら0を返す.
	return 0;	// 0を返す.

}

// キーボードの初期化.
int CScene::InitKeyboard(){

	// キーボードオブジェクトの作成.
	m_pKeyboard = new CKeyboard();	// CKeyboardオブジェクトを作成し, ポインタをm_pKeyboardに格納.

	// 成功なら0を返す.
	return 0;	// 0を返す.

}

// 閉じるボタンのチェック.
int CScene::CheckClose(){

	// 閉じるボタンが押された時.
	if (m_pMainWnd->m_bClose){	// m_pMainWnd->m_bCloseがTRUEなら.
		return 1;	// 1を返す.
	}

	// 閉じられていない場合は0を返す.
	return 0;	// 0を返す.

}

// キーボードのチェック.
int CScene::CheckKeyboard(){

	// キー状態の取得.
	m_pKeyboard->Check();	// m_pKeyboard->Checkで状態確認.

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キー入力や時間などから処理を計算.
int CScene::RunProc(){

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの描画.
int CScene::DrawGameObjects(){

	// テストオブジェクトの描画.
#if 0
	if (m_pTest != NULL){	// m_pTestがNULLでない時.
		m_pTest->DrawRect(0, 0);	// m_pTest->DrawRectで(0, 0)の位置に描画.
	}
#endif

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの終了処理.
int CScene::ExitGameObjects(){

	// テストオブジェクトの破棄.
#if 0
	if (m_pTest != NULL){	// m_pTestがNULLでない時.
		m_pTest->Destroy();	// m_pTest->Destroyで破棄.
		delete m_pTest;	// deleteでm_pTestを解放.
		m_pTest = NULL;	// m_pTestにNULlをセット.
	}
#endif

	// シェアードイメージバッファの解放.
	ReleaseDC(m_pMainWnd->m_hWnd, m_hDC);	// ReleaseDCで解放.
	delete m_pSharedImageBuffer;	// m_pSharedImageBufferを削除.

	// 常に成功なので0.
	return 0;	// 0を返す.

}

// キーボードの終了処理.
int CScene::ExitKeyboard(){

	// キーボードオブジェクトの破棄.
	if (m_pKeyboard != NULL){	// m_pKeyboardがNULLでない時.
		delete m_pKeyboard;	// deleteでm_pKeyboardを解放.
		m_pKeyboard = NULL;	// m_pKeyboardにNULLをセット.
	}

	// 常に成功なので0.
	return 0;	// 0を返す.

}