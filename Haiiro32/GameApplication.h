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