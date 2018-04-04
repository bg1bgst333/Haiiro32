// ヘッダのインクルード
// 独自のヘッダ
#include "Background.h"	// CBackground

// コンストラクタCBackground()
CBackground::CBackground() : CGameObject(){

	// メンバの初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.
	m_hOldBitmap = NULL;	// m_hOldBitmapをNULLで初期化.

}

// コンストラクタCBackground(const CScene *pScene)
CBackground::CBackground(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.
	m_hOldBitmap = NULL;	// m_hOldBitmapをNULLで初期化.

}

// デストラクタ~CBackground()
CBackground::~CBackground(){

}

// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
BOOL CBackground::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID){

	// メモリデバイスコンテキストの作成.
	m_hMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDCでm_hMemDCを作成.
	if (m_hMemDC == NULL){	// m_hMemDCがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// ビットマップのロード.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.
	m_hBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, iWidth, iHeight, LR_DEFAULTCOLOR);	// LoadImageでリソースIDがnIDのビットマップをロード.
	if (m_hBitmap == NULL){	// m_hBitmaoがNULLなら.
		DeleteDC(m_hMemDC);	// m_hMemDCをDeleteDCで削除.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// ブラシの選択.
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CBackground::Destroy(){

	// メンバの終了処理.
	m_x = 0;	// m_xに0を代入.
	m_y = 0;	// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.

	// ビットマップを戻す.
	if (m_hOldBitmap != NULL){	// m_hOldBitmapがNULLでなければ.
		SelectObject(m_hMemDC, m_hOldBitmap);	// SelectObjectでm_hOldBitmapに戻す.
		m_hOldBitmap = NULL;	// m_hOldBitmapにNULLをセット.
	}

	// ロードしたビットマップの破棄.
	if (m_hBitmap != NULL){	// m_hBitmapがNULLでなければ.
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmaoを削除.
		m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
	}

	// メモリデバイスコンテキストの破棄.
	if (m_hMemDC != NULL){	// m_hMemDCがNULLでなければ.
		DeleteDC(m_hMemDC);	// DeleteDCでm_hMemDCを破棄.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
	}

}

// ゲームオブジェクトの描画DrawRect.(指定されたリソースIDの画像をロード.)
void CBackground::DrawRect(int x, int y){

	// ビットマップの選択.
	SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// ビットマップの描画.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBltでバックバッファに描画.

}