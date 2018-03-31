// ヘッダのインクルード
// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// コンストラクタCGameObject()
CGameObject::CGameObject(){

	// メンバの初期化.
	m_pScene = NULL;	// m_pSceneをNULLで初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.
	m_iWidth = 0;	// m_iWidthを0で初期化.
	m_iHeight = 0;	// m_iHeightを0で初期化.
	m_hPen = NULL;	// m_hPenをNULLで初期化.
	m_hOldPen = NULL;	// m_hOldPenをNULLで初期化.
	m_hBrush = NULL;	// m_hBrushをNULLで初期化.
	m_hOldBrush = NULL;	// m_hOldBrushをNULLで初期化.

}

// コンストラクタCGameObject(const CScene *pScene)
CGameObject::CGameObject(const CScene *pScene){

	// メンバの初期化.
	m_pScene = pScene;	// m_pSceneをpSceneで初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.
	m_iWidth = 0;	// m_iWidthを0で初期化.
	m_iHeight = 0;	// m_iHeightを0で初期化.
	m_hPen = NULL;	// m_hPenをNULLで初期化.
	m_hOldPen = NULL;	// m_hOldPenをNULLで初期化.
	m_hBrush = NULL;	// m_hBrushをNULLで初期化.
	m_hOldBrush = NULL;	// m_hOldBrushをNULLで初期化.

}

// デストラクタ~CGameObject()
CGameObject::~CGameObject(){

}

// ゲームオブジェクトの作成Create.(ペンとブラシで描かれた矩形.)
BOOL CGameObject::Create(int x, int y, int iWidth, int iHeight, COLORREF clrPen, COLORREF clrBrush){

	// メンバにセット.
	m_x = x;	// m_xにxを代入.
	m_y = y;	// m_yにyを代入.
	m_iWidth = iWidth;	// m_iWidthにiWidthを代入.
	m_iHeight = iHeight;	// m_oHeightにiHeightを代入.

	// ペンの作成.
	m_hPen = CreatePen(PS_SOLID, 1, clrPen);	// CreatePenでhPenを作成.
	if (m_hPen == NULL){	// 作成失敗.
		return FALSE;	// FALSEを返す.
	}

	// ペンの選択.
	m_hOldPen = (HPEN)SelectObject(m_pScene->m_hMemDC, m_hPen);	// SelectObjectでm_hPenを選択.

	// ブラシの作成.
	m_hBrush = CreateSolidBrush(clrBrush);	// CreateSolidBrushでhBrushを作成.
	if (m_hBrush == NULL){	// 作成失敗.
		SelectObject(m_pScene->m_hMemDC, m_hOldPen);	// SelectObjectでm_hOldPenに戻すr
		m_hOldPen = NULL;	// m_hOldPenにNULLをセット.
		DeleteObject(m_hPen);	// DeleteObjectでm_hPenを破棄.
		m_hPen = NULL;	// m_hPenにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// ブラシの選択.
	m_hOldBrush = (HBRUSH)SelectObject(m_pScene->m_hMemDC, m_hBrush);	// SelectObjectでm_hBrushを選択.

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CGameObject::Destroy(){

	// メンバの終了処理.
	m_x = 0;	// m_xに0を代入.
	m_y = 0;	// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.

	// ブラシを戻す.
	if (m_hOldBrush != NULL){	// m_hOldBrushがNULLでない時.
		SelectObject(m_pScene->m_hMemDC, m_hOldBrush);	// SelectObjectでm_hOldBrushを選択.
		m_hOldBrush = NULL;	// m_hOldBrushにNULLをセット.
	}

	// ブラシの破棄.
	if (m_hBrush != NULL){	// m_hBrushがNULLでない時.
		DeleteObject(m_hBrush);	// DeleteObjectでm_hBrushを破棄.
		m_hBrush = NULL;	// m_hBrushにNULLをセット.
	}

	// ペンを戻す.
	if (m_hOldPen != NULL){	// m_hOldPenがNULLでない時.
		SelectObject(m_pScene->m_hMemDC, m_hOldPen);	// SelectObjectでm_hOldPenを選択.
		m_hOldPen = NULL;	// m_hOldPenにNULLをセット.
	}

	// ペンの破棄.
	if (m_hPen != NULL){	// m_hPenがNULLでない時.
		DeleteObject(m_hPen);	// DeleteObjectでm_hPenを破棄.
		m_hPen = NULL;	// m_hPenにNULLをセット.
	}

}

// ゲームオブジェクトの描画DrawRect.(ペンとブラシで描かれた矩形.)
void CGameObject::DrawRect(int x, int y){

	// ペンの選択.
	SelectObject(m_pScene->m_hMemDC, m_hPen);	// SelectObjectでm_hPenを選択.
	
	// ブラシの選択.
	SelectObject(m_pScene->m_hMemDC, m_hBrush);	// SelectObjectでm_hBrushを選択.

	// 矩形を描画.
	Rectangle(m_pScene->m_hMemDC, x, y, x + m_iWidth, y + m_iHeight);	// Rectangleで矩形を描画.

}