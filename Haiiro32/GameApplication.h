// 二重インクルード防止
#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "Scene.h"	// CScene
#include "GameTime.h"	// CGameTime

// ゲームアプリケーションクラスCGameApplication
class CGameApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		CScene *m_pScene;	// CSceneオブジェクトポインタm_pScene.
		CGameTime *m_pGameTime;	// CGameTimeオブジェクトポインタm_pGameTime.
		int m_iNo;	// 番号m_iNo.

		// publicメンバ関数
		// コンストラクタ
		CGameApplication();	// コンストラクタCGameApplication

		// メンバ関数.
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.
		virtual int Main();	// ゲームメイン処理関数Main.

};

#endif