// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene

// �R���X�g���N�^CScene
CScene::CScene(){

	// �����o�̏�����.
	m_pMainWnd = NULL;	// m_pMainWnd��NULL�ŏ�����.
	m_pGameTime = NULL;	// m_pGameTime��NULL�ŏ�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hMemBitmap = NULL;	// m_hMemBitmap��NULL�ŏ�����.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL�ŏ�����.
	m_iScreenWidth = 0;	// m_iScreenWidth��0�ŏ�����.
	m_iScreenHeight = 0;	// m_iScreenHeight��0�ŏ�����.
	m_pKeyboard = NULL;	// m_pKeyboard��NULL�ŏ�����.

}

// �R���X�g���N�^CScene(const CWindow *pWnd)
CScene::CScene(const CWindow *pWnd){

	// �����o�̏�����.
	m_pMainWnd = pWnd;	// m_pMainWnd��pWnd�ŏ�����.
	m_pGameTime = NULL;	// m_pGameTime��NULL�ŏ�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hMemBitmap = NULL;	// m_hMemBitmap��NULL�ŏ�����.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL�ŏ�����.
	m_iScreenWidth = 0;	// m_iScreenWidth��0�ŏ�����.
	m_iScreenHeight = 0;	// m_iScreenHeight��0�ŏ�����.
	m_pKeyboard = NULL;	// m_pKeyboard��NULL�ŏ�����.

}

// �R���X�g���N�^CScene(const CWindow *pWnd, CGameTime *pTime)
CScene::CScene(const CWindow *pWnd, CGameTime *pTime){

	// �����o�̏�����.
	m_pMainWnd = pWnd;	// m_pMainWnd��pWnd�ŏ�����.
	m_pGameTime = pTime;	// m_pGameTime��pTime�ŏ�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hMemBitmap = NULL;	// m_hMemBitmap��NULL�ŏ�����.
	m_hOldMemBitmap = NULL;	// m_hOldMemBitmap��NULL�ŏ�����.
	m_iScreenWidth = 0;	// m_iScreenWidth��0�ŏ�����.
	m_iScreenHeight = 0;	// m_iScreenHeight��0�ŏ�����.
	m_pKeyboard = NULL;	// m_pKeyboard��NULL�ŏ�����.

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

	// �Q�[���I�u�W�F�N�g�̏�����.
	int iRetGO = InitGameObjects();	// InitGameObjects�ŏ�����.
	if (iRetGO != 0){	// 0�łȂ����.
		return -1;	// -1��Ԃ��ċ����I��.
	}

	// �L�[�{�[�h�̏�����.
	int iRetKeys = InitKeyboard();	// InitKeyboard�ŏ�����.
	if (iRetKeys != 0){	// 0�łȂ����.
		return -1;	// -1��Ԃ��ċ����I��.
	}

	// �����Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �V�[��������RunScene.
int CScene::RunScene(){

	// ���̕��@�͒��~.
#if 0
	// ����{�^���̃`�F�b�N.
	int iRetClose = CheckClose();	// CheckClose�ŕ���{�^���������ꂽ�����`�F�b�N.
	if (iRetClose == 1){	// iRetClose��1�Ȃ�.
		return 2;	// 2��Ԃ��ăA�v�����I��.
	}

	// FPS��������.
	if (m_pGameTime->IsProc()){	// m_pGameTime->IsProc��TRUE.

		// �L�[��Ԃ̎擾.
		CheckKeyboard();	// CheckKeyboard�ŃL�[�{�[�h�̃`�F�b�N.

		// ���͂��Ԃ��玟�̏�Ԃ��v�Z.
		RunProc();	// RunProc�Ōv�Z����.

		// �Q�[���I�u�W�F�N�g�̕`��.
		DrawGameObjects();	// DrawGameObjects�Ńo�b�N�o�b�t�@�֕`�揈��.	

		// �t�����g�o�b�t�@�ɓ]��.
		Present();	// Present�Ńo�b�N�o�b�t�@����t�����g�o�b�t�@�֓]��.

	}

	// �t���[���J�E���g�̌v��.
	m_pGameTime->CountFrame();	// m_pGameTime->CountFrame�Ńt���[����1���₷.

	// 1�b�o�߂�����, ���Z�b�g.
	if (m_pGameTime->IsNextSecond()){	// ���̕b�Ȃ�.
		m_pGameTime->ResetFrame();	// m_pGameTime->ResetFrame�Ńt���[���J�E���g�����Z�b�g.
	}
#else	// ������̕��@�ɕύX.
	// ����{�^���̃`�F�b�N.
	int iRetClose = CheckClose();	// CheckClose�ŕ���{�^���������ꂽ�����`�F�b�N.
	if (iRetClose == 1){	// iRetClose��1�Ȃ�.
		return 2;	// 2��Ԃ��ăA�v�����I��.
	}

	// FPS�̂���Ȃ钲��(FPS�͂҂�����60�ɂȂ�Ȃ��̂�.)
	if (m_pGameTime->m_dwFrame % 3 == 1){	// 3�̗]�肪1�̎�.
		Sleep(1);	// 1�~���b�x�~.
	}

	// 1�b�o�߂�����, ���Z�b�g.
	if (m_pGameTime->IsNextSecond()){	// ���̕b�Ȃ�.
		m_pGameTime->ResetFrame();	// m_pGameTime->ResetFrame�Ńt���[���J�E���g�����Z�b�g.
	}

	// �L�[��Ԃ̎擾.
	CheckKeyboard();	// CheckKeyboard�ŃL�[�{�[�h�̃`�F�b�N.

	// ���͂��Ԃ��玟�̏�Ԃ��v�Z.
	RunProc();	// RunProc�Ōv�Z����.

	// �Q�[���I�u�W�F�N�g�̕`��.
	DrawGameObjects();	// DrawGameObjects�Ńo�b�N�o�b�t�@�֕`�揈��.	

	// �t�����g�o�b�t�@�ɓ]��.
	Present();	// Present�Ńo�b�N�o�b�t�@����t�����g�o�b�t�@�֓]��.

	// �t���[���J�E���g�̌v��.
	m_pGameTime->CountFrame();	// m_pGameTime->CountFrame�Ńt���[����1���₷.

	
#endif

	// �p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �V�[���I������ExitScene.
int CScene::ExitScene(){

	// �L�[�{�[�h�̏I������.
	ExitKeyboard();	// ExitKeyboard�ŃL�[�{�[�h�̏I������.
	
	// �Q�[���I�u�W�F�N�g�̏I������.
	ExitGameObjects();	// ExitGameObjects�ŃQ�[���I�u�W�F�N�g�̏I������.

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

// �Q�[���I�u�W�F�N�g�̏�����.
int CScene::InitGameObjects(){

	// �����Ȃ�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̏�����.
int CScene::InitKeyboard(){

	// �L�[�{�[�h�I�u�W�F�N�g�̍쐬.
	m_pKeyboard = new CKeyboard();	// CKeyboard�I�u�W�F�N�g���쐬��, �|�C���^��m_pKeyboard�Ɋi�[.

	// �����Ȃ�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// ����{�^���̃`�F�b�N.
int CScene::CheckClose(){

	// ����{�^���������ꂽ��.
	if (m_pMainWnd->m_bClose){	// m_pMainWnd->m_bClose��TRUE�Ȃ�.
		return 1;	// 1��Ԃ�.
	}

	// �����Ă��Ȃ��ꍇ��0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̃`�F�b�N.
int CScene::CheckKeyboard(){

	// �L�[��Ԃ̎擾.
	m_pKeyboard->Check();	// m_pKeyboard->Check�ŏ�Ԋm�F.

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
int CScene::RunProc(){

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̕`��.
int CScene::DrawGameObjects(){

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̏I������.
int CScene::ExitGameObjects(){

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̏I������.
int CScene::ExitKeyboard(){

	// �L�[�{�[�h�I�u�W�F�N�g�̔j��.
	if (m_pKeyboard != NULL){	// m_pKeyboard��NULL�łȂ���.
		delete m_pKeyboard;	// delete��m_pKeyboard�����.
		m_pKeyboard = NULL;	// m_pKeyboard��NULL���Z�b�g.
	}

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}