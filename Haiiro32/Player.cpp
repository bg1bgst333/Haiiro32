// ヘッダのインクルード
// 独自のヘッダ
#include "Player.h"	// CPlayer
#include "Shot.h"	// CShot
#include "resource.h"	// リソース.

// コンストラクタCPlayer
CPlayer::CPlayer() : CCharacter(){

	// メンバの初期化.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_iNo = 0;	// m_iNoに0をセット.
	m_vecpShotList.clear(); // m_vecpShotList.clearでクリア.

}

// デストラクタCPlayer(CScene *pScene)
CPlayer::CPlayer(CScene *pScene) : CCharacter(pScene){

	// メンバの初期化.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.
	m_iNo = 0;	// m_iNoに0をセット.
	m_vecpShotList.clear(); // m_vecpShotList.clearでクリア.

}

// デストラクタ~CPlayer()
CPlayer::~CPlayer(){

	// メンバの終了処理.
	m_iNo = 0;	// m_iNoに0をセット.

	// クリア
	Clear();	// Clearでフラグのクリア.

	// 破棄.
	Destroy();	// Destroyで破棄.

}

// キャラクターの破棄Destroy.
void CPlayer::Destroy(){

	// ショットの破棄.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpShotList.begin(); itor != m_vecpShotList.end(); itor++){	// リスト全ての破棄.
		if ((*itor) != NULL){	// (*itor)がNULLじゃない時.
			(*itor)->Destroy();	// (*itor)->Destroyで破棄.
			delete (*itor);	// deleteで(*Itor)を破棄.
			(*itor) = NULL;	// NULLをセット.
		}
	}
	m_vecpShotList.clear();	// クリア.

	// 親クラスのメンバ関数.
	CCharacter::Destroy();	// CCharacter::Destroyで破棄.

}

// マップの移動状態をクリア.
void CPlayer::Clear(){

	// フラグのクリア.
	m_bDown = FALSE;	// m_bDownにFALSEをセット.
	m_bUp = FALSE;	// m_bUpにFALSEをセット.
	m_bRight = FALSE;	// m_bRightにFALSEをセット.
	m_bLeft = FALSE;	// m_bLeftにFALSEをセット.

}

// マップの視点を下に移動Down.(マップ自体は上に移動.)
void CPlayer::Down(){

	// 下のフラグ.
	m_bDown = TRUE;	// m_bDownにTRUEをセット.

}

// マップの視点を上に移動Up.(マップ自体は下に移動.)
void CPlayer::Up(){

	// 上のフラグ.
	m_bUp = TRUE;	// m_bUpにTRUEをセット.

}

// マップの視点を右に移動Right.(マップ自体は左に移動.)
void CPlayer::Right(){

	// 右のフラグ.
	m_bRight = TRUE;	// m_bRightにTRUEをセット.

}

// マップの視点を左に移動Ledt.(マップ自体は右に移動.))
void CPlayer::Left(){

	// 左のフラグ.
	m_bLeft = TRUE;	// m_bLeftにTRUEをセット.

}

// 処理をするProc.
int CPlayer::Proc(){

	// 下.
	if (m_bDown){	// 下が押された時.
		m_y++;	// m_yを増やす.
		if (m_y >= 480 - 32){	// 上限超.
			m_y = 480 - 32;	// 上限.
		}
	}
	// 上.
	if (m_bUp){	// 上が押された時.
		m_y--;	// m_yを減らす.
		if (m_y <= 0){		// 下限超.
			m_y = 0;	// 下限.
		}
	}
	Set(0);	// 中央をセット.
	// 右.
	if (m_bRight){	// 右が押された時.
		m_x++;	// m_xを増やす.
		if (m_x >= 640 - 32){	// 上限超.
			m_x = 640 - 32;	// 上限.
		}
		Set(1);	// 右をセット.
	}
	// 左.
	if (m_bLeft){	// 左が押された時.
		m_x--;	// m_xを減らす.
		if (m_x <= 0){		// 下限超.
			m_x = 0;	// 下限.
		}
		Set(2);	// 左をセット.
	}

	// シーン継続なら0.
	return 0;	// 0を返す.

}

// 位置をセットするSet.
void CPlayer::Set(int x, int y){

	// メンバのセット.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.

}

// アニメーションをセットするSet.
void CPlayer::Set(int iNo){

	// アニメーションのセット.
	m_iNo = iNo;	// m_iNoにiNoをセット.

}

// 描画をするDraw.
void CPlayer::Draw(){

	// 描画.
	//CCharacter::Draw(m_x, m_y, m_iNo);	// CCharacter::Drawで描画.
	CCharacter::DrawSprite(m_x, m_y, m_iNo);	// CCharacter::DrawSpriteで描画.

}

// ショットを描画するDrawShot.
void CPlayer::DrawShot(){

	// ショットの描画.
	for (int i = 0; i < m_vecpShotList.size(); i++){
		((CShot *)m_vecpShotList[i])->DrawSprite(((CShot *)m_vecpShotList[i])->m_x, ((CShot *)m_vecpShotList[i])->m_y, 0);	// 描画.
	}

}

// ショットの作成CreateShot.
void CPlayer::CreateShot(int iSize){

	// ショットの作成.
	for (int i = 0; i < iSize; i++){	// iSize個繰り返す.
		CShot *pShot = new CShot(m_pScene);	// CShotオブジェクトの作成.
		pShot->Add(0, 32, 4, 32, IDB_SHARED2);	// イメージ追加.
		pShot->AddMask(320 + 0, 32, 4, 32, IDB_SHARED2);	// イメージ追加.
		pShot->m_x = m_x;
		pShot->m_y = m_y;
		m_vecpShotList.push_back(pShot);	// m_vecpShotList.push_backで追加.
	}

}