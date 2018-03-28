// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// メンバの初期化.
	m_iSceneNo = 0;	// m_iSceneNoを0で初期化.
	m_iSceneStatus = 0;	// m_iSceneStatusを0で初期化.

}

// ゲームメイン処理関数Main.
int CGameApplication::Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// 変数の初期化.
	int iRet = 0;	// 戻り値iRetを0で初期化.

	// シーンごとに振り分け..
	if (m_iSceneStatus == 0){	// m_iSceneStatusが0ならシーン初期化.
		iRet = InitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// InitSceneで初期化処理.
	}
	else if (m_iSceneStatus == 1){	// m_iSceneStatusが1ならシーン処理中.
		iRet = RunScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// RunSceneで処理中.
	}
	else if (m_iSceneStatus == 2){	// m_iSceneStatusが2ならシーン終了処理.
		iRet = ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitSceneで終了処理.
	}
	else{	// それ以外は何もせず終了.
		// 0を返す.
		return 0;	// 0を返す.
	}

	// 次の状態を決める.
	if (iRet == 1){	// iRetが1なら.(次のシーンへの切り替え.)
		if (m_iSceneStatus <= 1){	// InitまたはRunの場合.
			m_iSceneStatus++;	// m_iSceneStatusを1増やす.
		}
		else{	// Exitの時.
			m_iSceneNo++;	// m_iSceneNoを1増やす.
			m_iSceneStatus = 0;	// m_iSceneStatusを0にする.
		}
	}
	else if (iRet == 2){	// iRetが2なら.(アプリの終了.)
		if (m_iSceneStatus <= 1){	// InitまたはRunの場合.
			ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitSceneで終了処理.
		}
		m_iSceneStatus = -1;	// m_iSceneStatusが-1なら次以降処理しない.
		SendMessage(hWnd, WM_DESTROY, 0, 0);	// SendMessageでWM_DESTROYを送信.
	}

	// 0を返す.
	return 0;	// 0を返す.

}

// シーンの初期化InitScene.
int CGameApplication::InitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// 初期化終了なので1.
	return 1;	// 1を返す.

}

// シーンの処理中RunScene.
int CGameApplication::RunScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// ESCキーを押したら抜ける.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyStateでESCが押されていたら.
		MessageBox(NULL, _T("ESC"), _T("Haiiro"), MB_OK);	// MessageBoxで"ESC"と表示.(長く押すと, 2回以上分になってしまう.)
		return 1;	// 1を返す.
	}

	// 未だ処理中なので0.
	return 0;	// 0を返す.

}

// シーンの終了処理ExitScene.
int CGameApplication::ExitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// m_iSceneNoが3なら終了.
	if (m_iSceneNo == 3){	// m_iSceneNoが3の時.
		// アプリ終了なので2を返す.
		return 2;	// 2を返す.
	}

	// 終了処理なので1.
	return 1;	// 1を返す.

}