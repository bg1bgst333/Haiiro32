// ヘッダのインクルード
// 独自のヘッダ
#include "GameTime.h"	// CGameTime

// コンストラクタCGameTime
CGameTime::CGameTime(){

	// メンバの初期化.
	m_dwMilliTime = 0;	// m_dwMilliTimeを0で初期化.
	m_dwUserMilliTime = 0;	// m_dwUserMilliTimeを0で初期化.
	m_dwUserStartMilliTime = 0;	// m_dwUserStartMilliTimeを0で初期化.
	m_dwFrame = 0;	// m_dwFrameを0で初期化.
	m_dwFrameStartMilliTime = 0;	// m_dwFrameStartMilliTimeを0で初期化.
	m_dwFPS = 0;	// m_dwFPSを0で初期化.

}

// デストラクタ~CGameTime
CGameTime::~CGameTime(){

	// メンバの終了処理.
	m_dwMilliTime = 0;	// m_dwMilliTimeを0にセット.
	m_dwUserMilliTime = 0;	// m_dwUserMilliTimeを0で初期化.
	m_dwUserStartMilliTime = 0;	// m_dwUserStartMilliTimeを0で初期化.
	m_dwFrame = 0;	// m_dwFrameを0で初期化.
	m_dwFrameStartMilliTime = 0;	// m_dwFrameStartMilliTimeを0で初期化.
	m_dwFPS = 0;	// m_dwFPSを0で初期化.

}

// システム時刻をミリ秒で返すGetSystemTime.
DWORD CGameTime::GetSystemTime(){

	// システム時刻を返す.
	m_dwMilliTime = timeGetTime();	// timeGetTimeの値をm_dwMilliTimeに格納.
	return m_dwMilliTime;	// m_dwMilliTimeを返す.

}

// ユーザ時刻をミリ秒で返すGetUserTime.
DWORD CGameTime::GetUserTime(){

	// ユーザ時刻を返す.
	m_dwUserMilliTime = GetSystemTime() - m_dwUserStartMilliTime;	// GetSystemTime() - m_dwUserStartMilliTimeでユーザタイム算出.
	return m_dwUserMilliTime;	// m_dwUserMilliTimeを返す.

}

// ユーザ時刻のリセットResetUserTime.
void CGameTime::ResetUserTime(){

	// スタート時刻を現在時刻にする.
	m_dwUserStartMilliTime = GetSystemTime();	// m_dwUserStartMilliTimeにGetSystemTime()の値をセット.

}

// フレーム数のカウントCountFrame.
void CGameTime::CountFrame(){

	// フレーム数のカウント.
	m_dwFrame++;	// m_dwFrameをインクリメント.

}

// フレーム数のリセットResetFrame.
void CGameTime::ResetFrame(){

	// フレーム数のリセット.
	m_dwFrame = 0;	// m_dwFrameを0にリセット.
	m_dwFrameStartMilliTime = GetUserTime();	// m_dwFrameStartMilliTimeにGetUserTimeの値をセット.

}

// 1秒経過したかどうかIsNextSecond.
BOOL CGameTime::IsNextSecond(){

	// 1秒経過したかチェック.
	if (GetUserTime() - m_dwFrameStartMilliTime >= 1000){	// 1秒以上差があったら.
		m_dwFPS = m_dwFrame;	// m_dwFPSにm_dwFrameを代入.
		return TRUE;	// TRUEを返す.
	}
	else{
		return FALSE;	// FALSEを返す.
	}

}

// FPS値の取得GetFPS.
DWORD CGameTime::GetFPS(){

	// FPSを返す.
	return m_dwFPS;	// m_dwFPSを返す.

}