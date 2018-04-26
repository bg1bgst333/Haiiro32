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
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_iCursorX = 0;	// m_iCursorXに0をセット.
	m_iCursorY = 0;	// m_iCursorYに0をセット.

}

// コンストラクタCMap(CScene *pScene)
CMap::CMap(CScene *pScene) : CSharedObject(pScene){

	// メンバの初期化.
	m_iChipWidth = 0;	// m_iChipWidthに0をセット.
	m_iChipHeight = 0;	// m_iChipHeightに0をセット.
	m_iChipCountX;	// m_iChipCountXに0をセット.
	m_iChipCountY;	// m_iChipCountYに0をセット.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrixにNULLをセット.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_iCursorX = 0;	// m_iCursorXに0をセット.
	m_iCursorY = 0;	// m_iCursorYに0をセット.

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
#if 0
		m_ppMapDataMatrix[i][0].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][0].m_iDestX = 0;	// 0
		m_ppMapDataMatrix[i][0].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][1].m_iDestX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_iSrcX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iSrcY = 0;	// 0
		m_ppMapDataMatrix[i][2].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][2].m_iDestX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][2].m_iSrcX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iSrcY = 0;	// 0
#endif
	}

	// マップ配置.
	for (int y = 0; y < m_iChipCountY; y++){	// 縦方向.
		for (int x = 0; x < m_iChipCountX; x++){	// 横方向.
			m_ppMapDataMatrix[y][x].m_nID = IDB_SHARED1;
			if (x <= 1){
				m_ppMapDataMatrix[y][x].m_iDestX = x;
				m_ppMapDataMatrix[y][x].m_iDestY = y;
				m_ppMapDataMatrix[y][x].m_iSrcX = y;
				m_ppMapDataMatrix[y][x].m_iSrcY = 0;
				if (y >= 10){
					m_ppMapDataMatrix[y][x].m_iSrcX = y - 10;
					m_ppMapDataMatrix[y][x].m_iSrcY = 1;
				}
			}
			else{
				m_ppMapDataMatrix[y][x].m_iDestX = x;
				m_ppMapDataMatrix[y][x].m_iDestY = y;
				m_ppMapDataMatrix[y][x].m_iSrcX = 0;
				m_ppMapDataMatrix[y][x].m_iSrcY = 2;
			}
		}
	}

#if 1
#if 1
	// マップをエクスポート.
	ExportFile(_T("testmap1.bin"));	// ExportFileで"testmap1.bin"をエクスポート.
#else
	// マップをインポート.
	ImportFile(_T("testmap1.bin"));	// ImportFileで"testmap1.bin"をインポート.
#endif
#endif

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
	for (int y = 0; y < 15/*m_iChipCountY*/; y++){	// 縦方向.
		for (int x = 0; x < 20/*m_iChipCountX*/; x++){	// 横方向.
			HDC hMemDC = m_pScene->m_pSharedImageBuffer->Get(m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_nID);	// 指定のIDのバッファを取得.
			BitBlt(m_pScene->m_hMemDC, x * m_iChipWidth, y * m_iChipHeight, m_iChipWidth, m_iChipHeight, hMemDC, m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iSrcX * m_iChipWidth, m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iSrcY * m_iChipHeight, SRCCOPY);	// BitBltで描画.
		}
	}

}

// マップデータをファイルとしてエクスポートExportFile.
BOOL CMap::ExportFile(LPCTSTR lpctszFileName){

	// バイナリファイルの作成.
#if 1
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトpBinaryFileの生成.
	pBinaryFile->Set((BYTE *)&m_iChipWidth, sizeof(int));	// チップ幅.
	pBinaryFile->Write(lpctszFileName);	// 指定のファイルに書き込み.
	pBinaryFile->Set((BYTE *)&m_iChipHeight, sizeof(int));	// チップ高さ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_iChipCountX, sizeof(int));	// チップ横要素数.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_iChipCountY, sizeof(int));	// チップ縦要素数.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	// マップ配列の描画.
	for (int y = 0; y < m_iChipCountY; y++){	// 縦方向.
		for (int x = 0; x < m_iChipCountX; x++){	// 横方向.
			pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[y][x], sizeof(MapData));	// (x, y)マップデータ.
			pBinaryFile->Write();	// 先程開いたファイルに追記.
		}
	}
#if 0
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[0][1], sizeof(MapData));	// (x, y) = (1, 0)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][0], sizeof(MapData));	// (x, y) = (0, 1)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][1], sizeof(MapData));	// (x, y) = (1, 1)のマップデータ.
	pBinaryFile->Write();	// 先程開いたファイルに追記.
#endif
	delete pBinaryFile;	// pBinaryFileの終了処理.
#endif
	
	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// マップデータをファイルとしてインポートImportFile.
BOOL CMap::ImportFile(LPCTSTR lpctszFileName){

	// バイナリファイルから読み込み.
	CBinaryFile *pBinaryFile = new CBinaryFile();
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Readで読み込み.
	m_iChipWidth = (int)*pBinaryFile->m_pBytes;	// チップ幅を取得.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
	m_iChipHeight = (int)*pBinaryFile->m_pBytes;	// チップ高さを取得.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
	m_iChipCountX = (int)*pBinaryFile->m_pBytes;	// チップ横要素数を取得.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Readで読み込み.
	m_iChipCountY = (int)*pBinaryFile->m_pBytes;	// チップ縦要素数を取得.

	// マップ配列作成.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY];	// 縦方向の要素数newする.
	for (int i = 0; i < m_iChipCountY; i++){	// 縦方向の要素数繰り返す.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX];	// 横方向の要素数newする.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * m_iChipCountX);	// ZeroMemoryでクリア.
	}

	// マップ配列にバイナリの値をセット.
	for (int y = 0; y < m_iChipCountY; y++){	// 縦方向.
		for (int x = 0; x < m_iChipCountX; x++){	// 横方向.
			pBinaryFile->Read(sizeof(MapData));	// pBinaryFile->Readで読み込み.
			CopyMemory(&m_ppMapDataMatrix[y][x], (MapData *)pBinaryFile->m_pBytes, sizeof(MapData));	// CopyMemoryでバイナリデータをコピー.
		}
	}

	// バイナリファイルオブジェクトの破棄.
	delete pBinaryFile;	// pBinaryFileの終了処理.

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// マップの移動状態をクリア.
void CMap::Clear(){

	// フラグをクリア.
	m_bDown = FALSE;	// m_bDownをFALSEにする.
	m_bUp = FALSE;	// m_bUpをFALSEにする.
	m_bRight = FALSE;	// m_bRightをFALSEにする.
	m_bLeft = FALSE;	// m_bLeftをFALSEにする.

}

// マップの視点を下に移動Down.(マップ自体は上に移動.)
void CMap::Down(){

	// 下が有効.
	m_bDown = TRUE;	// m_bDownをTRUEにする.

}

// マップの視点を上に移動Up.(マップ自体は下に移動.)
void CMap::Up(){

	// 上が有効.
	m_bUp = TRUE;	// m_bUpをTRUEにする.

}

// マップの視点を右に移動Right.(マップ自体は左に移動.)
void CMap::Right(){

	// 右が有効.
	m_bRight = TRUE;	// m_bRightをTRUEにする.

}

// マップの視点を左に移動Ledt.(マップ自体は右に移動.)
void CMap::Left(){

	// 左が有効.
	m_bLeft =TRUE;	// m_bLeftをTRUEにする.

}

// 処理をするProc.
int CMap::Proc(){

	// 下.
	if (m_bDown){
		m_iCursorY++;	// yを1増やす.
	}

	// 上.
	if (m_bUp){
		m_iCursorY--;	// yを1減らす.
	}

	// 右.
	if (m_bRight){
		m_iCursorX++;	// xを1増やす.
	}

	// 左.
	if (m_bLeft){
		m_iCursorX--;	// xを1減らす.
	}

	// カーソル最小値最大値を超えないようにする.
	if (m_iCursorX < 0){	// 0未満.
		m_iCursorX = 0;	// 0にする.
	}
	if (m_iCursorY < 0){	// 0未満.
		m_iCursorY = 0;	// 0にする.
	}
	if (m_iCursorX > m_iChipCountX - 20){	// m_iChipCountX - 20を超える.
		m_iCursorX = m_iChipCountX - 20;	// m_iChipCountX - 20にする.
	}
	if (m_iCursorY > m_iChipCountY - 15){	// m_iChipCountY - 15を超える.
		m_iCursorY = m_iChipCountY - 15;	// m_iChipCountY - 15にする.
	}

	// シーン継続なら0.
	return 0;	// 0を返す.

}