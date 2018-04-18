// ��d�C���N���[�h�h�~
#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene
#include "Background.h"	// CBackground
#include "Title.h"	// CTitle
#include "SelectBox.h"	// CSelectBox
#include "GameTimeBox.h"	// CGameTimeBox

// �^�C�g���V�[���N���XCTitleScene
class CTitleScene : public CScene{

	// public�����o
	public:

		// public�����o�ϐ�
		CBackground *m_pBackground;	// �w�i�I�u�W�F�N�gm_pBackground.
		CTitle *m_pTitle;	// �^�C�g���I�u�W�F�N�gm_pTitle.
		CSelectBox *m_pSelectBox;	// �Z���N�g�{�b�N�Xm_pSelectBox.
		CGameTimeBox *m_pGameTimeBox;	// �Q�[���^�C���{�b�N�Xm_pGameTimeBox.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CTitleScene();	// �R���X�g���N�^CTitleScene
		CTitleScene(const CWindow *pWnd);	// �R���X�g���N�^CTitleScene(const CWindow *pWnd)
		CTitleScene(const CWindow *pWnd, CGameTime *pTime);	// �R���X�g���N�^CTitleScene(const CWindow *pWnd, CGameTime *pTime)
		CTitleScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// �R���X�g���N�^CTitleScnen(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CTitleScene();	// �f�X�g���N�^~CTitleScene
		virtual int InitGameObjects();	// �Q�[���I�u�W�F�N�g�̏�����.
		virtual int InitKeyboard();	// �L�[�{�[�h�̏�����.
		virtual int CheckKeyboard();	// �L�[�{�[�h�̃`�F�b�N.
		virtual int RunProc();	// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
		virtual int DrawGameObjects();	// �Q�[���I�u�W�F�N�g�̕`��.
		virtual int ExitGameObjects();	// �Q�[���I�u�W�F�N�g�̏I������.

};

#endif