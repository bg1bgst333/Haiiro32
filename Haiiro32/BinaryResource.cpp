// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryResource.h"	// CBinaryResource

// コンストラクタCBinaryResource
CBinaryResource::CBinaryResource(){

	// メンバの初期化
	m_pBytes = NULL;	// m_pBytesにNULLをセット.
	m_dwSize = 0;		// m_dwSizeに0をセット.
	m_dwPos = 0;	// m_dwPosに0をセット.

}

// デストラクタ~CBinaryResource
CBinaryResource::~CBinaryResource(){

	// メンバの終了処理
	m_pBytes = NULL;	// m_pBytesにNULLをセット.
	m_dwSize = 0;	// m_dwSizeに0をセット.
	m_dwPos = 0;	// m_dwPosに0をセット.

}

// 指定のリソースを読み込むLoad.
BOOL CBinaryResource::Load(HWND hWnd, int nID, LPCTSTR lpctszType){

	// アプリケーションインスタンスの取得.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// hInstanceを取得.
	if (hInstance == NULL){
		return FALSE;
	}

	// リソースを探す.
	HRSRC hRes = FindResource(hInstance, MAKEINTRESOURCE(nID), lpctszType);	// hResを取得.
	if (hRes == NULL){
		return FALSE;
	}

	// リソースのロード.
	HGLOBAL hGlobal = LoadResource(hInstance, hRes);	// hGlobalの取得.
	if (hGlobal == NULL){
		return FALSE;
	}

	// リソースのロック.
	m_pBytes = (BYTE *)LockResource(hGlobal);	// m_pBytesにリソースポインタを格納.
	if (m_pBytes == NULL){
		return FALSE;
	}

	// サイズを取得.
	m_dwSize = SizeofResource(hInstance, hRes);	// m_dwSizeを取得.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// 指定のサイズデータへのポインタを取得Get.
const LPVOID CBinaryResource::Get(DWORD dwSize){

	// ポインタを返す.
	const LPVOID p = (const LPVOID)&m_pBytes[m_dwPos];
	m_dwPos = m_dwPos + dwSize;	// dwSize移動.
	return p;	// pを返す.

}