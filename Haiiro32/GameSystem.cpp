// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameSystem.h"	// CGameSystem

// �R���X�g���N�^CGameSystem
CGameSystem::CGameSystem(){

	// �����o�̏�����.
	m_iMode = 0;	// m_iMode��0�ŏ�����.
}

// �f�X�g���N�^~CGameSystem
CGameSystem::~CGameSystem(){

	// �����o�̏I������.
	m_iMode = 0;	// m_iMode��0���Z�b�g.

}

// ���[�h�̐ݒ�SetMode.
void CGameSystem::SetMode(int iMode){

	// �����o�ɐݒ�.
	m_iMode = iMode;	// m_iMode��iMode���Z�b�g.

}

// ���[�h�̎擾GetMode.
int CGameSystem::GetMode(){

	// �����o���擾.
	return m_iMode;	// m_iMode��Ԃ�.

}