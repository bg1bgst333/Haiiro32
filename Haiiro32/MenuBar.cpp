// ヘッダのインクルード
// 独自のヘッダ
#include "MenuBar.h"	// CMenuBar

// コンストラクタCMenuBar
CMenuBar::CMenuBar(){

	// メンバの初期化.
	m_hMenu = NULL;	// m_hMenuにNULLをセット.
	m_hWnd = NULL;	// m_hWndにNULLをセット.

}

// コンストラクタCMenuBar(HWND hWnd)
CMenuBar::CMenuBar(HWND hWnd){

	// メンバの初期化.
	m_hMenu = NULL;	// m_hMenuにNULLをセット.
	m_hWnd = hWnd;	// m_hWndにhWndをセット.

}

// メニューをリソースからロード.
BOOL CMenuBar::LoadMenu(HINSTANCE hInstance, UINT nID){

	// リソースIDがnIDなメニューをロード.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nID));	// WindowsAPIのLoadMenuでnIDをロード.
	if (m_hMenu == NULL){	// m_hMenuがNULLなら.

		// 失敗なのでFALSE.
		return FALSE;	//  FALSEを返す.

	}

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// メニューのセット.
BOOL CMenuBar::SetMenu(HWND hWnd){

	// メンバに引数をセット.
	m_hWnd = hWnd;	// m_hWndにhWndをセット.

	// メニューのセット.
	return ::SetMenu(m_hWnd, m_hMenu);	// WindowsAPIのSetMenuでm_hMenuをセットし, 戻り値をそのまま返す.

}