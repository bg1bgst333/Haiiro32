// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SelectBox.h"	// CSelectBox

// �R���X�g���N�^CSelectBox()
CSelectBox::CSelectBox() : CGameObject(){

	// �����o�̏�����.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL�ŏ�����.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL�ŏ�����.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL�ŏ�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.
	m_iLineHeight = 0;	// m_iLineHeight��0�ŏ�����.
	m_iMargin = 0;	// m_iMargin��0�ŏ�����.
	m_hCursorMemDC = NULL;	// m_hCursorMemDC��NULL�ŏ�����.
	m_hCursorBitmap = NULL;	// m_hCursorBitmap��NULL�ŏ�����.
	m_hOldCursorBitmap = NULL;	// m_hOldCursorBitmap��NULL�ŏ�����.
	m_iCursorX = 0;	// m_iCursorX��0�ŏ�����.
	m_iCursorY = 0;	// m_iCursorY��0�ŏ�����.
	m_iCursorWidth = 0;	// m_iCursorWidth��0�ŏ�����.
	m_iCursorHeight = 0;	// m_iCursorHeight��0�ŏ�����.
	m_iCursorIndex = 0;	// m_iCursorIndex��0�ŏ�����.
	m_bCursorVisible = FALSE;	// m_bCursorVisible��FALSE�ŏ�����.
	m_bDown = FALSE;	// m_bDown��FALSE�ŏ�����.
	m_bUp = FALSE;	// m_bUp��FALSE�ŏ�����.
	m_bReturn = FALSE;	// m_bReturn��FALSE�ŏ�����.
	m_bDetermine = FALSE;	// m_bDetermine��FALSE�ŏ�����.
	m_dwInterval = 0;	// m_dwInterval��0�ŏ�����.
	m_dwTimerStart = 0;	// m_dwTimerStart��0�ŏ�����.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clear�ŃN���A.

}

// �R���X�g���N�^CSelectBox(const CScene *pScene)
CSelectBox::CSelectBox(const CScene *pScene) : CGameObject(pScene){

	// �����o�̏�����.
	m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL�ŏ�����.
	m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL�ŏ�����.
	m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL�ŏ�����.
	m_hFont = NULL;	// m_hFont��NULL�ŏ�����.
	m_hOldFont = NULL;	// m_hOldFont��NULL�ŏ�����.
	m_iLineHeight = 0;	// m_iLineHeight��0�ŏ�����.
	m_iMargin = 0;	// m_iMargin��0�ŏ�����.
	m_hCursorMemDC = NULL;	// m_hCursorMemDC��NULL�ŏ�����.
	m_hCursorBitmap = NULL;	// m_hCursorBitmap��NULL�ŏ�����.
	m_hOldCursorBitmap = NULL;	// m_hOldCursorBitmap��NULL�ŏ�����.
	m_iCursorX = 0;	// m_iCursorX��0�ŏ�����.
	m_iCursorY = 0;	// m_iCursorY��0�ŏ�����.
	m_iCursorWidth = 0;	// m_iCursorWidth��0�ŏ�����.
	m_iCursorHeight = 0;	// m_iCursorHeight��0�ŏ�����.
	m_iCursorIndex = 0;	// m_iCursorIndex��0�ŏ�����.
	m_bCursorVisible = FALSE;	// m_bCursorVisible��FALSE�ŏ�����.
	m_bDown = FALSE;	// m_bDown��FALSE�ŏ�����.
	m_bUp = FALSE;	// m_bUp��FALSE�ŏ�����.
	m_bReturn = FALSE;	// m_bReturn��FALSE�ŏ�����.
	m_bDetermine = FALSE;	// m_bDetermine��FALSE�ŏ�����.
	m_dwInterval = 0;	// m_dwInterval��0�ŏ�����.
	m_dwTimerStart = 0;	// m_dwTimerStart��0�ŏ�����.
	m_vectstrSelectItemList.clear();	// m_vectstrSelectItemList.clear�ŃN���A.

}

// �f�X�g���N�^~CSelectBox()
CSelectBox::~CSelectBox(){

}

// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
BOOL CSelectBox::Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName, int iMargin, int iCursorWidth, int iCursorHeight, UINT nCursorID){

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

	// �w�i�r�b�g�}�b�v�̑I��.
	m_hOldBackgroundBitmap = (HBITMAP)SelectObject(m_hBackgroundMemDC, m_hBackgroundBitmap);	// SelectObject��m_hBackgroundBitmap��I��.

	// �ʒu�ƃT�C�Y�̎擾.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.

	// �t�H���g�̍쐬.
	m_hFont = CreateFont(nFontSize, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, lpctszFontName);	// CreateFont�Ńt�H���g���쐬��, m_hFont�Ɋi�[.
	if (m_hFont == NULL){	// m_hFont��NULL�Ȃ�.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObject��m_hOldBackgroundBitmap��I��.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL���Z�b�g.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObject��m_hBackgroundBitmap���폜.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL���Z�b�g.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDC��DeleteDC�ō폜.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �t�H���g�̑I��.
	m_hOldFont = (HFONT)SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.

	// �e�L�X�g�̍������擾.
	TEXTMETRIC tm;	// �t�H���g��������TEXTMETRIC�\���̕ϐ�tm.
	GetTextMetrics(m_pScene->m_hMemDC, &tm);	// GetTextMetrics��tm�̓��e���擾.
	m_iLineHeight = tm.tmHeight;	// m_iLineHeight��tm.tmHeight���Z�b�g.

	// �s�̊Ԋu�̃Z�b�g.
	m_iMargin = iMargin;	// m_iMargin��iMargin���Z�b�g.

	// �J�[�\���������f�o�C�X�R���e�L�X�g�̍쐬.
	m_hCursorMemDC = CreateCompatibleDC(m_pScene->m_hDC);	// CreateCompatibleDC��m_hCursorMemDC���쐬.
	if (m_hCursorMemDC == NULL){	// m_hCursorMemDC��NULL�Ȃ�.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObject��m_hOldFont�ɖ߂�.
		m_hOldFont = NULL;	// m_hOldFont��NULL���Z�b�g.
		DeleteObject(m_hFont);	// DeleteObject��m_hFont���폜.
		m_hFont = NULL;	// m_hFont��NULL���Z�b�g.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObject��m_hOldBackgroundBitmap��I��.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL���Z�b�g.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObject��m_hBackgroundBitmap���폜.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL���Z�b�g.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDC��DeleteDC�ō폜.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �J�[�\���r�b�g�}�b�v�̃��[�h.
	m_iCursorX = 0;	// m_iCursorX��0�ŏ�����.
	m_iCursorY = 0;	// m_iCursorY��0�ŏ�����.
	m_iCursorWidth = iCursorWidth;	// m_iCursorWidth��iCursorWidth���Z�b�g.
	m_iCursorHeight = iCursorHeight;	// m_iCursorHeight��iCursorHeight���Z�b�g.
	m_iCursorIndex = 0;	// m_iCursorIndex��0�ŏ�����.
	m_bCursorVisible = TRUE;	// m_bCursorVisible��TRUE����.
	m_bDown = FALSE;	// m_bDown��FALSE�ŏ�����.
	m_bUp = FALSE;	// m_bUp��FALSE�ŏ�����.
	m_bReturn = FALSE;	// m_bReturn��FALSE�ŏ�����.
	m_bDetermine = FALSE;	// m_bDetermine��FALSE�ŏ�����.
	m_dwInterval = 0;	// m_dwInterval��0�ŏ�����.
	m_dwTimerStart = 0;	// m_dwTimerStart��0�ŏ�����.
	m_hCursorBitmap = (HBITMAP)LoadImage(hInstance, MAKEINTRESOURCE(nCursorID), IMAGE_BITMAP, m_iCursorWidth, m_iCursorHeight, LR_DEFAULTCOLOR);	// LoadImage�Ń��\�[�XID��nCursorID�̃r�b�g�}�b�v�����[�h.
	if (m_hCursorBitmap == NULL){	// m_hCursorBitmap��NULL�Ȃ�.
		DeleteDC(m_hCursorMemDC);	// DeleteDC��m_hCursorMemDC���폜.
		m_hCursorMemDC = NULL;	// m_hCursorMemDC��NULL���Z�b�g.
		SelectObject(m_pScene->m_hMemDC, m_hOldFont);	// SelectObject��m_hOldFont�ɖ߂�.
		m_hOldFont = NULL;	// m_hOldFont��NULL���Z�b�g.
		DeleteObject(m_hFont);	// DeleteObject��m_hFont���폜.
		m_hFont = NULL;	// m_hFont��NULL���Z�b�g.
		SelectObject(m_hBackgroundMemDC, m_hOldBackgroundBitmap);	// SelectObject��m_hOldBackgroundBitmap��I��.
		m_hOldBackgroundBitmap = NULL;	// m_hOldBackgroundBitmap��NULL���Z�b�g.
		DeleteObject(m_hBackgroundBitmap);	// DeleteObject��m_hBackgroundBitmap���폜.
		m_hBackgroundBitmap = NULL;	// m_hBackgroundBitmap��NULL���Z�b�g.
		DeleteDC(m_hBackgroundMemDC);	// m_hBackgroundMemDC��DeleteDC�ō폜.
		m_hBackgroundMemDC = NULL;	// m_hBackgroundMemDC��NULL���Z�b�g.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �J�[�\���r�b�g�}�b�v�̑I��.
	m_hOldCursorBitmap = (HBITMAP)SelectObject(m_hCursorMemDC, m_hCursorBitmap);	// SelectObject��m_hCursorBitmap��I��.

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
	m_iMargin = 0;	// m_iMargin��0����.
	m_iLineHeight = 0;	// m_iLineHeight��0����.
	m_iCursorX = 0;	// m_iCursorX��0����.
	m_iCursorY = 0;	// m_iCursorY��0����.
	m_iCursorWidth = 0;	// m_iCursorWidth��0����.
	m_iCursorHeight = 0;	// m_iCursorHeight��0����.
	m_iCursorIndex = 0;	// m_iCursorIndex��0����.
	m_bCursorVisible = FALSE;	// m_bCursorVisible��FALSE����.
	m_bDown = FALSE;	// m_bDown��FALSE����.
	m_bUp = FALSE;	// m_bUp��FALSE����.
	m_bReturn = FALSE;	// m_bReturn��FALSE����.
	m_bDetermine = FALSE;	// m_bDetermine��FALSE����.
	m_dwInterval = 0;	// m_dwInterval��0����.
	m_dwTimerStart = 0;	// m_dwTimerStart��0����.

	// �J�[�\���r�b�g�}�b�v��߂�.
	if (m_hOldCursorBitmap != NULL){	// m_hOldCursorBitmap��NULL�łȂ����.
		SelectObject(m_hCursorMemDC, m_hOldCursorBitmap);	// SelectObject��m_hOldCursorBitmap�ɖ߂�.
		m_hOldCursorBitmap = NULL;	// m_hOldCursorBitmap��NULL���Z�b�g.
	}

	// �J�[�\���r�b�g�}�b�v�̍폜.
	if (m_hCursorBitmap != NULL){	// m_hCursorBitmap��NULL�łȂ����.
		DeleteObject(m_hCursorBitmap);	// DeleteObject��m_hCursorBitmap���폜.
		m_hCursorBitmap = NULL;	// m_hCursorBitmap��NULL���Z�b�g.
	}

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
	SelectObject(m_pScene->m_hMemDC, m_hFont);	// SelectObject��m_hFont��I��.
	int iPosY = m_y + y;	// iPosY��m_y + y�ŏ�����.
	for (std::vector<tstring>::iterator itor = m_vectstrSelectItemList.begin(); itor != m_vectstrSelectItemList.end(); itor++){	// itor���I���܂ŌJ��Ԃ�.
		RECT rc = {m_x + x, iPosY, m_x + x + m_iWidth, m_y + y + m_iHeight};	// rc���������g���ď�����.
		::DrawText(m_pScene->m_hMemDC, (*itor).c_str(), _tcslen((*itor).c_str()), &rc, DT_LEFT | DT_SINGLELINE);	// DrawText�ŕ`��.
		iPosY = iPosY + m_iLineHeight;	// iPosY��m_iLineHeight�𑫂�.
		iPosY = iPosY + m_iMargin;	// iPosY��m_iMargin�𑫂�.
	}

}

// �J�[�\���̕`��DrawCursor.
void CSelectBox::DrawCursor(int x, int y){

	// �J�[�\���ʒu�̌���.
	m_iCursorY = (m_iLineHeight + m_iMargin) * m_iCursorIndex;	// (m_iLineHeight + m_iMargin) * m_iCursorIndex���Z�b�g.

	// �J�[�\���̕`��.
	if (m_bCursorVisible){	// m_bCursorVisible��TRUE�Ȃ�.
		BitBlt(m_pScene->m_hMemDC, m_x + x + m_iCursorX,  m_y + y + m_iCursorY, m_iCursorWidth, m_iCursorHeight, m_hCursorMemDC, 0, 0, SRCCOPY);	// BitBlt�ŃJ�[�\����`��.
	}

}

// ���̓N���A.
void CSelectBox::ClearInput(){

	// ���̓N���A.
	m_bDown = FALSE;	// m_bDown��FALSE�ɏ�����.
	m_bUp = FALSE;	// m_bUp��FALSE�ɏ�����.
	m_bReturn = FALSE;	// m_bReturn��FALSE�ɏ�����.

}

// �J�[�\�������Ɉړ�Down.
void CSelectBox::Down(){

	// �����L��.
	m_bDown = TRUE;	// m_bDown��TRUE�ɂ���.

}

// �J�[�\������Ɉړ�Up.
void CSelectBox::Up(){

	// �オ�L��.
	m_bUp = TRUE;	// m_bUp��TRUE�ɂ���.

}

// ����Return.
void CSelectBox::Return(){

	// ���^�[�����L��.
	m_bReturn = TRUE;	// m_bReturn��TRUE�ɂ���.

}

// ����������Proc.
int CSelectBox::Proc(){

	// ���m��̎�.
	if (!m_bDetermine){	// m_bDetermin��FALSE.

		// ���^�[���������ꂽ��.
		if (m_bReturn){	// m_bReturn��TRUE.

			// �m����.
			m_bDetermine = TRUE;	// m_bDetermin��TRUE���Z�b�g.

			// �^�C�}�[�̃Z�b�g.
			SetTimer(100);	// 100�~���b(0.1�b)�̃^�C�}�[���Z�b�g.

			// �����Ȃ̂�0.
			return 0;	// 0��Ԃ�.

		}

		// ���������ꂽ��.
		if (m_bDown){	// m_bDown��TRUE.
			m_iCursorIndex++;	// m_iCursorIndex���C���N�������g.
		}

		// �オ�����ꂽ��.
		if (m_bUp){	// m_bUp��TRUE.
			m_iCursorIndex--;	// m_iCursorIndex���f�N�������g.
		}

		// �C���f�b�N�X���v�f���ȏ�̎�.
		if (m_iCursorIndex > (int)m_vectstrSelectItemList.size() - 1){	// �Ō�̗v�f���z������.
			m_iCursorIndex = 0;	// 0�ɂ���.
		}

		// �C���f�b�N�X��0�����̎�.
		if (m_iCursorIndex < 0){	// 0�����̎�.
			m_iCursorIndex = (int)m_vectstrSelectItemList.size() - 1;	// �Ō�̗v�f�ɂ���.
		}

	}
	else{	// m_bDetermine��TRUE�̎�.

		// �^�C�}�[�������Ƃɐ؂�ւ���.
		if (IsElapsed()){	// IsElapsed��TRUE.
			if (m_bCursorVisible){	// TRUE�Ȃ�
				m_bCursorVisible = FALSE;	// FALSE�ɐ؂�ւ�.
			}
			else{	// FALSE�Ȃ�
				m_bCursorVisible = TRUE;	// TRUE�ɐ؂�ւ�.
			}
		}

	}

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �^�C�}�[�̃Z�b�gSetTimer.
void CSelectBox::SetTimer(DWORD dwInterval){

	// �C���^�[�o���̃Z�b�g.
	m_dwInterval = dwInterval;	// m_dwInterval��dwInterval���Z�b�g.

	// �^�C�}�[�̃Z�b�g.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	m_dwTimerStart = pTime->Get();	// pTime->Get�Ŏ擾����������m_dwTimerStart�Ɋi�[.

}

// �^�C�}�[���o�ߎ��Ԃ��߂��������`�F�b�NIsElapsed.
BOOL CSelectBox::IsElapsed(){

	// ���ݎ����̎擾.
	const CScene *pScene = m_pScene;	// m_pScene��pScene�Ɋi�[.
	CGameTime *pTime = pScene->m_pGameTime;	// pScene->m_pGameTime��pTime�Ɋi�[.
	DWORD dwNow = pTime->Get();	// pTime->Get�Ŏ擾����������dwNow�Ɋi�[.

	// �o�ߎ��ԃ`�F�b�N.
	if (dwNow - m_dwTimerStart >= m_dwInterval){	// m_dwInterval�ȏ�Ȃ�.
		m_dwTimerStart = dwNow;	// dwNow��m_dwTimerStart�ɃZ�b�g.
		return TRUE;	// TRUE��Ԃ�.
	}
	else{
		return FALSE;	// FALSE��Ԃ�.
	}

}