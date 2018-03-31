// 二重インクルード防止
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene

// 前方宣言.
class CScene;	// CScene.

// ゲームオブジェクトクラスCGameObject
class CGameObject{

	// publicメンバ
	public:

		// publicメンバ変数
		const CScene *m_pScene;	// CSceneオブジェクトポインタm_pScene.(const)
		int m_x;	// 位置x座標m_x.
		int m_y;	// 位置y座標m_y.
		int m_iWidth;	// 幅m_iWidth.
		int m_iHeight;	// 高さm_iHeight.
		HPEN m_hPen;	// ペンm_hPen.
		HPEN m_hOldPen;	// 元のペンm_hOldPen.
		HBRUSH m_hBrush;	// ブラシm_hBrush.
		HBRUSH m_hOldBrush;	// 元のブラシm_hOldBrush.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CGameObject();	// コンストラクタCGameObject()
		CGameObject(const CScene *pScene);	// コンストラクタCGameObject(const CScene *pScene)
		virtual ~CGameObject();	// デストラクタ~CGameObject()
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, COLORREF clrPen, COLORREF clrBrush);	// ゲームオブジェクトの作成Create.(ペンとブラシで描かれた矩形.)
		virtual void Destroy();	// ゲームオブジェクトの破棄Destroy.
		virtual void DrawRect(int x, int y);	// ゲームオブジェクトの描画DrawRect.(ペンとブラシで描かれた矩形.)

};

#endif