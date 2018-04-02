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
	Destroy();	// Destroy�ł��̃E�B���h�E�̏I������������.

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

// �E�B���h�E�̔j���ƏI�������֐�Destroy.
void CMenuWindow::Destroy(){

	// ���j���[�o�[�̔j��.
 	if (m_pMenuBar != NULL){	// m_pMenuBar��NULL�łȂ����.
 		delete m_pMenuBar;	// delete��m_pMenuBar�����.
 		m_pMenuBar = NULL;	// m_pMenuBar��NULL���Z�b�g.
 	}
 
	// �e�E�B���h�E��Destroy���Ă�.
	CWindow::Destroy();	// CWindow::Destroy���Ă�.

}

// �E�B���h�E���j�����ꂽ��.
void CMenuWindow::OnDestroy(){

	// �e�E�B���h�E��OnDestroy.
 	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������.
int CMenuWindow::OnClose(){

	// ����{�^���������ꂽ.
	m_bClose = TRUE;	// m_bClose��TRUE���Z�b�g.

	// �E�B���h�E�̏I������.
	Destroy();	// Destroy�ł��̃E�B���h�E�̏I������������.

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}