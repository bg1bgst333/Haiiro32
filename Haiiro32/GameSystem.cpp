// ヘッダのインクルード
// 独自のヘッダ
#include "GameSystem.h"	// CGameSystem

// コンストラクタCGameSystem
CGameSystem::CGameSystem(){

	// メンバの初期化.
	m_iMode = 0;	// m_iModeを0で初期化.
	m_pSharedResources = NULL;	// m_pSharedResourcesをNULLで初期化.

}

// デストラクタ~CGameSystem
CGameSystem::~CGameSystem(){

	// メンバの終了処理.
	m_iMode = 0;	// m_iModeに0をセット.
	Exit();	// 終了処理.

}

// モードの設定SetMode.
void CGameSystem::SetMode(int iMode){

	// メンバに設定.
	m_iMode = iMode;	// m_iModeにiModeをセット.

}

// モードの取得GetMode.
int CGameSystem::GetMode(){

	// メンバを取得.
	return m_iMode;	// m_iModeを返す.

}

// 初期化.
void CGameSystem::Init(HINSTANCE hInstance){

	// シェアードリソース生成.
	m_pSharedResources = new CSharedResources(hInstance);	// CSharedResourcesのコンストラクタにhInstanceを渡して生成.

}

// 終了処理.
void CGameSystem::Exit(){

	// シェアードリソース破棄.
	if (m_pSharedResources != NULL){	// m_pSharedResourcesがNULL.
		delete m_pSharedResources;	// deleteでm_pSharedResourcesを削除.
		m_pSharedResources = NULL;	// m_pSharedResourcesにNULLをセット.
	}

}