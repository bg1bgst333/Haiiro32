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
			Main(m_pMainWnd->m_hWnd, m_pMainWnd->m_iClientAreaWidth, m_pMainWnd->m_iClientAreaHeight);	// �E�B���h�E�����݂���Ԃ�Main�����s.(m_pMainWnd->m_hWnd, m_pMainWnd->m_iClientAreaWidth, m_pMainWnd->m_iClientAreaHeight��n��.)
		}
	}

	// �Ƃ肠����TRUE.
	return TRUE;

}

// �O���t�B�J�����C�������֐�Main.
int CGraphicalApplication::Main(HWND hWnd, int iClientAreaWidth, int iClientAreaHeight){

	// �\������J�E���g�̏�����.
	static int iCount = 0;	// static�ϐ�iCount��0�ŏ�����.
	TCHAR tszCount[32] = {0};	// TCHAR�^�z��(�v�f��32)��{0}�ŏ�����.

	// �f�o�C�X�R���e�L�X�g�̎擾.
	HDC hDC = GetDC(hWnd);	// GetDC��hWnd����hDC���擾.

	// �y���ƃu���V�̐���.
	HPEN hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0xff, 0));	// CreatePen�ŗ�(�W)�̃y�����쐬.
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0x7f, 0));		// CreateSolidBrush�ŗ�(�Z)�̃u���V���쐬.

	// �y���ƃu���V�̑I��.
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);		// �΂̃y����I��.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);	// �΂̃u���V��I��.

	// ��`�`��.
	Rectangle(hDC, 0, 0, iClientAreaWidth, iClientAreaHeight);	// Rectangle�ŋ�`��`��.

	// �e�L�X�g�̕\��.
	_stprintf(tszCount, _T("%d"), iCount);	// _stprintf�Ő����liCount�𕶎���tszCount�ɕϊ�.
	SetBkMode(hDC, TRANSPARENT);	// SetBkMode��TRANSPARENT(����)�ɂ���.
	TextOut(hDC, 50, 50, tszCount, _tcslen(tszCount));	// TextOut��tszCount���o��.
	iCount++;	// iCount���C���N�������g.
	if (iCount >= 10000){	// iCount��10000�ȏ�Ȃ�.
		iCount = 0;	// iCount��0�Ƀ��Z�b�g.
	}

	// �y���ƃu���V�̕���
	SelectObject(hDC, hOldBrush);		// �Â��u���V��I��.
	SelectObject(hDC, hOldPen);		// �Â��y����I��.

	// �y���ƃu���V�̔j��.
	DeleteObject(hBrush);	// �u���V�̔j��.
	DeleteObject(hPen);	// �y���̔j��.

	// �f�o�C�X�R���e�L�X�g�̉��.
	ReleaseDC(hWnd, hDC);	// ReleaseDC��hDC�����.

	// 0��Ԃ�.
	return 0;	// 0��Ԃ�.

}