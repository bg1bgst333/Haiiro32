// ��d�C���N���[�h�h�~
#ifndef __MAP_H__
#define __MAP_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MapData.h"	// �\����MapData
#include "SharedObject.h"	// CSharedObject

// �}�b�v�N���XCMap
class CMap : public CSharedObject{

	// public�����o
	public:

		// public�����o�ϐ�
		int m_iChipWidth;	// �`�b�v��.
		int m_iChipHeight;	// �`�b�v����.
		int m_iChipCountX;	// ���`�b�v��.
		int m_iChipCountY;	// �c�`�b�v��.
		MapData** m_ppMapDataMatrix;	// MapData2�����z��m_ppMapDataMatrix.
		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMap();	// �R���X�g���N�^CMap
		CMap(CScene *pScene);	// �R���X�g���N�^CMap(CScene *pScene)
		virtual ~CMap();	// �f�X�g���N�^~CMap
		// �����o�֐�
		virtual BOOL Create(int iChipWidth, int iChipHeight, int iChipCountX, int iChipCountY);	// �}�b�v�̍쐬Create.
		virtual void Destroy();	// �}�b�v�̔j��Destroy.
		virtual void Draw();	// �}�b�v�̕`��Draw.

};

#endif