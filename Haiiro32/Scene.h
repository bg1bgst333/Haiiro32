// 二重インクルード防止
#ifndef __SCENE_H__
#define __SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// シーンクラスCScene
class CScene{

	// publicメンバ
	public:

		// publicメンバ変数
		const CWindow *m_pMainWnd;	// CWindowオブジェクトポインタm_pMainWnd.(const)

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CScene();	// コンストラクタCScene
		CScene(const CWindow *pWnd);	// コンストラクタCScene(const CWindow *pWnd)
		virtual ~CScene();	// デストラクタ~CScene
		virtual int InitScene();	// シーン初期化InitScene.
		virtual int RunScene();	// シーン処理中RunScene.
		virtual int ExitScene();	// シーン終了処理ExitScene.

};

#endif