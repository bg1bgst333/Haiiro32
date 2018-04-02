// 二重インクルード防止
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI
#include <vector>	// std::vector

// キーボードクラスCKeyboard
class CKeyboard{

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<int> m_veciKeyList;	// キーリストm_veciKeyList.
		BYTE m_arybtKeys[256];	// キー状態配列m_arybtKeys.
		int m_aryiPressKeys[256];	// キーが押しっぱなし状態m_aryiPressKeys.
		size_t uiLen;	// 要素数uiLen.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CKeyboard();	// コンストラクタCKyeboard()
		virtual ~CKeyboard();	// デストラクタ~CKeyboard()
		// メンバ関数
		virtual void AddKey(int iKey);	// キーの追加.
		virtual void Clear();	// キーのクリア.
		virtual size_t GetLength();	// 要素数の取得.
		virtual BOOL Check();	// キーボード状態のチェック.
		virtual BOOL IsDown(int iNo);	// iNo番目が押されている状態を返す.
		virtual BOOL IsPress(int iNo);	// iNo番目が押された瞬間かを返す.

};

#endif