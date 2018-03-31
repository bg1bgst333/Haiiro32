// 二重インクルード防止
#ifndef __SCENE_H__
#define __SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "GameObject.h"	// CGameObject

// 前方宣言.
class CGameObject;	// CGameObject.

// シーンクラスCScene
class CScene{

	// publicメンバ
	public:

		// publicメンバ変数
		const CWindow *m_pMainWnd;	// CWindowオブジェクトポインタm_pMainWnd.(const)
		HDC m_hDC;	// ウィンドウデバイスコンテキストハンドルm_hDC.
		HDC m_hMemDC;	// メモリデバイスコンテキストハンドルm_hMemDC.
		HBITMAP m_hMemBitmap;	// メモリビットマップハンドルm_hMemBitmap.
		HBITMAP m_hOldMemBitmap;	// 元のメモリビットマップハンドルm_hOldMemBitmap.
		int m_iScreenWidth;	// スクリーン幅.
		int m_iScreenHeight;	// スクリーン高さ.
		CGameObject *m_pBackground;	// 背景ゲームオブジェクトm_pBackground.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CScene();	// コンストラクタCScene
		CScene(const CWindow *pWnd);	// コンストラクタCScene(const CWindow *pWnd)
		virtual ~CScene();	// デストラクタ~CScene
		virtual int InitScene();	// シーン初期化InitScene.
		virtual int RunScene();	// シーン処理中RunScene.
		virtual int ExitScene();	// シーン終了処理ExitScene.
		virtual void ResizeWindow(int iWidth, int iHeight);	// ウィンドウのリサイズResizeWindow.
		virtual void CreateScreen(int iWidth, int iHeight);	// スクリーンの作成CreateScreen.
		virtual void Present();	// バックバッファからフロントバッファへ転送することで画面を描画するPresent.
		virtual void DestroyScreen();	// スクリーンの破棄DestroyScreen.

};

#endif