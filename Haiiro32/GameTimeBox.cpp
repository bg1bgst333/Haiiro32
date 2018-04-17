// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameTimeBox.h"	// CGameTimeBoxe

// �R���X�g���N�^CGameTimeBox
CGameTimeBox::CGameTimeBox(){

	// �����o�̏�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.
	m_dwTime = 0;	// m_dwTime��0�ŏ�����.
	m_dwFPS = 0;	// m_dwFPS��0�ŏ�����.
	m_dwRunFPS = 0;	// m_dwRunFPS��0�ŏ�����.

}

// �R���X�g���N�^CGameTimeBox(const CScene *pScene)
CGameTimeBox::CGameTimeBox(const CScene *pScene) : CGameObject(pScene){

	// �����o�̏�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.
	m_dwTime = 0;	// m_dwTime��0�ŏ�����.
	m_dwFPS = 0;	// m_dwFPS��0�ŏ�����.
	m_dwRunFPS = 0;	// m_dwRunFPS��0�ŏ�����.

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

	// ���[�U�^�C�����Z�b�g.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	pTime->ResetUserTime();	// pTime->ResetUserTime�Ń��[�U�^�C�����Z�b�g.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̔j��Destroy.
void CGameTimeBox::Destroy(){

	// �����o�̏I������.
	m_dwTime = 0;	// m_dwTime��0���Z�b�g.
	m_dwFPS = 0;	// m_dwFPS��0���Z�b�g.
	m_dwRunFPS = 0;	// m_dwRunFPS��0���Z�b�g.

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

// ����������Proc.
int CGameTimeBox::Proc(){
	
	// �������擾.
	TCHAR tszTime[256] = {0};	// TCHAR�z��tszTime��{0}�ŏ�����.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	//m_dwTime = pTime->GetSystemTime();	// pTime->GetSystemTime�Ŏ擾����������m_dwTime�Ɋi�[.
	m_dwTime = pTime->GetUserTime();	// pTime->GetUserTime�Ŏ擾����������m_dwTime�Ɋi�[.
	m_dwFPS = pTime->GetFPS();	// pTime->GetFPS��m_dwFPS�ɃZ�b�g.
	m_dwRunFPS = pTime->GetRunFPS();	// pTime->GetRunFPS��m_dwRunFPS�̃Z�b�g.
	m_dwFrameIntervalMilliTime = pTime->GetFrameIntervalMilliTime();	// pTime->GetFrameIntervalMilliTime��m_dwFrameIntervalMilliTime�ɃZ�b�g.

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

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

// DrawTime�Ŏ��Ԃ�`��.
void CGameTimeBox::DrawTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// �������擾.
	TCHAR tszTime[256] = {0};	// TCHAR�z��tszTime��{0}�ŏ�����.
	_stprintf(tszTime, _T("%lu"), m_dwTime);	// _stprintf��m_dwTime����tszTime�ɕϊ�.
	DrawText(x, y, iWidth, iHeight, tszTime, clrColor);	// DrawText�Ń��[�U���Ԃ�`��.

}

// DrawFPS�Ŏ��Ԃ�`��.
void CGameTimeBox::DrawFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// FPS���擾.
	TCHAR tszFPS[256] = {0};	// TCHAR�z��tszFPS��{0}�ŏ�����.
	_stprintf(tszFPS, _T("%lu"), m_dwFPS);	// _stprintf��m_dwFPS����tszFPS�ɕϊ�.
	DrawText(x, y, iWidth, iHeight, tszFPS, clrColor);	// DrawText��FPS��`��.

}

// DrawRunFPS�Ŏ��sFPS��`��
void CGameTimeBox::DrawRunFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// ���sFPS���擾.
	TCHAR tszRunFPS[256] = {0};	// TCHAR�z��tszRunFPS��{0}�ŏ�����.
	_stprintf(tszRunFPS, _T("%lu"), m_dwRunFPS);	// _stprintf��m_dwRunFPS����tszRunFPS�ɕϊ�.
	DrawText(x, y, iWidth, iHeight, tszRunFPS, clrColor);	// DrawText�Ŏ��sFPS��`��.

}

// DrawFrameIntervalMilliTime�Ńt���[���Ԋu��`��.
void CGameTimeBox::DrawFrameIntervalMilliTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor){

	// �t���[���Ԋu���擾.
	TCHAR tszFrameInterval[256] = {0};	// tszFrameInterval��{0}�ŏ�����.
	_stprintf(tszFrameInterval, _T("%lu"), m_dwFrameIntervalMilliTime);	// m_dwFrameIntervalMilliTime��tszFrameInterval�ɕϊ�.
	DrawText(x, y, iWidth, iHeight, tszFrameInterval, clrColor);	// DrawText�Ńt���[���Ԋu��`��.

}