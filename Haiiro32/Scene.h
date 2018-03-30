// ��d�C���N���[�h�h�~
#ifndef __SCENE_H__
#define __SCENE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �V�[���N���XCScene
class CScene{

	// public�����o
	public:

		// public�����o�ϐ�
		const CWindow *m_pMainWnd;	// CWindow�I�u�W�F�N�g�|�C���^m_pMainWnd.(const)

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CScene();	// �R���X�g���N�^CScene
		CScene(const CWindow *pWnd);	// �R���X�g���N�^CScene(const CWindow *pWnd)
		virtual ~CScene();	// �f�X�g���N�^~CScene
		virtual int InitScene();	// �V�[��������InitScene.
		virtual int RunScene();	// �V�[��������RunScene.
		virtual int ExitScene();	// �V�[���I������ExitScene.

};

#endif