// 二重インクルード防止
#ifndef __MAP_H__
#define __MAP_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "MapData.h"	// 構造体MapData
#include "SharedObject.h"	// CSharedObject

// マップクラスCMap
class CMap : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_iChipWidth;	// チップ幅.
		int m_iChipHeight;	// チップ高さ.
		int m_iChipCountX;	// 横チップ数.
		int m_iChipCountY;	// 縦チップ数.
		MapData** m_ppMapDataMatrix;	// MapData2次元配列m_ppMapDataMatrix.
		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMap();	// コンストラクタCMap
		CMap(CScene *pScene);	// コンストラクタCMap(CScene *pScene)
		virtual ~CMap();	// デストラクタ~CMap
		// メンバ関数
		virtual BOOL Create(int iChipWidth, int iChipHeight, int iChipCountX, int iChipCountY);	// マップの作成Create.
		virtual void Destroy();	// マップの破棄Destroy.
		virtual void Draw();	// マップの描画Draw.

};

#endif