// ��d�C���N���[�h�h�~
#ifndef __MENU_WINDOW_H__
#define __MENU_WINDOW_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "MenuBar.h"	// CMenuBar

// ���j���[�E�B���h�E�N���XCMenuWindow
class CMenuWindow : public CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		CMenuBar *m_pMenuBar;	// CMenuBar�I�u�W�F�N�g�|�C���^m_pMenuBar

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMenuWindow();	// �R���X�g���N�^CMenuWindow()
		virtual ~CMenuWindow();	// �f�X�g���N�^~CMenuWindow()
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�v���V�[�W���ȗ�, ���j���[���w��o�[�W����.)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.

};

#endif