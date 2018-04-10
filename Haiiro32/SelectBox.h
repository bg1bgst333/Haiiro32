// 二重インクルード防止
#ifndef __SELECT_BOX_H__
#define __SELECT_BOX_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
#include <vector>	// std::vector

// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// セレクトボックスクラスCSelectBox
class CSelectBox sealed : public CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		HDC m_hBackgroundMemDC;	// 背景メモリデバイスコンテキストm_hBackgroundMemDC.
		HBITMAP m_hBackgroundBitmap;	// ロードした背景ビットマップm_hBackgroundBitmap.
		HBITMAP m_hOldBackgroundBitmap;	// 以前の背景ビットマップm_hOldBackgroundBitmap.
		HFONT m_hFont;	// フォントm_hFont.
		HFONT m_hOldFont;	// 以前のフォントm_hOldFont.
		int m_iLineHeight;	// 行の高さm_iLineHeight.
		int m_iMargin;	// 行の間隔m_iMargin.
		HDC m_hCursorMemDC;	// カーソルメモリデバイスコンテキストm_hCursorMemDC.
		HBITMAP m_hCursorBitmap;	// ロードしたカーソルビットマップm_hCursorBitmap.
		HBITMAP m_hOldCursorBitmap;	// 以前のカーソルビットマップm_hOldCursorBitmap.
		int m_iCursorWidth;	// カーソルの幅m_iCursorWidth.
		int m_iCursorHeight;	// カーソルの高さm_iCursorHeight.
		std::vector<tstring> m_vectstrSelectItemList;	// セレクトアイテムリストm_vectstrSelectItemList.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CSelectBox();	// コンストラクタCSelectBox()
		CSelectBox(const CScene *pScene);	// コンストラクタCSelectBox(const CScene *pScene)
		virtual ~CSelectBox();	// デストラクタ~CSelectBox()
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName, int iMargin, int iCursorWidth, int iCursorHeight, UINT nCursorID);	// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual void AddSelectItem(tstring tstrSelectItem);	// セレクトアイテムの追加AddSelectItem.
		virtual void ClearSelectItem();	// セレクトアイテムのクリアClearSelectItem.
		virtual void DrawRect(int x, int y);	// ゲームオブジェクトの描画DrawRect.
		virtual void DrawSelectItemList(int x, int y, COLORREF clrColor);	// セレクトアイテムリストの描画DrawSelectItemList.
		virtual void DrawCursor(int x, int y);	// カーソルの描画DrawCursor.

};

#endif