// ��d�C���N���[�h�h�~
#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene

// �O���錾.
class CScene;	// CScene.

// �Q�[���I�u�W�F�N�g�N���XCGameObject
class CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		const CScene *m_pScene;	// CScene�I�u�W�F�N�g�|�C���^m_pScene.(const)
		int m_x;	// �ʒux���Wm_x.
		int m_y;	// �ʒuy���Wm_y.
		int m_iWidth;	// ��m_iWidth.
		int m_iHeight;	// ����m_iHeight.
		HPEN m_hPen;	// �y��m_hPen.
		HPEN m_hOldPen;	// ���̃y��m_hOldPen.
		HBRUSH m_hBrush;	// �u���Vm_hBrush.
		HBRUSH m_hOldBrush;	// ���̃u���Vm_hOldBrush.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CGameObject();	// �R���X�g���N�^CGameObject()
		CGameObject(const CScene *pScene);	// �R���X�g���N�^CGameObject(const CScene *pScene)
		virtual ~CGameObject();	// �f�X�g���N�^~CGameObject()
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, COLORREF clrPen, COLORREF clrBrush);	// �Q�[���I�u�W�F�N�g�̍쐬Create.(�y���ƃu���V�ŕ`���ꂽ��`.)
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual void DrawRect(int x, int y);	// �Q�[���I�u�W�F�N�g�̕`��DrawRect.(�y���ƃu���V�ŕ`���ꂽ��`.)

};

#endif