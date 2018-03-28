// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// コンストラクタCGraphicalApplication
CGraphicalApplication::CGraphicalApplication() : CApplication(){

}

// メッセージループ処理関数Run.
int CGraphicalApplication::Run(){

	// 変数の初期化.
	MSG msg = {0};	// MSG型メッセージ構造体msgを{0}で初期化.
	int lCount = 0;	// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 0にリセット.
			lCount = 0;	// lCountを0にリセット.

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

			}
			else{	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else{	// 偽ならウィンドウメッセージが来ていないとき.

			// アイドル処理
			if (OnIdle(lCount)) {	// OnIdleにlCountを渡して, この中でアイドル処理をする.
				lCount++;	// TRUEで返ってくるたびにlCountを増やす.
			}

		}

	}

	// ExitInstanceの値を返す.
	return ExitInstance();	// returnでExitInstanceを返す.

}

// 終了処理関数ExitInstance.
int CGraphicalApplication::ExitInstance(){

	// メインウィンドウの破棄
	if (m_pMainWnd != NULL){	// m_pMainWndがNULLでない時.

		// 破棄する.
		delete m_pMainWnd;	// deleteでm_pMainWndを破棄.
		m_pMainWnd = NULL;	// m_pMainWndにNULLをセット.

	}

	// 今回は常に0を返す.
	return 0;	// returnで0を返す.

}

// アイドル処理関数OnIdle.
BOOL CGraphicalApplication::OnIdle(LONG lCount){

	// 画面の更新.
	if (m_pMainWnd != NULL){	// m_pMainWndがNULLでない時.
		if (m_pMainWnd->m_hWnd != NULL){	// m_pMainWnd->m_hWndがNULLでない時.
			Main(m_pMainWnd->m_hWnd, m_pMainWnd->m_iClientAreaWidth, m_pMainWnd->m_iClientAreaHeight);	// ウィンドウが存在する間はMainを実行.(m_pMainWnd->m_hWnd, m_pMainWnd->m_iClientAreaWidth, m_pMainWnd->m_iClientAreaHeightを渡す.)
		}
	}

	// とりあえずTRUE.
	return TRUE;

}

// グラフィカルメイン処理関数Main.
int CGraphicalApplication::Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// 表示するカウントの初期化.
	static int iCount = 0;	// static変数iCountを0で初期化.
	TCHAR tszCount[32] = {0};	// TCHAR型配列(要素数32)を{0}で初期化.

	// デバイスコンテキストの取得.
	HDC hDC = GetDC(hWnd);	// GetDCでhWndからhDCを取得.

	// ペンとブラシの生成.
	HPEN hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0xff, 0));	// CreatePenで緑(淡)のペンを作成.
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0x7f, 0));		// CreateSolidBrushで緑(濃)のブラシを作成.

	// ペンとブラシの選択.
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);		// 緑のペンを選択.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);	// 緑のブラシを選択.

	// 矩形描画.
	Rectangle(hDC, 0, 0, iClientAreaWidth, iClientAreaHeight);	// Rectangleで矩形を描画.

	// テキストの表示.
	_stprintf(tszCount, _T("%d"), iCount);	// _stprintfで整数値iCountを文字列tszCountに変換.
	SetBkMode(hDC, TRANSPARENT);	// SetBkModeでTRANSPARENT(透過)にする.
	TextOut(hDC, 50, 50, tszCount, _tcslen(tszCount));	// TextOutでtszCountを出力.
	iCount++;	// iCountをインクリメント.
	if (iCount >= 10000){	// iCountが10000以上なら.
		iCount = 0;	// iCountを0にリセット.
	}

	// ペンとブラシの復元
	SelectObject(hDC, hOldBrush);		// 古いブラシを選択.
	SelectObject(hDC, hOldPen);		// 古いペンを選択.

	// ペンとブラシの破棄.
	DeleteObject(hBrush);	// ブラシの破棄.
	DeleteObject(hPen);	// ペンの破棄.

	// デバイスコンテキストの解放.
	ReleaseDC(hWnd, hDC);	// ReleaseDCでhDCを解放.

	// 0を返す.
	return 0;	// 0を返す.

}