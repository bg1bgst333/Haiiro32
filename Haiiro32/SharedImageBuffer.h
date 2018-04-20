// 二重インクルード防止
#ifndef __SHARED_IMAGE_BUFFER_H__
#define __SHARED_IMAGE_BUFFER_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
#include <map>	// std::map
// 独自のヘッダ
#include "SharedResources.h"	// CSharedResources

// シェアードイメージバッファCSharedImageBuffer
class CSharedImageBuffer{

	// publicメンバ
	public:

		// publicメンバ変数
		std::map<int, HDC> m_mapSharedImageBufferMap;	// シェアードイメージバッファマップm_mapSharedImageBufferMap.
		CSharedResources *m_pSharedResources;	// CSharedResourcesオブジェクトポインタm_pSharedResources.
		HDC m_hDC;	// ベースデバイスコンテキストハンドルm_hDC.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CSharedImageBuffer(CSharedResources *pSharedResources, HDC hDC);	// コンストラクタCSharedImageBuffer
		virtual ~CSharedImageBuffer();	// デストラクタ~CSharedImageBuffer
		void Add(int nID);	// メモリデバイスコンテキストを追加Add.
		void Remove(int nID);	// メモリデバイスコンテキストを削除Remove.
		void RemoveAll();	// メモリデバイスコンテキストを全削除RemoveAll.
		HDC Get(int nID);	// メモリデバイスコンテキストを取得Get.

};

#endif