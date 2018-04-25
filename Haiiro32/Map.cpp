// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Map.h"	// CMap
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CMap
CMap::CMap() : CSharedObject(){

	// �����o�̏�����.
	m_iChipWidth = 0;	// m_iChipWidth��0���Z�b�g.
	m_iChipHeight = 0;	// m_iChipHeight��0���Z�b�g.
	m_iChipCountX;	// m_iChipCountX��0���Z�b�g.
	m_iChipCountY;	// m_iChipCountY��0���Z�b�g.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrix��NULL���Z�b�g.

}

// �R���X�g���N�^CMap(CScene *pScene)
CMap::CMap(CScene *pScene) : CSharedObject(pScene){

	// �����o�̏�����.
	m_iChipWidth = 0;	// m_iChipWidth��0���Z�b�g.
	m_iChipHeight = 0;	// m_iChipHeight��0���Z�b�g.
	m_iChipCountX;	// m_iChipCountX��0���Z�b�g.
	m_iChipCountY;	// m_iChipCountY��0���Z�b�g.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrix��NULL���Z�b�g.

}

// �f�X�g���N�^~CMap
CMap::~CMap(){

}

// �}�b�v�̍쐬Create.
BOOL CMap::Create(int iChipWidth, int iChipHeight, int iChipCountX, int iChipCountY){

	// �����o�̃Z�b�g.
	m_iChipWidth = iChipWidth;	// m_iChipWidth��iChipWidth���Z�b�g.
	m_iChipHeight = iChipHeight;	// m_iChipHeight��iChipHeight���Z�b�g.
	m_iChipCountX = iChipCountX;	// m_iChipCountX��iChipCountX���Z�b�g.
	m_iChipCountY = iChipCountY;	// m_iChipCountY��iChipCountY���Z�b�g.

	// �}�b�v�z��쐬.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY];	// �c�����̗v�f��new����.
	for (int i = 0; i < m_iChipCountY; i++){	// �c�����̗v�f���J��Ԃ�.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX];	// �������̗v�f��new����.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * m_iChipCountX);	// ZeroMemory�ŃN���A.
#if 1
		m_ppMapDataMatrix[i][0].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][0].m_iDestX = 0;	// 0
		m_ppMapDataMatrix[i][0].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][1].m_iDestX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_iSrcX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iSrcY = 0;	// 0
		/*
		m_ppMapDataMatrix[i][2].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][2].m_iDestX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][2].m_iSrcX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iSrcY = 0;	// 0
		*/
#endif
	}

	// �}�b�v���G�N�X�|�[�g.
	ExportFile(_T("testmap1.bin"));	// ExportFile��"testmap1.bin"���G�N�X�|�[�g.

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �}�b�v�̔j��Destroy.
void CMap::Destroy(){
	
	// �}�b�v�z��̔j��.
	for (int i = 0; i < m_iChipCountY; i++){	// �c�����̗v�f���J��Ԃ�.
		delete [] m_ppMapDataMatrix[i];	// m_ppMapDataMatrix[i]�����.
		m_ppMapDataMatrix[i] = NULL;	// m_ppMapDataMatrix[i]��NULL���Z�b�g.
	}
	delete [] m_ppMapDataMatrix;	// m_ppMapDataMatrix�����.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrix��NULL���Z�b�g.

	// �����o�̃��Z�b�g.
	m_iChipWidth = 0;	// m_iChipWidth��0���Z�b�g.
	m_iChipHeight = 0;	// m_iChipHeight��0���Z�b�g.
	m_iChipCountX;	// m_iChipCountX��0���Z�b�g.
	m_iChipCountY;	// m_iChipCountY��0���Z�b�g.

}

// �}�b�v�̕`��Draw.
void CMap::Draw(){

	// �}�b�v�z��̕`��.
	for (int y = 0; y < m_iChipCountY; y++){	// �c����.
		for (int x = 0; x < m_iChipCountX; x++){	// ������.
			HDC hMemDC = m_pScene->m_pSharedImageBuffer->Get(m_ppMapDataMatrix[y][x].m_nID);	// �w���ID�̃o�b�t�@���擾.
			BitBlt(m_pScene->m_hMemDC, m_ppMapDataMatrix[y][x].m_iDestX * m_iChipWidth, m_ppMapDataMatrix[y][x].m_iDestY * m_iChipHeight, m_iChipWidth, m_iChipHeight, hMemDC, m_ppMapDataMatrix[y][x].m_iSrcX * m_iChipWidth, m_ppMapDataMatrix[y][x].m_iSrcY * m_iChipHeight, SRCCOPY);	// BitBlt�ŕ`��.
		}
	}

}

// �}�b�v�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFile.
BOOL CMap::ExportFile(LPCTSTR lpctszFileName){

	// �o�C�i���t�@�C���̍쐬.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�gpBinaryFile�̐���.
	pBinaryFile->Set((BYTE *)&m_iChipWidth, sizeof(int));	// �`�b�v��.
	pBinaryFile->Write(lpctszFileName);	// �w��̃t�@�C���ɏ�������.
	pBinaryFile->Set((BYTE *)&m_iChipHeight, sizeof(int));	// �`�b�v����.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_iChipCountX, sizeof(int));	// �`�b�v���v�f��.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_iChipCountY, sizeof(int));	// �`�b�v�c�v�f��.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[0][0], sizeof(MapData));	// (x, y) = (0, 0)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[0][1], sizeof(MapData));	// (x, y) = (1, 0)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][0], sizeof(MapData));	// (x, y) = (0, 1)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][1], sizeof(MapData));	// (x, y) = (1, 1)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	delete pBinaryFile;	// pBinaryFile�̏I������.

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}