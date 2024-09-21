#include <config/ConfigDI/ConfigDI.h>

int main(int, char **)
{
	config::ConfigDI::Instance().Init();
	return 0;
}
