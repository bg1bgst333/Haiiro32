// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameApplication.h"	// CGameApplication

// �R���X�g���N�^CGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// �����o�̏�����.
	m_pScene = NULL;	// m_pScene��NULL�ŏ�����.
	m_iNo = 0;	// m_iNo��0�ŏ�����.

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

	if (m_pScene == NULL){	// m_pScene��NULL�̎�.	
		m_pScene = pScene;	// pScene���i�[.
		iRet = m_pScene->InitScene();	// �����Ȃ�0��Ԃ�.
		if (iRet == -1){	// -1�̎�.
			m_pScene->ExitScene();	// �I������.
			delete m_pScene;	// m_pScene���폜.
			m_pScene = NULL;	// NULL���Z�b�g.
			m_iNo = -1;	// m_iNo��-1�ɂ��邱�ƂŏI����������(�����V�[���؂�ւ����Ȃ�����)������.
			SendMessage(m_pMainWnd->m_hWnd, WM_DESTROY, 0, 0);	// WM_DESTROY�𑗐M���ďI��.
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
				SendMessage(m_pMainWnd->m_hWnd, WM_DESTROY, 0, 0);	// WM_DESTROY�𑗐M���ďI��.
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
			SendMessage(m_pMainWnd->m_hWnd, WM_DESTROY, 0, 0);	// WM_DESTROY�𑗐M���ďI��.
		}
	}

	// ���������̂�0.
	return 0;	// 0��Ԃ�.

}