// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Map.h"	// CMap
#include "BinaryResource.h"	// CBinaryResource
#include "resource.h"	// ���\�[�X.

// �R���X�g���N�^CMap
CMap::CMap() : CSharedObject(){

	// �����o�̏�����.
	m_iChipWidth = 0;	// m_iChipWidth��0���Z�b�g.
	m_iChipHeight = 0;	// m_iChipHeight��0���Z�b�g.
	m_iChipCountX;	// m_iChipCountX��0���Z�b�g.
	m_iChipCountY;	// m_iChipCountY��0���Z�b�g.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrix��NULL���Z�b�g.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_iCursorX = 0;	// m_iCursorX��0���Z�b�g.
	m_iCursorY = 0;	// m_iCursorY��0���Z�b�g.
	m_iPixelX = 0;	// m_iPixelX��0���Z�b�g.
	m_iPixelY = 0;	// m_iPixelY��0���Z�b�g.

}

// �R���X�g���N�^CMap(CScene *pScene)
CMap::CMap(CScene *pScene) : CSharedObject(pScene){

	// �����o�̏�����.
	m_iChipWidth = 0;	// m_iChipWidth��0���Z�b�g.
	m_iChipHeight = 0;	// m_iChipHeight��0���Z�b�g.
	m_iChipCountX;	// m_iChipCountX��0���Z�b�g.
	m_iChipCountY;	// m_iChipCountY��0���Z�b�g.
	m_ppMapDataMatrix = NULL;	// m_ppMapDataMatrix��NULL���Z�b�g.
	m_bDown = FALSE;	// m_bDown��FALSE���Z�b�g.
	m_bUp = FALSE;	// m_bUp��FALSE���Z�b�g.
	m_bRight = FALSE;	// m_bRight��FALSE���Z�b�g.
	m_bLeft = FALSE;	// m_bLeft��FALSE���Z�b�g.
	m_iCursorX = 0;	// m_iCursorX��0���Z�b�g.
	m_iCursorY = 0;	// m_iCursorY��0���Z�b�g.
	m_iPixelX = 0;	// m_iPixelX��0���Z�b�g.
	m_iPixelY = 0;	// m_iPixelY��0���Z�b�g.

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
	m_ppMapDataMatrix = new MapData * [m_iChipCountY + 2];	// (�c�����̗v�f�� + 2)��new����.
	for (int i = 0; i < m_iChipCountY + 2; i++){	// (�c�����̗v�f�� + 2)���J��Ԃ�.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX + 2];	// (�������̗v�f�� + 2)��new����.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * m_iChipCountX + 2);	// ZeroMemory�ŃN���A.
#if 0
		m_ppMapDataMatrix[i][0].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][0].m_iDestX = 0;	// 0
		m_ppMapDataMatrix[i][0].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][1].m_iDestX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][1].m_iSrcX = 1;	// 1
		m_ppMapDataMatrix[i][1].m_iSrcY = 0;	// 0
		m_ppMapDataMatrix[i][2].m_nID = IDB_SHARED1;	// shared1
		m_ppMapDataMatrix[i][2].m_iDestX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iDestY = i;	// i
		m_ppMapDataMatrix[i][2].m_iSrcX = 2;	// 2
		m_ppMapDataMatrix[i][2].m_iSrcY = 0;	// 0
#endif
	}

	// �}�b�v�z�u.
	for (int y = 1; y < m_iChipCountY + 1; y++){	// �c����.
		for (int x = 1; x < m_iChipCountX + 1; x++){	// ������.
			m_ppMapDataMatrix[y][x].m_nID = IDB_SHARED1;
			if (x <= 2){
				m_ppMapDataMatrix[y][x].m_iDestX = x - 1;
				m_ppMapDataMatrix[y][x].m_iDestY = y - 1;
				m_ppMapDataMatrix[y][x].m_iSrcX = y - 1;
				m_ppMapDataMatrix[y][x].m_iSrcY = 0;
				if (y >= 11){
					m_ppMapDataMatrix[y][x].m_iSrcX = y - 11;
					m_ppMapDataMatrix[y][x].m_iSrcY = 1;
				}
			}
			else{
				m_ppMapDataMatrix[y][x].m_iDestX = x - 1;
				m_ppMapDataMatrix[y][x].m_iDestY = y - 1;
				m_ppMapDataMatrix[y][x].m_iSrcX = 0;
				m_ppMapDataMatrix[y][x].m_iSrcY = 2;
			}
		}
	}

#if 1
#if 1
	// �}�b�v���G�N�X�|�[�g.
	ExportFile(_T("testmap1.bin"));	// ExportFile��"testmap1.bin"���G�N�X�|�[�g.
#else
	// �}�b�v���C���|�[�g.
	ImportFile(_T("testmap1.bin"));	// ImportFile��"testmap1.bin"���C���|�[�g.
#endif
#endif

	// �����Ȃ̂�0.
	return 0;	// 0��Ԃ�.

}

// �}�b�v�̔j��Destroy.
void CMap::Destroy(){
	
	// �}�b�v�z��̔j��.
	for (int i = 0; i < m_iChipCountY + 2; i++){	// (�c�����̗v�f�� + 2)���J��Ԃ�.
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
	for (int y = 0; y < 17/*m_iChipCountY*/; y++){	// �c����.
		for (int x = 0; x < 22/*m_iChipCountX*/; x++){	// ������.
			HDC hMemDC = m_pScene->m_pSharedImageBuffer->Get(m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_nID);	// �w���ID�̃o�b�t�@���擾.
			if (hMemDC == NULL){
				BitBlt(m_pScene->m_hMemDC, (x - 1) * m_iChipWidth + m_iPixelX, (y - 1) * m_iChipHeight + m_iPixelY, m_iChipWidth, m_iChipHeight, hMemDC, m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iSrcX * m_iChipWidth, m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iSrcY * m_iChipHeight, SRCCOPY);	// BitBlt�ŕ`��.
			}
			else{
				BitBlt(m_pScene->m_hMemDC, (m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iDestX - m_iCursorX) * m_iChipWidth + m_iPixelX, (m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iDestY - m_iCursorY) * m_iChipHeight + m_iPixelY, m_iChipWidth, m_iChipHeight, hMemDC, m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iSrcX * m_iChipWidth, m_ppMapDataMatrix[y + m_iCursorY][x + m_iCursorX].m_iSrcY * m_iChipHeight, SRCCOPY);	// BitBlt�ŕ`��.
			}
		}
	}

}

// �}�b�v�f�[�^���t�@�C���Ƃ��ăG�N�X�|�[�gExportFile.
BOOL CMap::ExportFile(LPCTSTR lpctszFileName){

	// �o�C�i���t�@�C���̍쐬.
#if 1
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�gpBinaryFile�̐���.
	pBinaryFile->Set((BYTE *)&m_iChipWidth, sizeof(int));	// �`�b�v��.
	pBinaryFile->Write(lpctszFileName);	// �w��̃t�@�C���ɏ�������.
	pBinaryFile->Set((BYTE *)&m_iChipHeight, sizeof(int));	// �`�b�v����.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_iChipCountX, sizeof(int));	// �`�b�v���v�f��.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_iChipCountY, sizeof(int));	// �`�b�v�c�v�f��.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	// �}�b�v�z��̕`��.
	for (int y = 1; y < m_iChipCountY + 1; y++){	// �c����.
		for (int x = 1; x < m_iChipCountX + 1; x++){	// ������.
			pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[y][x], sizeof(MapData));	// (x, y)�}�b�v�f�[�^.
			pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
		}
	}
#if 0
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[0][1], sizeof(MapData));	// (x, y) = (1, 0)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][0], sizeof(MapData));	// (x, y) = (0, 1)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
	pBinaryFile->Set((BYTE *)&m_ppMapDataMatrix[1][1], sizeof(MapData));	// (x, y) = (1, 1)�̃}�b�v�f�[�^.
	pBinaryFile->Write();	// ����J�����t�@�C���ɒǋL.
#endif
	delete pBinaryFile;	// pBinaryFile�̏I������.
#endif
	
	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �}�b�v�f�[�^���t�@�C���Ƃ��ăC���|�[�gImportFile.
BOOL CMap::ImportFile(LPCTSTR lpctszFileName){

#if 0
	// �o�C�i�����\�[�X����ǂݍ���.
	CBinaryResource *pBinaryResource = new CBinaryResource();
	pBinaryResource->Load(m_pScene->m_pMainWnd->m_hWnd, IDR_TESTMAP1, _T("BIN"));	// pBinaryResource->Load�Ń��[�h.
	m_iChipWidth = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	m_iChipHeight = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	m_iChipCountX = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	m_iChipCountY = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	// �}�b�v�z��쐬.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY + 2];	// (�c�����̗v�f�� + 2)��new����.
	for (int i = 0; i < m_iChipCountY + 2; i++){	// (�c�����̗v�f�� + 2)���J��Ԃ�.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX + 2];	// (�������̗v�f�� + 2)��new����.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * (m_iChipCountX + 2));	// ZeroMemory�ŃN���A.
	}
	// �}�b�v�z��Ƀo�C�i���̒l���Z�b�g.
	for (int y = 1; y < m_iChipCountY + 1; y++){	// �c����.
		for (int x = 1; x < m_iChipCountX + 1; x++){	// ������.
			CopyMemory(&m_ppMapDataMatrix[y][x], (MapData *)pBinaryResource->Get(sizeof(MapData)), sizeof(MapData));	// CopyMemory�Ńo�C�i���f�[�^���R�s�[.
		}
	}
	// �o�C�i�����\�[�X�I�u�W�F�N�g�̔j��.
	delete pBinaryResource;	// pBinaryResource�̏I������.
#else
	// �o�C�i���t�@�C������ǂݍ���.
	CBinaryFile *pBinaryFile = new CBinaryFile();
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipWidth = (int)*pBinaryFile->m_pBytes;	// �`�b�v�����擾.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipHeight = (int)*pBinaryFile->m_pBytes;	// �`�b�v�������擾.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipCountX = (int)*pBinaryFile->m_pBytes;	// �`�b�v���v�f�����擾.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipCountY = (int)*pBinaryFile->m_pBytes;	// �`�b�v�c�v�f�����擾.

	// �}�b�v�z��쐬.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY + 2];	// (�c�����̗v�f�� + 2)��new����.
	for (int i = 0; i < m_iChipCountY + 2; i++){	// (�c�����̗v�f�� + 2)���J��Ԃ�.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX + 2];	// (�������̗v�f�� + 2)��new����.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * (m_iChipCountX + 2));	// ZeroMemory�ŃN���A.
	}

	// �}�b�v�z��Ƀo�C�i���̒l���Z�b�g.
	for (int y = 1; y < m_iChipCountY + 1; y++){	// �c����.
		for (int x = 1; x < m_iChipCountX + 1; x++){	// ������.
			pBinaryFile->Read(sizeof(MapData));	// pBinaryFile->Read�œǂݍ���.
			CopyMemory(&m_ppMapDataMatrix[y][x], (MapData *)pBinaryFile->m_pBytes, sizeof(MapData));	// CopyMemory�Ńo�C�i���f�[�^���R�s�[.
		}
	}

	// �o�C�i���t�@�C���I�u�W�F�N�g�̔j��.
	delete pBinaryFile;	// pBinaryFile�̏I������.
#endif

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �}�b�v�f�[�^�����\�[�X�Ƃ��ăC���|�[�gImportResource.
BOOL CMap::ImportResource(int nID){

#if 1
	// �o�C�i�����\�[�X����ǂݍ���.
	CBinaryResource *pBinaryResource = new CBinaryResource();
	pBinaryResource->Load(m_pScene->m_pMainWnd->m_hWnd, nID, _T("BIN"));	// pBinaryResource->Load�Ń��[�h.
	m_iChipWidth = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	m_iChipHeight = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	m_iChipCountX = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	m_iChipCountY = (int)(*(BYTE *)pBinaryResource->Get(sizeof(int)));
	// �}�b�v�z��쐬.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY + 2];	// (�c�����̗v�f�� + 2)��new����.
	for (int i = 0; i < m_iChipCountY + 2; i++){	// (�c�����̗v�f�� + 2)���J��Ԃ�.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX + 2];	// (�������̗v�f�� + 2)��new����.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * (m_iChipCountX + 2));	// ZeroMemory�ŃN���A.
	}
	// �}�b�v�z��Ƀo�C�i���̒l���Z�b�g.
	for (int y = 1; y < m_iChipCountY + 1; y++){	// �c����.
		for (int x = 1; x < m_iChipCountX + 1; x++){	// ������.
			CopyMemory(&m_ppMapDataMatrix[y][x], (MapData *)pBinaryResource->Get(sizeof(MapData)), sizeof(MapData));	// CopyMemory�Ńo�C�i���f�[�^���R�s�[.
		}
	}
	// �o�C�i�����\�[�X�I�u�W�F�N�g�̔j��.
	delete pBinaryResource;	// pBinaryResource�̏I������.
#else
	// �o�C�i���t�@�C������ǂݍ���.
	CBinaryFile *pBinaryFile = new CBinaryFile();
	pBinaryFile->Read(lpctszFileName, 0, sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipWidth = (int)*pBinaryFile->m_pBytes;	// �`�b�v�����擾.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipHeight = (int)*pBinaryFile->m_pBytes;	// �`�b�v�������擾.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipCountX = (int)*pBinaryFile->m_pBytes;	// �`�b�v���v�f�����擾.
	pBinaryFile->Read(sizeof(int));	// pBinaryFile->Read�œǂݍ���.
	m_iChipCountY = (int)*pBinaryFile->m_pBytes;	// �`�b�v�c�v�f�����擾.

	// �}�b�v�z��쐬.
	m_ppMapDataMatrix = new MapData * [m_iChipCountY + 2];	// (�c�����̗v�f�� + 2)��new����.
	for (int i = 0; i < m_iChipCountY + 2; i++){	// (�c�����̗v�f�� + 2)���J��Ԃ�.
		m_ppMapDataMatrix[i] = new MapData[m_iChipCountX + 2];	// (�������̗v�f�� + 2)��new����.
		ZeroMemory(m_ppMapDataMatrix[i], sizeof(MapData) * (m_iChipCountX + 2));	// ZeroMemory�ŃN���A.
	}

	// �}�b�v�z��Ƀo�C�i���̒l���Z�b�g.
	for (int y = 1; y < m_iChipCountY + 1; y++){	// �c����.
		for (int x = 1; x < m_iChipCountX + 1; x++){	// ������.
			pBinaryFile->Read(sizeof(MapData));	// pBinaryFile->Read�œǂݍ���.
			CopyMemory(&m_ppMapDataMatrix[y][x], (MapData *)pBinaryFile->m_pBytes, sizeof(MapData));	// CopyMemory�Ńo�C�i���f�[�^���R�s�[.
		}
	}

	// �o�C�i���t�@�C���I�u�W�F�N�g�̔j��.
	delete pBinaryFile;	// pBinaryFile�̏I������.
#endif

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �}�b�v�̈ړ���Ԃ��N���A.
void CMap::Clear(){

	// �t���O���N���A.
	m_bDown = FALSE;	// m_bDown��FALSE�ɂ���.
	m_bUp = FALSE;	// m_bUp��FALSE�ɂ���.
	m_bRight = FALSE;	// m_bRight��FALSE�ɂ���.
	m_bLeft = FALSE;	// m_bLeft��FALSE�ɂ���.

}

// �}�b�v�̎��_�����Ɉړ�Down.(�}�b�v���̂͏�Ɉړ�.)
void CMap::Down(){

	// �����L��.
	m_bDown = TRUE;	// m_bDown��TRUE�ɂ���.

}

// �}�b�v�̎��_����Ɉړ�Up.(�}�b�v���͉̂��Ɉړ�.)
void CMap::Up(){

	// �オ�L��.
	m_bUp = TRUE;	// m_bUp��TRUE�ɂ���.

}

// �}�b�v�̎��_���E�Ɉړ�Right.(�}�b�v���͍̂��Ɉړ�.)
void CMap::Right(){

	// �E���L��.
	m_bRight = TRUE;	// m_bRight��TRUE�ɂ���.

}

// �}�b�v�̎��_�����Ɉړ�Ledt.(�}�b�v���͉̂E�Ɉړ�.)
void CMap::Left(){

	// �����L��.
	m_bLeft =TRUE;	// m_bLeft��TRUE�ɂ���.

}

// ����������Proc.
int CMap::Proc(){

	// ��.
	if (m_bDown){
		//m_iCursorY++;	// y��1���₷.
		if (!(m_iCursorY == m_iChipCountY - 15 && m_iPixelY <= 0)){
			m_iPixelY--;	// y��1���₷.
		}
	}

	// ��.
	if (m_bUp){
		//m_iCursorY--;	// y��1���炷.
		if (!(m_iCursorY == 0 && m_iPixelY >= 0)){
			m_iPixelY++;	// y��1���₷.
		}
	}

	// �E.
	if (m_bRight){
		//m_iCursorX++;	// x��1���₷.
		if (!(m_iCursorX == m_iChipCountX - 20 && m_iPixelX <= 0)){
			m_iPixelX--;	// y��1���₷.
		}
	}

	// ��.
	if (m_bLeft){
		//m_iCursorX--;	// x��1���炷.
		if (!(m_iCursorX == 0 && m_iPixelX >= 0)){
			m_iPixelX++;	// x��1���₷.
		}
	}

	// �s�N�Z���̏���.
	if (m_iPixelY <= (-1 * m_iChipHeight) + 1){
		m_iPixelY = 0;	// 0
		m_iCursorY++;	// 1������.
	}
	if (m_iPixelX <= (-1 * m_iChipWidth) + 1){
		m_iPixelX = 0;	// 0
		m_iCursorX++;	// 1������.
	}
	if (m_iPixelY >= m_iChipHeight){
		m_iPixelY = 0;	// 0
		m_iCursorY--;	// 1���炷.
	}
	if (m_iPixelX >= m_iChipWidth){
		m_iPixelX = 0;	// 0
		m_iCursorX--;	// 1���炷.
	}

	// �J�[�\���ŏ��l�ő�l�𒴂��Ȃ��悤�ɂ���.
	if (m_iCursorX < 0){	// 0����.
		m_iCursorX = 0;	// 0�ɂ���.
	}
	if (m_iCursorY < 0){	// 0����.
		m_iCursorY = 0;	// 0�ɂ���.
	}
	if (m_iCursorX > m_iChipCountX - 20){	// m_iChipCountX - 20�𒴂���.
		m_iCursorX = m_iChipCountX - 20;	// m_iChipCountX - 20�ɂ���.
	}
	if (m_iCursorY > m_iChipCountY - 15){	// m_iChipCountY - 15�𒴂���.
		m_iCursorY = m_iChipCountY - 15;	// m_iChipCountY - 15�ɂ���.
	}

	// �V�[���p���Ȃ�0.
	return 0;	// 0��Ԃ�.

}