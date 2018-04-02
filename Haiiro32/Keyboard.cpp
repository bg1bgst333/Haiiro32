// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Keyboard.h"	// CKeyoard

// �R���X�g���N�^CKeyboard()
CKeyboard::CKeyboard(){

	// �����o�̏�����.
	Clear();	// Clear�ŃN���A.

}

// �f�X�g���N�^~CKeyboard()
CKeyboard::~CKeyboard(){

	// �����o�̃N���A.
	Clear();	// Clear�ŃN���A.

}

// �L�[�̒ǉ�.
void CKeyboard::AddKey(int iKey){

	// �Ď�����L�[�̒ǉ�.
	m_veciKeyList.push_back(iKey);	// m_veciKeyList.push_back��iKey�̒ǉ�.

}

// �L�[�̃N���A.
void CKeyboard::Clear(){

	// �L�[���X�g�ƃL�[��Ԕz����N���A.
	m_veciKeyList.clear();	// m_veciKeyList.clear�ŃN���A.
	ZeroMemory(m_arybtKeys, sizeof(BYTE) * 256);	// ZeroMemory��m_arybtKeys���N���A.
	ZeroMemory(m_aryiPressKeys, sizeof(int) * 256);	// ZeroMemory��m_aryiPressKeys���N���A.

}

// �v�f���̎擾.
size_t CKeyboard::GetLength(){

	// �L�[���X�g�̒�����Ԃ�.
	return m_veciKeyList.size();	// m_veciKeyList.size�ŗv�f����Ԃ�.

}

// �L�[�{�[�h��Ԃ̃`�F�b�N.
BOOL CKeyboard::Check(){

	// �L�[��Ԃ̎擾.
	return GetKeyboardState(m_arybtKeys);	// GetKeyboardState�ŏ�Ԃ��擾��, �߂�l��Ԃ�.

}

// iNo�Ԗڂ�������Ă����Ԃ�Ԃ�.
BOOL CKeyboard::IsDown(int iNo){

	// ������Ă��邩���`�F�b�N.
	if (m_arybtKeys[m_veciKeyList[iNo]] & 0x80){	// ���݉�����Ă��邩�͍ŏ�ʃr�b�g(0x80)��AND���Z.
		if (m_aryiPressKeys[m_veciKeyList[iNo]] == 0){	// ������Ă��Ȃ�����.
			m_aryiPressKeys[m_veciKeyList[iNo]] = 1;	// ������Ă����Ԃɂ���.
		}
		else if (m_aryiPressKeys[m_veciKeyList[iNo]] >= 1){	// ���łɉ�����Ă�����.
			m_aryiPressKeys[m_veciKeyList[iNo]] = 2;	// �������ςȂ����.
		}
		return TRUE;	// TRUE��Ԃ�.
	}
	// ������Ă��Ȃ�.
	m_aryiPressKeys[m_veciKeyList[iNo]] = 0;	// ������Ă��Ȃ��Ƀ��Z�b�g.
	return FALSE;	// ������Ă��Ȃ��Ȃ�FALSE.

}

// iNo�Ԗڂ������ꂽ�u�Ԃ���Ԃ�.
BOOL CKeyboard::IsPress(int iNo){
	
	// �������u�Ԃ��ǂ������`�F�b�N.
	if (m_aryiPressKeys[m_veciKeyList[iNo]] == 1){	// �������u�Ԃ���.
		return TRUE;
	}
	return FALSE;	// �������u�ԂłȂ��Ȃ�FALSE.

}