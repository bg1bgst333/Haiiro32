// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"	// CMainWindow
#include "TitleScene.h"	// CTitleScene

// �C���X�^���X�������֐�InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �E�B���h�E�N���X�̓o�^.
	CMainWindow::RegisterClass(hInstance);	// CMainWindow::RegisterClass�ŃE�B���h�E�N���X"CMainWindow"��o�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWnd = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWnd�Ɋi�[.

	// �E�B���h�E�̍쐬.
	if (!m_pMainWnd->Create(_T("Haiiro"), WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Create�ŃE�B���h�E�쐬(�ő剻�ƃ��T�C�Y�𖳌���.)��, ���s�����ꍇ.

		// �G���[����
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindow�ŕ\��.

	// �e��InitInstance���Ă�.
	BOOL bRet = CGameApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CGameApplication::InitInstance���Ă�.

	// �ڕWFPS�l�̐ݒ�.
	if (m_pGameTime != NULL){	// m_pGameTime��NULL�łȂ����.
		m_pGameTime->SetTargetFPS(60);	// 60FPS��ڎw��.
	}

	// InitInstance�̖߂�l��Ԃ�.
	return bRet;	// bRet��Ԃ�.

}

// �Q�[�����C�������֐�Main.
int CMainApplication::Main(){

	// �ϐ��̏�����.
	int iRet = 0;	// iRet��0�ŏ�����.
	CScene *pScene = NULL;	// pScene��NULL�ŏ�����.

	// ����.
	if (m_iNo == 0 && m_pScene == NULL){	// m_iNo��0�Ő�������Ă��Ȃ���.
		pScene = new CTitleScene(m_pMainWnd, m_pGameTime);	// CTitleScene�𐶐���, pScene�Ɋi�[.(m_pMainWnd��m_pGameTime��n��.)
	}
	else if (m_iNo == 1 && m_pScene == NULL){	// m_iNo��1�Ő�������Ă��Ȃ���.
		pScene = new CScene(m_pMainWnd, m_pGameTime);	// CScene�𐶐���, pScene�Ɋi�[.(m_pMainWnd��m_pGameTime��n��.)
	}

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