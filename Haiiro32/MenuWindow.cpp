// ヘッダのインクルード
// 独自のヘッダ
#include "MenuWindow.h"	// CMenuWindow

// コンストラクタCMenuWindow()
CMenuWindow::CMenuWindow() : CWindow(){

	// メンバの初期化.
	m_pMenuBar = NULL;	// m_pMenuBarをNULLで初期化.

}

// デストラクタ~CMenuWindow()
CMenuWindow::~CMenuWindow(){

	// メンバの終了処理
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウプロシージャ省略, メニュー名指定バージョン.)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName){

	// メニューはlpszMenuNameを使う.
	return CWindow::RegisterClass(hInstance, lpctszClassName, lpszMenuName);	// CWindow::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL  CMenuWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名は指定のモノを使う.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラス名指定バージョンで作成.

}

// ウィンドウの破棄と終了処理関数Destroy.
void CMenuWindow::Destroy(){

	// メニューバーの破棄.
 	if (m_pMenuBar != NULL){	// m_pMenuBarがNULLでなければ.
 		delete m_pMenuBar;	// deleteでm_pMenuBarを解放.
 		m_pMenuBar = NULL;	// m_pMenuBarにNULLをセット.
 	}
 
	// 親ウィンドウのDestroyを呼ぶ.
	CWindow::Destroy();	// CWindow::Destroyを呼ぶ.

}

// ウィンドウが破棄された時.
void CMenuWindow::OnDestroy(){

	// 親ウィンドウのOnDestroy.
 	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウを閉じた時.
int CMenuWindow::OnClose(){

	// 閉じるボタンが押された.
	m_bClose = TRUE;	// m_bCloseにTRUEをセット.

	// ウィンドウの終了処理.
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}