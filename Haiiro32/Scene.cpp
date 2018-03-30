// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene

// �R���X�g���N�^CScene
CScene::CScene(){

	// �����o�̏�����.
	m_pMainWnd = NULL;	// m_pMainWnd��NULL�ŏ�����.

}

// �R���X�g���N�^CScene(const CWindow *pWnd)
CScene::CScene(const CWindow *pWnd){

	// �����o�̏�����.
	m_pMainWnd = pWnd;	// m_pMainWnd��pWnd�ŏ�����.

}

// �f�X�g���N�^~CScene
CScene::~CScene(){

}

// �V�[��������InitScene.
int CScene::InitScene(){

	// �����Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �V�[��������RunScene.
int CScene::RunScene(){

	// SPACE�L�[���������甲����.
	if (GetAsyncKeyState(VK_SPACE)){	// GetAsyncKeyState��SPACE��������Ă�����.
		MessageBox(NULL, _T("SPACE"), _T("Haiiro"), MB_OK);	// MessageBox��"SPACE"�ƕ\��.(����������, 2��ȏ㕪�ɂȂ��Ă��܂�.)
		return 1;	// 1��Ԃ�.
	}

	// ESCAPE�L�[���������甲����.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyState��ESCAPE��������Ă�����.
		MessageBox(NULL, _T("ESCAPE"), _T("Haiiro"), MB_OK);	// MessageBox��"ESCAPE"�ƕ\��.(����������, 2��ȏ㕪�ɂȂ��Ă��܂�.)
		return 2;	// 2��Ԃ�.
	}

	// �p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}

// �V�[���I������ExitScene.
int CScene::ExitScene(){

	// �p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}