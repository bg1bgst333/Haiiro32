// ヘッダのインクルード
// 独自のヘッダ
#include "Title.h"	// CTitle

// コンストラクタCTitle()
CTitle::CTitle() : CGameObject(){

	// メンバの初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.
	m_hOldBitmap = NULL;	// m_hOldBitmapをNULLで初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.

}

// コンストラクタCTitle(const CScene *pScene)
CTitle::CTitle(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.
	m_hOldBitmap = NULL;	// m_hOldBitmapをNULLで初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.

}

// デストラクタ~CTitle()
CTitle::~CTitle(){

}

// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
BOOL CTitle::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName){

	// メモリデバイスコンテキストの作成.
	m_hMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDCでm_hMemDCを作成.
	if (m_hMemDC == NULL){	// m_hMemDCがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// ビットマップのロード.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.
	m_hBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, iWidth, iHeight, LR_DEFAULTCOLOR);	// LoadImageでリソースIDがnIDのビットマップをロード.
	if (m_hBitmap == NULL){	// m_hBitmapがNULLなら.
		DeleteDC(m_hMemDC);	// m_hMemDCをDeleteDCで削除.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// ビットマップの選択.
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// フォントの作成.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFontでフォントを作成し, m_hFontに格納.
	if (m_hFont == NULL){	// m_hFontがNULLなら.
		SelectObject(m_hMemDC, m_hOldBitmap);	// ビットマップを戻す.
		m_hOldBitmap = NULL;	// m_hOldBitmapにNULLをセット.
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmapを削除.
		m_hBitmap = NULL;	// m_hBitmapにNULLをセット.
		DeleteDC(m_hMemDC);	// m_hMemDCをDeleteDCで削除.
		m_hMemDC = NULL;	// m_hMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// フォントの選択.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CTitle::Destroy(){

	// メンバの終了処理.
	m_x = 0;	// m_xに0を代入.
	m_y = 0;	// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.

	// フォントを戻す.
	if (m_hOldFont != NULL){	// m_hOldFontがNULLでなければ.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObjectでm_hOldFontに戻す.
		m_hOldFont = NULL;	// m_hOldFontにNULLをセット.

	}

	// フォントの削除.
	if (m_hFont != NULL){	// m_hFontがNULLでなければ.
		DeleteObject(m_hFont);	// DeleteObjectでm_hFontを削除.
		m_hFont = NULL;	// m_hFontにNULLをセット.
	}

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
void CTitle::DrawRect(int x, int y){

	// ビットマップの選択.
	SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// ビットマップの描画.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBltでバックバッファに描画.

}

// DrawTextでテキストを描画.
void CTitle::DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor){

	// テキストを描画.
	RECT rc = {x, y, x + iWidth, y + iHeight};	// rcを引数を使って初期化.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	::DrawText(m_pScene->m_hMemDC, lpctszText, _tcslen(lpctszText), &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	// WindowsAPIのDrawTextでタイトル文字列の描画.
	
}