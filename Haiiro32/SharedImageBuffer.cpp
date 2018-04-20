// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedImageBuffer.h"	// CSharedImageBuffer

// �R���X�g���N�^CSharedImageBuffer
CSharedImageBuffer::CSharedImageBuffer(CSharedResources *pSharedResources, HDC hDC){

	// �����o�̏�����.
	m_mapSharedImageBufferMap.clear();	// m_mapSharedImageBufferMap.clear�ŃN���A.
	m_pSharedResources = pSharedResources;	// m_pSharedResources��pSharedResources���Z�b�g.
	m_hDC = hDC;	// m_hDC��hDC���Z�b�g.

}

// �f�X�g���N�^~CSharedImageBuffer
CSharedImageBuffer::~CSharedImageBuffer(){

	// �����o�̏I������.
	RemoveAll();	// RemoveAll�őS�폜.

}

// �������f�o�C�X�R���e�L�X�g��ǉ�Add.
void CSharedImageBuffer::Add(int nID){

	// �������f�o�C�X�R���e�L�X�g���쐬��, �r�b�g�}�b�v�ƕR�t����.
	HDC hMemDC = CreateCompatibleDC(m_hDC);	// hMemDC�𐶐�.
	if (hMemDC != NULL){	// NULL����Ȃ����.
		HBITMAP hBitmap = (HBITMAP)m_pSharedResources->Get(nID);
		SelectObject(hMemDC, hBitmap);	// SelectObject��hMemDC��hBitmap��I��.
		m_mapSharedImageBufferMap.insert(std::make_pair<int, HDC>(nID, hMemDC));	// (nID, hMemDC)�̑g��o�^.
	}

}

// �������f�o�C�X�R���e�L�X�g���폜Remove.
void CSharedImageBuffer::Remove(int nID){

	// nID����hMemDC������.
	std::map<int, HDC>::iterator itor = m_mapSharedImageBufferMap.find(nID);	// itor�̎擾.
	if (itor != m_mapSharedImageBufferMap.end()){	// �݂�������.
		HDC hMemDC = m_mapSharedImageBufferMap[nID];	// m_mapSharedImageBufferMap[nID]��hMemDC���擾.
		DeleteDC(hMemDC);	// DeleteDC��hMemDC���폜.
		m_mapSharedImageBufferMap.erase(itor);	// m_mapSharedImageBufferMap.erase��itor���폜.
	}

}

// �������f�o�C�X�R���e�L�X�g��S�폜RemoveAll.
void CSharedImageBuffer::RemoveAll(){

	// ���ׂč폜.
	for (std::map<int, HDC>::iterator itor = m_mapSharedImageBufferMap.begin(); itor !=  m_mapSharedImageBufferMap.end(); itor++){	// ���ׂė�.
		DeleteDC(itor->second);	// DeleteDC��itor->second���폜.
		itor->second = NULL;	// itor->second��NULL���Z�b�g.
	}
	m_mapSharedImageBufferMap.clear();	// m_mapSharedImageBufferMap.clear�ō폜.

}

// �������f�o�C�X�R���e�L�X�g���擾Get.
HDC CSharedImageBuffer::Get(int nID){

	// nID����hDC������.
	std::map<int, HDC>::iterator itor = m_mapSharedImageBufferMap.find(nID);	// itor�̎擾.
	if (itor != m_mapSharedImageBufferMap.end()){	// �݂�������.
		return m_mapSharedImageBufferMap[nID];	// m_mapSharedImageBufferMap[nID]��Ԃ�.
	}
	else{
		return NULL;	// NULL��Ԃ�.
	}

}