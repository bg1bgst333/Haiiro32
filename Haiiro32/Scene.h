// 二重インクルード防止
#ifndef __SCENE_H__
#define __SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "Keyboard.h"	// CKeyboard
#include "GameObject.h"	// CGameObject
#include "GameTime.h"	// CGameTime
#include "GameSystem.h"	// CGameSystem

// 前方宣言.
class CGameObject;	// CGameObject.

// シーンクラスCScene
class CScene{

	// publicメンバ
	public:

		// publicメンバ変数
		const CWindow *m_pMainWnd;	// CWindowオブジェクトポインタm_pMainWnd.(const)
		CGameTime *m_pGameTime;	// CGameTimeオブジェクトポインタm_pGameTime.
		CGameSystem *m_pGameSystem;	// CGameSystemオブジェクトポインタm_pGameSystem.
		HDC m_hDC;	// ウィンドウデバイスコンテキストハンドルm_hDC.
		HDC m_hMemDC;	// メモリデバイスコンテキストハンドルm_hMemDC.
		HBITMAP m_hMemBitmap;	// メモリビットマップハンドルm_hMemBitmap.
		HBITMAP m_hOldMemBitmap;	// 元のメモリビットマップハンドルm_hOldMemBitmap.
		int m_iScreenWidth;	// スクリーン幅.
		int m_iScreenHeight;	// スクリーン高さ.
		CKeyboard *m_pKeyboard;	// キーボードオブジェクトm_pKeyboard.
		CGameObject *m_pTest;	// テストオブジェクトm_pTest.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CScene();	// コンストラクタCScene
		CScene(const CWindow *pWnd);	// コンストラクタCScene(const CWindow *pWnd)
		CScene(const CWindow *pWnd, CGameTime *pTime);	// コンストラクタCScene(const CWindow *pWnd, CGameTime *pTime)
		CScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// コンストラクタCScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CScene();	// デストラクタ~CScene
		virtual int InitScene();	// シーン初期化InitScene.
		virtual int RunScene();	// シーン処理中RunScene.
		virtual int ExitScene();	// シーン終了処理ExitScene.
		virtual void ResizeWindow(int iWidth, int iHeight);	// ウィンドウのリサイズResizeWindow.
		virtual void CreateScreen(int iWidth, int iHeight);	// スクリーンの作成CreateScreen.
		virtual void Present();	// バックバッファからフロントバッファへ転送することで画面を描画するPresent.
		virtual void DestroyScreen();	// スクリーンの破棄DestroyScreen.
		virtual int InitGameObjects();	// ゲームオブジェクトの初期化.
		virtual int InitKeyboard();	// キーボードの初期化.
		virtual int CheckClose();	// 閉じるボタンのチェック.
		virtual int CheckKeyboard();	// キーボードのチェック.
		virtual int RunProc();	// キー入力や時間などから処理を計算.
		virtual int DrawGameObjects();	// ゲームオブジェクトの描画.
		virtual int ExitGameObjects();	// ゲームオブジェクトの終了処理.
		virtual int ExitKeyboard();	// キーボードの終了処理.

};

#endif