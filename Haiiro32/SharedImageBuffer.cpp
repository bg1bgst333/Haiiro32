// ヘッダのインクルード
// 独自のヘッダ
#include "SharedImageBuffer.h"	// CSharedImageBuffer

// コンストラクタCSharedImageBuffer
CSharedImageBuffer::CSharedImageBuffer(CSharedResources *pSharedResources, HDC hDC){

	// メンバの初期化.
	m_mapSharedImageBufferMap.clear();	// m_mapSharedImageBufferMap.clearでクリア.
	m_pSharedResources = pSharedResources;	// m_pSharedResourcesにpSharedResourcesをセット.
	m_hDC = hDC;	// m_hDCにhDCをセット.

}

// デストラクタ~CSharedImageBuffer
CSharedImageBuffer::~CSharedImageBuffer(){

	// メンバの終了処理.
	RemoveAll();	// RemoveAllで全削除.

}

// メモリデバイスコンテキストを追加Add.
void CSharedImageBuffer::Add(int nID){

	// メモリデバイスコンテキストを作成し, ビットマップと紐付ける.
	HDC hMemDC = CreateCompatibleDC(m_hDC);	// hMemDCを生成.
	if (hMemDC != NULL){	// NULLじゃなければ.
		HBITMAP hBitmap = (HBITMAP)m_pSharedResources->Get(nID);
		SelectObject(hMemDC, hBitmap);	// SelectObjectでhMemDCにhBitmapを選択.
		m_mapSharedImageBufferMap.insert(std::make_pair<int, HDC>(nID, hMemDC));	// (nID, hMemDC)の組を登録.
	}

}

// メモリデバイスコンテキストを削除Remove.
void CSharedImageBuffer::Remove(int nID){

	// nIDからhMemDCを引く.
	std::map<int, HDC>::iterator itor = m_mapSharedImageBufferMap.find(nID);	// itorの取得.
	if (itor != m_mapSharedImageBufferMap.end()){	// みつかったら.
		HDC hMemDC = m_mapSharedImageBufferMap[nID];	// m_mapSharedImageBufferMap[nID]でhMemDCを取得.
		DeleteDC(hMemDC);	// DeleteDCでhMemDCを削除.
		m_mapSharedImageBufferMap.erase(itor);	// m_mapSharedImageBufferMap.eraseでitorを削除.
	}

}

// メモリデバイスコンテキストを全削除RemoveAll.
void CSharedImageBuffer::RemoveAll(){

	// すべて削除.
	for (std::map<int, HDC>::iterator itor = m_mapSharedImageBufferMap.begin(); itor !=  m_mapSharedImageBufferMap.end(); itor++){	// すべて列挙.
		DeleteDC(itor->second);	// DeleteDCでitor->secondを削除.
		itor->second = NULL;	// itor->secondにNULLをセット.
	}
	m_mapSharedImageBufferMap.clear();	// m_mapSharedImageBufferMap.clearで削除.

}

// メモリデバイスコンテキストを取得Get.
HDC CSharedImageBuffer::Get(int nID){

	// nIDからhDCを引く.
	std::map<int, HDC>::iterator itor = m_mapSharedImageBufferMap.find(nID);	// itorの取得.
	if (itor != m_mapSharedImageBufferMap.end()){	// みつかったら.
		return m_mapSharedImageBufferMap[nID];	// m_mapSharedImageBufferMap[nID]を返す.
	}
	else{
		return NULL;	// NULLを返す.
	}

}