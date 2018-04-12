// ��d�C���N���[�h�h�~
#ifndef __GAME_TIME_H__
#define __GAME_TIME_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <mmsystem.h>	// �}���`���f�B�A

// �Q�[���^�C���N���XCGameTime
class CGameTime{

	// public�����o
	public:

		// public�����o�ϐ�
		DWORD m_dwMilliTime;	// �~���bm_dwMilliTime.
		DWORD m_dwUserMilliTime;	// �C�ӂ̎��Ԃ���̃~���bm_dwUserMilliTime.
		DWORD m_dwUserStartMilliTime;	// �C�ӂ̊J�n����m_dwUserStartMilliTime.
		DWORD m_dwFrame;	// �t���[����m_dwFrame.
		DWORD m_dwFPS;	// FPS�lm_dwFPS.
		DWORD m_dwFrameStartMilliTime;	// �t���[���v���J�n����m_dwFrameStartMilliTime.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CGameTime();	// �R���X�g���N�^CGameTime
		virtual ~CGameTime();	// �f�X�g���N�^~CGameTime
		// �����o�֐�
		DWORD GetSystemTime();	// �V�X�e���������~���b�ŕԂ�GetSystemTime.
		DWORD GetUserTime();	// ���[�U�������~���b�ŕԂ�GetUserTime.
		void ResetUserTime();	// ���[�U�����̃��Z�b�gResetUserTime.
		void CountFrame();	// �t���[�����̃J�E���gCountFrame.
		void ResetFrame();	// �t���[�����̃��Z�b�gResetFrame.
		BOOL IsNextSecond();	// 1�b�o�߂������ǂ���IsNextSecond.
		DWORD GetFPS();	// FPS�l�̎擾GetFPS.

};

#endif