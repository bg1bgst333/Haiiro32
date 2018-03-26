// 二重インクルード防止
#ifndef __MENU_WINDOW_H__
#define __MENU_WINDOW_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "MenuBar.h"	// CMenuBar

// メニューウィンドウクラスCMenuWindow
class CMenuWindow : public CWindow{

	// publicメンバ
	public:

		// publicメンバ変数
		CMenuBar *m_pMenuBar;	// CMenuBarオブジェクトポインタm_pMenuBar

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMenuWindow();	// コンストラクタCMenuWindow()
		virtual ~CMenuWindow();	// デストラクタ~CMenuWindow()
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウプロシージャ省略, メニュー名指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual void OnDestroy();	// ウィンドウが破棄された時.

};

#endif