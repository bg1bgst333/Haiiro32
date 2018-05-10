// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Player.h"	// CPlayer
#include "Shot.h"	// CShot
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CPlayer
CPlayer::CPlayer() : CCharacter(){

	// �����o�̏�����.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	m_vecpShotList.clear(); // m_vecpShotList.clear�ŃN���A.

}

// �f�X�g���N�^CPlayer(CScene *pScene)
CPlayer::CPlayer(CScene *pScene) : CCharacter(pScene){

	// �����o�̏�����.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_iNo = 0;	// m_iNo��0���Z�b�g.
	m_vecpShotList.clear(); // m_vecpShotList.clear�ŃN���A.

}

// �f�X�g���N�^~CPlayer()
CPlayer::~CPlayer(){

	// �����o�̏I������.
	m_iNo = 0;	// m_iNo��0���Z�b�g.

	// �N���A
	Clear();	// Clear�Ńt���O�̃N���A.

	// �j��.
	Destroy();	// Destroy�Ŕj��.

}

// �L�����N�^�[�̔j��Destroy.
void CPlayer::Destroy(){

	// �V���b�g�̔j��.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpShotList.begin(); itor != m_vecpShotList.end(); itor++){	// ���X�g�S�Ă̔j��.
		if ((*itor) != NULL){	// (*itor)��NULL����Ȃ���.
			(*itor)->Destroy();	// (*itor)->Destroy�Ŕj��.
			delete (*itor);	// delete��(*Itor)��j��.
			(*itor) = NULL;	// NULL���Z�b�g.
		}
	}
	m_vecpShotList.clear();	// �N���A.

	// �e�N���X�̃����o�֐�.
	CCharacter::Destroy();	// CCharacter::Destroy�Ŕj��.

}

// �}�b�v�̈ړ���Ԃ��N���A.
void CPlayer::Clear(){

	// �t���O�̃N���A.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.

}

// �}�b�v�̎��_�����Ɉړ�Down.(�}�b�v���̂͏�Ɉړ�.)
void CPlayer::Down(){

	// ���̃t���O.
	m_bDown = TRUE;	// m_bDown��TRUE���Z�b�g.

}

// �}�b�v�̎��_����Ɉړ�Up.(�}�b�v���͉̂��Ɉړ�.)
void CPlayer::Up(){

	// ��̃t���O.
	m_bUp = TRUE;	// m_bUp��TRUE���Z�b�g.

}

// �}�b�v�̎��_���E�Ɉړ�Right.(�}�b�v���͍̂��Ɉړ�.)
void CPlayer::Right(){

	// �E�̃t���O.
	m_bRight = TRUE;	// m_bRight��TRUE���Z�b�g.

}

// �}�b�v�̎��_�����Ɉړ�Ledt.(�}�b�v���͉̂E�Ɉړ�.))
void CPlayer::Left(){

	// ���̃t���O.
	m_bLeft = TRUE;	// m_bLeft��TRUE���Z�b�g.

}

// ����������Proc.
int CPlayer::Proc(){

	// ��.
	if (m_bDown){	// ���������ꂽ��.
		m_y++;	// m_y�𑝂₷.
		if (m_y >= 480 - 32){	// �����.
			m_y = 480 - 32;	// ���.
		}
	}
	// ��.
	if (m_bUp){	// �オ�����ꂽ��.
		m_y--;	// m_y�����炷.
		if (m_y <= 0){		// ������.
			m_y = 0;	// ����.
		}
	}
	Set(0);	// �������Z�b�g.
	// �E.
	if (m_bRight){	// �E�������ꂽ��.
		m_x++;	// m_x�𑝂₷.
		if (m_x >= 640 - 32){	// �����.
			m_x = 640 - 32;	// ���.
		}
		Set(1);	// �E���Z�b�g.
	}
	// ��.
	if (m_bLeft){	// ���������ꂽ��.
		m_x--;	// m_x�����炷.
		if (m_x <= 0){		// ������.
			m_x = 0;	// ����.
		}
		Set(2);	// �����Z�b�g.
	}

	// �V�[���p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �ʒu���Z�b�g����Set.
void CPlayer::Set(int x, int y){

	// �����o�̃Z�b�g.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.

}

// �A�j���[�V�������Z�b�g����Set.
void CPlayer::Set(int iNo){

	// �A�j���[�V�����̃Z�b�g.
	m_iNo = iNo;	// m_iNo��iNo���Z�b�g.

}

// �`�������Draw.
void CPlayer::Draw(){

	// �`��.
	//CCharacter::Draw(m_x, m_y, m_iNo);	// CCharacter::Draw�ŕ`��.
	CCharacter::DrawSprite(m_x, m_y, m_iNo);	// CCharacter::DrawSprite�ŕ`��.

}

// �V���b�g��`�悷��DrawShot.
void CPlayer::DrawShot(){

	// �V���b�g�̕`��.
	for (int i = 0; i < m_vecpShotList.size(); i++){
		((CShot *)m_vecpShotList[i])->DrawSprite(((CShot *)m_vecpShotList[i])->m_x, ((CShot *)m_vecpShotList[i])->m_y, 0);	// �`��.
	}

}

// �V���b�g�̍쐬CreateShot.
void CPlayer::CreateShot(int iSize){

	// �V���b�g�̍쐬.
	for (int i = 0; i < iSize; i++){	// iSize�J��Ԃ�.
		CShot *pShot = new CShot(m_pScene);	// CShot�I�u�W�F�N�g�̍쐬.
		pShot->Add(0, 32, 4, 32, IDB_SHARED2);	// �C���[�W�ǉ�.
		pShot->AddMask(320 + 0, 32, 4, 32, IDB_SHARED2);	// �C���[�W�ǉ�.
		pShot->m_x = m_x;
		pShot->m_y = m_y;
		m_vecpShotList.push_back(pShot);	// m_vecpShotList.push_back�Œǉ�.
	}

}