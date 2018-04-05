// 二重インクルード防止
#ifndef __TITLE_H__
#define __TITLE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// タイトルクラスCTitle
class CTitle : public CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		HDC m_hMemDC;	// メモリデバイスコンテキストm_hMemDC.
		HBITMAP m_hBitmap;	// ロードしたビットマップm_hBitmap.
		HBITMAP m_hOldBitmap;	// 以前のビットマップm_hOldBitmap.
		HFONT m_hFont;	// フォントm_hFont.
		HFONT m_hOldFont;	// 以前のフォントm_hOldFont.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CTitle();	// コンストラクタCTitle()
		CTitle(const CScene *pScene);	// コンストラクタCTitle(const CScene *pScene)
		virtual ~CTitle();	// デストラクタ~CTitle()
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName);	// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual void DrawRect(int x, int y);	// ゲームオブジェクトの描画DrawRect.(指定されたリソースIDの画像をロード.)
		virtual void DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor);	// DrawTextでテキストを描画.

};

#endif