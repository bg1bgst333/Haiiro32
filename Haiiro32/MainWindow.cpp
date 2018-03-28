// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
#include "resource.h"		// ���\�[�X

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CMenuWindow(){

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow(){

	// �����o�̏I������
	Destroy();	// Destroy�ł��̃E�B���h�E�̏I������������.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�v���V�[�W���ɂ�CWindow::StaticWndowProc, ���j���[�͂Ȃ�(NULL)�Ƃ���.((LPCTSTR)�ŃL���X�g���Ȃ��ƃI�[�o�[���[�h���B���ɂȂ�.)
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), (LPCTSTR)NULL);	// CWindow::RegisterClass�œo�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpszMenuName){

	// �E�B���h�E�v���V�[�W���ɂ�CWindow::StaticWndowProc, ���j���[��lpszMenuName�Ƃ���.((LPCTSTR)�ŃL���X�g���Ȃ��ƃI�[�o�[���[�h���B���ɂȂ�.)
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), (LPCTSTR)lpszMenuName);	// CWindow::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CMainWindow"���w��.

}

// �E�B���h�E�̔j���ƏI�������֐�Destroy.
void CMainWindow::Destroy(){

	// �e�E�B���h�E��Destroy���Ă�.
	CMenuWindow::Destroy();	// CMenuWindow::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ���j���[�o�[�̍쐬.
	m_pMenuBar = new CMenuBar(hwnd);	// CMenuBar�I�u�W�F�N�gm_pMenuBar���쐬.

	// ���j���[�̃��[�h.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MENU1);	// LoadMenu��IDR_MENU1�����[�h.

	// ���j���[�̃Z�b�g.
	m_pMenuBar->SetMenu(hwnd);	// SetMenu��hwnd�Ƀ��j���[���Z�b�g.

	// ���j���[�n���h���̒ǉ�.
	AddCommandHandler(ID_APP_EXIT, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnAppExit);	// AddCommandHandler��ID_APP_EXIT�ɑ΂���n���h��CMainWindow::OnAppExit��o�^.

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_APP_EXIT, 0);	// DeleteCommandHandler��ID_APP_EXIT�̃n���h�����폜.

	// �e�E�B���h�E��OnDestroy���Ă�.
	CMenuWindow::OnDestroy();	// CMenuWindow::OnDestroy���Ă�.

	// �I�����b�Z�[�W�̑��M.
	PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���WM_QUIT���b�Z�[�W�𑗐M.

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CMainWindow::OnPaint(){

	// �g��Ȃ��̂ŃR�����g�A�E�g.
#if 0
	// �ϐ��̏�����.
	HDC hDC = NULL;	// hDC��NULL�ŏ�����.
	PAINTSTRUCT ps = {0};	// ps��{0}�ŏ�����.
	HPEN hPen = NULL;	// hPen��NULL�ŏ�����.
	HBRUSH hBrush = NULL;	// hBrush��NULL�ŏ�����.
	static int iCount = 0;	// static�ϐ�iCount��0�ŏ�����.
	TCHAR tszCount[32] = {0};	// TCHAR�^�z��(�v�f��32)��{0}�ŏ�����.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.

	// �y���ƃu���V�̐���.
	hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0xff, 0));	// CreatePen�ŗ�(�W)�̃y�����쐬.
	hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0x7f, 0));		// CreateSolidBrush�ŗ�(�Z)�̃u���V���쐬.

	// �y���ƃu���V�̑I��.
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);		// �΂̃y����I��.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);	// �΂̃u���V��I��.

	// ��`�`��.
	Rectangle(hDC, 0, 0, m_iClientAreaWidth, m_iClientAreaHeight);	// Rectangle�ŋ�`��`��.

	// �e�L�X�g�̕\��.
	_stprintf(tszCount, _T("%d"), iCount);	// _stprintf�Ő����liCount�𕶎���tszCount�ɕϊ�.
	SetBkMode(hDC, TRANSPARENT);	// SetBkMode��TRANSPARENT(����)�ɂ���.
	TextOut(hDC, 50, 50, tszCount, _tcslen(tszCount));	// TextOut��tszCount���o��.
	iCount++;	// iCount���C���N�������g.
	if (iCount >= 10000){	// iCount��10000�ȏ�Ȃ�.
		iCount = 0;	// iCount��0�Ƀ��Z�b�g.
	}

	// �y���ƃu���V�̕���
	SelectObject(hDC, hOldBrush);		// �Â��u���V��I��.
	SelectObject(hDC, hOldPen);		// �Â��y����I��.

	// �y���ƃu���V�̔j��.
	DeleteObject(hBrush);	// �u���V�̔j��.
	DeleteObject(hPen);	// �y���̔j��.

	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.
#endif

}

// �E�B���h�E�������.
int CMainWindow::OnClose(){

	// �A�v���P�[�V�������I�����邩�ǂ����̔���.
	int iRet = MessageBox(m_hWnd, _T("�A�v���P�[�V�������I�����܂���?"), _T("Haiiro"), MB_YESNO | MB_ICONQUESTION);	// "�A�v���P�[�V�������I�����܂���?"�ƕ\��.("�͂�", "������"�̃��b�Z�[�W�{�b�N�X���\�������.)
	if (iRet == IDYES){	// "�͂�"�������ꂽ��.

		// �E�B���h�E�̏I������.
		Destroy();	// Destroy�ł��̃E�B���h�E�̏I������������.

		// 0��Ԃ�.
		return 0;	// 0��Ԃ��ăE�B���h�E�����.

	}
	else{	// "������"�������ꂽ���Ȃ�.

		// -1��Ԃ�.
		return -1;	// -1��Ԃ��ăE�B���h�E����Ȃ�.

	}

}

// "�A�v���P�[�V�����̏I��"��I�����ꂽ���̃n���h��.
int CMainWindow::OnAppExit(WPARAM wParam, LPARAM lParam){

	// ����.
	SendMessage(m_hWnd, WM_CLOSE, 0, 0);	// WM_CLOSE�𑗐M���ăE�B���h�E�����.

	// ���������̂�0.
	return 0;	// return��0��Ԃ�.

}