// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameTime.h"	// CGameTime

// �R���X�g���N�^CGameTime
CGameTime::CGameTime(){

	// �����o�̏�����.
	m_dwMilliTime = 0;	// m_dwMilliTime��0�ŏ�����.
	m_dwUserMilliTime = 0;	// m_dwUserMilliTime��0�ŏ�����.
	m_dwUserStartMilliTime = 0;	// m_dwUserStartMilliTime��0�ŏ�����.
	m_dwFrame = 0;	// m_dwFrame��0�ŏ�����.
	m_dwFrameStartMilliTime = 0;	// m_dwFrameStartMilliTime��0�ŏ�����.
	m_dwFPS = 0;	// m_dwFPS��0�ŏ�����.

}

// �f�X�g���N�^~CGameTime
CGameTime::~CGameTime(){

	// �����o�̏I������.
	m_dwMilliTime = 0;	// m_dwMilliTime��0�ɃZ�b�g.
	m_dwUserMilliTime = 0;	// m_dwUserMilliTime��0�ŏ�����.
	m_dwUserStartMilliTime = 0;	// m_dwUserStartMilliTime��0�ŏ�����.
	m_dwFrame = 0;	// m_dwFrame��0�ŏ�����.
	m_dwFrameStartMilliTime = 0;	// m_dwFrameStartMilliTime��0�ŏ�����.
	m_dwFPS = 0;	// m_dwFPS��0�ŏ�����.

}

// �V�X�e���������~���b�ŕԂ�GetSystemTime.
DWORD CGameTime::GetSystemTime(){

	// �V�X�e��������Ԃ�.
	m_dwMilliTime = timeGetTime();	// timeGetTime�̒l��m_dwMilliTime�Ɋi�[.
	return m_dwMilliTime;	// m_dwMilliTime��Ԃ�.

}

// ���[�U�������~���b�ŕԂ�GetUserTime.
DWORD CGameTime::GetUserTime(){

	// ���[�U������Ԃ�.
	m_dwUserMilliTime = GetSystemTime() - m_dwUserStartMilliTime;	// GetSystemTime() - m_dwUserStartMilliTime�Ń��[�U�^�C���Z�o.
	return m_dwUserMilliTime;	// m_dwUserMilliTime��Ԃ�.

}

// ���[�U�����̃��Z�b�gResetUserTime.
void CGameTime::ResetUserTime(){

	// �X�^�[�g���������ݎ����ɂ���.
	m_dwUserStartMilliTime = GetSystemTime();	// m_dwUserStartMilliTime��GetSystemTime()�̒l���Z�b�g.

}

// �t���[�����̃J�E���gCountFrame.
void CGameTime::CountFrame(){

	// �t���[�����̃J�E���g.
	m_dwFrame++;	// m_dwFrame���C���N�������g.

}

// �t���[�����̃��Z�b�gResetFrame.
void CGameTime::ResetFrame(){

	// �t���[�����̃��Z�b�g.
	m_dwFrame = 0;	// m_dwFrame��0�Ƀ��Z�b�g.
	m_dwFrameStartMilliTime = GetUserTime();	// m_dwFrameStartMilliTime��GetUserTime�̒l���Z�b�g.

}

// 1�b�o�߂������ǂ���IsNextSecond.
BOOL CGameTime::IsNextSecond(){

	// 1�b�o�߂������`�F�b�N.
	if (GetUserTime() - m_dwFrameStartMilliTime >= 1000){	// 1�b�ȏ㍷����������.
		m_dwFPS = m_dwFrame;	// m_dwFPS��m_dwFrame����.
		return TRUE;	// TRUE��Ԃ�.
	}
	else{
		return FALSE;	// FALSE��Ԃ�.
	}

}

// FPS�l�̎擾GetFPS.
DWORD CGameTime::GetFPS(){

	// FPS��Ԃ�.
	return m_dwFPS;	// m_dwFPS��Ԃ�.

}