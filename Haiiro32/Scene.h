// ��d�C���N���[�h�h�~
#ifndef __SCENE_H__
#define __SCENE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "Keyboard.h"	// CKeyboard
#include "GameObject.h"	// CGameObject
#include "GameTime.h"	// CGameTime
#include "GameSystem.h"	// CGameSystem

// �O���錾.
class CGameObject;	// CGameObject.

// �V�[���N���XCScene
class CScene{

	// public�����o
	public:

		// public�����o�ϐ�
		const CWindow *m_pMainWnd;	// CWindow�I�u�W�F�N�g�|�C���^m_pMainWnd.(const)
		CGameTime *m_pGameTime;	// CGameTime�I�u�W�F�N�g�|�C���^m_pGameTime.
		CGameSystem *m_pGameSystem;	// CGameSystem�I�u�W�F�N�g�|�C���^m_pGameSystem.
		HDC m_hDC;	// �E�B���h�E�f�o�C�X�R���e�L�X�g�n���h��m_hDC.
		HDC m_hMemDC;	// �������f�o�C�X�R���e�L�X�g�n���h��m_hMemDC.
		HBITMAP m_hMemBitmap;	// �������r�b�g�}�b�v�n���h��m_hMemBitmap.
		HBITMAP m_hOldMemBitmap;	// ���̃������r�b�g�}�b�v�n���h��m_hOldMemBitmap.
		int m_iScreenWidth;	// �X�N���[����.
		int m_iScreenHeight;	// �X�N���[������.
		CKeyboard *m_pKeyboard;	// �L�[�{�[�h�I�u�W�F�N�gm_pKeyboard.
		CGameObject *m_pTest;	// �e�X�g�I�u�W�F�N�gm_pTest.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CScene();	// �R���X�g���N�^CScene
		CScene(const CWindow *pWnd);	// �R���X�g���N�^CScene(const CWindow *pWnd)
		CScene(const CWindow *pWnd, CGameTime *pTime);	// �R���X�g���N�^CScene(const CWindow *pWnd, CGameTime *pTime)
		CScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// �R���X�g���N�^CScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CScene();	// �f�X�g���N�^~CScene
		virtual int InitScene();	// �V�[��������InitScene.
		virtual int RunScene();	// �V�[��������RunScene.
		virtual int ExitScene();	// �V�[���I������ExitScene.
		virtual void ResizeWindow(int iWidth, int iHeight);	// �E�B���h�E�̃��T�C�YResizeWindow.
		virtual void CreateScreen(int iWidth, int iHeight);	// �X�N���[���̍쐬CreateScreen.
		virtual void Present();	// �o�b�N�o�b�t�@����t�����g�o�b�t�@�֓]�����邱�Ƃŉ�ʂ�`�悷��Present.
		virtual void DestroyScreen();	// �X�N���[���̔j��DestroyScreen.
		virtual int InitGameObjects();	// �Q�[���I�u�W�F�N�g�̏�����.
		virtual int InitKeyboard();	// �L�[�{�[�h�̏�����.
		virtual int CheckClose();	// ����{�^���̃`�F�b�N.
		virtual int CheckKeyboard();	// �L�[�{�[�h�̃`�F�b�N.
		virtual int RunProc();	// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
		virtual int DrawGameObjects();	// �Q�[���I�u�W�F�N�g�̕`��.
		virtual int ExitGameObjects();	// �Q�[���I�u�W�F�N�g�̏I������.
		virtual int ExitKeyboard();	// �L�[�{�[�h�̏I������.

};

#endif