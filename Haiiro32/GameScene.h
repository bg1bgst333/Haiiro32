// 二重インクルード防止
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene
#include "SharedImageBuffer.h"	// CSharedImageBuffer

// ゲームシーンクラスCGameScene
class CGameScene : public CScene{

	// publicメンバ
	public:

		// publicメンバ変数
		CSharedImageBuffer *m_pSharedImageBuffer;	// CSharedImageBufferオブジェクトポインタm_pSharedImageBuffer.
		HDC m_hDC;	// デバイスコンテキストハンドルm_hDC.

		// コンストラクタ・デストラクタ
		CGameScene();	// コンストラクタCGameScene
		CGameScene(const CWindow *pWnd);	// コンストラクタCGameScene(const CWindow *pWnd)
		CGameScene(const CWindow *pWnd, CGameTime *pTime);	// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime)
		CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CGameScene();	// デストラクタ~CGameScene
		virtual int InitGameObjects();	// ゲームオブジェクトの初期化.
		virtual int InitKeyboard();	// キーボードの初期化.
		virtual int CheckKeyboard();	// キーボードのチェック.
		virtual int RunProc();	// キー入力や時間などから処理を計算.
		virtual int DrawGameObjects();	// ゲームオブジェクトの描画.
		virtual int ExitGameObjects();	// ゲームオブジェクトの終了処理.

};

#endif