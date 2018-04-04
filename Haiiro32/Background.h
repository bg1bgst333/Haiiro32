// ��d�C���N���[�h�h�~
#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �o�b�N�O���E���h�N���XCBackground
class CBackground : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HDC m_hMemDC;	// 
		HBITMAP m_hBitmap;	// ���[�h�����r�b�g�}�b�vm_hBitmap.
		HBITMAP m_hOldBitmap;	// �ȑO�̃r�b�g�}�b�vm_hOldBitmap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBackground();	// �R���X�g���N�^CBackground()
		CBackground(const CScene *pScene);	// �R���X�g���N�^CBackground(const CScene *pScene)
		virtual ~CBackground();	// �f�X�g���N�^~CBackground()
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWnd, UINT nID);	// �Q�[���I�u�W�F�N�g�̍쐬Create.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void DrawRect(int x, int y);	// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�w�肳�ꂽ���\�[�XID�̉摜�����[�h.)

};

#endif