// ��d�C���N���[�h�h�~
#ifndef __GAME_SYSTEM_H__
#define __GAME_SYSTEM_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// �Q�[���V�X�e���N���XCGameSystem
class CGameSystem{

	// public�����o
	public:

		// public�����o�ϐ�
		int m_iMode;	// ���[�hm_iMode.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CGameSystem();	// �R���X�g���N�^CGameSystem
		virtual ~CGameSystem();	// �f�X�g���N�^~CGameSystem
		// �����o�֐�
		void SetMode(int iMode);	// ���[�h�̐ݒ�SetMode.
		int GetMode();	// ���[�h�̎擾GetMode.

};

#endif