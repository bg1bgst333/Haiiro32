// ��d�C���N���[�h�h�~
#ifndef __SELECT_BOX_H__
#define __SELECT_BOX_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �Z���N�g�{�b�N�X�N���XCSelectBox
class CSelectBox : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HDC m_hBackgroundMemDC;	// �w�i�������f�o�C�X�R���e�L�X�gm_hBackgroundMemDC.
		HBITMAP m_hBackgroundBitmap;	// ���[�h�����w�i�r�b�g�}�b�vm_hBackgroundBitmap.
		HBITMAP m_hOldBackgroundBitmap;	// �ȑO�̔w�i�r�b�g�}�b�vm_hOldBackgroundBitmap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CSelectBox();	// �R���X�g���N�^CSelectBox()
		CSelectBox(const CScene *pScene);	// �R���X�g���N�^CSelectBox(const CScene *pScene)
		virtual ~CSelectBox();	// �f�X�g���N�^~CSelectBox()
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID);	// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void DrawRect(int x, int y);	// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)

};

#endif