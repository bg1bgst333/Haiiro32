// ��d�C���N���[�h�h�~
#ifndef __FILE_H__
#define __FILE_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <string>	// std::string

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �t�@�C���N���XCFile
class CFile {

	// public�����o
	public:
		
		// public�����o�ϐ�
		HANDLE m_hFile;	// �t�@�C���n���h��
		tstring m_tstrFileName;	// �t�@�C����(�t���p�X)

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CFile();	// �R���X�g���N�^CFile
		virtual ~CFile();	// �f�X�g���N�^~CFile
		// �����o�֐�
		virtual BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// �t�@�C�����J��Open.
		virtual void Close();	// �t�@�C�������Close.
		virtual DWORD Read(LPVOID lpBuf, DWORD dwBytes);	// �t�@�C�����e�̓ǂݍ���Read.
		virtual DWORD Write(LPVOID lpBuf, DWORD dwBytes);	// �t�@�C�����e�̏�������Write.

};

#endif