// 二重インクルード防止
#ifndef __MAP_H__
#define __MAP_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "MapData.h"	// 構造体MapData
#include "SharedObject.h"	// CSharedObject
#include "BinaryFile.h"	// CBinaryFile

// マップクラスCMap
class CMap : public CSharedObject{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_iChipWidth;	// チップ幅.
		int m_iChipHeight;	// チップ高さ.
		int m_iChipCountX;	// 横チップ数.
		int m_iChipCountY;	// 縦チップ数.
		int m_iCursorX;	// 描画開始位置x.
		int m_iCursorY;	// 描画開始位置y.
		int m_iPixelX;	// 描画開始位置(ピクセル単位)x.
		int m_iPixelY;	// 描画開始位置(ピクセル単位)y.
		MapData** m_ppMapDataMatrix;	// MapData2次元配列m_ppMapDataMatrix.
		BOOL m_bDown;	// 下が押されているフラグm_bDown.
		BOOL m_bUp;	// 上が押されているフラグm_bUp.
		BOOL m_bRight;	// 右が押されているフラグm_bRight.
		BOOL m_bLeft;	// 左が押されているフラグm_bLeft.
		BOOL m_bLoop;	// ループかどうかフラグm_bLoop.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMap();	// コンストラクタCMap
		CMap(CScene *pScene);	// コンストラクタCMap(CScene *pScene)
		virtual ~CMap();	// デストラクタ~CMap
		// メンバ関数
		virtual BOOL Create(int iChipWidth, int iChipHeight, int iChipCountX, int iChipCountY);	// マップの作成Create.
		virtual void Destroy();	// マップの破棄Destroy.
		virtual void Draw();	// マップの描画Draw.
		virtual BOOL ExportFile(LPCTSTR lpctszFileName);	// マップデータをファイルとしてエクスポートExportFile.
		virtual BOOL ImportFile(LPCTSTR lpctszFileName);	// マップデータをファイルとしてインポートImportFile.
		virtual BOOL ImportResource(int nID);	// マップデータをリソースとしてインポートImportResource.
		virtual void Clear();	// マップの移動状態をクリア.
		virtual void Down();	// マップの視点を下に移動Down.(マップ自体は上に移動.)
		virtual void Up();	// マップの視点を上に移動Up.(マップ自体は下に移動.)
		virtual void Right();	// マップの視点を右に移動Right.(マップ自体は左に移動.)
		virtual void Left();	// マップの視点を左に移動Ledt.(マップ自体は右に移動.))
		virtual int Proc();	// 処理をするProc.

};

#endif