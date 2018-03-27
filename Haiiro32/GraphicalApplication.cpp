// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "GraphicalApplication.h"	// CGraphicalApplication

// �R���X�g���N�^CGraphicalApplication
CGraphicalApplication::CGraphicalApplication() : CApplication(){

}

// ���b�Z�[�W���[�v�����֐�Run.
int CGraphicalApplication::Run(){

	// �ϐ��̏�����.
	MSG msg = {0};	// MSG�^���b�Z�[�W�\����msg��{0}�ŏ�����.
	int lCount = 0;	// �E�B���h�E���b�Z�[�W�����Ȃ��������̉񐔂�ێ�����int�^�ϐ�lCount�̏����l��0�Ƃ���.

	// PeekMessage�ɂ�郁�C�����[�v.
	while (TRUE){	// ��ɐ^(TRUE)�Ȃ̂Ŗ������[�v.

		// �E�B���h�E���b�Z�[�W�����Ă��邩���m�F����.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)){	// PeekMessage�ŃE�B���h�E���b�Z�[�W�����Ă��邩���m�F��, �^�Ȃ痈�Ă���.(PM_NOREMOVE�Ȃ̂Ń��b�Z�[�W�L���[���炱�̃��b�Z�[�W���폜���Ȃ�.����GetMessage�����̃��b�Z�[�W����������.)

			// 0�Ƀ��Z�b�g.
			lCount = 0;	// lCount��0�Ƀ��Z�b�g.

			// ���Ă����炻�̃��b�Z�[�W���擾.
			if (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage��PeekMessage�Ŋm�F�������b�Z�[�W���擾.

				// �E�B���h�E���b�Z�[�W�̑��o
				TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
				DispatchMessage(&msg);	// DispatchMessage�Ŏ󂯎�������b�Z�[�W���E�B���h�E�v���V�[�W��(���̏ꍇ�͓Ǝ��ɒ�`����WindowProc)�ɑ��o.

			}
			else{	// ����I��(0), �܂��̓G���[�ɂ��ُ�I��(-1).

				// ���C�����[�v�𔲂���.
				break;	// break�Ń��C�����[�v�𔲂���.

			}

		}
		else{	// �U�Ȃ�E�B���h�E���b�Z�[�W�����Ă��Ȃ��Ƃ�.

			// �A�C�h������
			if (OnIdle(lCount)) {	// OnIdle��lCount��n����, ���̒��ŃA�C�h������������.
				lCount++;	// TRUE�ŕԂ��Ă��邽�т�lCount�𑝂₷.
			}

		}

	}

	// ExitInstance�̒l��Ԃ�.
	return ExitInstance();	// return��ExitInstance��Ԃ�.

}

// �I�������֐�ExitInstance.
int CGraphicalApplication::ExitInstance(){

	// ���C���E�B���h�E�̔j��
	if (m_pMainWnd != NULL){	// m_pMainWnd��NULL�łȂ���.

		// �j������.
		delete m_pMainWnd;	// delete��m_pMainWnd��j��.
		m_pMainWnd = NULL;	// m_pMainWnd��NULL���Z�b�g.

	}

	// ����͏��0��Ԃ�.
	return 0;	// return��0��Ԃ�.

}

// �A�C�h�������֐�OnIdle.
BOOL CGraphicalApplication::OnIdle(LONG lCount){

	// ��ʂ̍X�V.
	if (m_pMainWnd != NULL){	// m_pMainWnd��NULL�łȂ���.
		if (m_pMainWnd->m_hWnd != NULL){	// m_pMainWnd->m_hWnd��NULL�łȂ���.
			InvalidateRect(m_pMainWnd->m_hWnd, NULL, FALSE);	// InvalidateRect�ŉ�ʂ��X�V.
		}
	}

	// �Ƃ肠����TRUE.
	return TRUE;

}