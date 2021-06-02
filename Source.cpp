#include "MyForm.h"
using namespace L3;
[STAThreadAttribute]
int main()
{
	MyForm mf;
	mf.ShowDialog();
	return 0;
}