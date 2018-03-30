// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// メンバの初期化.
	m_pScene = NULL;	// m_pSceneをNULLで初期化.
	m_iNo = 0;	// m_iNoを0で初期化.

}

// ゲームメイン処理関数Main.
int CGameApplication::Main(){

	// 変数の初期化.
	int iRet = 0;	// iRetを0で初期化.
	CScene *pScene = NULL;	// pSceneをNULLで初期化.

	// 生成.
	if (m_iNo == 0 && m_pScene == NULL){	// m_iNoが0で生成されていない時.
		pScene = new CScene(m_pMainWnd);	// CSceneを生成し, pSceneに格納.(m_pMainWndを渡す.)
	}
	else if (m_iNo == 1 && m_pScene == NULL){	// m_iNoが1で生成されていない時.
		pScene = new CScene(m_pMainWnd);	// CSceneを生成し, pSceneに格納.(m_pMainWndを渡す.)
	}
	else if (m_iNo == 2 && m_pScene == NULL){	// m_iNoが2で生成されていない時.
		pScene = new CScene(m_pMainWnd);	// CSceneを生成し, pSceneに格納.(m_pMainWndを渡す.)
	}

	if (m_pScene == NULL){	// m_pSceneがNULLの時.	
		m_pScene = pScene;	// pSceneを格納.
		iRet = m_pScene->InitScene();	// 成功なら0を返す.
		if (iRet == -1){	// -1の時.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
			SendMessage(m_pMainWnd->m_hWnd, WM_DESTROY, 0, 0);	// WM_DESTROYを送信して終了.
		}
		else{	// 0の時.
			iRet = m_pScene->RunScene();	// 処理中.
			if (iRet == 1){	// 1なら次のシーンへ.
				m_pScene->ExitScene();	// 終了処理.
				delete m_pScene;	// m_pSceneを削除.
				m_pScene = NULL;	// NULLをセット.
				m_iNo++;	// m_iNoをインクリメント.
			}
			else if (iRet == 2){	// 2なら終了.
				m_pScene->ExitScene();	// 終了処理.
				delete m_pScene;	// m_pSceneを削除.
				m_pScene = NULL;	// NULLをセット.
				m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
				SendMessage(m_pMainWnd->m_hWnd, WM_DESTROY, 0, 0);	// WM_DESTROYを送信して終了.
			}
		}
	}
	else{	// m_pSceneがNULLでない時.
		iRet = m_pScene->RunScene();	// 処理中.
		if (iRet == 1){	// 1なら次のシーンへ.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo++;	// m_iNoをインクリメント.
		}
		else if (iRet == 2){	// 2なら終了.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
			SendMessage(m_pMainWnd->m_hWnd, WM_DESTROY, 0, 0);	// WM_DESTROYを送信して終了.
		}
	}

	// 処理したので0.
	return 0;	// 0を返す.

}