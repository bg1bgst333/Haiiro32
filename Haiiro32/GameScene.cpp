// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"	// リソース
#include "GameScene.h"	// CGameScene

// コンストラクタCGameScene
CGameScene::CGameScene() : CScene(){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.

}

// コンストラクタCGameScene(const CWindow *pWnd)
CGameScene::CGameScene(const CWindow *pWnd) : CScene(pWnd){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.

}

// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.

}

// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem) : CScene(pWnd, pTime, pSystem){

	// メンバの初期化.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1にNULLをセット.
	m_pSharedObject2 = NULL;	// m_pSharedObject2にNULLをセット.
	m_pSharedObject3 = NULL;	// m_pSharedObject3にNULLをセット.
#endif
	m_pMap = NULL;	// m_pMapにNULLをセット.

}

// デストラクタ~CGameScene
CGameScene::~CGameScene(){

}

// ゲームオブジェクトの初期化.
int CGameScene::InitGameObjects(){

	// 基底クラスの初期化.
	int iRet = CScene::InitGameObjects();	// CScene::InitGameObjectsで初期化.

	// シェアードイメージバッファの追加.
	m_pSharedImageBuffer->Add(IDB_SHARED1);	// 追加.
	m_pSharedImageBuffer->Add(IDB_SHARED2);	// 追加.
	m_pSharedImageBuffer->Add(IDB_SHARED3);	// 追加.

	// シェアードオブジェクトの生成.
#if 0
	m_pSharedObject1 = new CSharedObject(this);	// 生成.
	m_pSharedObject1->Create(0 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject1->Createで生成.
	m_pSharedObject2 = new CSharedObject(this);	// 生成.
	m_pSharedObject2->Create(1 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject2->Createで生成.
	m_pSharedObject3 = new CSharedObject(this);	// 生成.
	m_pSharedObject3->Create(2 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject3->Createで生成.
#endif
	m_pMap = new CMap(this);	// CMapのオブジェクト生成.
	m_pMap->Create(32, 32, 3, 3);	// Createで生成.

	// iRet.
	return iRet;	// iRetを返す.

}

// キーボードの初期化.
int CGameScene::InitKeyboard(){

	// 成功なので0.
	return 0;	// 0を返す.

}

// キーボードのチェック.
int CGameScene::CheckKeyboard(){

	// 成功なので0.
	return 0;	// 0を返す.

}

// キー入力や時間などから処理を計算.
int CGameScene::RunProc(){

	// 成功なので0.
	return 0;	// 0を返す.

}

// ゲームオブジェクトの描画.
int CGameScene::DrawGameObjects(){

	// シェアードオブジェクトの描画.
#if 0
	m_pSharedObject1->Draw(0 * 32, 0 * 32);	// m_pSharedObject1->Drawで描画.
	m_pSharedObject2->Draw(1 * 32, 0 * 32);	// m_pSharedObject2->Drawで描画.
	m_pSharedObject3->Draw(2 * 32, 0 * 32);	// m_pSharedObject3->Drawで描画.
#endif
	m_pMap->Draw();

	// 基底クラスの処理.
	return CScene::DrawGameObjects();	// CScene::DrawGameObjectsを呼ぶ.

}

// ゲームオブジェクトの終了処理.
int CGameScene::ExitGameObjects(){

	// シェアードオブジェクトの破棄.
#if 0
	delete m_pSharedObject1;	// m_pSharedObject1を破棄.
	delete m_pSharedObject2;	// m_pSharedObject2を破棄.
	delete m_pSharedObject3;	// m_pSharedObject3を破棄.
#endif
	m_pMap->Destroy();	// Destroyで破棄.
	delete m_pMap;	// m_pMapを削除.
	m_pMap = NULL;	// m_pMapにNULLをセット.
	// 基底クラスの処理.
	return CScene::ExitGameObjects();	// CScene::ExitGameObjectsで終了処理.

}