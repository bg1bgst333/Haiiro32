// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryResource.h"	// CBinaryResource

// �R���X�g���N�^CBinaryResource
CBinaryResource::CBinaryResource(){

	// �����o�̏�����
	m_pBytes = NULL;	// m_pBytes��NULL���Z�b�g.
	m_dwSize = 0;		// m_dwSize��0���Z�b�g.
	m_dwPos = 0;	// m_dwPos��0���Z�b�g.

}

// �f�X�g���N�^~CBinaryResource
CBinaryResource::~CBinaryResource(){

	// �����o�̏I������
	m_pBytes = NULL;	// m_pBytes��NULL���Z�b�g.
	m_dwSize = 0;	// m_dwSize��0���Z�b�g.
	m_dwPos = 0;	// m_dwPos��0���Z�b�g.

}

// �w��̃��\�[�X��ǂݍ���Load.
BOOL CBinaryResource::Load(HWND hWnd, int nID, LPCTSTR lpctszType){

	// �A�v���P�[�V�����C���X�^���X�̎擾.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// hInstance���擾.
	if (hInstance == NULL){
		return FALSE;
	}

	// ���\�[�X��T��.
	HRSRC hRes = FindResource(hInstance, MAKEINTRESOURCE(nID), lpctszType);	// hRes���擾.
	if (hRes == NULL){
		return FALSE;
	}

	// ���\�[�X�̃��[�h.
	HGLOBAL hGlobal = LoadResource(hInstance, hRes);	// hGlobal�̎擾.
	if (hGlobal == NULL){
		return FALSE;
	}

	// ���\�[�X�̃��b�N.
	m_pBytes = (BYTE *)LockResource(hGlobal);	// m_pBytes�Ƀ��\�[�X�|�C���^���i�[.
	if (m_pBytes == NULL){
		return FALSE;
	}

	// �T�C�Y���擾.
	m_dwSize = SizeofResource(hInstance, hRes);	// m_dwSize���擾.

	// �����Ȃ̂�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �w��̃T�C�Y�f�[�^�ւ̃|�C���^���擾Get.
const LPVOID CBinaryResource::Get(DWORD dwSize){

	// �|�C���^��Ԃ�.
	const LPVOID p = (const LPVOID)&m_pBytes[m_dwPos];
	m_dwPos = m_dwPos + dwSize;	// dwSize�ړ�.
	return p;	// p��Ԃ�.

}