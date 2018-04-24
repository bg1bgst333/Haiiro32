// 二重インクルード防止
#ifndef __MAP_DATA_H__
#define __MAP_DATA_H__

// マップデータ構造体MapData
struct MapData{
	int m_iDestX;	// 転送先x座標.
	int m_iDestY;	// 転送先y座標.
	int m_iSrcX;	// 転送元x座標.
	int m_iSrcY;	// 転送元y座標.
	int m_nID;	// 転送元マップリソースID.
};

#endif
