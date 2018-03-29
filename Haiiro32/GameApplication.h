// 二重インクルード防止
#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// ゲームアプリケーションクラスCGameApplication
class CGameApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_iSceneNo;	// シーン番号m_iSceneNo.
		int m_iSceneStatus;	// シーン状態を表す変数m_iSceneStatus.
		HDC m_hDC;	// ウィンドウデバイスコンテキストm_hDC.
		HDC m_hMemDC;	// メモリデバイスコンテキストm_hMemDC.
		HBITMAP m_hMemBitmap;	// メモリビットマップm_hMemBitmap.
		HBITMAP m_hOldMemBitmap;	// 元のメモリビットマップm_hOldMemBitmap.
		HPEN m_hBackPen;	// 背景ペンm_hBackPen.
		HPEN m_hOldBackPen;	// 元の背景ペンm_hOldBackPen.
		HBRUSH m_hBackBrush;	// 背景ブラシm_hBackBrush.
		HBRUSH m_hOldBackBrush;	// 元の背景ブラシm_hOldBackBrush.
		HPEN m_hCursorPen;	// カーソルペンm_hCursorPen.
		HPEN m_hOldCursorPen;	// 元のカーソルペンm_hOldCursorPen.
		HBRUSH m_hCursorBrush;	// カーソルブラシm_hCursorBrush.
		HBRUSH m_hOldCursorBrush;	// カーソルブラシm_hOldCursorBrush.
		int m_iCursorX;	// カーソルのx座標m_iCursorX.
		int m_iCursorY;	// カーソルのy座標m_iCursorY.

		// publicメンバ関数
		// コンストラクタ
		CGameApplication();	// コンストラクタCGameApplication
		// メンバ関数.
		virtual int Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// ゲームメイン処理関数Main.
		virtual int InitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// シーンの初期化InitScene.
		virtual int RunScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// シーンの処理中RunScene.
		virtual int ExitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// シーンの終了処理ExitScene.

};

#endif