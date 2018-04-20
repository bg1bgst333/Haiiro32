// ��d�C���N���[�h�h�~
#ifndef __SHARED_RESOURCES_H__
#define __SHARED_RESOURCES_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <map>	// std::map

// �V�F�A�[�h���\�[�V�Y�N���XCSharedResources
class CSharedResources{

	// public�����o
	public:

		// public�����o�ϐ�
		std::map<int, HGDIOBJ> m_mapSharedResourceMap;	// �V�F�A�[�h���\�[�X�}�b�vm_mapSharedResourceMap.
		HINSTANCE m_hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��m_hInstance.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CSharedResources(HINSTANCE hInstance);	// �R���X�g���N�^CSharedResources
		virtual ~CSharedResources();	// �f�X�g���N�^~CSharedResources
		void Add(int nID);	// ���\�[�X��ǉ�Add.
		void Remove(int nID);	// ���\�[�X���폜Remove.
		void RemoveAll();	// ���\�[�X��S�폜RemoveAll.
		HGDIOBJ Get(int nID);	// ���\�[�X���擾Get.

};

#endif