// 二重インクルード防止
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "SharedObject.h"	// CSharedObject

// キャラクタークラスCCharacter
class CCharacter : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CCharacter();	// コンストラクタCCharacter()
		CCharacter(CScene *pScene);	// デストラクタCCharacter(CScene *pScene)
		virtual ~CCharacter();	// デストラクタ~CCharacter()
		// メンバ関数
		virtual void Add(int sx, int sy, int iWidth, int iHeight, int nID);	// アニメーションの追加Add.
		virtual void Destroy();	// キャラクターの破棄Destroy.
		virtual void Draw(int x, int y, int iNo);	// シェアードオブジェクトの描画Draw.

};

#endif