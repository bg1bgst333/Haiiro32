// 二重インクルード防止
#ifndef __SHARED_RESOURCES_H__
#define __SHARED_RESOURCES_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
#include <map>	// std::map

// シェアードリソーシズクラスCSharedResources
class CSharedResources{

	// publicメンバ
	public:

		// publicメンバ変数
		std::map<int, HGDIOBJ> m_mapSharedResourceMap;	// シェアードリソースマップm_mapSharedResourceMap.
		HINSTANCE m_hInstance;	// アプリケーションインスタンスハンドルm_hInstance.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CSharedResources(HINSTANCE hInstance);	// コンストラクタCSharedResources
		virtual ~CSharedResources();	// デストラクタ~CSharedResources
		void Add(int nID);	// リソースを追加Add.
		void Remove(int nID);	// リソースを削除Remove.
		void RemoveAll();	// リソースを全削除RemoveAll.
		HGDIOBJ Get(int nID);	// リソースを取得Get.

};

#endif