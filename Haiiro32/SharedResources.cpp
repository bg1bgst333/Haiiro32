// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SharedResources.h"	// CSharedResources

// �R���X�g���N�^CSharedResources
CSharedResources::CSharedResources(HINSTANCE hInstance){

	// �����o�̏�����.
	m_mapSharedResourceMap.clear();	// m_mapSharedResourceMap.clear�ŃN���A.
	m_hInstance = hInstance;	// m_hInstance��hInstance�ŏ�����.

}

// �f�X�g���N�^~CSharedResources
CSharedResources::~CSharedResources(){

	// �����o�̏I������.
	RemoveAll();	// RemoveAll�őS�폜.
	m_hInstance = NULL;	// m_hInstance��NULL���Z�b�g.

}

// ���\�[�X��ǉ�Add.
void CSharedResources::Add(int nID){

	// �w���ID�̃��\�[�X(�����ł̓r�b�g�}�b�v�Ƃ���.)�����[�h��, �}�b�v�ɒǉ�.
	HGDIOBJ hObj = LoadImage(m_hInstance, MAKEINTRESOURCE(nID), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);	// LoadImage�Ń��[�h.
	if (hObj != NULL){	// NULL����Ȃ����.
		m_mapSharedResourceMap.insert(std::make_pair<int, HGDIOBJ>(nID, hObj));	// m_mapSharedResourceMap.insert��(nID, hObj)�̑g��ǉ�.
	}

}

// ���\�[�X���폜Remove.
void CSharedResources::Remove(int nID){

	// nID����hBitmap������.
	std::map<int, HGDIOBJ>::iterator itor = m_mapSharedResourceMap.find(nID);	// itor�̎擾.
	if (itor != m_mapSharedResourceMap.end()){	// �݂�������.
		HGDIOBJ hObj = m_mapSharedResourceMap[nID];	// m_mapSharedResourceMap[nID]��hBitmap���擾.
		DeleteObject(hObj);	// DeleteObject��hObj���폜.
		m_mapSharedResourceMap.erase(itor);	// m_mapSharedResourceMap.erase��itor���폜.
	}

}

// ���\�[�X��S�폜RemoveAll.
void CSharedResources::RemoveAll(){

	// ���ׂč폜.
	for (std::map<int, HGDIOBJ>::iterator itor = m_mapSharedResourceMap.begin(); itor !=  m_mapSharedResourceMap.end(); itor++){	// ���ׂė�.
		DeleteObject(itor->second);	// DeleteObject��itor->second���폜.
		itor->second = NULL;	// itor->second��NULL���Z�b�g.
	}
	m_mapSharedResourceMap.clear();	// m_mapSharedResourceMap.clear�ō폜.

}

// ���\�[�X���擾Get.
HGDIOBJ CSharedResources::Get(int nID){

	// nID����hBitmap������.
	std::map<int, HGDIOBJ>::iterator itor = m_mapSharedResourceMap.find(nID);	// itor�̎擾.
	if (itor != m_mapSharedResourceMap.end()){	// �݂�������.
		return m_mapSharedResourceMap[nID];	// m_mapSharedResourceMap[nID]��Ԃ�.
	}
	else{
		return NULL;	// NULL��Ԃ�.
	}

}