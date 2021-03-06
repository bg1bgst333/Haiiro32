// 二重インクルード防止
#ifndef __GAME_TIME_BOX_H__
#define __GAME_TIME_BOX_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string

// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// ゲームタイムボックスクラスCGameTimeBox
class CGameTimeBox : public CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		HFONT m_hFont;	// フォントm_hFont.
		HFONT m_hOldFont;	// 以前のフォントm_hOldFont.
		DWORD m_dwTime;	// 時刻(ミリ秒)m_dwTime.
		DWORD m_dwFPS;	// FPS値m_dwFPS.
		DWORD m_dwRunFPS;	// 実行FPS値m_dwRunFPS.
		DWORD m_dwFrameIntervalMilliTime;	// フレーム間隔m_dwFrameIntervalMilliTime.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CGameTimeBox();	// コンストラクタCGameTimeBox
		CGameTimeBox(const CScene *pScene);	// コンストラクタCGameTimeBox(const CScene *pScene)
		virtual ~CGameTimeBox();	// デストラクタ~CGameTimeBox
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName);	// ゲームオブジェクトの作成Create.
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual int Proc();	// 処理をするProc.
		virtual void DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor);	// DrawTextでテキストを描画.
		virtual void DrawTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawTimeで時間を描画.
		virtual void DrawFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawFPSでFPSを描画.
		virtual void DrawRunFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawRunFPSで実行FPSを描画.
		virtual void DrawFrameIntervalMilliTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawFrameIntervalMilliTimeでフレーム間隔を描画.

};

#endif