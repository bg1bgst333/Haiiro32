// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameApplication.h"	// CGameApplication

// �R���X�g���N�^CGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// �����o�̏�����.
	m_iSceneNo = 0;	// m_iSceneNo��0�ŏ�����.
	m_iSceneStatus = 0;	// m_iSceneStatus��0�ŏ�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hMemBitmap = NULL;	// m_hMemBitmap��NULL�ŏ�����.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL�ŏ�����.
#if 0
	m_hBackPen = NULL;	// m_hBackPen��NULL�ŏ�����.
	m_hOldBackPen = NULL;	// m_hOldBackPen��NULL�ŏ�����.
	m_hBackBrush = NULL;	// m_hBackBrush��NULL�ŏ�����.
	m_hOldBackBrush = NULL;	// m_hOldBackBrush��NULL�ŏ�����.
	m_hCursorPen = NULL;	// m_hCursorPen��NULL�ŏ�����.
	m_hOldCursorPen = NULL;	// m_hOldCursorPen��NULL�ŏ�����.
	m_hCursorBrush = NULL;	// m_hCursorBrush��NULL�ŏ�����.
	m_hOldCursorBrush = NULL;	// m_hOldCursorBrush��NULL�ŏ�����.
	m_iCursorX = 0;	// m_iCursorX��0�ŏ�����.
	m_iCursorY = 0;	// m_iCursorY��0�ŏ�����.
#endif

}

// �Q�[�����C�������֐�Main.
int CGameApplication::Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �ϐ��̏�����.
	int iRet = 0;	// �߂�liRet��0�ŏ�����.

	// �V�[�����ƂɐU�蕪��..
	if (m_iSceneStatus == 0){	// m_iSceneStatus��0�Ȃ�V�[��������.
		iRet = InitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// InitScene�ŏ���������.
	}
	else if (m_iSceneStatus == 1){	// m_iSceneStatus��1�Ȃ�V�[��������.
		iRet = RunScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// RunScene�ŏ�����.
	}
	else if (m_iSceneStatus == 2){	// m_iSceneStatus��2�Ȃ�V�[���I������.
		iRet = ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitScene�ŏI������.
	}
	else{	// ����ȊO�͉��������I��.
		// 0��Ԃ�.
		return 0;	// 0��Ԃ�.
	}

	// ���̏�Ԃ����߂�.
	if (iRet == 1){	// iRet��1�Ȃ�.(���̃V�[���ւ̐؂�ւ�.)
		if (m_iSceneStatus <= 1){	// Init�܂���Run�̏ꍇ.
			m_iSceneStatus++;	// m_iSceneStatus��1���₷.
		}
		else{	// Exit�̎�.
			m_iSceneNo++;	// m_iSceneNo��1���₷.
			m_iSceneStatus = 0;	// m_iSceneStatus��0�ɂ���.
		}
	}
	else if (iRet == 2){	// iRet��2�Ȃ�.(�A�v���̏I��.)
		if (m_iSceneStatus <= 1){	// Init�܂���Run�̏ꍇ.
			ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitScene�ŏI������.
		}
		m_iSceneStatus = -1;	// m_iSceneStatus��-1�Ȃ玟�ȍ~�������Ȃ�.
		SendMessage(hWnd, WM_DESTROY, 0, 0);	// SendMessage��WM_DESTROY�𑗐M.
	}

	// 0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// �V�[���̏�����InitScene.
int CGameApplication::InitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �E�B���h�E�̃��T�C�Y.
	ResizeWindow(hWnd, 640, 480);	// ResizeWindow�ŃN���C�A���g�̈悪(640, 480)�ƂȂ�E�B���h�E�Ƀ��T�C�Y. 

	// �X�N���[���̍쐬.
	CreateScreen(hWnd);	// CreateScreen�ŃX�N���[���쐬.

	// �������I���Ȃ̂�1.
	return 1;	// 1��Ԃ�.

}

// �V�[���̏�����RunScene.
int CGameApplication::RunScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �t�����g�o�b�t�@�֓]��.
	Present(iClientAreaWidth, iClientAreaHeight);	// Present�ŕ\��.

	// ESC�L�[���������甲����.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyState��ESC��������Ă�����.
		MessageBox(NULL, _T("ESC"), _T("Haiiro"), MB_OK);	// MessageBox��"ESC"�ƕ\��.(����������, 2��ȏ㕪�ɂȂ��Ă��܂�.)
		return 1;	// 1��Ԃ�.
	}

	// �����������Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �V�[���̏I������ExitScene.
int CGameApplication::ExitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �X�N���[���̔j��.
	DestroyScreen(hWnd);	// DestroyScreen�ŃX�N���[���j��.

	// m_iSceneNo��3�Ȃ�I��.
	if (m_iSceneNo == 3){	// m_iSceneNo��3�̎�.
		// �A�v���I���Ȃ̂�2��Ԃ�.
		return 2;	// 2��Ԃ�.
	}

	// �I�������Ȃ̂�1.
	return 1;	// 1��Ԃ�.

}

// �E�B���h�E�̃��T�C�YResizeWindow.
void CGameApplication::ResizeWindow(HWND hWnd, int iWidth, int iHeight){

	// �E�B���h�E�T�C�Y���N���C�A���g�̈�̃T�C�Y��iWidthxiHeight�ɂȂ�悤�ȃT�C�Y����.
	RECT rc = {0, 0, iWidth, iHeight};	// RECT�^rc��{0, 0, iWidth, iHeight}�ŏ�����.
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, TRUE);	// AdjustWindowRect�œK�؂ȃE�B���h�E�T�C�Y���擾.
	RECT rcWnd = {0};	// �E�B���h�E��`�̈�rcWnd��{0}�ŏ�����.
	GetWindowRect(hWnd, &rcWnd);	// GetWindowRect��rcWnd���擾.
	MoveWindow(hWnd, rcWnd.left, rcWnd.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);	// MoveWindow�Ń��T�C�Y.

}

// �X�N���[���̍쐬CreateScreen.
void CGameApplication::CreateScreen(HWND hWnd){

	// �f�o�C�X�R���e�L�X�g�̎擾.
	m_hDC = GetDC(hWnd);	// GetDC��m_hDC���擾.

	// �������f�o�C�X�R���e�L�X�g�̐���.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDC��m_hMemDC�𐶐�.

	// �������r�b�g�}�b�v�̐���.
	m_hMemBitmap = CreateCompatibleBitmap(m_hDC, 640, 480);	// CreateCompatibleBitmap��m_hMemBitmap�𐶐�.

	// �������f�o�C�X�R���e�L�X�g�̑I��.
	m_hOldMemBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hMemBitmap);	// SelectObject��m_hMemBitmap��I��.

}

// �t�����g�o�b�t�@�ɓ]��Present.
void CGameApplication::Present(int iClientAreaWidth, int iClientAreaHeight){

	// �O�ʂɓ]��.
	if (m_hDC != NULL){	// m_hDC��NULL�łȂ���.
		BitBlt(m_hDC, 0, 0, iClientAreaWidth, iClientAreaHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBlt��m_hMemDC����m_hDC�ɓ]��.
	}

}

// �X�N���[���̔j��DestroyScreen.
void CGameApplication::DestroyScreen(HWND hWnd){

	// �������f�o�C�X�R���e�L�X�g��߂�.
	if (m_hOldMemBitmap != NULL){	// m_hOldMemBitmap��NULL�łȂ���.
		SelectObject(m_hMemDC, m_hOldMemBitmap);	// SelectObject��m_hOldMemBitmap��I��.
		m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL���Z�b�g.
	}

	// �������r�b�g�}�b�v�̍폜.
	if (m_hMemBitmap != NULL){	// m_hMemBitmap��NULL�łȂ���.
		DeleteObject(m_hMemBitmap);	// DeleteObject��m_hMemBitmap���폜.
		m_hMemBitmap = NULL;	// m_hMemBitmap��NULL���Z�b�g.
	}

	// �������f�o�C�X�R���e�L�X�g�̍폜.
	if (m_hMemDC != NULL){	// m_hMemDC��NULL�łȂ���.
		DeleteDC(m_hMemDC);	// DeleteDC��m_hMemDC���폜.
		m_hMemDC = NULL;	// m_hMemDC��NULL���Z�b�g.
	}

	// �f�o�C�X�R���e�L�X�g�̉��.
	if (m_hDC != NULL){	// m_hDC��NULL�łȂ���.
		ReleaseDC(hWnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// m_hDC��NULL���Z�b�g.
	}

}