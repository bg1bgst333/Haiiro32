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

#if 0
	m_pMap->Create(32, 32, 21, 17);	// Createで生成.
#else
	//m_pMap->ImportFile(_T("testmap1.bin"));	// m_pMap->ImportFileでインポート.
	m_pMap->ImportResource(IDR_TESTMAP1);	// m_pMap->ImportResourceでインポート.
#endif

	// iRet.
	return iRet;	// iRetを返す.

}

// キーボードの初期化.
int CGameScene::InitKeyboard(){

	// キーボードオブジェクトの作成.
	m_pKeyboard = new CKeyboard();	// CKeyboardオブジェクトを作成し, ポインタをm_pKeyboardに格納.
	
	// 監視キーの追加.
	m_pKeyboard->AddKey(VK_DOWN);	// 下キーを追加.
	m_pKeyboard->AddKey(VK_UP);	// 上キーを追加.
	m_pKeyboard->AddKey(VK_RIGHT);	// 右キーを追加.
	m_pKeyboard->AddKey(VK_LEFT);	// 左キーを追加.

	// 成功なので0.
	return 0;	// 0を返す.

}

// キーボードのチェック.
int CGameScene::CheckKeyboard(){

	// マップのキー状態クリア.
	m_pMap->Clear();	// クリア.

	// キー状態の取得.
	m_pKeyboard->Check();	// m_pKeyboard->Checkで状態確認.

	// 0番目のキー(ここでは下キー.)が押された時.
	if (m_pKeyboard->IsDown(0)){	// m_pKeyboard->IsDown(0)がTRUEなら.
		m_pMap->Down();	// 下.
	}

	// 1番目のキー(ここでは上キー.)が押された時.
	if (m_pKeyboard->IsDown(1)){	// m_pKeyboard->IsDown(1)がTRUEなら.
		m_pMap->Up();	// 上.
	}

	// 2番目のキー(ここでは右キー.)が押された時.
	if (m_pKeyboard->IsDown(2)){	// m_pKeyboard->IsDown(2)がTRUEなら.
		m_pMap->Right();	// 右.
	}

	// 3番目のキー(ここでは左キー.)が押された時.
	if (m_pKeyboard->IsDown(3)){	// m_pKeyboard->IsDown(3)がTRUEなら.
		m_pMap->Left();	// 左.
	}

	// 成功なので0.
	return 0;	// 0を返す.

}

// キー入力や時間などから処理を計算.
int CGameScene::RunProc(){

	// マップ処理.
	if (m_pMap != NULL){	// m_pMapがNULLでなければ.
		m_pMap->Proc();	// m_pMap->Procで処理.
	}

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