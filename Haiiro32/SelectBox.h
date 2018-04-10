// ��d�C���N���[�h�h�~
#ifndef __SELECT_BOX_H__
#define __SELECT_BOX_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
#include <vector>	// std::vector

// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �Z���N�g�{�b�N�X�N���XCSelectBox
class CSelectBox sealed : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HDC m_hBackgroundMemDC;	// �w�i�������f�o�C�X�R���e�L�X�gm_hBackgroundMemDC.
		HBITMAP m_hBackgroundBitmap;	// ���[�h�����w�i�r�b�g�}�b�vm_hBackgroundBitmap.
		HBITMAP m_hOldBackgroundBitmap;	// �ȑO�̔w�i�r�b�g�}�b�vm_hOldBackgroundBitmap.
		HFONT m_hFont;	// �t�H���gm_hFont.
		HFONT m_hOldFont;	// �ȑO�̃t�H���gm_hOldFont.
		int m_iLineHeight;	// �s�̍���m_iLineHeight.
		int m_iMargin;	// �s�̊Ԋum_iMargin.
		HDC m_hCursorMemDC;	// �J�[�\���������f�o�C�X�R���e�L�X�gm_hCursorMemDC.
		HBITMAP m_hCursorBitmap;	// ���[�h�����J�[�\���r�b�g�}�b�vm_hCursorBitmap.
		HBITMAP m_hOldCursorBitmap;	// �ȑO�̃J�[�\���r�b�g�}�b�vm_hOldCursorBitmap.
		int m_iCursorWidth;	// �J�[�\���̕�m_iCursorWidth.
		int m_iCursorHeight;	// �J�[�\���̍���m_iCursorHeight.
		std::vector<tstring> m_vectstrSelectItemList;	// �Z���N�g�A�C�e�����X�gm_vectstrSelectItemList.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CSelectBox();	// �R���X�g���N�^CSelectBox()
		CSelectBox(const CScene *pScene);	// �R���X�g���N�^CSelectBox(const CScene *pScene)
		virtual ~CSelectBox();	// �f�X�g���N�^~CSelectBox()
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID, int nFontSize, LPCTSTR lpctszFontName, int iMargin, int iCursorWidth, int iCursorHeight, UINT nCursorID);	// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void AddSelectItem(tstring tstrSelectItem);	// �Z���N�g�A�C�e���̒ǉ�AddSelectItem.
		virtual void ClearSelectItem();	// �Z���N�g�A�C�e���̃N���AClearSelectItem.
		virtual void DrawRect(int x, int y);	// �Q�[���I�u�W�F�N�g�̕`��DrawRect.
		virtual void DrawSelectItemList(int x, int y, COLORREF clrColor);	// �Z���N�g�A�C�e�����X�g�̕`��DrawSelectItemList.
		virtual void DrawCursor(int x, int y);	// �J�[�\���̕`��DrawCursor.

};

#endif