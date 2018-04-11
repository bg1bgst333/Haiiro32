// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameTimeBox.h"	// CGameTimeBoxe

// �R���X�g���N�^CGameTimeBox
CGameTimeBox::CGameTimeBox(){

	// �����o�̏�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.

}

// �R���X�g���N�^CGameTimeBox(const CScene *pScene)
CGameTimeBox::CGameTimeBox(const CScene *pScene) : CGameObject(pScene){

	// �����o�̏�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.

}

// �f�X�g���N�^~CGameTimeBox
CGameTimeBox::~CGameTimeBox(){

}

// �Q�[���I�u�W�F�N�g�̍쐬Create.
BOOL CGameTimeBox::Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName){

	// �ʒu�ƃT�C�Y�̎擾.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.

	// �t�H���g�̍쐬.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFont�Ńt�H���g���쐬��, m_hFont�Ɋi�[.
	if (m_hFont == NULL){	// m_hFont��NULL�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �t�H���g�̑I��.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̔j��Destroy.
void CGameTimeBox::Destroy(){

	// �t�H���g��߂�.
	if (m_hOldFont != NULL){	// m_hOldFont��NULL�łȂ����.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObject��m_hOldFont�ɖ߂�.
		m_hOldFont = NULL;	// m_hOldFont��NULL���Z�b�g.

	}

	// �t�H���g�̍폜.
	if (m_hFont != NULL){	// m_hFont��NULL�łȂ����.
		DeleteObject(m_hFont);	// DeleteObject��m_hFont���폜.
		m_hFont = NULL;	// m_hFont��NULL���Z�b�g.
	}

}

// DrawText�Ńe�L�X�g��`��.
void CGameTimeBox::DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor){

	// �e�L�X�g��`��.
	RECT rc = {x, y, x + iWidth, y + iHeight};	// rc���������g���ď�����.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColor�ŐF��clrColor���w��.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkMode�Ŕw�i�͓���.
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.
	::DrawText(m_pScene->m_hMemDC, lpctszText, _tcslen(lpctszText), &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);	// WindowsAPI��DrawText�Ń^�C�g��������̕`��.
	
}

// DrawTime�ŃV�X�e�����Ԃ�`��.
void CGameTimeBox::DrawTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// �������擾.
	TCHAR tszTime[256] = {0};	// TCHAR�z��tszTime��{0}�ŏ�����.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	_stprintf(tszTime, _T("%lu"), pTime->Get());	// _stprintf��dwTime����tszTime�ɕϊ�.
	DrawText(x, y, iWidth, iHeight, tszTime, clrColor);	// DrawText�ŃV�X�e�����Ԃ�`��.

}