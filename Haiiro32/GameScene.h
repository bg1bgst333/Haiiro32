// 二重インクルード防止
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene
#include "Map.h"	// CMap
//#include "Character.h"	// CCharacter
#include "Player.h"	// CPlayer
#include "GameTimeBox.h"	// CGameTimeBox

// 前方宣言.
class CScene;	// CScene.
class CMap;	// CMap.
//class CCharacter;	// CCharacter.
class CPlayer;	// CPlayer.

// ゲームシーンクラスCGameScene
class CGameScene : public CScene{

	// publicメンバ
	public:

		// publicメンバ変数
#if 0
		CSharedObject *m_pSharedObject1;	// CSharedObjectオブジェクトポインタm_pSharedObject1.
		CSharedObject *m_pSharedObject2;	// CSharedObjectオブジェクトポインタm_pSharedObject2.
		CSharedObject *m_pSharedObject3;	// CSharedObjectオブジェクトポインタm_pSharedObject3.
#endif
		CMap *m_pMap;	// CMapオブジェクトポインタm_pMap.
		//CCharacter *m_pCharacter;	// CCharacterオブジェクトポインタm_pCharacter.
		CPlayer *m_pPlayer;	// プレイヤーm_pPlayer.
		CGameTimeBox *m_pGameTimeBox;	// ゲームタイムボックスm_pGameTimeBox.
		
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