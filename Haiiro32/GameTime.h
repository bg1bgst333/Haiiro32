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

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CGameTime();	// �R���X�g���N�^CGameTime
		virtual ~CGameTime();	// �f�X�g���N�^~CGameTime
		// �����o�֐�
		DWORD Get();	// �V�X�e���������~���b�ŕԂ�Get.

};

#endif