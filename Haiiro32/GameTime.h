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
		DWORD m_dwFrameIntervalMilliTime;	// 1フレーム間にかかる時間m_dwFrameIntervalMilliTime.
		DWORD m_dwFrameIntervalStart;	// 1フレームの開始m_dwFrameIntervalStart.
		DWORD m_dwFrame;	// フレーム数m_dwFrame.
		DWORD m_dwRunFrame;	// 実行フレーム数m_dwRunFrame.
		DWORD m_dwFPS;	// FPS値m_dwFPS.
		DWORD m_dwFrameStartMilliTime;	// フレーム計測開始時間m_dwFrameStartMilliTime.
		DWORD m_dwTargetFPS;	// 目標FPS値m_dwTargetFPS.
		DWORD m_dwRunFPS;	// 実行FPS値m_dwRunFPS.

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
		DWORD GetRunFPS();	// 実行FPS値の取得GetRunFPS.
		DWORD GetFrameIntervalMilliTime();	// フレーム間隔を取得GetFrameIntervalMilliTime.
		void SetTargetFPS(DWORD dwTargetFPS);	// 目標FPS値の設定SetTargetFPS.
		BOOL IsProc();	// 処理するかどうかを判定IsProc.

};

#endif