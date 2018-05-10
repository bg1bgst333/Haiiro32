// ヘッダのインクルード
// 独自のヘッダ
#include "Shot.h"	// CShot
#include "resource.h"	// リソース.

// コンストラクタCShot()
CShot::CShot() : CSharedObject(){

}

// デストラクタCShot(CScene *pScene)
CShot::CShot(CScene *pScene) : CSharedObject(pScene){

}

// デストラクタ~CShot()
CShot::~CShot(){

	// 破棄.
	Destroy();	// Destroyで破棄.

}

// アニメーションの追加Add.
void CShot::Add(int sx, int sy, int iWidth, int iHeight, int nID){

	// 子オブジェクトを生成して追加.
	CSharedObject *pSharedObject = new CSharedObject(m_pScene);			// CSharedObjectオブジェクトを生成.
	pSharedObject->Create(sx, sy, iWidth, iHeight, nID);	// Createで生成.
	m_vecpSharedObjectList.push_back(pSharedObject);	// push_backで追加.

}

// マスクの追加AddMask.
void CShot::AddMask(int sx, int sy, int iWidth, int iHeight, int nID){

	// マスクの生成と追加.
	CSharedObject *pMask = new CSharedObject(m_pScene);			// CSharedObjectオブジェクトを生成.
	pMask->Create(sx, sy, iWidth, iHeight, nID);	// Createで生成.
	m_vecpMaskList.push_back(pMask);	// push_backで追加.

}

// ショットの破棄Destroy.
void CShot::Destroy(){

	// 子オブジェクトを破棄.
	// マスク.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpMaskList.begin(); itor != m_vecpMaskList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	// イメージ.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpSharedObjectList.begin(); itor != m_vecpSharedObjectList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	m_vecpMaskList.clear();	// クリア.
	m_vecpSharedObjectList.clear();	// クリア.

}

// シェアードオブジェクトの描画Draw.
void CShot::Draw(int x, int y, int iNo){

	// iNo番目を描画.
	m_vecpSharedObjectList[iNo]->Draw(x, y);	// m_vecpSharedObjectList[iNo]->Drawで描画.

}

// スプライトの描画DrawSprite.
void CShot::DrawSprite(int x, int y, int iNo){

	// 描画.
	m_vecpSharedObjectList[iNo]->m_x = x;	// m_vecpSharedObjectList[iNo]->m_xにxをセット.
	m_vecpSharedObjectList[iNo]->m_y = y;	// m_vecpSharedObjectList[iNo]->m_yにyをセット.
	HDC hMemDC = m_vecpSharedObjectList[iNo]->m_pScene->m_pSharedImageBuffer->Get(m_vecpSharedObjectList[iNo]->m_nID);	// hMemDCを取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = m_vecpSharedObjectList[iNo]->m_iWidth;	// m_iWidthのセット.
	m_iHeight = m_vecpSharedObjectList[iNo]->m_iHeight;	// m_iHeightのセット.
	m_sx = m_vecpSharedObjectList[iNo]->m_sx;	// m_sxのセット.
	m_sy = m_vecpSharedObjectList[iNo]->m_sy;	// m_syのセット.
	HDC hMaskMemDC = m_vecpMaskList[iNo]->m_pScene->m_pSharedImageBuffer->Get(m_vecpMaskList[iNo]->m_nID);	// hMasMemDCを取得.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, hMaskMemDC, m_vecpMaskList[iNo]->m_sx, m_vecpMaskList[iNo]->m_sy, SRCPAINT);	// マスクをSRCPAINT.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, hMemDC, m_sx, m_sy, SRCAND);	// SRCANDでメインイメージを描画.

}