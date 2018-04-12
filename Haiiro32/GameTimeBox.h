// ��d�C���N���[�h�h�~
#ifndef __GAME_TIME_BOX_H__
#define __GAME_TIME_BOX_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string

// �Ǝ��̃w�b�_
#include "GameObject.h"	// CGameObject

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �Q�[���^�C���{�b�N�X�N���XCGameTimeBox
class CGameTimeBox : public CGameObject{

	// public�����o
	public:

		// public�����o�ϐ�
		HFONT m_hFont;	// �t�H���gm_hFont.
		HFONT m_hOldFont;	// �ȑO�̃t�H���gm_hOldFont.
		DWORD m_dwTime;	// ����(�~���b)m_dwTime.
		DWORD m_dwFPS;	// FPS�lm_dwFPS.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CGameTimeBox();	// �R���X�g���N�^CGameTimeBox
		CGameTimeBox(const CScene *pScene);	// �R���X�g���N�^CGameTimeBox(const CScene *pScene)
		virtual ~CGameTimeBox();	// �f�X�g���N�^~CGameTimeBox
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, int nFontSize, LPCTSTR lpctszFontName);	// �Q�[���I�u�W�F�N�g�̍쐬Create.
		virtual void Destroy();	// �Q�[���I�u�W�F�N�g�̔j��Destroy.
		virtual int Proc();	// ����������Proc.
		virtual void DrawText(int x, int y, int iWidth, int iHeight, LPCTSTR lpctszText, COLORREF clrColor);	// DrawText�Ńe�L�X�g��`��.
		virtual void DrawTime(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawTime�Ŏ��Ԃ�`��.
		virtual void DrawFPS(int x, int y, int iWidth, int iHeight, COLORREF clrColor);	// DrawFPS�Ŏ��Ԃ�`��.

};

#endif