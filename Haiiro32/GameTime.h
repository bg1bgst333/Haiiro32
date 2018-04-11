// 二重インクルード防止
#ifndef __GAME_TIME_H__
#define __GAME_TIME_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
#include <mmsystem.h>	// マルチメディア

// ゲームタイムクラスCGameTime
class CGameTime{

	// publicメンバ
	public:

		// publicメンバ変数
		DWORD m_dwMilliTime;	// ミリ秒m_dwMilliTime.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CGameTime();	// コンストラクタCGameTime
		virtual ~CGameTime();	// デストラクタ~CGameTime
		// メンバ関数
		DWORD Get();	// システム時刻をミリ秒で返すGet.

};

#endif