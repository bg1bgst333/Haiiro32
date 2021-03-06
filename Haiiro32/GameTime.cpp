// ヘッダのインクルード
// 独自のヘッダ
#include "GameTime.h"	// CGameTime

// コンストラクタCGameTime
CGameTime::CGameTime(){

	// メンバの初期化.
	m_dwMilliTime = 0;	// m_dwMilliTimeを0で初期化.
	m_dwUserMilliTime = 0;	// m_dwUserMilliTimeを0で初期化.
	m_dwUserStartMilliTime = 0;	// m_dwUserStartMilliTimeを0で初期化.
	m_dwFrameIntervalMilliTime = 0;	// m_dwFrameIntervalMilliTimeを0で初期化.
	m_dwFrameIntervalStart = 0;	// m_dwFrameIntervalStartを0で初期化.
	m_dwFrame = 0;	// m_dwFrameを0で初期化.
	m_dwRunFrame = 0;	// m_dwRunFrameを0で初期化.
	m_dwFrameStartMilliTime = 0;	// m_dwFrameStartMilliTimeを0で初期化.
	m_dwFPS = 0;	// m_dwFPSを0で初期化.
	m_dwTargetFPS = 0;	// m_dwTargetFPSを0で初期化.
	m_dwRunFPS = 0;	// m_dwRunFPSを0で初期化.

}

// デストラクタ~CGameTime
CGameTime::~CGameTime(){

	// メンバの終了処理.
	m_dwMilliTime = 0;	// m_dwMilliTimeを0にセット.
	m_dwUserMilliTime = 0;	// m_dwUserMilliTimeを0で初期化.
	m_dwUserStartMilliTime = 0;	// m_dwUserStartMilliTimeを0で初期化.
	m_dwFrameIntervalMilliTime = 0;	// m_dwFrameIntervalMilliTimeを0で初期化.
	m_dwFrameIntervalStart = 0;	// m_dwFrameIntervalStartを0で初期化.
	m_dwFrame = 0;	// m_dwFrameを0で初期化.
	m_dwRunFrame = 0;	// m_dwRunFrameを0で初期化.
	m_dwFrameStartMilliTime = 0;	// m_dwFrameStartMilliTimeを0で初期化.
	m_dwFPS = 0;	// m_dwFPSを0で初期化.
	m_dwTargetFPS = 0;	// m_dwTargetFPSを0で初期化.
	m_dwRunFPS = 0;	// m_dwRunFPSを0で初期化.

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
	m_dwRunFrame = 0;	// m_dwRunFrmeを0にリセット.

}

// 1秒経過したかどうかIsNextSecond.
BOOL CGameTime::IsNextSecond(){

	// フレーム間隔取得.
	BOOL bRet = FALSE;	// 戻り値bRet.
	DWORD dwUserTime = GetUserTime();	// ユーザ時刻取得.
	// 1秒経過したかチェック.
	if (dwUserTime - m_dwFrameStartMilliTime >= 1000){	// 1秒以上差があったら.
		m_dwFPS = m_dwFrame;	// m_dwFPSにm_dwFrameを代入.
		m_dwRunFPS = m_dwRunFrame;	// m_dwRunFPSにm_dwRunFrameを代入.
		bRet = TRUE;	// TRUEを返す.
	}
	else{
		bRet = FALSE;	// FALSEを返す.
	}
	m_dwFrameIntervalMilliTime = dwUserTime - m_dwFrameIntervalStart;	// 現在時刻からフレーム間隔開始秒を引く.
	DWORD dwSleep = 1000 / m_dwTargetFPS;	// Sleepミリ秒を計算.
	m_dwFrameIntervalStart = dwUserTime;	// 現在時刻に更新.
	if (m_dwFrameIntervalMilliTime <= dwSleep){	// Sleepより間隔が小さい場合.
		Sleep(dwSleep - m_dwFrameIntervalMilliTime);	// スリープ.(スリープ時間からフレーム間隔を引いた時間.)
	}
	return bRet;	// bRetを返す.

}

// FPS値の取得GetFPS.
DWORD CGameTime::GetFPS(){

	// FPSを返す.
	return m_dwFPS;	// m_dwFPSを返す.

}

// 実行FPS値の取得GetRunFPS.
DWORD CGameTime::GetRunFPS(){

	// 実行FPSを返す.
	return m_dwRunFPS;	// m_dwRunFPSを返す.

}

// フレーム間隔を取得GetFrameIntervalMilliTime.
DWORD CGameTime::GetFrameIntervalMilliTime(){

	// フレーム間隔を返す.
	return m_dwFrameIntervalMilliTime;

}

// 目標FPS値の設定SetTargetFPS.
void CGameTime::SetTargetFPS(DWORD dwTargetFPS){

	// メンバにセット.
	m_dwTargetFPS = dwTargetFPS;	// m_dwTargetFPSにdwTargetFPSをセット.

}

// 処理するかどうかを判定IsProc.
BOOL CGameTime::IsProc(){

	// 1つのフレーム以外は処理をしないようにする.
	DWORD dwNowFrame = m_dwFPS / m_dwTargetFPS;	// 現在余計なものを含めたフレームはdwNowFrame.
	if (m_dwFPS <= m_dwTargetFPS){	// FPSが少ない場合はTRUEとして処理をまわす.
		m_dwRunFrame++;	// m_dwRunFrameをインクリメント.
		return TRUE;	// TRUEを返す.
	}
	if ((m_dwFrame % dwNowFrame) == 0){	// dwNowFrameの時だけ処理する.
		m_dwRunFrame++;	// m_dwRunFrameをインクリメント.
		return TRUE;	// TRUEを返す.
	}
	else{
		return FALSE;	// FALSEを返す.
	}

}