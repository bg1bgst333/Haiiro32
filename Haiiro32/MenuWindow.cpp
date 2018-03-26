// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuWindow.h"	// CMenuWindow

// �R���X�g���N�^CMenuWindow()
CMenuWindow::CMenuWindow() : CWindow(){

	// �����o�̏�����.
	m_pMenuBar = NULL;	// m_pMenuBar��NULL�ŏ�����.

}

// �f�X�g���N�^~CMenuWindow()
CMenuWindow::~CMenuWindow(){

	// �����o�̏I������
	if (m_pMenuBar != NULL){	// m_pMenuBar��NULL�łȂ����.
		delete m_pMenuBar;	// delete��m_pMenuBar�����.
		m_pMenuBar = NULL;	// m_pMenuBar��NULL���Z�b�g.
	}

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�v���V�[�W���ȗ�, ���j���[���w��o�[�W����.)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpszMenuName){

	// ���j���[��lpszMenuName���g��.
	return CWindow::RegisterClass(hInstance, lpctszClassName, lpszMenuName);	// CWindow::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.
BOOL  CMenuWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X���͎w��̃��m���g��.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X���w��o�[�W�����ō쐬.

}

// �E�B���h�E���j�����ꂽ��.
void CMenuWindow::OnDestroy(){

	// �����o�̏I������
	if (m_pMenuBar != NULL){	// m_pMenuBar��NULL�łȂ����.
		delete m_pMenuBar;	// delete��m_pMenuBar�����.
		m_pMenuBar = NULL;	// m_pMenuBar��NULL���Z�b�g.
	}

	// �e�E�B���h�E��OnDestroy.
	CWindow::OnDestroy();	// CWindow��OnDestroy���Ă�.

}