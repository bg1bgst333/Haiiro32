// 二重インクルード防止
#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene
#include "Background.h"	// CBackground
#include "Title.h"	// CTitle
#include "SelectBox.h"	// CSelectBox
#include "GameTimeBox.h"	// CGameTimeBox

// タイトルシーンクラスCTitleScene
class CTitleScene : public CScene{

	// publicメンバ
	public:

		// publicメンバ変数
		CBackground *m_pBackground;	// 背景オブジェクトm_pBackground.
		CTitle *m_pTitle;	// タイトルオブジェクトm_pTitle.
		CSelectBox *m_pSelectBox;	// セレクトボックスm_pSelectBox.
		CGameTimeBox *m_pGameTimeBox;	// ゲームタイムボックスm_pGameTimeBox.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CTitleScene();	// コンストラクタCTitleScene
		CTitleScene(const CWindow *pWnd);	// コンストラクタCTitleScene(const CWindow *pWnd)
		CTitleScene(const CWindow *pWnd, CGameTime *pTime);	// コンストラクタCTitleScene(const CWindow *pWnd, CGameTime *pTime)
		CTitleScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// コンストラクタCTitleScnen(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CTitleScene();	// デストラクタ~CTitleScene
		virtual int InitGameObjects();	// ゲームオブジェクトの初期化.
		virtual int InitKeyboard();	// キーボードの初期化.
		virtual int CheckKeyboard();	// キーボードのチェック.
		virtual int RunProc();	// キー入力や時間などから処理を計算.
		virtual int DrawGameObjects();	// ゲームオブジェクトの描画.
		virtual int ExitGameObjects();	// ゲームオブジェクトの終了処理.

};

#endif