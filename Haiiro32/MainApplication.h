// ��d�C���N���[�h�h�~
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H_

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameApplication.h"	// CGameApplication

// ���C���A�v���P�[�V�����N���XCMainApplication
class CMainApplication : public CGameApplication{

	// public�����o
	public:

		// public�����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �C���X�^���X�������֐�InitInstance.

};

#endif