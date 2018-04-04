// ��d�C���N���[�h�h�~
#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene
#include "Background.h"	// CBackground

// �^�C�g���V�[���N���XCTitleScene
class CTitleScene : public CScene{

	// public�����o
	public:

		// public�����o�ϐ�
		CBackground *m_pBackground;	// �w�i�I�u�W�F�N�gm_pBackground.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CTitleScene();	// �R���X�g���N�^CTitleScene
		CTitleScene(const CWindow *pWnd);	// �R���X�g���N�^CTitleScene(const CWindow *pWnd)
		virtual ~CTitleScene();	// �f�X�g���N�^~CTitleScene
		virtual int InitGameObjects();	// �Q�[���I�u�W�F�N�g�̏�����.
		virtual int InitKeyboard();	// �L�[�{�[�h�̏�����.
		virtual int CheckKeyboard();	// �L�[�{�[�h�̃`�F�b�N.
		virtual int RunProc();	// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
		virtual int DrawGameObjects();	// �Q�[���I�u�W�F�N�g�̕`��.
		virtual int ExitGameObjects();	// �Q�[���I�u�W�F�N�g�̏I������.

};

#endif