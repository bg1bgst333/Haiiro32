// ��d�C���N���[�h�h�~
#ifndef __GRAPHICAL_APPLICATION_H__
#define __GRAPHICAL_APPLICATION_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// �O���t�B�J���A�v���P�[�V�����N���XCGraphicalApplication
class CGraphicalApplication : public CApplication{

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^
		CGraphicalApplication();	// �R���X�g���N�^CGraphicalApplication
		// �����o�֐�.
		virtual int Run();	// ���b�Z�[�W���[�v�����֐�Run.
		virtual int ExitInstance();	// �I�������֐�ExitInstance.
		virtual BOOL OnIdle(LONG lCount);	// �A�C�h�������֐�OnIdle.
		virtual int Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight);	// �O���t�B�J�����C�������֐�Main.

};

#endif