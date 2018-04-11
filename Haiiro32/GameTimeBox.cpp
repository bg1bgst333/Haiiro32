// ヘッダのインクルード
// 独自のヘッダ
#include "GameTimeBox.h"	// CGameTimeBoxe

// コンストラクタCGameTimeBox
CGameTimeBox::CGameTimeBox(){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.

}

// コンストラクタCGameTimeBox(const CScene *pScene)
CGameTimeBox::CGameTimeBox(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.

}

// デストラクタ~CGameTimeBox
CGameTimeBox::~CGameTimeBox(){

}

// ゲームオブジェクトの作成Create.
BOOL CGameTimeBox::Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName){

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// フォントの作成.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFontでフォントを作成し, m_hFontに格納.
	if (m_hFont == NULL){	// m_hFontがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// フォントの選択.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CGameTimeBox::Destroy(){

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

}

// DrawTextでテキストを描画.
void CGameTimeBox::DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor){

	// テキストを描画.
	RECT rc = {x, y, x + iWidth, y + iHeight};	// rcを引数を使って初期化.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	::DrawText(m_pScene->m_hMemDC, lpctszText, _tcslen(lpctszText), &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	// WindowsAPIのDrawTextでタイトル文字列の描画.
	
}

// DrawTimeでシステム時間を描画.
void CGameTimeBox::DrawTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// 時刻を取得.
	TCHAR tszTime[256] = {0};	// TCHAR配列tszTimeを{0}で初期化.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	_stprintf(tszTime, _T("%lu"), pTime->Get());	// _stprintfでdwTimeからtszTimeに変換.
	DrawText(x, y, iWidth, iHeight, tszTime, clrColor);	// DrawTextでシステム時間を描画.

}