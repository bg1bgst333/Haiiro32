// ヘッダのインクルード
// 独自のヘッダ
#include "GameTime.h"	// CGameTime

// コンストラクタCGameTime
CGameTime::CGameTime(){

	// メンバの初期化.
	m_dwMilliTime = 0;	// m_dwMilliTimeを0で初期化.

}

// デストラクタ~CGameTime
CGameTime::~CGameTime(){

	// メンバの終了処理.
	m_dwMilliTime = 0;	// m_dwMilliTimeを0にセット..

}

// システム時刻をミリ秒で返すGet.
DWORD CGameTime::Get(){

	// システム時刻を返す.
	m_dwMilliTime = timeGetTime();	// timeGetTimeの値をm_dwMilliTimeに格納.
	return m_dwMilliTime;	// m_dwMilliTimeを返す.

}