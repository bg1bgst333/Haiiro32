// ��d�C���N���[�h�h�~
#ifndef __SHARED_OBJECT_H__
#define __SHARED_OBJECT_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene

// �V�F�A�[�h�I�u�W�F�N�g�N���XCSharedObject
class CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		CScene *m_pScene;	// CScene�I�u�W�F�N�g�|�C���^m_pScene.
		int m_x;	// �ʒux���Wm_x.
		int m_y;	// �ʒuy���Wm_y.
		int m_iWidth;	// ��m_iWidth.
		int m_iHeight;	// ����m_iHeight.
		int m_nID;	// ���\�[�XID.
		int m_sx;	// �]����x���Wm_sx.
		int m_sy;	// �]����y���Wm_sy.
		std::vector<CSharedObject *> m_vecpSharedObjectList;	// �V�F�A�[�h�I�u�W�F�N�g���X�gm_vecpSharedObjectList.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CSharedObject();	// �R���X�g���N�^CSharedObject
		CSharedObject(CScene *pScene);	// �R���X�g���N�^CSharedObject(CScene *pScene)
		virtual ~CSharedObject();	// �f�X�g���N�^~CSharedObject
		// �����o�֐�
		virtual BOOL Create(int sx, int sy, int iWidth, int iHeight, int nID);	// �V�F�A�[�h�I�u�W�F�N�g�̍쐬Create.
		virtual void Destroy();	// �V�F�A�[�h�I�u�W�F�N�g�̔j��Destroy.
		virtual void Draw(int x, int y);	// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.

};

#endif