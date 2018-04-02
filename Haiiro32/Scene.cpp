// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene

// �R���X�g���N�^CScene
CScene::CScene(){

	// �����o�̏�����.
	m_pMainWnd = NULL;	// m_pMainWnd��NULL�ŏ�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hMemBitmap = NULL;	// m_hMemBitmap��NULL�ŏ�����.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL�ŏ�����.
	m_iScreenWidth = 0;	// m_iScreenWidth��0�ŏ�����.
	m_iScreenHeight = 0;	// m_iScreenHeight��0�ŏ�����.
	m_pBackground = NULL;	// m_pBackground��NULL�ŏ�����.

}

// �R���X�g���N�^CScene(const CWindow *pWnd)
CScene::CScene(const CWindow *pWnd){

	// �����o�̏�����.
	m_pMainWnd = pWnd;	// m_pMainWnd��pWnd�ŏ�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hMemBitmap = NULL;	// m_hMemBitmap��NULL�ŏ�����.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL�ŏ�����.
	m_iScreenWidth = 0;	// m_iScreenWidth��0�ŏ�����.
	m_iScreenHeight = 0;	// m_iScreenHeight��0�ŏ�����.
	m_pBackground = NULL;	// m_pBackground��NULL�ŏ�����.

}

// �f�X�g���N�^~CScene
CScene::~CScene(){

}

// �V�[��������InitScene.
int CScene::InitScene(){

	// �E�B���h�E�̃��T�C�Y.
	ResizeWindow(640, 480);	// ResizeWindow��(640, 480)�Ƀ��T�C�Y.

	// �X�N���[���̍쐬.
	CreateScreen(640, 480);	// CreateScreen��(640, 480)�̃T�C�Y�̃X�N���[�����쐬.

	// �w�i�̍쐬.
	m_pBackground = new CGameObject(this);	// CGameObject�I�u�W�F�N�g�𐶐�(this��n��.)��, �|�C���^��m_pBackground�Ɋi�[.
	m_pBackground->Create(0, 0, 640, 480, RGB(0xff, 0x0, 0x0), RGB(0x7f, 0x0, 0x0));	// m_pBackground->Create�Ŕw�i�I�u�W�F�N�g���쐬.

	// �����Ȃ�0.
	return 0;	// 0��Ԃ�.
	//return -1;	// -1��Ԃ��čŏ��ɋ����I��.	

}

// �V�[��������RunScene.
int CScene::RunScene(){

	// ����{�^���������ꂽ��.
	if (m_pMainWnd->m_bClose){	// m_pMainWnd->m_bClose��TRUE�Ȃ�.
		return 2;	// 2��Ԃ�.
	}

#if 0
	// SPACE�L�[���������甲����.
	if (GetAsyncKeyState(VK_SPACE)){	// GetAsyncKeyState��SPACE��������Ă�����.
		MessageBox(NULL, _T("SPACE"), _T("Haiiro"), MB_OK);	// MessageBox��"SPACE"�ƕ\��.(����������, 2��ȏ㕪�ɂȂ��Ă��܂�.)
		return 1;	// 1��Ԃ�.
	}

	// ESCAPE�L�[���������甲����.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyState��ESCAPE��������Ă�����.
		MessageBox(NULL, _T("ESCAPE"), _T("Haiiro"), MB_OK);	// MessageBox��"ESCAPE"�ƕ\��.(����������, 2��ȏ㕪�ɂȂ��Ă��܂�.)
		return 2;	// 2��Ԃ�.
	}
#endif

	// �w�i�̕`��.
	if (m_pBackground != NULL){	// m_pBackground��NULL�łȂ���.
		m_pBackground->DrawRect(0, 0);	// m_pBackground->DrawRect��(0, 0)�̈ʒu�ɕ`��.
	}

	// �O�ʂɓ]��..
	Present();	// Present�Ńo�b�N�o�b�t�@����t�����g�o�b�t�@�֓]��.

	// �p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �V�[���I������ExitScene.
int CScene::ExitScene(){

	// �w�i�̔j��.
	if (m_pBackground != NULL){	// m_pBackground��NULL�łȂ���.
		m_pBackground->Destroy();	// m_pBackground->Destroy�Ŕj��.
		delete m_pBackground;	// delete��m_pBackground�����.
		m_pBackground = NULL;	// m_pBackground��NULl���Z�b�g.
	}

	// �X�N���[���̔j��.
	DestroyScreen();	// DestroyScreen�ŃX�N���[����j��.

	// �p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �E�B���h�E�̃��T�C�YResizeWindow.
void CScene::ResizeWindow(int iWidth, int iHeight){

	// �E�B���h�E�T�C�Y���N���C�A���g�̈�̃T�C�Y��(iWidth, iHeight)�ɂȂ�悤�ȃT�C�Y�ɂ���.
	RECT rc = {0, 0, iWidth, iHeight};	// RECT�^rc��{0, 0, iWidth, iHeight}�ŏ�����.
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, TRUE);	// AdjustWindowRect�œK�؂ȃE�B���h�E�T�C�Y���擾.
	RECT rcWnd = {0};	// �E�B���h�E��`�̈�rcWnd��{0}�ŏ�����.
	GetWindowRect(m_pMainWnd->m_hWnd, &rcWnd);	// GetWindowRect��rcWnd���擾.
	MoveWindow(m_pMainWnd->m_hWnd, rcWnd.left, rcWnd.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);	// MoveWindow�Ń��T�C�Y.

}

// �X�N���[���̍쐬CreateScreen.
void CScene::CreateScreen(int iWidth, int iHeight){

	// �X�N���[���T�C�Y�̃Z�b�g.
	m_iScreenWidth = iWidth;	// m_iScreenWidth��iWidth���Z�b�g.
	m_iScreenHeight = iHeight;	// m_iScreenHeight��iHeight���Z�b�g.

	// �f�o�C�X�R���e�L�X�g�̎擾.
	m_hDC = GetDC(m_pMainWnd->m_hWnd);	// GetDC��m_hDC���擾.

	// �������f�o�C�X�R���e�L�X�g�̐���.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDC��m_hMemDC�𐶐�.

	// �������r�b�g�}�b�v�̐���.
	m_hMemBitmap = CreateCompatibleBitmap(m_hDC, m_iScreenWidth, m_iScreenHeight);	// CreateCompatibleBitmap��m_hMemBitmap�𐶐�.

	// �������f�o�C�X�R���e�L�X�g�̑I��.
	m_hOldMemBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hMemBitmap);	// SelectObject��m_hMemBitmap��I��.

}

// �o�b�N�o�b�t�@����t�����g�o�b�t�@�֓]�����邱�Ƃŉ�ʂ�`�悷��Present.
void CScene::Present(){

	// �O�ʂɓ]��.
	if (m_hDC != NULL){	// m_hDC��NULL�łȂ���.
		BitBlt(m_hDC, 0, 0, m_iScreenWidth, m_iScreenHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBlt��m_hMemDC����m_hDC�ɓ]��.
	}

}

// �X�N���[���̔j��DestroyScreen.
void CScene::DestroyScreen(){

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
		ReleaseDC(m_pMainWnd->m_hWnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// m_hDC��NULL���Z�b�g.
	}

}