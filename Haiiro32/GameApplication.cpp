// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GameApplication.h"	// CGameApplication

// �R���X�g���N�^CGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// �����o�̏�����.
	m_iSceneNo = 0;	// m_iSceneNo��0�ŏ�����.
	m_iSceneStatus = 0;	// m_iSceneStatus��0�ŏ�����.

}

// �Q�[�����C�������֐�Main.
int CGameApplication::Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �ϐ��̏�����.
	int iRet = 0;	// �߂�liRet��0�ŏ�����.

	// �V�[�����ƂɐU�蕪��..
	if (m_iSceneStatus == 0){	// m_iSceneStatus��0�Ȃ�V�[��������.
		iRet = InitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// InitScene�ŏ���������.
	}
	else if (m_iSceneStatus == 1){	// m_iSceneStatus��1�Ȃ�V�[��������.
		iRet = RunScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// RunScene�ŏ�����.
	}
	else if (m_iSceneStatus == 2){	// m_iSceneStatus��2�Ȃ�V�[���I������.
		iRet = ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitScene�ŏI������.
	}
	else{	// ����ȊO�͉��������I��.
		// 0��Ԃ�.
		return 0;	// 0��Ԃ�.
	}

	// ���̏�Ԃ����߂�.
	if (iRet == 1){	// iRet��1�Ȃ�.(���̃V�[���ւ̐؂�ւ�.)
		if (m_iSceneStatus <= 1){	// Init�܂���Run�̏ꍇ.
			m_iSceneStatus++;	// m_iSceneStatus��1���₷.
		}
		else{	// Exit�̎�.
			m_iSceneNo++;	// m_iSceneNo��1���₷.
			m_iSceneStatus = 0;	// m_iSceneStatus��0�ɂ���.
		}
	}
	else if (iRet == 2){	// iRet��2�Ȃ�.(�A�v���̏I��.)
		if (m_iSceneStatus <= 1){	// Init�܂���Run�̏ꍇ.
			ExitScene(hWnd, iClientAreaWidth, iClientAreaHeight);	// ExitScene�ŏI������.
		}
		m_iSceneStatus = -1;	// m_iSceneStatus��-1�Ȃ玟�ȍ~�������Ȃ�.
		SendMessage(hWnd, WM_DESTROY, 0, 0);	// SendMessage��WM_DESTROY�𑗐M.
	}

	// 0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// �V�[���̏�����InitScene.
int CGameApplication::InitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �������I���Ȃ̂�1.
	return 1;	// 1��Ԃ�.

}

// �V�[���̏�����RunScene.
int CGameApplication::RunScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// ESC�L�[���������甲����.
	if (GetAsyncKeyState(VK_ESCAPE)){	// GetAsyncKeyState��ESC��������Ă�����.
		MessageBox(NULL, _T("ESC"), _T("Haiiro"), MB_OK);	// MessageBox��"ESC"�ƕ\��.(����������, 2��ȏ㕪�ɂȂ��Ă��܂�.)
		return 1;	// 1��Ԃ�.
	}

	// �����������Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �V�[���̏I������ExitScene.
int CGameApplication::ExitScene(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// m_iSceneNo��3�Ȃ�I��.
	if (m_iSceneNo == 3){	// m_iSceneNo��3�̎�.
		// �A�v���I���Ȃ̂�2��Ԃ�.
		return 2;	// 2��Ԃ�.
	}

	// �I�������Ȃ̂�1.
	return 1;	// 1��Ԃ�.

}