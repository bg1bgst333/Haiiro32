// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameTime.h"	// CGameTime

// �R���X�g���N�^CGameTime
CGameTime::CGameTime(){

	// �����o�̏�����.
	m_dwMilliTime = 0;	// m_dwMilliTime��0�ŏ�����.

}

// �f�X�g���N�^~CGameTime
CGameTime::~CGameTime(){

	// �����o�̏I������.
	m_dwMilliTime = 0;	// m_dwMilliTime��0�ɃZ�b�g..

}

// �V�X�e���������~���b�ŕԂ�Get.
DWORD CGameTime::Get(){

	// �V�X�e��������Ԃ�.
	m_dwMilliTime = timeGetTime();	// timeGetTime�̒l��m_dwMilliTime�Ɋi�[.
	return m_dwMilliTime;	// m_dwMilliTime��Ԃ�.

}