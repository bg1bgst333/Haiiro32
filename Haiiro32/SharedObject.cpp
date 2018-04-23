// ヘッダのインクルード
// 独自のヘッダ
#include "SharedObject.h"	// CSharedObject

// コンストラクタCSharedObject
CSharedObject::CSharedObject(){

	// メンバの初期化.
	m_pScene = NULL;	// m_pSceneにNULLをセット.
	m_x = 0;	// m_xに0をセット.
	m_y = 0;	// m_yに0をセット.
	m_iWidth = 0;	// m_iWidthに0をセット.
	m_iHeight = 0;	// m_iHeightに0をセット.
	m_nID = 0;	// m_nIDに0をセット.
	m_sx = 0;	// m_sxに0をセット.
	m_sy = 0;	// m_syに0をセット.
	m_vecpSharedObjectList.clear();	// m_vecpSharedObjectListでクリア.

}

// コンストラクタCSharedObject(CScene *pScene)
CSharedObject::CSharedObject(CScene *pScene){

	// メンバの初期化.
	m_pScene = pScene;	// m_pSceneにpSceneをセット.
	m_x = 0;	// m_xに0をセット.
	m_y = 0;	// m_yに0をセット.
	m_iWidth = 0;	// m_iWidthに0をセット.
	m_iHeight = 0;	// m_iHeightに0をセット.
	m_nID = 0;	// m_nIDに0をセット.
	m_sx = 0;	// m_sxに0をセット.
	m_sy = 0;	// m_syに0をセット.
	m_vecpSharedObjectList.clear();	// m_vecpSharedObjectListでクリア.

}

// デストラクタ~CSharedObject
CSharedObject::~CSharedObject(){

}

// シェアードオブジェクトの作成Create.
BOOL CSharedObject::Create(int sx, int sy, int iWidth, int iHeight, int nID){

	// メンバのセット.
	m_sx = sx;	// m_sxにsxをセット.
	m_sy = sy;	// m_syにsyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.
	m_nID = nID;	// m_nIDにnIDをセット.

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// シェアードオブジェクトの破棄Destroy.
void CSharedObject::Destroy(){

	// メンバのリセット.
	m_sx = 0;	// m_sxに0をセット.
	m_sy = 0;	// m_syに0をセット.
	m_iWidth = 0;	// m_iWidthに0をセット.
	m_iHeight = 0;	// m_iHeightに0をセット.
	m_nID = 0;	// m_nIDに0をセット.

}

// シェアードオブジェクトの描画Draw.
void CSharedObject::Draw(int x, int y){

	// 描画.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	HDC hMemDC = m_pScene->m_pSharedImageBuffer->Get(m_nID);	// 指定のIDのバッファを取得.
	BitBlt(m_pScene->m_hMemDC, x, y, m_iWidth, m_iHeight, hMemDC, m_sx, m_sy, SRCCOPY);	// BitBltでバックバッファに転送.

}