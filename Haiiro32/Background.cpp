// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Background.h"	// CBackground

// �R���X�g���N�^CBackground()
CBackground::CBackground() : CGameObject(){

	// �����o�̏�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL�ŏ�����.
	m_hOldBitmap = NULL;	// m_hOldBitmap��NULL�ŏ�����.

}

// �R���X�g���N�^CBackground(const CScene *pScene)
CBackground::CBackground(const CScene *pScene) : CGameObject(pScene){

	// �����o�̏�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL�ŏ�����.
	m_hOldBitmap = NULL;	// m_hOldBitmap��NULL�ŏ�����.

}

// �f�X�g���N�^~CBackground()
CBackground::~CBackground(){

}

// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
BOOL CBackground::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID){

	// �������f�o�C�X�R���e�L�X�g�̍쐬.
	m_hMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDC��m_hMemDC���쐬.
	if (m_hMemDC == NULL){	// m_hMemDC��NULL�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �r�b�g�}�b�v�̃��[�h.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// GetWindowLong��hInstance�擾.
	m_hBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, iWidth, iHeight, LR_DEFAULTCOLOR);	// LoadImage�Ń��\�[�XID��nID�̃r�b�g�}�b�v�����[�h.
	if (m_hBitmap == NULL){	// m_hBitmao��NULL�Ȃ�.
		DeleteDC(m_hMemDC);	// m_hMemDC��DeleteDC�ō폜.
		m_hMemDC = NULL;	// m_hMemDC��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �u���V�̑I��.
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObject��m_hBitmap��I��.

	// �ʒu�ƃT�C�Y�̎擾.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̔j��Destroy.
void CBackground::Destroy(){

	// �����o�̏I������.
	m_x = 0;	// m_x��0����.
	m_y = 0;	// m_y��0����.
	m_iWidth = 0;	// m_iWidth��0����.
	m_iHeight = 0;	// m_iHeight��0����.

	// �r�b�g�}�b�v��߂�.
	if (m_hOldBitmap != NULL){	// m_hOldBitmap��NULL�łȂ����.
		SelectObject(m_hMemDC, m_hOldBitmap);	// SelectObject��m_hOldBitmap�ɖ߂�.
		m_hOldBitmap = NULL;	// m_hOldBitmap��NULL���Z�b�g.
	}

	// ���[�h�����r�b�g�}�b�v�̔j��.
	if (m_hBitmap != NULL){	// m_hBitmap��NULL�łȂ����.
		DeleteObject(m_hBitmap);	// DeleteObject��m_hBitmao���폜.
		m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.
	}

	// �������f�o�C�X�R���e�L�X�g�̔j��.
	if (m_hMemDC != NULL){	// m_hMemDC��NULL�łȂ����.
		DeleteDC(m_hMemDC);	// DeleteDC��m_hMemDC��j��.
		m_hMemDC = NULL;	// m_hMemDC��NULL���Z�b�g.
	}

}

// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
void CBackground::DrawRect(int x, int y){

	// �r�b�g�}�b�v�̑I��.
	SelectObject(m_hMemDC, m_hBitmap);	// SelectObject��m_hBitmap��I��.

	// �r�b�g�}�b�v�̕`��.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBlt�Ńo�b�N�o�b�t�@�ɕ`��.

}