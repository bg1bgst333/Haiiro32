// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X
#include "GameScene.h"	// CGameScene

// �R���X�g���N�^CGameScene
CGameScene::CGameScene() : CScene(){

	// �����o�̏�����.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBuffer��NULL���Z�b�g.
	m_hDC = NULL;	// m_hDC��NULL���Z�b�g.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd)
CGameScene::CGameScene(const CWindow *pWnd) : CScene(pWnd){

	// �����o�̏�����.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBuffer��NULL���Z�b�g.
	m_hDC = NULL;	// m_hDC��NULL���Z�b�g.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// �����o�̏�����.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBuffer��NULL���Z�b�g.
	m_hDC = NULL;	// m_hDC��NULL���Z�b�g.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem) : CScene(pWnd, pTime, pSystem){

	// �����o�̏�����.
	m_pSharedImageBuffer = NULL;	// m_pSharedImageBuffer��NULL���Z�b�g.
	m_hDC = NULL;	// m_hDC��NULL���Z�b�g.

}

// �f�X�g���N�^~CGameScene
CGameScene::~CGameScene(){

}

// �Q�[���I�u�W�F�N�g�̏�����.
int CGameScene::InitGameObjects(){

	// �V�F�A�[�h���\�[�X�̃��[�h.(����͑S�̂Ńt�@�C�����Ƃ�1�񂸂���Ă����΂���.)
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED1);	// m_pGameSystem->m_pSharedResources->Add��IDB_SHARED1��ǉ�.
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED2);	// m_pGameSystem->m_pSharedResources->Add��IDB_SHARED2��ǉ�.
	m_pGameSystem->m_pSharedResources->Add(IDB_SHARED3);	// m_pGameSystem->m_pSharedResources->Add��IDB_SHARED3��ǉ�.

	// �V�F�A�[�h�C���[�W�o�b�t�@�̐���.
	m_hDC = GetDC(m_pMainWnd->m_hWnd);	// m_hDC���擾.
	m_pSharedImageBuffer = new CSharedImageBuffer(m_pGameSystem->m_pSharedResources, m_hDC);	// ����.
	m_pSharedImageBuffer->Add(IDB_SHARED1);	// �ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED2);	// �ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED3);	// �ǉ�.

	return 0;

}

// �L�[�{�[�h�̏�����.
int CGameScene::InitKeyboard(){

	return 0;

}

// �L�[�{�[�h�̃`�F�b�N.
int CGameScene::CheckKeyboard(){

	return 0;

}

// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
int CGameScene::RunProc(){

	return 0;

}

// �Q�[���I�u�W�F�N�g�̕`��.
int CGameScene::DrawGameObjects(){

	HDC hShared1DC = m_pSharedImageBuffer->Get(IDB_SHARED1);
	BitBlt(m_hMemDC, 0, 0, 100, 100, hShared1DC, 0, 0, SRCCOPY);
	
	HDC hShared2DC = m_pSharedImageBuffer->Get(IDB_SHARED2);
	BitBlt(m_hMemDC, 100, 100, 100, 100, hShared2DC, 0, 0, SRCCOPY);
	
	HDC hShared3DC = m_pSharedImageBuffer->Get(IDB_SHARED3);
	BitBlt(m_hMemDC, 200, 200, 100, 100, hShared3DC, 0, 0, SRCCOPY);

	return 0;

}

// �Q�[���I�u�W�F�N�g�̏I������.
int CGameScene::ExitGameObjects(){

	// �V�F�A�[�h�C���[�W�o�b�t�@�̉��.
	ReleaseDC(m_pMainWnd->m_hWnd, m_hDC);	// ReleaseDC�ŉ��.
	delete m_pSharedImageBuffer;	// m_pSharedImageBuffer���폜.

	return 0;

}