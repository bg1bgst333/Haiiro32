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
		DWORD m_dwUserMilliTime;	// 任意の時間からのミリ秒m_dwUserMilliTime.
		DWORD m_dwUserStartMilliTime;	// 任意の開始時間m_dwUserStartMilliTime.
		DWORD m_dwFrame;	// フレーム数m_dwFrame.
		DWORD m_dwFPS;	// FPS値m_dwFPS.
		DWORD m_dwFrameStartMilliTime;	// フレーム計測開始時間m_dwFrameStartMilliTime.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CGameTime();	// コンストラクタCGameTime
		virtual ~CGameTime();	// デストラクタ~CGameTime
		// メンバ関数
		DWORD GetSystemTime();	// システム時刻をミリ秒で返すGetSystemTime.
		DWORD GetUserTime();	// ユーザ時刻をミリ秒で返すGetUserTime.
		void ResetUserTime();	// ユーザ時刻のリセットResetUserTime.
		void CountFrame();	// フレーム数のカウントCountFrame.
		void ResetFrame();	// フレーム数のリセットResetFrame.
		BOOL IsNextSecond();	// 1秒経過したかどうかIsNextSecond.
		DWORD GetFPS();	// FPS値の取得GetFPS.

};

#endif