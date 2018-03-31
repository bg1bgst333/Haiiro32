// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �R���X�g���N�^CGameObject()
CGameObject::CGameObject(){

	// �����o�̏�����.
	m_pScene = NULL;	// m_pScene��NULL�ŏ�����.
	m_x = 0;	// m_x��0�ŏ�����.
	m_y = 0;	// m_y��0�ŏ�����.
	m_iWidth = 0;	// m_iWidth��0�ŏ�����.
	m_iHeight = 0;	// m_iHeight��0�ŏ�����.
	m_hPen = NULL;	// m_hPen��NULL�ŏ�����.
	m_hOldPen = NULL;	// m_hOldPen��NULL�ŏ�����.
	m_hBrush = NULL;	// m_hBrush��NULL�ŏ�����.
	m_hOldBrush = NULL;	// m_hOldBrush��NULL�ŏ�����.

}

// �R���X�g���N�^CGameObject(const CScene *pScene)
CGameObject::CGameObject(const CScene *pScene){

	// �����o�̏�����.
	m_pScene = pScene;	// m_pScene��pScene�ŏ�����.
	m_x = 0;	// m_x��0�ŏ�����.
	m_y = 0;	// m_y��0�ŏ�����.
	m_iWidth = 0;	// m_iWidth��0�ŏ�����.
	m_iHeight = 0;	// m_iHeight��0�ŏ�����.
	m_hPen = NULL;	// m_hPen��NULL�ŏ�����.
	m_hOldPen = NULL;	// m_hOldPen��NULL�ŏ�����.
	m_hBrush = NULL;	// m_hBrush��NULL�ŏ�����.
	m_hOldBrush = NULL;	// m_hOldBrush��NULL�ŏ�����.

}

// �f�X�g���N�^~CGameObject()
CGameObject::~CGameObject(){

}

// �Q�[���I�u�W�F�N�g�̍쐬Create.(�y���ƃu���V�ŕ`���ꂽ��`.)
BOOL CGameObject::Create(int x, int y, int iWidth, int iHeight, COLORREF clrPen, COLORREF clrBrush){

	// �����o�ɃZ�b�g.
	m_x = x;	// m_x��x����.
	m_y = y;	// m_y��y����.
	m_iWidth = iWidth;	// m_iWidth��iWidth����.
	m_iHeight = iHeight;	// m_oHeight��iHeight����.

	// �y���̍쐬.
	m_hPen = CreatePen(PS_SOLID, 1, clrPen);	// CreatePen��hPen���쐬.
	if (m_hPen == NULL){	// �쐬���s.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �y���̑I��.
	m_hOldPen = (HPEN)SelectObject(m_pScene->m_hMemDC, m_hPen);	// SelectObject��m_hPen��I��.

	// �u���V�̍쐬.
	m_hBrush = CreateSolidBrush(clrBrush);	// CreateSolidBrush��hBrush���쐬.
	if (m_hBrush == NULL){	// �쐬���s.
		SelectObject(m_pScene->m_hMemDC, m_hOldPen);	// SelectObject��m_hOldPen�ɖ߂�r
		m_hOldPen = NULL;	// m_hOldPen��NULL���Z�b�g.
		DeleteObject(m_hPen);	// DeleteObject��m_hPen��j��.
		m_hPen = NULL;	// m_hPen��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �u���V�̑I��.
	m_hOldBrush = (HBRUSH)SelectObject(m_pScene->m_hMemDC, m_hBrush);	// SelectObject��m_hBrush��I��.

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̔j��Destroy.
void CGameObject::Destroy(){

	// �����o�̏I������.
	m_x = 0;	// m_x��0����.
	m_y = 0;	// m_y��0����.
	m_iWidth = 0;	// m_iWidth��0����.
	m_iHeight = 0;	// m_iHeight��0����.

	// �u���V��߂�.
	if (m_hOldBrush != NULL){	// m_hOldBrush��NULL�łȂ���.
		SelectObject(m_pScene->m_hMemDC, m_hOldBrush);	// SelectObject��m_hOldBrush��I��.
		m_hOldBrush = NULL;	// m_hOldBrush��NULL���Z�b�g.
	}

	// �u���V�̔j��.
	if (m_hBrush != NULL){	// m_hBrush��NULL�łȂ���.
		DeleteObject(m_hBrush);	// DeleteObject��m_hBrush��j��.
		m_hBrush = NULL;	// m_hBrush��NULL���Z�b�g.
	}

	// �y����߂�.
	if (m_hOldPen != NULL){	// m_hOldPen��NULL�łȂ���.
		SelectObject(m_pScene->m_hMemDC, m_hOldPen);	// SelectObject��m_hOldPen��I��.
		m_hOldPen = NULL;	// m_hOldPen��NULL���Z�b�g.
	}

	// �y���̔j��.
	if (m_hPen != NULL){	// m_hPen��NULL�łȂ���.
		DeleteObject(m_hPen);	// DeleteObject��m_hPen��j��.
		m_hPen = NULL;	// m_hPen��NULL���Z�b�g.
	}

}

// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�y���ƃu���V�ŕ`���ꂽ��`.)
void CGameObject::DrawRect(int x, int y){

	// �y���̑I��.
	SelectObject(m_pScene->m_hMemDC, m_hPen);	// SelectObject��m_hPen��I��.
	
	// �u���V�̑I��.
	SelectObject(m_pScene->m_hMemDC, m_hBrush);	// SelectObject��m_hBrush��I��.

	// ��`��`��.
	Rectangle(m_pScene->m_hMemDC, x, y, x + m_iWidth, y + m_iHeight);	// Rectangle�ŋ�`��`��.

}