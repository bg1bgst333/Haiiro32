// ��d�C���N���[�h�h�~
#ifndef __MAP_H__
#define __MAP_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MapData.h"	// �\����MapData
#include "SharedObject.h"	// CSharedObject
#include "BinaryFile.h"	// CBinaryFile

// �}�b�v�N���XCMap
class CMap : public CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		int m_iChipWidth;	// �`�b�v��.
		int m_iChipHeight;	// �`�b�v����.
		int m_iChipCountX;	// ���`�b�v��.
		int m_iChipCountY;	// �c�`�b�v��.
		int m_iCursorX;	// �`��J�n�ʒux.
		int m_iCursorY;	// �`��J�n�ʒuy.
		int m_iPixelX;	// �`��J�n�ʒu(�s�N�Z���P��)x.
		int m_iPixelY;	// �`��J�n�ʒu(�s�N�Z���P��)y.
		MapData** m_ppMapDataMatrix;	// MapData2�����z��m_ppMapDataMatrix.
		BOOL m_bDown;	// ����������Ă���t���Om_bDown.
		BOOL m_bUp;	// �オ������Ă���t���Om_bUp.
		BOOL m_bRight;	// �E��������Ă���t���Om_bRight.
		BOOL m_bLeft;	// ����������Ă���t���Om_bLeft.
		BOOL m_bLoop;	// ���[�v���ǂ����t���Om_bLoop.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMap();	// �R���X�g���N�^CMap
		CMap(CScene *pScene);	// �R���X�g���N�^CMap(CScene *pScene)
		virtual ~CMap();	// �f�X�g���N�^~CMap
		// �����o�֐�
		virtual BOOL Create(int iChipWidth, int iChipHeight, int iChipCountX, int iChipCountY);	// �}�b�v�̍쐬Create.
		virtual void Destroy();	// �}�b�v�̔j��Destroy.
		virtual void Draw();	// �}�b�v�̕`��Draw.
		virtual BOOL ExportFile(LPCTSTR lpctszFileName);	// �}�b�v�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFile.
		virtual BOOL ImportFile(LPCTSTR lpctszFileName);	// �}�b�v�f�[�^���t�@�C���Ƃ��ăC���|�[�gImportFile.
		virtual BOOL ImportResource(int nID);	// �}�b�v�f�[�^�����\�[�X�Ƃ��ăC���|�[�gImportResource.
		virtual void Clear();	// �}�b�v�̈ړ���Ԃ��N���A.
		virtual void Down();	// �}�b�v�̎��_�����Ɉړ�Down.(�}�b�v���̂͏�Ɉړ�.)
		virtual void Up();	// �}�b�v�̎��_����Ɉړ�Up.(�}�b�v���͉̂��Ɉړ�.)
		virtual void Right();	// �}�b�v�̎��_���E�Ɉړ�Right.(�}�b�v���͍̂��Ɉړ�.)
		virtual void Left();	// �}�b�v�̎��_�����Ɉړ�Ledt.(�}�b�v���͉̂E�Ɉړ�.))
		virtual int Proc();	// ����������Proc.

};

#endif