// ヘッダのインクルード
// 独自のヘッダ
#include "GameTimeBox.h"	// CGameTimeBoxe

// コンストラクタCGameTimeBox
CGameTimeBox::CGameTimeBox(){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_dwTime = 0;	// m_dwTimeを0で初期化.
	m_dwFPS = 0;	// m_dwFPSを0で初期化.
	m_dwRunFPS = 0;	// m_dwRunFPSを0で初期化.

}

// コンストラクタCGameTimeBox(const CScene *pScene)
CGameTimeBox::CGameTimeBox(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_dwTime = 0;	// m_dwTimeを0で初期化.
	m_dwFPS = 0;	// m_dwFPSを0で初期化.
	m_dwRunFPS = 0;	// m_dwRunFPSを0で初期化.

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

	// ユーザタイムリセット.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	pTime->ResetUserTime();	// pTime->ResetUserTimeでユーザタイムリセット.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CGameTimeBox::Destroy(){

	// メンバの終了処理.
	m_dwTime = 0;	// m_dwTimeに0をセット.
	m_dwFPS = 0;	// m_dwFPSに0をセット.
	m_dwRunFPS = 0;	// m_dwRunFPSに0をセット.

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

// 処理をするProc.
int CGameTimeBox::Proc(){
	
	// 時刻を取得.
	TCHAR tszTime[256] = {0};	// TCHAR配列tszTimeを{0}で初期化.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	//m_dwTime = pTime->GetSystemTime();	// pTime->GetSystemTimeで取得した時刻をm_dwTimeに格納.
	m_dwTime = pTime->GetUserTime();	// pTime->GetUserTimeで取得した時刻をm_dwTimeに格納.
	m_dwFPS = pTime->GetFPS();	// pTime->GetFPSをm_dwFPSにセット.
	m_dwRunFPS = pTime->GetRunFPS();	// pTime->GetRunFPSをm_dwRunFPSのセット.
	m_dwFrameIntervalMilliTime = pTime->GetFrameIntervalMilliTime();	// pTime->GetFrameIntervalMilliTimeをm_dwFrameIntervalMilliTimeにセット.

	// 成功なので0.
	return 0;	// 0を返す.

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

// DrawTimeで時間を描画.
void CGameTimeBox::DrawTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// 時刻を取得.
	TCHAR tszTime[256] = {0};	// TCHAR配列tszTimeを{0}で初期化.
	_stprintf(tszTime, _T("%lu"), m_dwTime);	// _stprintfでm_dwTimeからtszTimeに変換.
	DrawText(x, y, iWidth, iHeight, tszTime, clrColor);	// DrawTextでユーザ時間を描画.

}

// DrawFPSで時間を描画.
void CGameTimeBox::DrawFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// FPSを取得.
	TCHAR tszFPS[256] = {0};	// TCHAR配列tszFPSを{0}で初期化.
	_stprintf(tszFPS, _T("%lu"), m_dwFPS);	// _stprintfでm_dwFPSからtszFPSに変換.
	DrawText(x, y, iWidth, iHeight, tszFPS, clrColor);	// DrawTextでFPSを描画.

}

// DrawRunFPSで実行FPSを描画
void CGameTimeBox::DrawRunFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// 実行FPSを取得.
	TCHAR tszRunFPS[256] = {0};	// TCHAR配列tszRunFPSを{0}で初期化.
	_stprintf(tszRunFPS, _T("%lu"), m_dwRunFPS);	// _stprintfでm_dwRunFPSからtszRunFPSに変換.
	DrawText(x, y, iWidth, iHeight, tszRunFPS, clrColor);	// DrawTextで実行FPSを描画.

}

// DrawFrameIntervalMilliTimeでフレーム間隔を描画.
void CGameTimeBox::DrawFrameIntervalMilliTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// フレーム間隔を取得.
	TCHAR tszFrameInterval[256] = {0};	// tszFrameIntervalを{0}で初期化.
	_stprintf(tszFrameInterval, _T("%lu"), m_dwFrameIntervalMilliTime);	// m_dwFrameIntervalMilliTimeをtszFrameIntervalに変換.
	DrawText(x, y, iWidth, iHeight, tszFrameInterval, clrColor);	// DrawTextでフレーム間隔を描画.

}