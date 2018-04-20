// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameSystem.h"	// CGameSystem

// �R���X�g���N�^CGameSystem
CGameSystem::CGameSystem(){

	// �����o�̏�����.
	m_iMode = 0;	// m_iMode��0�ŏ�����.
	m_pSharedResources = NULL;	// m_pSharedResources��NULL�ŏ�����.

}

// �f�X�g���N�^~CGameSystem
CGameSystem::~CGameSystem(){

	// �����o�̏I������.
	m_iMode = 0;	// m_iMode��0���Z�b�g.
	Exit();	// �I������.

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

// ������.
void CGameSystem::Init(HINSTANCE hInstance){

	// �V�F�A�[�h���\�[�X����.
	m_pSharedResources = new CSharedResources(hInstance);	// CSharedResources�̃R���X�g���N�^��hInstance��n���Đ���.

}

// �I������.
void CGameSystem::Exit(){

	// �V�F�A�[�h���\�[�X�j��.
	if (m_pSharedResources != NULL){	// m_pSharedResources��NULL.
		delete m_pSharedResources;	// delete��m_pSharedResources���폜.
		m_pSharedResources = NULL;	// m_pSharedResources��NULL���Z�b�g.
	}

}