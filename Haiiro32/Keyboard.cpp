// ヘッダのインクルード
// 独自のヘッダ
#include "Keyboard.h"	// CKeyoard

// コンストラクタCKeyboard()
CKeyboard::CKeyboard(){

	// メンバの初期化.
	Clear();	// Clearでクリア.

}

// デストラクタ~CKeyboard()
CKeyboard::~CKeyboard(){

	// メンバのクリア.
	Clear();	// Clearでクリア.

}

// キーの追加.
void CKeyboard::AddKey(int iKey){

	// 監視するキーの追加.
	m_veciKeyList.push_back(iKey);	// m_veciKeyList.push_backでiKeyの追加.

}

// キーのクリア.
void CKeyboard::Clear(){

	// キーリストとキー状態配列をクリア.
	m_veciKeyList.clear();	// m_veciKeyList.clearでクリア.
	ZeroMemory(m_arybtKeys, sizeof(BYTE) * 256);	// ZeroMemoryでm_arybtKeysをクリア.
	ZeroMemory(m_aryiPressKeys, sizeof(int) * 256);	// ZeroMemoryでm_aryiPressKeysをクリア.

}

// 要素数の取得.
size_t CKeyboard::GetLength(){

	// キーリストの長さを返す.
	return m_veciKeyList.size();	// m_veciKeyList.sizeで要素数を返す.

}

// キーボード状態のチェック.
BOOL CKeyboard::Check(){

	// キー状態の取得.
	return GetKeyboardState(m_arybtKeys);	// GetKeyboardStateで状態を取得し, 戻り値を返す.

}

// iNo番目が押されている状態を返す.
BOOL CKeyboard::IsDown(int iNo){

	// 押されているかをチェック.
	if (m_arybtKeys[m_veciKeyList[iNo]] & 0x80){	// 現在押されているかは最上位ビット(0x80)でAND演算.
		if (m_aryiPressKeys[m_veciKeyList[iNo]] == 0){	// 押されていなかった.
			m_aryiPressKeys[m_veciKeyList[iNo]] = 1;	// 押されている状態にする.
		}
		else if (m_aryiPressKeys[m_veciKeyList[iNo]] >= 1){	// すでに押されている状態.
			m_aryiPressKeys[m_veciKeyList[iNo]] = 2;	// 押しっぱなし状態.
		}
		return TRUE;	// TRUEを返す.
	}
	// 押されていない.
	m_aryiPressKeys[m_veciKeyList[iNo]] = 0;	// 押されていないにリセット.
	return FALSE;	// 押されていないならFALSE.

}

// iNo番目が押された瞬間かを返す.
BOOL CKeyboard::IsPress(int iNo){
	
	// 押した瞬間かどうかをチェック.
	if (m_aryiPressKeys[m_veciKeyList[iNo]] == 1){	// 押した瞬間だけ.
		return TRUE;
	}
	return FALSE;	// 押した瞬間でないならFALSE.

}