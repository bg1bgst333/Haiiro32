// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "resource.h"		// リソース

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CMenuWindow(){

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow(){

	// メンバの終了処理
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance){

	// ウィンドウプロシージャにはCWindow::StaticWndowProc, メニューはなし(NULL)とする.((LPCTSTR)でキャストしないとオーバーロードが曖昧になる.)
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), (LPCTSTR)NULL);	// CWindow::RegisterClassで登録.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpszMenuName){

	// ウィンドウプロシージャにはCWindow::StaticWndowProc, メニューはlpszMenuNameとする.((LPCTSTR)でキャストしないとオーバーロードが曖昧になる.)
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), (LPCTSTR)lpszMenuName);	// CWindow::RegisterClassで登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウの破棄と終了処理関数Destroy.
void CMainWindow::Destroy(){

	// 親ウィンドウのDestroyを呼ぶ.
	CMenuWindow::Destroy();	// CMenuWindow::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// メニューバーの作成.
	m_pMenuBar = new CMenuBar(hwnd);	// CMenuBarオブジェクトm_pMenuBarを作成.

	// メニューのロード.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MENU1);	// LoadMenuでIDR_MENU1をロード.

	// メニューのセット.
	m_pMenuBar->SetMenu(hwnd);	// SetMenuでhwndにメニューをセット.

	// メニューハンドラの追加.
	AddCommandHandler(ID_APP_EXIT, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnAppExit);	// AddCommandHandlerでID_APP_EXITに対するハンドラCMainWindow::OnAppExitを登録.

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_APP_EXIT, 0);	// DeleteCommandHandlerでID_APP_EXITのハンドラを削除.

	// 親ウィンドウのOnDestroyを呼ぶ.
	CMenuWindow::OnDestroy();	// CMenuWindow::OnDestroyを呼ぶ.

	// 終了メッセージの送信.
	PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.

}

// ウィンドウを閉じた時.
int CMainWindow::OnClose(){

	// アプリケーションを終了するかどうかの判定.
	int iRet = MessageBox(m_hWnd, _T("アプリケーションを終了しますか?"), _T("Haiiro"), MB_YESNO | MB_ICONQUESTION);	// "アプリケーションを終了しますか?"と表示.("はい", "いいえ"のメッセージボックスが表示される.)
	if (iRet == IDYES){	// "はい"が押された時.

		// ウィンドウの終了処理.
		Destroy();	// Destroyでこのウィンドウの終了処理をする.

		// 0を返す.
		return 0;	// 0を返してウィンドウを閉じる.

	}
	else{	// "いいえ"が押された時など.

		// -1を返す.
		return -1;	// -1を返してウィンドウを閉じない.

	}

}

// "アプリケーションの終了"を選択された時のハンドラ.
int CMainWindow::OnAppExit(WPARAM wParam, LPARAM lParam){

	// 閉じる.
	SendMessage(m_hWnd, WM_CLOSE, 0, 0);	// WM_CLOSEを送信してウィンドウを閉じる.

	// 処理したので0.
	return 0;	// returnで0を返す.

}