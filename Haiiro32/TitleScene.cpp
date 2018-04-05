// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X
#include "TitleScene.h"	// CTitleScene

// �R���X�g���N�^CTitleScene
CTitleScene::CTitleScene() : CScene(){

	// �����o�̏�����.
	m_pBackground = NULL;	// m_pBackground��NULL�ŏ�����.
	m_pTitle = NULL;	// m_pTitle��NULL�ŏ�����.
	m_pSelectBox = NULL;	// m_pSelectBox��NULL�ŏ�����.

}

// �R���X�g���N�^TitleCScene(const CWindow *pWnd)
CTitleScene::CTitleScene(const CWindow *pWnd) : CScene(pWnd){

	// �����o�̏�����.
	m_pBackground = NULL;	// m_pBackground��NULL�ŏ�����.
	m_pTitle = NULL;	// m_pTitle��NULL�ŏ�����.
	m_pSelectBox = NULL;	// m_pSelectBox��NULL�ŏ�����.

}

// �f�X�g���N�^~CTitleScene
CTitleScene::~CTitleScene(){

}

// �Q�[���I�u�W�F�N�g�̏�����.
int CTitleScene::InitGameObjects(){

	// �w�i�̍쐬.
	m_pBackground = new CBackground(this);	// CBackground�I�u�W�F�N�g�𐶐�(this��n��.)��, �|�C���^��m_pBackground�Ɋi�[.
	m_pBackground->Create(0, 0, m_iScreenWidth, m_iScreenHeight, m_pMainWnd->m_hWnd, IDB_BACKGROUND1);	// m_pBackground->Create�Ŕw�i�I�u�W�F�N�g���쐬.

	// �^�C�g���̍쐬.
	m_pTitle = new CTitle(this);	// CTitle�I�u�W�F�N�g�𐶐�(this��n��.)��, �|�C���^��m_pTitle�Ɋi�[.
	m_pTitle->Create(160, 60, 320, 240, m_pMainWnd->m_hWnd, IDB_TITLE1);	// m_pTitle->Create�Ń^�C�g���I�u�W�F�N�g���쐬.

	// �Z���N�g�{�b�N�X�̍쐬.
	m_pSelectBox = new CSelectBox(this);	// CSelectBox�I�u�W�F�N�g�𐶐�(this��n��.), �|�C���^��m_pSelectBox�Ɋi�[.
	m_pSelectBox->Create(160, 300, 320, 120, m_pMainWnd->m_hWnd, IDB_SELECTBOX1);	// m_pSelectBox->Create�ŃZ���N�g�{�b�N�X�I�u�W�F�N�g���쐬.

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̏�����.
int CTitleScene::InitKeyboard(){

	// �L�[�{�[�h�I�u�W�F�N�g�̍쐬.
	m_pKeyboard = new CKeyboard();	// CKeyboard�I�u�W�F�N�g���쐬��, �|�C���^��m_pKeyboard�Ɋi�[.

	// �Ď��L�[�̒ǉ�.
	m_pKeyboard->AddKey(VK_ESCAPE);	// ESC�L�[��ǉ�.

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[�{�[�h�̃`�F�b�N.
int CTitleScene::CheckKeyboard(){

	// �L�[��Ԃ̎擾.
	m_pKeyboard->Check();	// m_pKeyboard->Check�ŏ�Ԋm�F.

	// 0�Ԗڂ̃L�[(�����ł�ESC�L�[.)�������ꂽ��.
	if (m_pKeyboard->IsPress(0)){	// m_pKeyboard->IsPress(0)��TRUE�Ȃ�.
		SendMessage(m_pMainWnd->m_hWnd, WM_CLOSE, 0, 0);	// SendMessage��WM_CLOSE�𑗐M.
	}

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
int CTitleScene::RunProc(){

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̕`��.
int CTitleScene::DrawGameObjects(){

	// �w�i�̕`��.
	if (m_pBackground != NULL){	// m_pBackground��NULL�łȂ���.
		m_pBackground->DrawRect(0, 0);	// m_pBackground->DrawRect��(0, 0)�̈ʒu�ɕ`��.
	}

	// �^�C�g���̕`��.
	if (m_pTitle != NULL){	// m_pTitle��NULL�łȂ���.
		m_pTitle->DrawRect(160, 60);	// m_pTitle->DrawRect��(160, 60)�̈ʒu�ɕ`��.
		m_pTitle->DrawText(160, 60, 320, 240, _T("Haiiro"), RGB(0xff, 0xff, 0xff));	// m_pTitle->DrawText�Ń^�C�g���e�L�X�g�̕`��.
	}

	// �Z���N�g�{�b�N�X�̕`��.
	if (m_pSelectBox != NULL){	// m_pSelectBox��NULL�łȂ���.
		m_pSelectBox->DrawRect(160, 300);	// m_pSelectBox->DrawRect��(160, 300)�̈ʒu�ɕ`��.
	}

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �Q�[���I�u�W�F�N�g�̏I������.
int CTitleScene::ExitGameObjects(){

	// �Z���N�g�{�b�N�X�̔j��.
	if (m_pSelectBox != NULL){	// m_pSelectBox��NULL�łȂ���.
		m_pSelectBox->Destroy();	// m_pSelectBox->Destroy�Ŕj��.
		delete m_pSelectBox;	// delete��m_pSelectBox�����.
		m_pSelectBox = NULL;	// m_pSelectBox��NULL���Z�b�g.
	}

	// �^�C�g���̔j��.
	if (m_pTitle != NULL){	// m_pTitle��NULL�łȂ���.
		m_pTitle->Destroy();	// m_pTitle->Destroy�Ŕj��.
		delete m_pTitle;	// delete��m_pTitle�����.
		m_pTitle = NULL;	// m_pTitle��NULL���Z�b�g.
	}

	// �w�i�̔j��.
	if (m_pBackground != NULL){	// m_pBackground��NULL�łȂ���.
		m_pBackground->Destroy();	// m_pBackground->Destroy�Ŕj��.
		delete m_pBackground;	// delete��m_pBackground�����.
		m_pBackground = NULL;	// m_pBackground��NULl���Z�b�g.
	}

	// ��ɐ����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}