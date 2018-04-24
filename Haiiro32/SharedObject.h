// 二重インクルード防止
#ifndef __SHARED_OBJECT_H__
#define __SHARED_OBJECT_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Scene.h"	// CScene

// シェアードオブジェクトクラスCSharedObject
class CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		CScene *m_pScene;	// CSceneオブジェクトポインタm_pScene.
		int m_x;	// 位置x座標m_x.
		int m_y;	// 位置y座標m_y.
		int m_iWidth;	// 幅m_iWidth.
		int m_iHeight;	// 高さm_iHeight.
		int m_nID;	// リソースID.
		int m_sx;	// 転送元x座標m_sx.
		int m_sy;	// 転送元y座標m_sy.
		std::vector<CSharedObject *> m_vecpSharedObjectList;	// シェアードオブジェクトリストm_vecpSharedObjectList.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CSharedObject();	// コンストラクタCSharedObject
		CSharedObject(CScene *pScene);	// コンストラクタCSharedObject(CScene *pScene)
		virtual ~CSharedObject();	// デストラクタ~CSharedObject
		// メンバ関数
		virtual BOOL Create(int sx, int sy, int iWidth, int iHeight, int nID);	// シェアードオブジェクトの作成Create.
		virtual void Destroy();	// シェアードオブジェクトの破棄Destroy.
		virtual void Draw(int x, int y);	// シェアードオブジェクトの描画Draw.

};

#endif