// ��d�C���N���[�h�h�~
#ifndef __SHOT_H__
#define __SHOT_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedObject.h"	// CSharedObject

// �V���b�g�N���XCShot
class CShot : public CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		std::vector<CSharedObject *> m_vecpMaskList;	// �}�X�N���X�gm_vecpMaskList.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CShot();	// �R���X�g���N�^CShot()
		CShot(CScene *pScene);	// �f�X�g���N�^CShot(CScene *pScene)
		virtual ~CShot();	// �f�X�g���N�^~CShot()
		// �����o�֐�
		virtual void Add(int sx, int sy, int iWidth, int iHeight, int nID);	// �A�j���[�V�����̒ǉ�Add.
		virtual void AddMask(int sx, int sy, int iWidth, int iHeight, int nID);	// �}�X�N�̒ǉ�AddMask.
		virtual void Destroy();	// �V���b�g�̔j��Destroy.
		virtual void Draw(int x, int y, int iNo);	// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.
		virtual void DrawSprite(int x, int y, int iNo);	// �X�v���C�g�̕`��DrawSprite.

};

#endif