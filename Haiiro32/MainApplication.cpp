// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"	// CMainWindow
#include "TitleScene.h"	// CTitleScene
#include "GameScene.h"	// CGameScene

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);	// CMainWindow::RegisterClassでウィンドウクラス"CMainWindow"を登録.

	// CMainWindowオブジェクトの作成.
	m_pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, m_pMainWndに格納.

	// ウィンドウの作成.
	if (!m_pMainWnd->Create(_T("Haiiro"), WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Createでウィンドウ作成(最大化とリサイズを無効化.)し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// 親のInitInstanceを呼ぶ.
	BOOL bRet = CGameApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CGameApplication::InitInstanceを呼ぶ.

	// 目標FPS値の設定.
	if (m_pGameTime != NULL){	// m_pGameTimeがNULLでなければ.
		m_pGameTime->SetTargetFPS(60);	// 60FPSを目指す.
	}

	// シェアードリソースのロード.(これは全体でファイルごとに1回ずつやっておけばいい.)
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED1);	// m_pGameSystem->m_pSharedResources->AddでIDB_SHARED1を追加.
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED2);	// m_pGameSystem->m_pSharedResources->AddでIDB_SHARED2を追加.
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED3);	// m_pGameSystem->m_pSharedResources->AddでIDB_SHARED3を追加.

	// InitInstanceの戻り値を返す.
	return bRet;	// bRetを返す.

}

// ゲームメイン処理関数Main.
int CMainApplication::Main(){

	// 変数の初期化.
	int iRet = 0;	// iRetを0で初期化.
	CScene *pScene = NULL;	// pSceneをNULLで初期化.

	// 生成.
	if (m_iNo == 0 && m_pScene == NULL){	// m_iNoが0で生成されていない時.
		pScene = new CTitleScene(m_pMainWnd, m_pGameTime, m_pGameSystem);	// CTitleSceneを生成し, pSceneに格納.(m_pMainWndとm_pGameTimeとm_pGameSystemを渡す.)
	}
	else if (m_iNo == 1 && m_pScene == NULL){	// m_iNoが1で生成されていない時.
		pScene = new CGameScene(m_pMainWnd, m_pGameTime, m_pGameSystem);	// CGameSceneを生成し, pSceneに格納.(m_pMainWndとm_pGameTimeとm_pGameSystemを渡す.)
	}

#if 0
	else if (m_iNo == 2 && m_pScene == NULL){	// m_iNoが2で生成されていない時.
		pScene = new CScene(m_pMainWnd, m_pGameTime, m_pGameSystem);	// CSceneを生成し, pSceneに格納.(m_pMainWndとm_pGameTimeとm_pGameSystemを渡す.)
	}
	else if (m_iNo == 3 && m_pScene == NULL){	// m_iNoが3で生成されていない時.
		pScene = new CScene(m_pMainWnd, m_pGameTime, m_pGameSystem);	// CSceneを生成し, pSceneに格納.(m_pMainWndとm_pGameTimeとm_pGameSystemを渡す.)
	}
#endif

	// 処理.
	if (m_pScene == NULL){	// m_pSceneがNULLの時.	
		m_pScene = pScene;	// pSceneを格納.
		if (pScene == NULL){	// pSceneがNULLなら.
			// InitSceneが呼べないので終了.
			return 0;	// 0を返す.
		}
		iRet = m_pScene->InitScene();	// 成功なら0を返す.
		if (iRet == -1){	// -1の時.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
			m_pMainWnd->Destroy();	// m_pMainWnd->Destroyでウィンドウを閉じる.
		}
		else{	// 0の時.
			iRet = m_pScene->RunScene();	// 処理中.
			if (iRet == 1){	// 1なら次のシーンへ.
				m_pScene->ExitScene();	// 終了処理.
				delete m_pScene;	// m_pSceneを削除.
				m_pScene = NULL;	// NULLをセット.
				//m_iNo++;	// m_iNoをインクリメント.
				if (m_pGameSystem->GetMode() == 1){
					m_iNo = 1;	// m_iNoを1にする.
				}
				else if (m_pGameSystem->GetMode() == 2){
					m_iNo = 2;	// m_iNoを2にする.
				}
				else if (m_pGameSystem->GetMode() == 3){
					m_iNo = 3;	// m_iNoを3にする.
				}
			}
			else if (iRet == 2){	// 2なら終了.
				m_pScene->ExitScene();	// 終了処理.
				delete m_pScene;	// m_pSceneを削除.
				m_pScene = NULL;	// NULLをセット.
				m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
				m_pMainWnd->Destroy();	// m_pMainWnd->Destroyでウィンドウを閉じる.
			}
		}
	}
	else{	// m_pSceneがNULLでない時.
		iRet = m_pScene->RunScene();	// 処理中.
		if (iRet == 1){	// 1なら次のシーンへ.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			//m_iNo++;	// m_iNoをインクリメント.
			if (m_pGameSystem->GetMode() == 1){
				m_iNo = 1;	// m_iNoを1にする.
			}
			else if (m_pGameSystem->GetMode() == 2){
				m_iNo = 2;	// m_iNoを2にする.
			}
			else if (m_pGameSystem->GetMode() == 3){
				m_iNo = 3;	// m_iNoを3にする.
			}
		}
		else if (iRet == 2){	// 2なら終了.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
			m_pMainWnd->Destroy();	// m_pMainWnd->Destroyでウィンドウを閉じる.
		}
	}

	// 処理したので0.
	return 0;	// 0を返す.

}