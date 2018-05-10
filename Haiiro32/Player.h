// 二重インクルード防止
#ifndef __PLAYER_H__
#define __PLAYER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Character.h"	// CCharacter

// プレイヤークラスCPlayer
class CPlayer : public CCharacter{

	// publicメンバ
	public:

		// publicメンバ変数
		BOOL m_bDown;	// 下が押されているフラグm_bDown.
		BOOL m_bUp;	// 上が押されているフラグm_bUp.
		BOOL m_bRight;	// 右が押されているフラグm_bRight.
		BOOL m_bLeft;	// 左が押されているフラグm_bLeft.
		BOOL m_bShot;	// ショットが押されているフラグm_bShot.
		int m_iNo;	// アニメーション番号m_iNo.
		std::vector<CSharedObject *> m_vecpShotList;	// ショットリストm_vecpShotList.
		int m_iShotIdx;	// ショットのインデックス.(発射する番号.)

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CPlayer();	// コンストラクタCPlayer
		CPlayer(CScene *pScene);	// デストラクタCPlayer(CScene *pScene)
		virtual ~CPlayer();	// デストラクタ~CPlayer()
		virtual void Destroy();	// キャラクターの破棄Destroy.
		virtual void Clear();	// マップの移動状態をクリア.
		virtual void Down();	// マップの視点を下に移動Down.(マップ自体は上に移動.)
		virtual void Up();	// マップの視点を上に移動Up.(マップ自体は下に移動.)
		virtual void Right();	// マップの視点を右に移動Right.(マップ自体は左に移動.)
		virtual void Left();	// マップの視点を左に移動Ledt.(マップ自体は右に移動.))
		virtual void Shot();	// ショット発射.
		virtual int Proc();	// 処理をするProc.
		virtual void Set(int x, int y);	// 位置をセットするSet.
		virtual void Set(int iNo);	// アニメーションをセットするSet.
		virtual void Draw();	// 描画をするDraw.
		virtual void DrawShot();	// ショットを描画するDrawShot.
		virtual void CreateShot(int iSize);	// ショットの作成CreateShot.

};

#endif