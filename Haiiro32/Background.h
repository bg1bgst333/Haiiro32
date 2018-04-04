// 二重インクルード防止
#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GameObject.h"	// CGameObject

// バックグラウンドクラスCBackground
class CBackground : public CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		HDC m_hMemDC;	// 
		HBITMAP m_hBitmap;	// ロードしたビットマップm_hBitmap.
		HBITMAP m_hOldBitmap;	// 以前のビットマップm_hOldBitmap.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBackground();	// コンストラクタCBackground()
		CBackground(const CScene *pScene);	// コンストラクタCBackground(const CScene *pScene)
		virtual ~CBackground();	// デストラクタ~CBackground()
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID);	// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual void DrawRect(int x, int y);	// ゲームオブジェクトの描画DrawRect.(指定されたリソースIDの画像をロード.)

};

#endif