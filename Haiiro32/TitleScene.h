// 二重インクルード防止
#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene
#include "Background.h"	// CBackground

// タイトルシーンクラスCTitleScene
class CTitleScene : public CScene{

	// publicメンバ
	public:

		// publicメンバ変数
		CBackground *m_pBackground;	// 背景オブジェクトm_pBackground.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CTitleScene();	// コンストラクタCTitleScene
		CTitleScene(const CWindow *pWnd);	// コンストラクタCTitleScene(const CWindow *pWnd)
		virtual ~CTitleScene();	// デストラクタ~CTitleScene
		virtual int InitGameObjects();	// ゲームオブジェクトの初期化.
		virtual int InitKeyboard();	// キーボードの初期化.
		virtual int CheckKeyboard();	// キーボードのチェック.
		virtual int RunProc();	// キー入力や時間などから処理を計算.
		virtual int DrawGameObjects();	// ゲームオブジェクトの描画.
		virtual int ExitGameObjects();	// ゲームオブジェクトの終了処理.

};

#endif