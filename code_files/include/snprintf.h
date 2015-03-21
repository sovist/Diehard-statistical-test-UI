#include <windows.h>
#include <stdio.h>

#ifdef _MSC_VER

#define snprintf c99_snprintf_

int c99_vsnprintf_(char* str, size_t size, const char* format, va_list ap)
{
	int count = -1;

	if (size != 0)
		count = _vsnprintf_s(str, size, _TRUNCATE, format, ap);
	if (count == -1)
		count = _vscprintf(format, ap);

	return count;
}

int c99_snprintf_(char* str, size_t size, const char* format, ...)
{
	int count;
	va_list ap;

	va_start(ap, format);
	count = c99_vsnprintf_(str, size, format, ap);
	va_end(ap);

	return count;
}

#endif // _MSC_VER