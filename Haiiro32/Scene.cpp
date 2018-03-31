// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene

// コンストラクタCScene
CScene::CScene(){

	// メンバの初期化.
	m_pMainWnd = NULL;	// m_pMainWndをNULLで初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
	m_iScreenWidth = 0;	// m_iScreenWidthを0で初期化.
	m_iScreenHeight = 0;	// m_iScreenHeightを0で初期化.

}

// コンストラクタCScene(const CWindow *pWnd)
CScene::CScene(const CWindow *pWnd){

	// メンバの初期化.
	m_pMainWnd = pWnd;	// m_pMainWndをpWndで初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
	m_iScreenWidth = 0;	// m_iScreenWidthを0で初期化.
	m_iScreenHeight = 0;	// m_iScreenHeightを0で初期化.

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

	// 描画.
	Present();	// Presentでバックバッファからフロントバッファへ転送.

	// 継続なら0.
	return 0;	// 0を返す.

}

// シーン終了処理ExitScene.
int CScene::ExitScene(){

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