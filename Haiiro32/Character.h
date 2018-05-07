// ��d�C���N���[�h�h�~
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedObject.h"	// CSharedObject

// �L�����N�^�[�N���XCCharacter
class CCharacter : public CSharedObject{

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CCharacter();	// �R���X�g���N�^CCharacter()
		CCharacter(CScene *pScene);	// �f�X�g���N�^CCharacter(CScene *pScene)
		virtual ~CCharacter();	// �f�X�g���N�^~CCharacter()
		// �����o�֐�
		virtual void Add(int sx, int sy, int iWidth, int iHeight, int nID);	// �A�j���[�V�����̒ǉ�Add.
		virtual void Destroy();	// �L�����N�^�[�̔j��Destroy.
		virtual void Draw(int x, int y, int iNo);	// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.

};

#endif