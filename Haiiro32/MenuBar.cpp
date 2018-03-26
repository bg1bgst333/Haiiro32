// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuBar.h"	// CMenuBar

// �R���X�g���N�^CMenuBar
CMenuBar::CMenuBar(){

	// �����o�̏�����.
	m_hMenu = NULL;	// m_hMenu��NULL���Z�b�g.
	m_hWnd = NULL;	// m_hWnd��NULL���Z�b�g.

}

// �R���X�g���N�^CMenuBar(HWND hWnd)
CMenuBar::CMenuBar(HWND hWnd){

	// �����o�̏�����.
	m_hMenu = NULL;	// m_hMenu��NULL���Z�b�g.
	m_hWnd = hWnd;	// m_hWnd��hWnd���Z�b�g.

}

// ���j���[�����\�[�X���烍�[�h.
BOOL CMenuBar::LoadMenu(HINSTANCE hInstance, UINT nID){

	// ���\�[�XID��nID�ȃ��j���[�����[�h.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nID));	// WindowsAPI��LoadMenu��nID�����[�h.
	if (m_hMenu == NULL){	// m_hMenu��NULL�Ȃ�.

		// ���s�Ȃ̂�FALSE.
		return FALSE;	//  FALSE��Ԃ�.

	}

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// ���j���[�̃Z�b�g.
BOOL CMenuBar::SetMenu(HWND hWnd){

	// �����o�Ɉ������Z�b�g.
	m_hWnd = hWnd;	// m_hWnd��hWnd���Z�b�g.

	// ���j���[�̃Z�b�g.
	return ::SetMenu(m_hWnd, m_hMenu);	// WindowsAPI��SetMenu��m_hMenu���Z�b�g��, �߂�l�����̂܂ܕԂ�.

}