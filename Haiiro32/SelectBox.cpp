// ヘッダのインクルード
// 独自のヘッダ
#include "SelectBox.h"	// CSelectBox

// コンストラクタCSelectBox()
CSelectBox::CSelectBox() : CGameObject(){

	// メンバの初期化.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCをNULLで初期化.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapをNULLで初期化.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapをNULLで初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_iLineHeight = 0;	// m_iLineHeightを0で初期化.
	m_iMargin = 0;	// m_iMarginを0で初期化.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clearでクリア.

}

// コンストラクタCSelectBox(const CScene *pScene)
CSelectBox::CSelectBox(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCをNULLで初期化.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapをNULLで初期化.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapをNULLで初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_iLineHeight = 0;	// m_iLineHeightを0で初期化.
	m_iMargin = 0;	// m_iMarginを0で初期化.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clearでクリア.

}

// デストラクタ~CSelectBox()
CSelectBox::~CSelectBox(){

}

// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
BOOL CSelectBox::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName, int iMargin){

	// 背景メモリデバイスコンテキストの作成.
	m_hBackgroundMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDCでm_hBackgroundMemDCを作成.
	if (m_hBackgroundMemDC == NULL){	// m_hBackgroundMemDCがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// 背景ビットマップのロード.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.
	m_hBackgroundBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, iWidth, iHeight, LR_DEFAULTCOLOR);	// LoadImageでリソースIDがnIDのビットマップをロード.
	if (m_hBackgroundBitmap == NULL){	// m_hBackgroundBitmapがNULLなら.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDCをDeleteDCで削除.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// ブラシの選択.
	m_hOldBackgroundBitmap = (HBITMAP)SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObjectでm_hBackgroundBitmapを選択.

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// フォントの作成.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFontでフォントを作成し, m_hFontに格納.
	if (m_hFont == NULL){	// m_hFontがNULLなら.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObjectでm_hOldBackgroundBitmapを選択.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapにNULLをセット.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObjectでm_hBackgroundBitmapを削除.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapにNULLをセット.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDCをDeleteDCで削除.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// フォントの選択.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.

	// テキストの高さを取得.
	TEXTMETRIC tm;	// フォント情報を持つTEXTMETRIC構造体変数tm.
	GetTextMetrics(m_pScene->m_hMemDC, &tm);	// GetTextMetricsでtmの内容を取得.
	m_iLineHeight = tm.tmHeight;	// m_iLineHeightにtm.tmHeightをセット.

	// 行の間隔のセット.
	m_iMargin = iMargin;	// m_iMarginにiMarginをセット.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CSelectBox::Destroy(){

	// メンバの終了処理.
	m_x = 0;	// m_xに0を代入.
	m_y = 0;	// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.
	m_iMargin = 0;	// m_iMarginに0を代入.
	m_iLineHeight = 0;	// m_iLineHeightに0を代入.

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

	// 背景ビットマップを戻す.
	if (m_hOldBackgroundBitmap != NULL){	// m_hOldBackgroundBitmapがNULLでなければ.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObjectでm_hOldBackgroundBitmapに戻す.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapにNULLをセット.
	}

	// ロードした背景ビットマップの破棄.
	if (m_hBackgroundBitmap != NULL){	// m_hBackgroundBitmapがNULLでなければ.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObjectでm_hBackgroundBitmaoを削除.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapにNULLをセット.
	}

	// 背景メモリデバイスコンテキストの破棄.
	if (m_hBackgroundMemDC != NULL){	// m_hBackgroundMemDCがNULLでなければ.
		DeleteDC(m_hBackgroundMemDC);	// DeleteDCでm_hBackgroundMemDCを破棄.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
	}

}

// セレクトアイテムの追加AddSelectItem.
void CSelectBox::AddSelectItem(tstring tstrSelectItem){

	// セレクトアイテムリストに追加.
	m_vectstrSelectItemList.push_back(tstrSelectItem);	// m_vectstrSelectItemList.push_backでtstrSelectItemを追加.

}

// セレクトアイテムのクリアClearSelectItem.
void CSelectBox::ClearSelectItem(){

	// セレクトアイテムの全削除.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clearでクリア.

}		

// ゲームオブジェクトの描画DrawRect.(指定されたリソースIDの画像をロード.)
void CSelectBox::DrawRect(int x, int y){

	// 背景ビットマップの選択.
	SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObjectでm_hBackgroundBitmapを選択.

	// 背景ビットマップの描画.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, m_hBackgroundMemDC, 0, 0, SRCCOPY);	// BitBltでバックバッファに描画.

}

// セレクトアイテムリストの描画DrawSelectItemList.
void CSelectBox::DrawSelectItemList(int x, int y, COLORREF clrColor){

	// アイテムの数だけ描画.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	int iPosY = m_y + y;	// iPosYをm_y + yで初期化.
	for (std::vector<tstring>::iterator itor = m_vectstrSelectItemList.begin(); itor != m_vectstrSelectItemList.end(); itor++){	// itorが終わるまで繰り返す.
		RECT rc = {m_x + x, iPosY, m_x + x + m_iWidth, m_y + y + m_iHeight};	// rcを引数を使って初期化.
		::DrawText(m_pScene->m_hMemDC, (*itor).c_str(), _tcslen((*itor).c_str()), &rc, DT_LEFT | DT_SINGLELINE);	// DrawTextで描画.
		iPosY = iPosY + m_iLineHeight;	// iPosYにm_iLineHeightを足す.
		iPosY = iPosY + m_iMargin;	// iPosYにm_iMarginを足す.
	}

}