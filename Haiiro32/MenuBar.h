// 二重インクルード防止
#ifndef __MENU_BAR_H__
#define __MENU_BAR_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// メニューバークラスCMenuBar
class CMenuBar{

	// publicメンバ
	public:

		// publicメンバ変数
		HMENU m_hMenu;	// メニューハンドルm_hMenu.
		HWND m_hWnd;	// 設置先ウィンドウハンドルm_hWnd.

		// publicメンバ関数
		// コンストラクタ
		CMenuBar();	// コンストラクタCMenuBar()
		CMenuBar(HWND hWnd);	// コンストラクタCMenuBar(HWND hWnd)
		// メンバ関数
		virtual BOOL LoadMenu(HINSTANCE hInstance, UINT nID);	// メニューをリソースからロード.
		virtual BOOL SetMenu(HWND hWnd);	// メニューのセット.

};

#endif