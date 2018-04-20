// ヘッダのインクルード
// 独自のヘッダ
#include "SharedResources.h"	// CSharedResources

// コンストラクタCSharedResources
CSharedResources::CSharedResources(HINSTANCE hInstance){

	// メンバの初期化.
	m_mapSharedResourceMap.clear();	// m_mapSharedResourceMap.clearでクリア.
	m_hInstance = hInstance;	// m_hInstanceをhInstanceで初期化.

}

// デストラクタ~CSharedResources
CSharedResources::~CSharedResources(){

	// メンバの終了処理.
	RemoveAll();	// RemoveAllで全削除.
	m_hInstance = NULL;	// m_hInstanceにNULLをセット.

}

// リソースを追加Add.
void CSharedResources::Add(int nID){

	// 指定のIDのリソース(ここではビットマップとする.)をロードし, マップに追加.
	HGDIOBJ hObj = LoadImage(m_hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);	// LoadImageでロード.
	if (hObj != NULL){	// NULLじゃなければ.
		m_mapSharedResourceMap.insert(std::make_pair<int, HGDIOBJ>(nID, hObj));	// m_mapSharedResourceMap.insertで(nID, hObj)の組を追加.
	}

}

// リソースを削除Remove.
void CSharedResources::Remove(int nID){

	// nIDからhBitmapを引く.
	std::map<int, HGDIOBJ>::iterator itor = m_mapSharedResourceMap.find(nID);	// itorの取得.
	if (itor != m_mapSharedResourceMap.end()){	// みつかったら.
		HGDIOBJ hObj = m_mapSharedResourceMap[nID];	// m_mapSharedResourceMap[nID]でhBitmapを取得.
		DeleteObject(hObj);	// DeleteObjectでhObjを削除.
		m_mapSharedResourceMap.erase(itor);	// m_mapSharedResourceMap.eraseでitorを削除.
	}

}

// リソースを全削除RemoveAll.
void CSharedResources::RemoveAll(){

	// すべて削除.
	for (std::map<int, HGDIOBJ>::iterator itor = m_mapSharedResourceMap.begin(); itor !=  m_mapSharedResourceMap.end(); itor++){	// すべて列挙.
		DeleteObject(itor->second);	// DeleteObjectでitor->secondを削除.
		itor->second = NULL;	// itor->secondにNULLをセット.
	}
	m_mapSharedResourceMap.clear();	// m_mapSharedResourceMap.clearで削除.

}

// リソースを取得Get.
HGDIOBJ CSharedResources::Get(int nID){

	// nIDからhBitmapを引く.
	std::map<int, HGDIOBJ>::iterator itor = m_mapSharedResourceMap.find(nID);	// itorの取得.
	if (itor != m_mapSharedResourceMap.end()){	// みつかったら.
		return m_mapSharedResourceMap[nID];	// m_mapSharedResourceMap[nID]を返す.
	}
	else{
		return NULL;	// NULLを返す.
	}

}