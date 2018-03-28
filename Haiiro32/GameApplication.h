// ��d�C���N���[�h�h�~
#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GraphicalApplication.h"	// CGraphicalApplication

// �Q�[���A�v���P�[�V�����N���XCGameApplication
class CGameApplication : public CGraphicalApplication{

	// public�����o
	public:

		// public�����o�ϐ�
		int m_iSceneNo;	// �V�[���ԍ�m_iSceneNo.
		int m_iSceneStatus;	// �V�[����Ԃ�\���ϐ�m_iSceneStatus.

		// public�����o�֐�
		// �R���X�g���N�^
		CGameApplication();	// �R���X�g���N�^CGameApplication
		// �����o�֐�.
		virtual int Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// �Q�[�����C�������֐�Main.
		virtual int InitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// �V�[���̏�����InitScene.
		virtual int RunScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// �V�[���̏�����RunScene.
		virtual int ExitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// �V�[���̏I������ExitScene.

};

#endif