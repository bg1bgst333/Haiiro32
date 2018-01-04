// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メッセージボックスで"Hello, Haiiro!"の表示.
	MessageBox(NULL, _T("Hello, Haiiro!"), _T("Haiiro"), MB_OK);	// MessageBoxで"Hello, Haiiro!"と表示.

	// プログラムの終了
	return 0;	// returnで0を返して正常終了.

}