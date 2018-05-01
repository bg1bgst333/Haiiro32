// ��d�C���N���[�h�h�~
#ifndef __BINARY_RESOURCE_H__
#define __BINARY_RESOURCE_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// �o�C�i�����\�[�X�N���XCBinaryResource
class CBinaryResource{

	// public�����o
	public:

		// public�����o�ϐ�
		BYTE *m_pBytes;	// �o�C�g��ւ̃|�C���^.
		DWORD m_dwSize;	// ���\�[�X�T�C�Y.
		DWORD m_dwPos;	// ���݂̓ǂݍ��݈ʒu.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBinaryResource();	// �R���X�g���N�^CBinaryResource
		virtual ~CBinaryResource();	// �f�X�g���N�^~CBinaryResource
		virtual BOOL Load(HWND hWnd, int nID, LPCTSTR lpctszType);	// �w��̃��\�[�X��ǂݍ���Load.
		virtual const LPVOID Get(DWORD dwSize);	// �w��̃T�C�Y�f�[�^�ւ̃|�C���^���擾Get.

};

#endif