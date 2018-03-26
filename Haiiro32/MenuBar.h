// ��d�C���N���[�h�h�~
#ifndef __MENU_BAR_H__
#define __MENU_BAR_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// ���j���[�o�[�N���XCMenuBar
class CMenuBar{

	// public�����o
	public:

		// public�����o�ϐ�
		HMENU m_hMenu;	// ���j���[�n���h��m_hMenu.
		HWND m_hWnd;	// �ݒu��E�B���h�E�n���h��m_hWnd.

		// public�����o�֐�
		// �R���X�g���N�^
		CMenuBar();	// �R���X�g���N�^CMenuBar()
		CMenuBar(HWND hWnd);	// �R���X�g���N�^CMenuBar(HWND hWnd)
		// �����o�֐�
		virtual BOOL LoadMenu(HINSTANCE hInstance, UINT nID);	// ���j���[�����\�[�X���烍�[�h.
		virtual BOOL SetMenu(HWND hWnd);	// ���j���[�̃Z�b�g.

};

#endif