// ��d�C���N���[�h�h�~
#ifndef __TITLE_H__
#define __TITLE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �^�C�g���N���XCTitle
class CTitle : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HDC m_hMemDC;	// 
		HBITMAP m_hBitmap;	// ���[�h�����r�b�g�}�b�vm_hBitmap.
		HBITMAP m_hOldBitmap;	// �ȑO�̃r�b�g�}�b�vm_hOldBitmap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CTitle();	// �R���X�g���N�^CTitle()
		CTitle(const CScene *pScene);	// �R���X�g���N�^CTitle(const CScene *pScene)
		virtual ~CTitle();	// �f�X�g���N�^~CTitle()
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID);	// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void DrawRect(int x, int y);	// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
		virtual void DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor);	// DrawText�Ńe�L�X�g��`��.

};

#endif