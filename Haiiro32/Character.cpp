// ヘッダのインクルード
// 独自のヘッダ
#include "Character.h"	// CCharacter
#include "resource.h"	// リソース.

// コンストラクタCCharacter()
CCharacter::CCharacter() : CSharedObject(){

}

// デストラクタCCharacter(CScene *pScene)
CCharacter::CCharacter(CScene *pScene) : CSharedObject(pScene){

}

// デストラクタ~CCharacter()
CCharacter::~CCharacter(){

	// 破棄.
	Destroy();	// Destroyで破棄.

}

// アニメーションの追加Add.
void CCharacter::Add(int sx, int sy, int iWidth, int iHeight, int nID){

	// 子オブジェクトを生成して追加.
	CSharedObject *pSharedObject = new CSharedObject(m_pScene);			// CSharedObjectオブジェクトを生成.
	pSharedObject->Create(sx, sy, iWidth, iHeight, nID);	// Createで生成.
	m_vecpSharedObjectList.push_back(pSharedObject);	// push_backで追加.

}

// キャラクターの破棄Destroy.
void CCharacter::Destroy(){

	// 子オブジェクトを破棄.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpSharedObjectList.begin(); itor != m_vecpSharedObjectList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	m_vecpSharedObjectList.clear();	// クリア.

}

// シェアードオブジェクトの描画Draw.
void CCharacter::Draw(int x, int y, int iNo){

	// iNo番目を描画.
	m_vecpSharedObjectList[iNo]->Draw(x, y);	// m_vecpSharedObjectList[iNo]->Drawで描画.

}