// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameApplication.h"	// CGameApplication

// �R���X�g���N�^CGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// �����o�̏�����.
	m_pScene = NULL;	// m_pScene��NULL�ŏ�����.
	m_pGameTime = NULL;	// m_pGameTime��NULL�ŏ�����.
	m_pGameSystem = NULL;	// m_pGameSystem��NULL�ŏ�����.
	m_iNo = 0;	// m_iNo��0�ŏ�����.

}

// �C���X�^���X�������֐�InitInstance.
BOOL CGameApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �Q�[���V�X�e���̍쐬.
	m_pGameSystem = new CGameSystem();	// CGameSystem�I�u�W�F�N�g�̍쐬��.
	m_pGameSystem->Init(hInstance);	// Init�ŏ�����.

	// �Q�[���^�C���̍쐬.
	m_pGameTime = new CGameTime();	// CGameTime�I�u�W�F�N�g�̍쐬.

	// TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �I�������֐�ExitInstance.
int CGameApplication::ExitInstance(){

	// �Q�[���^�C���̔j��.
	if (m_pGameTime != NULL){	// m_pGameTime��NULL�łȂ����.
		delete m_pGameTime;	// delete��m_pGameTime���폜.
		m_pGameTime = NULL;	// m_pGameTime��NULL���Z�b�g.
	}

	// �Q�[���V�X�e���̔j��.
	if (m_pGameSystem != NULL){	// m_pGameSystem��NULL�łȂ����.
		m_pGameSystem->Exit();	// Exit�ŏI������.
		delete m_pGameSystem;	// delete��m_pGameSystem���폜.
		m_pGameSystem = NULL;	// m_pGameSystem��NULL���Z�b�g.
	}

	// �e��ExitInstance���Ă�.
	return CGraphicalApplication::ExitInstance();	// �߂�l�͐e�̖߂�l.

}

// �Q�[�����C�������֐�Main.
int CGameApplication::Main(){

	// �ϐ��̏�����.
	int iRet = 0;	// iRet��0�ŏ�����.
	CScene *pScene = NULL;	// pScene��NULL�ŏ�����.

	// ����.
	if (m_iNo == 0 && m_pScene == NULL){	// m_iNo��0�Ő�������Ă��Ȃ���.
		pScene = new CScene(m_pMainWnd);	// CScene�𐶐���, pScene�Ɋi�[.(m_pMainWnd��n��.)
	}
	else if (m_iNo == 1 && m_pScene == NULL){	// m_iNo��1�Ő�������Ă��Ȃ���.
		pScene = new CScene(m_pMainWnd);	// CScene�𐶐���, pScene�Ɋi�[.(m_pMainWnd��n��.)
	}
	else if (m_iNo == 2 && m_pScene == NULL){	// m_iNo��2�Ő�������Ă��Ȃ���.
		pScene = new CScene(m_pMainWnd);	// CScene�𐶐���, pScene�Ɋi�[.(m_pMainWnd��n��.)
	}

	// ����.
	if (m_pScene == NULL){	// m_pScene��NULL�̎�.	
		m_pScene = pScene;	// pScene���i�[.
		if (pScene == NULL){	// pScene��NULL�Ȃ�.
			// InitScene���ĂׂȂ��̂ŏI��.
			return 0;	// 0��Ԃ�.
		}
		iRet = m_pScene->InitScene();	// �����Ȃ�0��Ԃ�.
		if (iRet == -1){	// -1�̎�.
			m_pScene->ExitScene();	// �I������.
			delete m_pScene;	// m_pScene���폜.
			m_pScene = NULL;	// NULL���Z�b�g.
			m_iNo = -1;	// m_iNo��-1�ɂ��邱�ƂŏI����������(�����V�[���؂�ւ����Ȃ�����)������.
			m_pMainWnd->Destroy();	// m_pMainWnd->Destroy�ŃE�B���h�E�����.
		}
		else{	// 0�̎�.
			iRet = m_pScene->RunScene();	// ������.
			if (iRet == 1){	// 1�Ȃ玟�̃V�[����.
				m_pScene->ExitScene();	// �I������.
				delete m_pScene;	// m_pScene���폜.
				m_pScene = NULL;	// NULL���Z�b�g.
				m_iNo++;	// m_iNo���C���N�������g.
			}
			else if (iRet == 2){	// 2�Ȃ�I��.
				m_pScene->ExitScene();	// �I������.
				delete m_pScene;	// m_pScene���폜.
				m_pScene = NULL;	// NULL���Z�b�g.
				m_iNo = -1;	// m_iNo��-1�ɂ��邱�ƂŏI����������(�����V�[���؂�ւ����Ȃ�����)������.
				m_pMainWnd->Destroy();	// m_pMainWnd->Destroy�ŃE�B���h�E�����.
			}
		}
	}
	else{	// m_pScene��NULL�łȂ���.
		iRet = m_pScene->RunScene();	// ������.
		if (iRet == 1){	// 1�Ȃ玟�̃V�[����.
			m_pScene->ExitScene();	// �I������.
			delete m_pScene;	// m_pScene���폜.
			m_pScene = NULL;	// NULL���Z�b�g.
			m_iNo++;	// m_iNo���C���N�������g.
		}
		else if (iRet == 2){	// 2�Ȃ�I��.
			m_pScene->ExitScene();	// �I������.
			delete m_pScene;	// m_pScene���폜.
			m_pScene = NULL;	// NULL���Z�b�g.
			m_iNo = -1;	// m_iNo��-1�ɂ��邱�ƂŏI����������(�����V�[���؂�ւ����Ȃ�����)������.
			m_pMainWnd->Destroy();	// m_pMainWnd->Destroy�ŃE�B���h�E�����.
		}
	}

	// ���������̂�0.
	return 0;	// 0��Ԃ�.

}