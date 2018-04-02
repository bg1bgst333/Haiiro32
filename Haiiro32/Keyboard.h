// ��d�C���N���[�h�h�~
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI
#include <vector>	// std::vector

// �L�[�{�[�h�N���XCKeyboard
class CKeyboard{

	// public�����o
	public:

		// public�����o�ϐ�
		std::vector<int> m_veciKeyList;	// �L�[���X�gm_veciKeyList.
		BYTE m_arybtKeys[256];	// �L�[��Ԕz��m_arybtKeys.
		int m_aryiPressKeys[256];	// �L�[���������ςȂ����m_aryiPressKeys.
		size_t uiLen;	// �v�f��uiLen.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CKeyboard();	// �R���X�g���N�^CKyeboard()
		virtual ~CKeyboard();	// �f�X�g���N�^~CKeyboard()
		// �����o�֐�
		virtual void AddKey(int iKey);	// �L�[�̒ǉ�.
		virtual void Clear();	// �L�[�̃N���A.
		virtual size_t GetLength();	// �v�f���̎擾.
		virtual BOOL Check();	// �L�[�{�[�h��Ԃ̃`�F�b�N.
		virtual BOOL IsDown(int iNo);	// iNo�Ԗڂ�������Ă����Ԃ�Ԃ�.
		virtual BOOL IsPress(int iNo);	// iNo�Ԗڂ������ꂽ�u�Ԃ���Ԃ�.

};

#endif