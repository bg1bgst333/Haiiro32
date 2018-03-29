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
		HDC m_hDC;	// �E�B���h�E�f�o�C�X�R���e�L�X�gm_hDC.
		HDC m_hMemDC;	// �������f�o�C�X�R���e�L�X�gm_hMemDC.
		HBITMAP m_hMemBitmap;	// �������r�b�g�}�b�vm_hMemBitmap.
		HBITMAP m_hOldMemBitmap;	// ���̃������r�b�g�}�b�vm_hOldMemBitmap.
		HPEN m_hBackPen;	// �w�i�y��m_hBackPen.
		HPEN m_hOldBackPen;	// ���̔w�i�y��m_hOldBackPen.
		HBRUSH m_hBackBrush;	// �w�i�u���Vm_hBackBrush.
		HBRUSH m_hOldBackBrush;	// ���̔w�i�u���Vm_hOldBackBrush.
		HPEN m_hCursorPen;	// �J�[�\���y��m_hCursorPen.
		HPEN m_hOldCursorPen;	// ���̃J�[�\���y��m_hOldCursorPen.
		HBRUSH m_hCursorBrush;	// �J�[�\���u���Vm_hCursorBrush.
		HBRUSH m_hOldCursorBrush;	// �J�[�\���u���Vm_hOldCursorBrush.
		int m_iCursorX;	// �J�[�\����x���Wm_iCursorX.
		int m_iCursorY;	// �J�[�\����y���Wm_iCursorY.

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