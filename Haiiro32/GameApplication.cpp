// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// メンバの初期化.
	m_iSceneNo = 0;	// m_iSceneNoを0で初期化.
	m_iSceneStatus = 0;	// m_iSceneStatusを0で初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hMemBitmap = NULL;	// m_hMemBitmapをNULLで初期化.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmapをNULLで初期化.
#if 0
	m_hBackPen = NULL;	// m_hBackPenをNULLで初期化.
	m_hOldBackPen = NULL;	// m_hOldBackPenをNULLで初期化.
	m_hBackBrush = NULL;	// m_hBackBrushをNULLで初期化.
	m_hOldBackBrush = NULL;	// m_hOldBackBrushをNULLで初期化.
	m_hCursorPen = NULL;	// m_hCursorPenをNULLで初期化.
	m_hOldCursorPen = NULL;	// m_hOldCursorPenをNULLで初期化.
	m_hCursorBrush = NULL;	// m_hCursorBrushをNULLで初期化.
	m_hOldCursorBrush = NULL;	// m_hOldCursorBrushをNULLで初期化.
	m_iCursorX = 0;	// m_iCursorXを0で初期化.
	m_iCursorY = 0;	// m_iCursorYを0で初期化.
#endif

}

// ゲームメイン処理関数Main.
int CGameApplication::Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// 変数の初期化.
	int iRet = 0;	// 戻り値iRetを0で初期化.

	// シーンごとに振り分け..
	if (m_iSceneStatus == 0){	// m_iSceneStatusが0ならシーン初期化.
		iRet = InitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// InitSceneで初期化処理.
	}
	else if (m_iSceneStatus == 1){	// m_iSceneStatusが1ならシーン処理中.
		iRet = RunScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// RunSceneで処理中.
	}
	else if (m_iSceneStatus == 2){	// m_iSceneStatusが2ならシーン終了処理.
		iRet = ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitSceneで終了処理.
	}
	else{	// それ以外は何もせず終了.
		// 0を返す.
		return 0;	// 0を返す.
	}

	// 次の状態を決める.
	if (iRet == 1){	// iRetが1なら.(次のシーンへの切り替え.)
		if (m_iSceneStatus <= 1){	// InitまたはRunの場合.
			m_iSceneStatus++;	// m_iSceneStatusを1増やす.
		}
		else{	// Exitの時.
			m_iSceneNo++;	// m_iSceneNoを1増やす.
			m_iSceneStatus = 0;	// m_iSceneStatusを0にする.
		}
	}
	else if (iRet == 2){	// iRetが2なら.(アプリの終了.)
		if (m_iSceneStatus <= 1){	// InitまたはRunの場合.
			ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitSceneで終了処理.
		}
		m_iSceneStatus = -1;	// m_iSceneStatusが-1なら次以降処理しない.
		SendMessage(hWnd, WM_DESTROY, 0, 0);	// SendMessageでWM_DESTROYを送信.
	}

	// 0を返す.
	return 0;	// 0を返す.

}

// シーンの初期化InitScene.
int CGameApplication::InitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// ウィンドウのリサイズ.
	ResizeWindow(hWnd, 640, 480);	// ResizeWindowでクライアント領域が(640, 480)となるウィンドウにリサイズ. 

	// スクリーンの作成.
	CreateScreen(hWnd);	// CreateScreenでスクリーン作成.

	// 初期化終了なので1.
	return 1;	// 1を返す.

}

// シーンの処理中RunScene.
int CGameApplication::RunScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// フロントバッファへ転送.
	Present(iClientAreaWidth, iClientAreaHeight);	// Presentで表示.

	// ESCキーを押したら抜ける.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyStateでESCが押されていたら.
		MessageBox(NULL, _T("ESC"), _T("Haiiro"), MB_OK);	// MessageBoxで"ESC"と表示.(長く押すと, 2回以上分になってしまう.)
		return 1;	// 1を返す.
	}

	// 未だ処理中なので0.
	return 0;	// 0を返す.

}

// シーンの終了処理ExitScene.
int CGameApplication::ExitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// スクリーンの破棄.
	DestroyScreen(hWnd);	// DestroyScreenでスクリーン破棄.

	// m_iSceneNoが3なら終了.
	if (m_iSceneNo == 3){	// m_iSceneNoが3の時.
		// アプリ終了なので2を返す.
		return 2;	// 2を返す.
	}

	// 終了処理なので1.
	return 1;	// 1を返す.

}

// ウィンドウのリサイズResizeWindow.
void CGameApplication::ResizeWindow(HWND hWnd, int iWidth, int iHeight){

	// ウィンドウサイズをクライアント領域のサイズがiWidthxiHeightになるようなサイズする.
	RECT rc = {0, 0, iWidth, iHeight};	// RECT型rcを{0, 0, iWidth, iHeight}で初期化.
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, TRUE);	// AdjustWindowRectで適切なウィンドウサイズを取得.
	RECT rcWnd = {0};	// ウィンドウ矩形領域rcWndを{0}で初期化.
	GetWindowRect(hWnd, &rcWnd);	// GetWindowRectでrcWndを取得.
	MoveWindow(hWnd, rcWnd.left, rcWnd.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);	// MoveWindowでリサイズ.

}

// スクリーンの作成CreateScreen.
void CGameApplication::CreateScreen(HWND hWnd){

	// デバイスコンテキストの取得.
	m_hDC = GetDC(hWnd);	// GetDCでm_hDCを取得.

	// メモリデバイスコンテキストの生成.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDCでm_hMemDCを生成.

	// メモリビットマップの生成.
	m_hMemBitmap = CreateCompatibleBitmap(m_hDC, 640, 480);	// CreateCompatibleBitmapでm_hMemBitmapを生成.

	// メモリデバイスコンテキストの選択.
	m_hOldMemBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hMemBitmap);	// SelectObjectでm_hMemBitmapを選択.

}

// フロントバッファに転送Present.
void CGameApplication::Present(int iClientAreaWidth, int iClientAreaHeight){

	// 前面に転送.
	if (m_hDC != NULL){	// m_hDCがNULLでない時.
		BitBlt(m_hDC, 0, 0, iClientAreaWidth, iClientAreaHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBltでm_hMemDCからm_hDCに転送.
	}

}

// スクリーンの破棄DestroyScreen.
void CGameApplication::DestroyScreen(HWND hWnd){

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
		ReleaseDC(hWnd, m_hDC);	// ReleaseDCでm_hDCを解放.
		m_hDC = NULL;	// m_hDCにNULLをセット.
	}

}