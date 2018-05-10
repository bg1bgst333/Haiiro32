// 二重インクルード防止
#ifndef __SHOT_H__
#define __SHOT_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "SharedObject.h"	// CSharedObject

// ショットクラスCShot
class CShot : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<CSharedObject *> m_vecpMaskList;	// マスクリストm_vecpMaskList.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CShot();	// コンストラクタCShot()
		CShot(CScene *pScene);	// デストラクタCShot(CScene *pScene)
		virtual ~CShot();	// デストラクタ~CShot()
		// メンバ関数
		virtual void Add(int sx, int sy, int iWidth, int iHeight, int nID);	// アニメーションの追加Add.
		virtual void AddMask(int sx, int sy, int iWidth, int iHeight, int nID);	// マスクの追加AddMask.
		virtual void Destroy();	// ショットの破棄Destroy.
		virtual void Draw(int x, int y, int iNo);	// シェアードオブジェクトの描画Draw.
		virtual void DrawSprite(int x, int y, int iNo);	// スプライトの描画DrawSprite.

};

#endif