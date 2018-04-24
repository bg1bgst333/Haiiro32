// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X
#include "GameScene.h"	// CGameScene

// �R���X�g���N�^CGameScene
CGameScene::CGameScene() : CScene(){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd)
CGameScene::CGameScene(const CWindow *pWnd) : CScene(pWnd){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime) : CScene(pWnd, pTime){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.

}

// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
CGameScene::CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem) : CScene(pWnd, pTime, pSystem){

	// �����o�̏�����.
#if 0
	m_pSharedObject1 = NULL;	// m_pSharedObject1��NULL���Z�b�g.
	m_pSharedObject2 = NULL;	// m_pSharedObject2��NULL���Z�b�g.
	m_pSharedObject3 = NULL;	// m_pSharedObject3��NULL���Z�b�g.
#endif
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.

}

// �f�X�g���N�^~CGameScene
CGameScene::~CGameScene(){

}

// �Q�[���I�u�W�F�N�g�̏�����.
int CGameScene::InitGameObjects(){

	// ���N���X�̏�����.
	int iRet = CScene::InitGameObjects();	// CScene::InitGameObjects�ŏ�����.

	// �V�F�A�[�h�C���[�W�o�b�t�@�̒ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED1);	// �ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED2);	// �ǉ�.
	m_pSharedImageBuffer->Add(IDB_SHARED3);	// �ǉ�.

	// �V�F�A�[�h�I�u�W�F�N�g�̐���.
#if 0
	m_pSharedObject1 = new CSharedObject(this);	// ����.
	m_pSharedObject1->Create(0 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject1->Create�Ő���.
	m_pSharedObject2 = new CSharedObject(this);	// ����.
	m_pSharedObject2->Create(1 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject2->Create�Ő���.
	m_pSharedObject3 = new CSharedObject(this);	// ����.
	m_pSharedObject3->Create(2 * 32, 0 * 32, 32, 32, IDB_SHARED1);	// m_pSharedObject3->Create�Ő���.
#endif
	m_pMap = new CMap(this);	// CMap�̃I�u�W�F�N�g����.
	m_pMap->Create(32, 32, 3, 3);	// Create�Ő���.

	// iRet.
	return iRet;	// iRet��Ԃ�.

}

// �L�[�{�[�h�̏�����.
int CGameScene::InitKeyboard(){

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̃`�F�b�N.
int CGameScene::CheckKeyboard(){

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
int CGameScene::RunProc(){

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̕`��.
int CGameScene::DrawGameObjects(){

	// �V�F�A�[�h�I�u�W�F�N�g�̕`��.
#if 0
	m_pSharedObject1->Draw(0 * 32, 0 * 32);	// m_pSharedObject1->Draw�ŕ`��.
	m_pSharedObject2->Draw(1 * 32, 0 * 32);	// m_pSharedObject2->Draw�ŕ`��.
	m_pSharedObject3->Draw(2 * 32, 0 * 32);	// m_pSharedObject3->Draw�ŕ`��.
#endif
	m_pMap->Draw();

	// ���N���X�̏���.
	return CScene::DrawGameObjects();	// CScene::DrawGameObjects���Ă�.

}

// �Q�[���I�u�W�F�N�g�̏I������.
int CGameScene::ExitGameObjects(){

	// �V�F�A�[�h�I�u�W�F�N�g�̔j��.
#if 0
	delete m_pSharedObject1;	// m_pSharedObject1��j��.
	delete m_pSharedObject2;	// m_pSharedObject2��j��.
	delete m_pSharedObject3;	// m_pSharedObject3��j��.
#endif
	m_pMap->Destroy();	// Destroy�Ŕj��.
	delete m_pMap;	// m_pMap���폜.
	m_pMap = NULL;	// m_pMap��NULL���Z�b�g.
	// ���N���X�̏���.
	return CScene::ExitGameObjects();	// CScene::ExitGameObjects�ŏI������.

}