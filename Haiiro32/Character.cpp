// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Character.h"	// CCharacter
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CCharacter()
CCharacter::CCharacter() : CSharedObject(){

}

// �f�X�g���N�^CCharacter(CScene *pScene)
CCharacter::CCharacter(CScene *pScene) : CSharedObject(pScene){

}

// �f�X�g���N�^~CCharacter()
CCharacter::~CCharacter(){

	// �j��.
	Destroy();	// Destroy�Ŕj��.

}

// �A�j���[�V�����̒ǉ�Add.
void CCharacter::Add(int sx, int sy, int iWidth, int iHeight, int nID){

	// �q�I�u�W�F�N�g�𐶐����Ēǉ�.
	CSharedObject *pSharedObject = new CSharedObject(m_pScene);			// CSharedObject�I�u�W�F�N�g�𐶐�.
	pSharedObject->Create(sx, sy, iWidth, iHeight, nID);	// Create�Ő���.
	m_vecpSharedObjectList.push_back(pSharedObject);	// push_back�Œǉ�.

}

// �L�����N�^�[�̔j��Destroy.
void CCharacter::Destroy(){

	// �q�I�u�W�F�N�g��j��.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpSharedObjectList.begin(); itor != m_vecpSharedObjectList.end(); itor++){	// ���X�g�S�Ă̔j��.
		if ((*itor) != NULL){	// (*itor)��NULL����Ȃ���.
			(*itor)->Destroy();	// (*itor)->Destroy�Ŕj��.
			delete (*itor);	// delete��(*Itor)��j��.
			(*itor) = NULL;	// NULL���Z�b�g.
		}
	}
	m_vecpSharedObjectList.clear();	// �N���A.

}

// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.
void CCharacter::Draw(int x, int y, int iNo){

	// iNo�Ԗڂ�`��.
	m_vecpSharedObjectList[iNo]->Draw(x, y);	// m_vecpSharedObjectList[iNo]->Draw�ŕ`��.

}