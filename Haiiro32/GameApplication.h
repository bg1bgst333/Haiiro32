// ��d�C���N���[�h�h�~
#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "Scene.h"	// CScene
#include "GameTime.h"	// CGameTime

// �Q�[���A�v���P�[�V�����N���XCGameApplication
class CGameApplication : public CGraphicalApplication{

	// public�����o
	public:

		// public�����o�ϐ�
		CScene *m_pScene;	// CScene�I�u�W�F�N�g�|�C���^m_pScene.
		CGameTime *m_pGameTime;	// CGameTime�I�u�W�F�N�g�|�C���^m_pGameTime.
		int m_iNo;	// �ԍ�m_iNo.

		// public�����o�֐�
		// �R���X�g���N�^
		CGameApplication();	// �R���X�g���N�^CGameApplication

		// �����o�֐�.
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �C���X�^���X�������֐�InitInstance.
		virtual int ExitInstance();	// �I�������֐�ExitInstance.
		virtual int Main();	// �Q�[�����C�������֐�Main.

};

#endif