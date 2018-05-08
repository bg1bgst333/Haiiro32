// ��d�C���N���[�h�h�~
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene
#include "Map.h"	// CMap
//#include "Character.h"	// CCharacter
#include "Player.h"	// CPlayer
#include "GameTimeBox.h"	// CGameTimeBox

// �O���錾.
class CScene;	// CScene.
class CMap;	// CMap.
//class CCharacter;	// CCharacter.
class CPlayer;	// CPlayer.

// �Q�[���V�[���N���XCGameScene
class CGameScene : public CScene{

	// public�����o
	public:

		// public�����o�ϐ�
#if 0
		CSharedObject *m_pSharedObject1;	// CSharedObject�I�u�W�F�N�g�|�C���^m_pSharedObject1.
		CSharedObject *m_pSharedObject2;	// CSharedObject�I�u�W�F�N�g�|�C���^m_pSharedObject2.
		CSharedObject *m_pSharedObject3;	// CSharedObject�I�u�W�F�N�g�|�C���^m_pSharedObject3.
#endif
		CMap *m_pMap;	// CMap�I�u�W�F�N�g�|�C���^m_pMap.
		//CCharacter *m_pCharacter;	// CCharacter�I�u�W�F�N�g�|�C���^m_pCharacter.
		CPlayer *m_pPlayer;	// �v���C���[m_pPlayer.
		CGameTimeBox *m_pGameTimeBox;	// �Q�[���^�C���{�b�N�Xm_pGameTimeBox.
		
		// �R���X�g���N�^�E�f�X�g���N�^
		CGameScene();	// �R���X�g���N�^CGameScene
		CGameScene(const CWindow *pWnd);	// �R���X�g���N�^CGameScene(const CWindow *pWnd)
		CGameScene(const CWindow *pWnd, CGameTime *pTime);	// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime)
		CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CGameScene();	// �f�X�g���N�^~CGameScene
		virtual int InitGameObjects();	// �Q�[���I�u�W�F�N�g�̏�����.
		virtual int InitKeyboard();	// �L�[�{�[�h�̏�����.
		virtual int CheckKeyboard();	// �L�[�{�[�h�̃`�F�b�N.
		virtual int RunProc();	// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
		virtual int DrawGameObjects();	// �Q�[���I�u�W�F�N�g�̕`��.
		virtual int ExitGameObjects();	// �Q�[���I�u�W�F�N�g�̏I������.

};

#endif