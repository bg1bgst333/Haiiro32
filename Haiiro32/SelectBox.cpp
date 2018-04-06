// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SelectBox.h"	// CSelectBox

// �R���X�g���N�^CSelectBox()
CSelectBox::CSelectBox() : CGameObject(){

	// �����o�̏�����.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL�ŏ�����.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL�ŏ�����.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL�ŏ�����.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clear�ŃN���A.

}

// �R���X�g���N�^CSelectBox(const CScene *pScene)
CSelectBox::CSelectBox(const CScene *pScene) : CGameObject(pScene){

	// �����o�̏�����.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL�ŏ�����.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL�ŏ�����.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL�ŏ�����.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clear�ŃN���A.

}

// �f�X�g���N�^~CSelectBox()
CSelectBox::~CSelectBox(){

}

// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
BOOL CSelectBox::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID){

	// �w�i�������f�o�C�X�R���e�L�X�g�̍쐬.
	m_hBackgroundMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDC��m_hBackgroundMemDC���쐬.
	if (m_hBackgroundMemDC == NULL){	// m_hBackgroundMemDC��NULL�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �w�i�r�b�g�}�b�v�̃��[�h.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// GetWindowLong��hInstance�擾.
	m_hBackgroundBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, iWidth, iHeight, LR_DEFAULTCOLOR);	// LoadImage�Ń��\�[�XID��nID�̃r�b�g�}�b�v�����[�h.
	if (m_hBackgroundBitmap == NULL){	// m_hBackgroundBitmap��NULL�Ȃ�.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDC��DeleteDC�ō폜.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �u���V�̑I��.
	m_hOldBackgroundBitmap = (HBITMAP)SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObject��m_hBackgroundBitmap��I��.

	// �ʒu�ƃT�C�Y�̎擾.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̔j��Destroy.
void CSelectBox::Destroy(){

	// �����o�̏I������.
	m_x = 0;	// m_x��0����.
	m_y = 0;	// m_y��0����.
	m_iWidth = 0;	// m_iWidth��0����.
	m_iHeight = 0;	// m_iHeight��0����.

	// �w�i�r�b�g�}�b�v��߂�.
	if (m_hOldBackgroundBitmap != NULL){	// m_hOldBackgroundBitmap��NULL�łȂ����.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObject��m_hOldBackgroundBitmap�ɖ߂�.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL���Z�b�g.
	}

	// ���[�h�����w�i�r�b�g�}�b�v�̔j��.
	if (m_hBackgroundBitmap != NULL){	// m_hBackgroundBitmap��NULL�łȂ����.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObject��m_hBackgroundBitmao���폜.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL���Z�b�g.
	}

	// �w�i�������f�o�C�X�R���e�L�X�g�̔j��.
	if (m_hBackgroundMemDC != NULL){	// m_hBackgroundMemDC��NULL�łȂ����.
		DeleteDC(m_hBackgroundMemDC);	// DeleteDC��m_hBackgroundMemDC��j��.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL���Z�b�g.
	}

}

// �Z���N�g�A�C�e���̒ǉ�AddSelectItem.
void CSelectBox::AddSelectItem(tstring tstrSelectItem){

	// �Z���N�g�A�C�e�����X�g�ɒǉ�.
	m_vectstrSelectItemList.push_back(tstrSelectItem);	// m_vectstrSelectItemList.push_back��tstrSelectItem��ǉ�.

}

// �Z���N�g�A�C�e���̃N���AClearSelectItem.
void CSelectBox::ClearSelectItem(){

	// �Z���N�g�A�C�e���̑S�폜.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clear�ŃN���A.

}		

// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
void CSelectBox::DrawRect(int x, int y){

	// �w�i�r�b�g�}�b�v�̑I��.
	SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObject��m_hBackgroundBitmap��I��.

	// �w�i�r�b�g�}�b�v�̕`��.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, m_hBackgroundMemDC, 0, 0, SRCCOPY);	// BitBlt�Ńo�b�N�o�b�t�@�ɕ`��.

}

// �Z���N�g�A�C�e�����X�g�̕`��DrawSelectItemList.
void CSelectBox::DrawSelectItemList(int x, int y, COLORREF clrColor){

	// �A�C�e���̐������`��.
	SetTextColor(m_pScene->m_hMemDC, clrColor);	// SetTextColor�ŐF��clrColor���w��.
	SetBkMode(m_pScene->m_hMemDC, TRANSPARENT);	// SetBkMode�Ŕw�i�͓���.
	int iMargin = 40;	// iMargin��40�ŏ�����.
	int iPosY = m_y + y;	// iPosY��m_y + y�ŏ�����.
	for (std::vector<tstring>::iterator itor = m_vectstrSelectItemList.begin(); itor != m_vectstrSelectItemList.end(); itor++){	// itor���I���܂ŌJ��Ԃ�.
		RECT rc = {m_x + x, iPosY, m_x + x + m_iWidth, m_y + y + m_iHeight};	// rc���������g���ď�����.
		::DrawText(m_pScene->m_hMemDC, (*itor).c_str(), _tcslen((*itor).c_str()), &rc, DT_LEFT | DT_SINGLELINE);	// DrawText�ŕ`��.
		iPosY = iPosY + iMargin;	// iPosY��iMargin�𑫂�.
	}

}