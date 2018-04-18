// 二重インクルード防止
#ifndef __GAME_SYSTEM_H__
#define __GAME_SYSTEM_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// ゲームシステムクラスCGameSystem
class CGameSystem{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_iMode;	// モードm_iMode.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CGameSystem();	// コンストラクタCGameSystem
		virtual ~CGameSystem();	// デストラクタ~CGameSystem
		// メンバ関数
		void SetMode(int iMode);	// モードの設定SetMode.
		int GetMode();	// モードの取得GetMode.

};

#endif