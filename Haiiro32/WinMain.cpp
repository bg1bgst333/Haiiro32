// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ���b�Z�[�W�{�b�N�X��"Hello, Haiiro!"�̕\��.
	MessageBox(NULL, _T("Hello, Haiiro!"), _T("Haiiro"), MB_OK);	// MessageBox��"Hello, Haiiro!"�ƕ\��.

	// �v���O�����̏I��
	return 0;	// return��0��Ԃ��Đ���I��.

}