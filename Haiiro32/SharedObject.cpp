// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedObject.h"	// CSharedObject

// �R���X�g���N�^CSharedObject
CSharedObject::CSharedObject(){

	// �����o�̏�����.
	m_pScene = NULL;	// m_pScene��NULL���Z�b�g.
	m_x = 0;	// m_x��0���Z�b�g.
	m_y = 0;	// m_y��0���Z�b�g.
	m_iWidth = 0;	// m_iWidth��0���Z�b�g.
	m_iHeight = 0;	// m_iHeight��0���Z�b�g.
	m_nID = 0;	// m_nID��0���Z�b�g.
	m_sx = 0;	// m_sx��0���Z�b�g.
	m_sy = 0;	// m_sy��0���Z�b�g.
	m_vecpSharedObjectList.clear();	// m_vecpSharedObjectList�ŃN���A.

}

// �R���X�g���N�^CSharedObject(CScene *pScene)
CSharedObject::CSharedObject(CScene *pScene){

	// �����o�̏�����.
	m_pScene = pScene;	// m_pScene��pScene���Z�b�g.
	m_x = 0;	// m_x��0���Z�b�g.
	m_y = 0;	// m_y��0���Z�b�g.
	m_iWidth = 0;	// m_iWidth��0���Z�b�g.
	m_iHeight = 0;	// m_iHeight��0���Z�b�g.
	m_nID = 0;	// m_nID��0���Z�b�g.
	m_sx = 0;	// m_sx��0���Z�b�g.
	m_sy = 0;	// m_sy��0���Z�b�g.
	m_vecpSharedObjectList.clear();	// m_vecpSharedObjectList�ŃN���A.

}

// �f�X�g���N�^~CSharedObject
CSharedObject::~CSharedObject(){

}

// �V�F�A�[�h�I�u�W�F�N�g�̍쐬Create.
BOOL CSharedObject::Create(int sx, int sy, int iWidth, int iHeight, int nID){

	// �����o�̃Z�b�g.
	m_sx = sx;	// m_sx��sx���Z�b�g.
	m_sy = sy;	// m_sy��sy���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.
	m_nID = nID;	// m_nID��nID���Z�b�g.

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �V�F�A�[�h�I�u�W�F�N�g�̔j��Destroy.
void CSharedObject::Destroy(){

	// �����o�̃��Z�b�g.
	m_sx = 0;	// m_sx��0���Z�b�g.
	m_sy = 0;	// m_sy��0���Z�b�g.
	m_iWidth = 0;	// m_iWidth��0���Z�b�g.
	m_iHeight = 0;	// m_iHeight��0���Z�b�g.
	m_nID = 0;	// m_nID��0���Z�b�g.

}

// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.
void CSharedObject::Draw(int x, int y){

	// �`��.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	HDC hMemDC = m_pScene->m_pSharedImageBuffer->Get(m_nID);	// �w���ID�̃o�b�t�@���擾.
	BitBlt(m_pScene->m_hMemDC, x, y, m_iWidth, m_iHeight, hMemDC, m_sx, m_sy, SRCCOPY);	// BitBlt�Ńo�b�N�o�b�t�@�ɓ]��.

}