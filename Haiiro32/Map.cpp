// ヘッダのインクルード
// 独自のヘッダ
#include "Map.h"	// CMap
#include "resource.h"	// リソース.

// コンストラクタCMap
CMap::CMap() : CSharedObject(){

	// メンバの初期化.
	m_iChipWidth = 0;	// m_iChipWidthに0をセット.
	m_iChipHeight = 0;	// m_iChipHeightに0をセット.
	m_iChipCountX;	// m_iChipCountXに0をセット.
	m_iChipCountY;	// m_iChipCountYに0をセット.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrixにNULLをセット.

}

// コンストラクタCMap(CScene *pScene)
CMap::CMap(CScene *pScene) : CSharedObject(pScene){

	// メンバの初期化.
	m_iChipWidth = 0;	// m_iChipWidthに0をセット.
	m_iChipHeight = 0;	// m_iChipHeightに0をセット.
	m_iChipCountX;	// m_iChipCountXに0をセット.
	m_iChipCountY;	// m_iChipCountYに0をセット.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrixにNULLをセット.

}

// デストラクタ~CMap
CMap::~CMap(){

}

// マップの作成Create.
BOOL CMap::Create(int iChipWidth, int iChipHeight, int iChipCountX, int iChipCountY){

	// メンバのセット.
	m_iChipWidth = iChipWidth;	// m_iChipWidthにiChipWidthをセット.
	m_iChipHeight = iChipHeight;	// m_iChipHeightにiChipHeightをセット.
	m_iChipCountX = iChipCountX;	// m_iChipCountXにiChipCountXをセット.
	m_iChipCountY = iChipCountY;	// m_iChipCountYにiChipCountYをセット.

	// マップ配列作成.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY];	// 縦方向の要素数newする.
	for (int i = 0; i < m_iChipCountY; i++){	// 縦方向の要素数繰り返す.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX];	// 横方向の要素数newする.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * m_iChipCountX);	// ZeroMemoryでクリア.
#if 1
		m_ppMapDataMatrix[i][0].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][0].m_iDestX = 0;	// 0
		m_ppMapDataMatrix[i][0].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][1].m_iDestX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_iSrcX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iSrcY = 0;	// 0
		/*
		m_ppMapDataMatrix[i][2].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][2].m_iDestX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][2].m_iSrcX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iSrcY = 0;	// 0
		*/
#endif
	}

	// マップをエクスポート.
	ExportFile(_T("testmap1.bin"));	// ExportFileで"testmap1.bin"をエクスポート.

	// 成功なので0.
	return 0;	// 0を返す.

}

// マップの破棄Destroy.
void CMap::Destroy(){
	
	// マップ配列の破棄.
	for (int i = 0; i < m_iChipCountY; i++){	// 縦方向の要素数繰り返す.
		delete [] m_ppMapDataMatrix[i];	// m_ppMapDataMatrix[i]を解放.
		m_ppMapDataMatrix[i] = NULL;	// m_ppMapDataMatrix[i]にNULLをセット.
	}
	delete [] m_ppMapDataMatrix;	// m_ppMapDataMatrixを解放.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrixにNULLをセット.

	// メンバのリセット.
	m_iChipWidth = 0;	// m_iChipWidthに0をセット.
	m_iChipHeight = 0;	// m_iChipHeightに0をセット.
	m_iChipCountX;	// m_iChipCountXに0をセット.
	m_iChipCountY;	// m_iChipCountYに0をセット.

}

// マップの描画Draw.
void CMap::Draw(){

	// マップ配列の描画.
	for (int y = 0; y < m_iChipCountY; y++){	// 縦方向.
		for (int x = 0; x < m_iChipCountX; x++){	// 横方向.
			HDC hMemDC = m_pScene->m_pSharedImageBuffer->Get(m_ppMapDataMatrix[y][x].m_nID);	// 指定のIDのバッファを取得.
			BitBlt(m_pScene->m_hMemDC, m_ppMapDataMatrix[y][x].m_iDestX * m_iChipWidth, m_ppMapDataMatrix[y][x].m_iDestY * m_iChipHeight, m_iChipWidth, m_iChipHeight, hMemDC, m_ppMapDataMatrix[y][x].m_iSrcX * m_iChipWidth, m_ppMapDataMatrix[y][x].m_iSrcY * m_iChipHeight, SRCCOPY);	// BitBltで描画.
		}
	}

}

// マップデータをファイルとしてエクスポートExportFile.
BOOL CMap::ExportFile(LPCTSTR lpctszFileName){

	// バイナリファイルの作成.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトpBinaryFileの生成.
	pBinaryFile->Set((BYTE *)&m_iChipWidth, sizeof(int));	// チップ幅.
	pBinaryFile->Write(lpctszFileName);	// 指定のファイルに書き込み.
	pBinaryFile->Set((BYTE *)&m_iChipHeight, sizeof(int));	// チップ高さ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_iChipCountX, sizeof(int));	// チップ横要素数.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_iChipCountY, sizeof(int));	// チップ縦要素数.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[0][0], sizeof(MapData));	// (x, y) = (0, 0)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[0][1], sizeof(MapData));	// (x, y) = (1, 0)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][0], sizeof(MapData));	// (x, y) = (0, 1)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][1], sizeof(MapData));	// (x, y) = (1, 1)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	delete pBinaryFile;	// pBinaryFileの終了処理.

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}