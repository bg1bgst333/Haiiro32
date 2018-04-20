// ��d�C���N���[�h�h�~
#ifndef __SHARED_IMAGE_BUFFER_H__
#define __SHARED_IMAGE_BUFFER_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <map>	// std::map
// �Ǝ��̃w�b�_
#include "SharedResources.h"	// CSharedResources

// �V�F�A�[�h�C���[�W�o�b�t�@CSharedImageBuffer
class CSharedImageBuffer{

	// public�����o
	public:

		// public�����o�ϐ�
		std::map<int, HDC> m_mapSharedImageBufferMap;	// �V�F�A�[�h�C���[�W�o�b�t�@�}�b�vm_mapSharedImageBufferMap.
		CSharedResources *m_pSharedResources;	// CSharedResources�I�u�W�F�N�g�|�C���^m_pSharedResources.
		HDC m_hDC;	// �x�[�X�f�o�C�X�R���e�L�X�g�n���h��m_hDC.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CSharedImageBuffer(CSharedResources *pSharedResources, HDC hDC);	// �R���X�g���N�^CSharedImageBuffer
		virtual ~CSharedImageBuffer();	// �f�X�g���N�^~CSharedImageBuffer
		void Add(int nID);	// �������f�o�C�X�R���e�L�X�g��ǉ�Add.
		void Remove(int nID);	// �������f�o�C�X�R���e�L�X�g���폜Remove.
		void RemoveAll();	// �������f�o�C�X�R���e�L�X�g��S�폜RemoveAll.
		HDC Get(int nID);	// �������f�o�C�X�R���e�L�X�g���擾Get.

};

#endif