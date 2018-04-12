// ヘッダのインクルード
// 独自のヘッダ
#include "SelectBox.h"	// CSelectBox

// コンストラクタCSelectBox()
CSelectBox::CSelectBox() : CGameObject(){

	// メンバの初期化.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCをNULLで初期化.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapをNULLで初期化.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapをNULLで初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_iLineHeight = 0;	// m_iLineHeightを0で初期化.
	m_iMargin = 0;	// m_iMarginを0で初期化.
	m_hCursorMemDC = NULL;	// m_hCursorMemDCをNULLで初期化.
	m_hCursorBitmap = NULL;	// m_hCursorBitmapをNULLで初期化.
	m_hOldCursorBitmap = NULL;	// m_hOldCursorBitmapをNULLで初期化.
	m_iCursorX = 0;	// m_iCursorXを0で初期化.
	m_iCursorY = 0;	// m_iCursorYを0で初期化.
	m_iCursorWidth = 0;	// m_iCursorWidthを0で初期化.
	m_iCursorHeight = 0;	// m_iCursorHeightを0で初期化.
	m_iCursorIndex = 0;	// m_iCursorIndexを0で初期化.
	m_bCursorVisible = FALSE;	// m_bCursorVisibleをFALSEで初期化.
	m_bDown = FALSE;	// m_bDownをFALSEで初期化.
	m_bUp = FALSE;	// m_bUpをFALSEで初期化.
	m_bReturn = FALSE;	// m_bReturnをFALSEで初期化.
	m_bDetermine = FALSE;	// m_bDetermineをFALSEで初期化.
	m_dwInterval = 0;	// m_dwIntervalを0で初期化.
	m_dwTimerStart = 0;	// m_dwTimerStartを0で初期化.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clearでクリア.

}

// コンストラクタCSelectBox(const CScene *pScene)
CSelectBox::CSelectBox(const CScene *pScene) : CGameObject(pScene){

	// メンバの初期化.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCをNULLで初期化.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapをNULLで初期化.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapをNULLで初期化.
	m_hFont = NULL;	// m_hFontをNULLで初期化.
	m_hOldFont = NULL;	// m_hOldFontをNULLで初期化.
	m_iLineHeight = 0;	// m_iLineHeightを0で初期化.
	m_iMargin = 0;	// m_iMarginを0で初期化.
	m_hCursorMemDC = NULL;	// m_hCursorMemDCをNULLで初期化.
	m_hCursorBitmap = NULL;	// m_hCursorBitmapをNULLで初期化.
	m_hOldCursorBitmap = NULL;	// m_hOldCursorBitmapをNULLで初期化.
	m_iCursorX = 0;	// m_iCursorXを0で初期化.
	m_iCursorY = 0;	// m_iCursorYを0で初期化.
	m_iCursorWidth = 0;	// m_iCursorWidthを0で初期化.
	m_iCursorHeight = 0;	// m_iCursorHeightを0で初期化.
	m_iCursorIndex = 0;	// m_iCursorIndexを0で初期化.
	m_bCursorVisible = FALSE;	// m_bCursorVisibleをFALSEで初期化.
	m_bDown = FALSE;	// m_bDownをFALSEで初期化.
	m_bUp = FALSE;	// m_bUpをFALSEで初期化.
	m_bReturn = FALSE;	// m_bReturnをFALSEで初期化.
	m_bDetermine = FALSE;	// m_bDetermineをFALSEで初期化.
	m_dwInterval = 0;	// m_dwIntervalを0で初期化.
	m_dwTimerStart = 0;	// m_dwTimerStartを0で初期化.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clearでクリア.

}

// デストラクタ~CSelectBox()
CSelectBox::~CSelectBox(){

}

// ゲームオブジェクトの作成Create.(指定されたリソースIDの画像をロード.)
BOOL CSelectBox::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName, int iMargin, int iCursorWidth, int iCursorHeight, UINT nCursorID){

	// 背景メモリデバイスコンテキストの作成.
	m_hBackgroundMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDCでm_hBackgroundMemDCを作成.
	if (m_hBackgroundMemDC == NULL){	// m_hBackgroundMemDCがNULLなら.
		return FALSE;	// FALSEを返す.
	}

	// 背景ビットマップのロード.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.
	m_hBackgroundBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, iWidth, iHeight, LR_DEFAULTCOLOR);	// LoadImageでリソースIDがnIDのビットマップをロード.
	if (m_hBackgroundBitmap == NULL){	// m_hBackgroundBitmapがNULLなら.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDCをDeleteDCで削除.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// 背景ビットマップの選択.
	m_hOldBackgroundBitmap = (HBITMAP)SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObjectでm_hBackgroundBitmapを選択.

	// 位置とサイズの取得.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// フォントの作成.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFontでフォントを作成し, m_hFontに格納.
	if (m_hFont == NULL){	// m_hFontがNULLなら.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObjectでm_hOldBackgroundBitmapを選択.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapにNULLをセット.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObjectでm_hBackgroundBitmapを削除.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapにNULLをセット.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDCをDeleteDCで削除.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// フォントの選択.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.

	// テキストの高さを取得.
	TEXTMETRIC tm;	// フォント情報を持つTEXTMETRIC構造体変数tm.
	GetTextMetrics(m_pScene->m_hMemDC, &tm);	// GetTextMetricsでtmの内容を取得.
	m_iLineHeight = tm.tmHeight;	// m_iLineHeightにtm.tmHeightをセット.

	// 行の間隔のセット.
	m_iMargin = iMargin;	// m_iMarginにiMarginをセット.

	// カーソルメモリデバイスコンテキストの作成.
	m_hCursorMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDCでm_hCursorMemDCを作成.
	if (m_hCursorMemDC == NULL){	// m_hCursorMemDCがNULLなら.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObjectでm_hOldFontに戻す.
		m_hOldFont = NULL;	// m_hOldFontにNULLをセット.
		DeleteObject(m_hFont);	// DeleteObjectでm_hFontを削除.
		m_hFont = NULL;	// m_hFontにNULLをセット.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObjectでm_hOldBackgroundBitmapを選択.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapにNULLをセット.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObjectでm_hBackgroundBitmapを削除.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapにNULLをセット.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDCをDeleteDCで削除.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// カーソルビットマップのロード.
	m_iCursorX = 0;	// m_iCursorXを0で初期化.
	m_iCursorY = 0;	// m_iCursorYを0で初期化.
	m_iCursorWidth = iCursorWidth;	// m_iCursorWidthにiCursorWidthをセット.
	m_iCursorHeight = iCursorHeight;	// m_iCursorHeightにiCursorHeightをセット.
	m_iCursorIndex = 0;	// m_iCursorIndexを0で初期化.
	m_bCursorVisible = TRUE;	// m_bCursorVisibleにTRUEを代入.
	m_bDown = FALSE;	// m_bDownをFALSEで初期化.
	m_bUp = FALSE;	// m_bUpをFALSEで初期化.
	m_bReturn = FALSE;	// m_bReturnをFALSEで初期化.
	m_bDetermine = FALSE;	// m_bDetermineをFALSEで初期化.
	m_dwInterval = 0;	// m_dwIntervalを0で初期化.
	m_dwTimerStart = 0;	// m_dwTimerStartを0で初期化.
	m_hCursorBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nCursorID), IMAGE_BITMAP, m_iCursorWidth, m_iCursorHeight, LR_DEFAULTCOLOR);	// LoadImageでリソースIDがnCursorIDのビットマップをロード.
	if (m_hCursorBitmap == NULL){	// m_hCursorBitmapがNULLなら.
		DeleteDC(m_hCursorMemDC);	// DeleteDCでm_hCursorMemDCを削除.
		m_hCursorMemDC = NULL;	// m_hCursorMemDCにNULLをセット.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObjectでm_hOldFontに戻す.
		m_hOldFont = NULL;	// m_hOldFontにNULLをセット.
		DeleteObject(m_hFont);	// DeleteObjectでm_hFontを削除.
		m_hFont = NULL;	// m_hFontにNULLをセット.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObjectでm_hOldBackgroundBitmapを選択.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapにNULLをセット.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObjectでm_hBackgroundBitmapを削除.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapにNULLをセット.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDCをDeleteDCで削除.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
		return FALSE;	// FALSEを返す.
	}

	// カーソルビットマップの選択.
	m_hOldCursorBitmap = (HBITMAP)SelectObject(m_hCursorMemDC, m_hCursorBitmap);	// SelectObjectでm_hCursorBitmapを選択.

	// 成功なのでTRUE.
	return TRUE;	// TRUEを返す.

}

// ゲームオブジェクトの破棄Destroy.
void CSelectBox::Destroy(){

	// メンバの終了処理.
	m_x = 0;	// m_xに0を代入.
	m_y = 0;	// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.
	m_iMargin = 0;	// m_iMarginに0を代入.
	m_iLineHeight = 0;	// m_iLineHeightに0を代入.
	m_iCursorX = 0;	// m_iCursorXに0を代入.
	m_iCursorY = 0;	// m_iCursorYに0を代入.
	m_iCursorWidth = 0;	// m_iCursorWidthに0を代入.
	m_iCursorHeight = 0;	// m_iCursorHeightに0を代入.
	m_iCursorIndex = 0;	// m_iCursorIndexに0を代入.
	m_bCursorVisible = FALSE;	// m_bCursorVisibleにFALSEを代入.
	m_bDown = FALSE;	// m_bDownにFALSEを代入.
	m_bUp = FALSE;	// m_bUpにFALSEを代入.
	m_bReturn = FALSE;	// m_bReturnにFALSEを代入.
	m_bDetermine = FALSE;	// m_bDetermineにFALSEを代入.
	m_dwInterval = 0;	// m_dwIntervalに0を代入.
	m_dwTimerStart = 0;	// m_dwTimerStartに0を代入.

	// カーソルビットマップを戻す.
	if (m_hOldCursorBitmap != NULL){	// m_hOldCursorBitmapがNULLでなければ.
		SelectObject(m_hCursorMemDC, m_hOldCursorBitmap);	// SelectObjectでm_hOldCursorBitmapに戻す.
		m_hOldCursorBitmap = NULL;	// m_hOldCursorBitmapにNULLをセット.
	}

	// カーソルビットマップの削除.
	if (m_hCursorBitmap != NULL){	// m_hCursorBitmapがNULLでなければ.
		DeleteObject(m_hCursorBitmap);	// DeleteObjectでm_hCursorBitmapを削除.
		m_hCursorBitmap = NULL;	// m_hCursorBitmapにNULLをセット.
	}

	// フォントを戻す.
	if (m_hOldFont != NULL){	// m_hOldFontがNULLでなければ.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObjectでm_hOldFontに戻す.
		m_hOldFont = NULL;	// m_hOldFontにNULLをセット.
	}

	// フォントの削除.
	if (m_hFont != NULL){	// m_hFontがNULLでなければ.
		DeleteObject(m_hFont);	// DeleteObjectでm_hFontを削除.
		m_hFont = NULL;	// m_hFontにNULLをセット.
	}

	// 背景ビットマップを戻す.
	if (m_hOldBackgroundBitmap != NULL){	// m_hOldBackgroundBitmapがNULLでなければ.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObjectでm_hOldBackgroundBitmapに戻す.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmapにNULLをセット.
	}

	// ロードした背景ビットマップの破棄.
	if (m_hBackgroundBitmap != NULL){	// m_hBackgroundBitmapがNULLでなければ.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObjectでm_hBackgroundBitmaoを削除.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmapにNULLをセット.
	}

	// 背景メモリデバイスコンテキストの破棄.
	if (m_hBackgroundMemDC != NULL){	// m_hBackgroundMemDCがNULLでなければ.
		DeleteDC(m_hBackgroundMemDC);	// DeleteDCでm_hBackgroundMemDCを破棄.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDCにNULLをセット.
	}

}

// セレクトアイテムの追加AddSelectItem.
void CSelectBox::AddSelectItem(tstring tstrSelectItem){

	// セレクトアイテムリストに追加.
	m_vectstrSelectItemList.push_back(tstrSelectItem);	// m_vectstrSelectItemList.push_backでtstrSelectItemを追加.

}

// セレクトアイテムのクリアClearSelectItem.
void CSelectBox::ClearSelectItem(){

	// セレクトアイテムの全削除.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clearでクリア.

}		

// ゲームオブジェクトの描画DrawRect.(指定されたリソースIDの画像をロード.)
void CSelectBox::DrawRect(int x, int y){

	// 背景ビットマップの選択.
	SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObjectでm_hBackgroundBitmapを選択.

	// 背景ビットマップの描画.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, m_hBackgroundMemDC, 0, 0, SRCCOPY);	// BitBltでバックバッファに描画.

}

// セレクトアイテムリストの描画DrawSelectItemList.
void CSelectBox::DrawSelectItemList(int x, int y, COLORREF clrColor){

	// アイテムの数だけ描画.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColorで色はclrColorを指定.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkModeで背景は透過.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObjectでm_hFontを選択.
	int iPosY = m_y + y;	// iPosYをm_y + yで初期化.
	for (std::vector<tstring>::iterator itor = m_vectstrSelectItemList.begin(); itor != m_vectstrSelectItemList.end(); itor++){	// itorが終わるまで繰り返す.
		RECT rc = {m_x + x, iPosY, m_x + x + m_iWidth, m_y + y + m_iHeight};	// rcを引数を使って初期化.
		::DrawText(m_pScene->m_hMemDC, (*itor).c_str(), _tcslen((*itor).c_str()), &rc, DT_LEFT | DT_SINGLELINE);	// DrawTextで描画.
		iPosY = iPosY + m_iLineHeight;	// iPosYにm_iLineHeightを足す.
		iPosY = iPosY + m_iMargin;	// iPosYにm_iMarginを足す.
	}

}

// カーソルの描画DrawCursor.
void CSelectBox::DrawCursor(int x, int y){

	// カーソル位置の決定.
	m_iCursorY = (m_iLineHeight + m_iMargin) * m_iCursorIndex;	// (m_iLineHeight + m_iMargin) * m_iCursorIndexをセット.

	// カーソルの描画.
	if (m_bCursorVisible){	// m_bCursorVisibleがTRUEなら.
		BitBlt(m_pScene->m_hMemDC, m_x + x + m_iCursorX,  m_y + y + m_iCursorY, m_iCursorWidth, m_iCursorHeight, m_hCursorMemDC, 0, 0, SRCCOPY);	// BitBltでカーソルを描画.
	}

}

// 入力クリア.
void CSelectBox::ClearInput(){

	// 入力クリア.
	m_bDown = FALSE;	// m_bDownをFALSEに初期化.
	m_bUp = FALSE;	// m_bUpをFALSEに初期化.
	m_bReturn = FALSE;	// m_bReturnをFALSEに初期化.

}

// カーソルを下に移動Down.
void CSelectBox::Down(){

	// 下が有効.
	m_bDown = TRUE;	// m_bDownをTRUEにする.

}

// カーソルを上に移動Up.
void CSelectBox::Up(){

	// 上が有効.
	m_bUp = TRUE;	// m_bUpをTRUEにする.

}

// 決定Return.
void CSelectBox::Return(){

	// リターンが有効.
	m_bReturn = TRUE;	// m_bReturnをTRUEにする.

}

// 処理をするProc.
int CSelectBox::Proc(){

	// 未確定の時.
	if (!m_bDetermine){	// m_bDeterminがFALSE.

		// リターンが押された時.
		if (m_bReturn){	// m_bReturnがTRUE.

			// 確定状態.
			m_bDetermine = TRUE;	// m_bDeterminにTRUEをセット.

			// タイマーのセット.
			SetTimer(100);	// 100ミリ秒(0.1秒)のタイマーをセット.

			// 成功なので0.
			return 0;	// 0を返す.

		}

		// 下が押された時.
		if (m_bDown){	// m_bDownがTRUE.
			m_iCursorIndex++;	// m_iCursorIndexをインクリメント.
		}

		// 上が押された時.
		if (m_bUp){	// m_bUpがTRUE.
			m_iCursorIndex--;	// m_iCursorIndexをデクリメント.
		}

		// インデックスが要素数以上の時.
		if (m_iCursorIndex > (int)m_vectstrSelectItemList.size() - 1){	// 最後の要素を越えたら.
			m_iCursorIndex = 0;	// 0にする.
		}

		// インデックスが0未満の時.
		if (m_iCursorIndex < 0){	// 0未満の時.
			m_iCursorIndex = (int)m_vectstrSelectItemList.size() - 1;	// 最後の要素にする.
		}

	}
	else{	// m_bDetermineがTRUEの時.

		// タイマー発生ごとに切り替える.
		if (IsElapsed()){	// IsElapsedがTRUE.
			if (m_bCursorVisible){	// TRUEなら
				m_bCursorVisible = FALSE;	// FALSEに切り替え.
			}
			else{	// FALSEなら
				m_bCursorVisible = TRUE;	// TRUEに切り替え.
			}
		}

	}

	// 成功なので0.
	return 0;	// 0を返す.

}

// タイマーのセットSetTimer.
void CSelectBox::SetTimer(DWORD dwInterval){

	// インターバルのセット.
	m_dwInterval = dwInterval;	// m_dwIntervalにdwIntervalをセット.

	// タイマーのセット.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	m_dwTimerStart = pTime->Get();	// pTime->Getで取得した時刻をm_dwTimerStartに格納.

}

// タイマーが経過時間を過ぎたかをチェックIsElapsed.
BOOL CSelectBox::IsElapsed(){

	// 現在時刻の取得.
	const CScene *pScene = m_pScene;	// m_pSceneをpSceneに格納.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTimeをpTimeに格納.
	DWORD dwNow = pTime->Get();	// pTime->Getで取得した時刻をdwNowに格納.

	// 経過時間チェック.
	if (dwNow - m_dwTimerStart >= m_dwInterval){	// m_dwInterval以上なら.
		m_dwTimerStart = dwNow;	// dwNowをm_dwTimerStartにセット.
		return TRUE;	// TRUEを返す.
	}
	else{
		return FALSE;	// FALSEを返す.
	}

}