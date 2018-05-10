// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Shot.h"	// CShot
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CShot()
CShot::CShot() : CSharedObject(){

}

// �f�X�g���N�^CShot(CScene *pScene)
CShot::CShot(CScene *pScene) : CSharedObject(pScene){

}

// �f�X�g���N�^~CShot()
CShot::~CShot(){

	// �j��.
	Destroy();	// Destroy�Ŕj��.

}

// �A�j���[�V�����̒ǉ�Add.
void CShot::Add(int sx, int sy, int iWidth, int iHeight, int nID){

	// �q�I�u�W�F�N�g�𐶐����Ēǉ�.
	CSharedObject *pSharedObject = new CSharedObject(m_pScene);			// CSharedObject�I�u�W�F�N�g�𐶐�.
	pSharedObject->Create(sx, sy, iWidth, iHeight, nID);	// Create�Ő���.
	m_vecpSharedObjectList.push_back(pSharedObject);	// push_back�Œǉ�.

}

// �}�X�N�̒ǉ�AddMask.
void CShot::AddMask(int sx, int sy, int iWidth, int iHeight, int nID){

	// �}�X�N�̐����ƒǉ�.
	CSharedObject *pMask = new CSharedObject(m_pScene);			// CSharedObject�I�u�W�F�N�g�𐶐�.
	pMask->Create(sx, sy, iWidth, iHeight, nID);	// Create�Ő���.
	m_vecpMaskList.push_back(pMask);	// push_back�Œǉ�.

}

// �V���b�g�̔j��Destroy.
void CShot::Destroy(){

	// �q�I�u�W�F�N�g��j��.
	// �}�X�N.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpMaskList.begin(); itor != m_vecpMaskList.end(); itor++){	// ���X�g�S�Ă̔j��.
		if ((*itor) != NULL){	// (*itor)��NULL����Ȃ���.
			(*itor)->Destroy();	// (*itor)->Destroy�Ŕj��.
			delete (*itor);	// delete��(*Itor)��j��.
			(*itor) = NULL;	// NULL���Z�b�g.
		}
	}
	// �C���[�W.
	for (std::vector<CSharedObject *>::iterator itor = m_vecpSharedObjectList.begin(); itor != m_vecpSharedObjectList.end(); itor++){	// ���X�g�S�Ă̔j��.
		if ((*itor) != NULL){	// (*itor)��NULL����Ȃ���.
			(*itor)->Destroy();	// (*itor)->Destroy�Ŕj��.
			delete (*itor);	// delete��(*Itor)��j��.
			(*itor) = NULL;	// NULL���Z�b�g.
		}
	}
	m_vecpMaskList.clear();	// �N���A.
	m_vecpSharedObjectList.clear();	// �N���A.

}

// �V�F�A�[�h�I�u�W�F�N�g�̕`��Draw.
void CShot::Draw(int x, int y, int iNo){

	// iNo�Ԗڂ�`��.
	m_vecpSharedObjectList[iNo]->Draw(x, y);	// m_vecpSharedObjectList[iNo]->Draw�ŕ`��.

}

// �X�v���C�g�̕`��DrawSprite.
void CShot::DrawSprite(int x, int y, int iNo){

	// �`��.
	m_vecpSharedObjectList[iNo]->m_x = x;	// m_vecpSharedObjectList[iNo]->m_x��x���Z�b�g.
	m_vecpSharedObjectList[iNo]->m_y = y;	// m_vecpSharedObjectList[iNo]->m_y��y���Z�b�g.
	HDC hMemDC = m_vecpSharedObjectList[iNo]->m_pScene->m_pSharedImageBuffer->Get(m_vecpSharedObjectList[iNo]->m_nID);	// hMemDC���擾.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = m_vecpSharedObjectList[iNo]->m_iWidth;	// m_iWidth�̃Z�b�g.
	m_iHeight = m_vecpSharedObjectList[iNo]->m_iHeight;	// m_iHeight�̃Z�b�g.
	m_sx = m_vecpSharedObjectList[iNo]->m_sx;	// m_sx�̃Z�b�g.
	m_sy = m_vecpSharedObjectList[iNo]->m_sy;	// m_sy�̃Z�b�g.
	HDC hMaskMemDC = m_vecpMaskList[iNo]->m_pScene->m_pSharedImageBuffer->Get(m_vecpMaskList[iNo]->m_nID);	// hMasMemDC���擾.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, hMaskMemDC, m_vecpMaskList[iNo]->m_sx, m_vecpMaskList[iNo]->m_sy, SRCPAINT);	// �}�X�N��SRCPAINT.
	BitBlt(m_pScene->m_hMemDC, m_x, m_y, m_iWidth, m_iHeight, hMemDC, m_sx, m_sy, SRCAND);	// SRCAND�Ń��C���C���[�W��`��.

}