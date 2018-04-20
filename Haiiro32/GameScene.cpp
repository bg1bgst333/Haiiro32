// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"	// リソース
#include "GameScene.h"	// CGameScene

// コンストラクタCGameScene
CGameScene::CGameScene() : CScene(){

	// メンバの初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.
	m_hDC = NULL;	// m_hDCにNULLをセット.

}

// コンストラクタCGameScene(const CWindow *pWnd)
CGameScene::CGameScene(const CWindow *pWnd) : CScene(pWnd){

	// メンバの初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.
	m_hDC = NULL;	// m_hDCにNULLをセット.

}

// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// メンバの初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.
	m_hDC = NULL;	// m_hDCにNULLをセット.

}

// コンストラクタCGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem) : CScene(pWnd, pTime, pSystem){

	// メンバの初期化.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBufferにNULLをセット.
	m_hDC = NULL;	// m_hDCにNULLをセット.

}

// デストラクタ~CGameScene
CGameScene::~CGameScene(){

}

// ゲームオブジェクトの初期化.
int CGameScene::InitGameObjects(){

	// シェアードリソースのロード.(これは全体でファイルごとに1回ずつやっておけばいい.)
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED1);	// m_pGameSystem->m_pSharedResources->AddでIDB_SHARED1を追加.
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED2);	// m_pGameSystem->m_pSharedResources->AddでIDB_SHARED2を追加.
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED3);	// m_pGameSystem->m_pSharedResources->AddでIDB_SHARED3を追加.

	// シェアードイメージバッファの生成.
	m_hDC = GetDC(m_pMainWnd->m_hWnd);	// m_hDCを取得.
	m_pSharedImageBuffer = new CSharedImageBuffer(m_pGameSystem->m_pSharedResources, m_hDC);	// 生成.
	m_pSharedImageBuffer->Add(IDB_SHARED1);	// 追加.
	m_pSharedImageBuffer->Add(IDB_SHARED2);	// 追加.
	m_pSharedImageBuffer->Add(IDB_SHARED3);	// 追加.

	return 0;

}

// キーボードの初期化.
int CGameScene::InitKeyboard(){

	return 0;

}

// キーボードのチェック.
int CGameScene::CheckKeyboard(){

	return 0;

}

// キー入力や時間などから処理を計算.
int CGameScene::RunProc(){

	return 0;

}

// ゲームオブジェクトの描画.
int CGameScene::DrawGameObjects(){

	HDC hShared1DC = m_pSharedImageBuffer->Get(IDB_SHARED1);
	BitBlt(m_hMemDC, 0, 0, 100, 100, hShared1DC, 0, 0, SRCCOPY);
	
	HDC hShared2DC = m_pSharedImageBuffer->Get(IDB_SHARED2);
	BitBlt(m_hMemDC, 100, 100, 100, 100, hShared2DC, 0, 0, SRCCOPY);
	
	HDC hShared3DC = m_pSharedImageBuffer->Get(IDB_SHARED3);
	BitBlt(m_hMemDC, 200, 200, 100, 100, hShared3DC, 0, 0, SRCCOPY);

	return 0;

}

// ゲームオブジェクトの終了処理.
int CGameScene::ExitGameObjects(){

	// シェアードイメージバッファの解放.
	ReleaseDC(m_pMainWnd->m_hWnd, m_hDC);	// ReleaseDCで解放.
	delete m_pSharedImageBuffer;	// m_pSharedImageBufferを削除.

	return 0;

}