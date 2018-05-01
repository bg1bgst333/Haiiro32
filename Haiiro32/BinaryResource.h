// 二重インクルード防止
#ifndef __BINARY_RESOURCE_H__
#define __BINARY_RESOURCE_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// バイナリリソースクラスCBinaryResource
class CBinaryResource{

	// publicメンバ
	public:

		// publicメンバ変数
		BYTE *m_pBytes;	// バイト列へのポインタ.
		DWORD m_dwSize;	// リソースサイズ.
		DWORD m_dwPos;	// 現在の読み込み位置.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBinaryResource();	// コンストラクタCBinaryResource
		virtual ~CBinaryResource();	// デストラクタ~CBinaryResource
		virtual BOOL Load(HWND hWnd, int nID, LPCTSTR lpctszType);	// 指定のリソースを読み込むLoad.
		virtual const LPVOID Get(DWORD dwSize);	// 指定のサイズデータへのポインタを取得Get.

};

#endif