#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ʵ��memmove
void * my_memmove(void * dest, const void * src, size_t n)
{
	assert(dest && src);
	//void* p1 = dest;
	//const void* p2 = src; ��֮��p2 + n�ᱨ�� ��Ϊ �������һ��ָ��δ֪�ߴ����ͣ�unknown size����ָ�����ֱ������
	char* p1 = (char *)dest;
	const char* p2 = (const char *)src;
	if (p1 <= p2 && p1 >= p2 + n)  //��������´�ǰ��󿽱�
	{
		while (n--)
		{
			*p1 = *p2;
		}
	}
	else  //�������ڴ渲��ʱ�Ӻ���ǰ����
	{
		while (n--)
		{
			*(p1 + n) = *(p2 + n);
		}
	}
	return dest;
}
int main()
{
	char str1[] = "abcdefg";
	char str2[] = "hijklmn";
	my_memmove(str1, str2, strlen(str1) + 1);
	printf("%s\n", str1);
	system("pause");
	return 0;
}

#endif

//memcpy��memmove��������C�����еĿ⺯������ͷ�ļ�string.h�У������ǿ���һ�����ȵ��ڴ�����ݣ�ԭ�ͷֱ����£�
//void *memcpy(void *dst, const void *src, size_t count);
//void *memmove(void *dst, const void *src, size_t count);
//���ǵ�������һ���ģ�Ψһ�������ǣ����ڴ淢���ֲ��ص���ʱ��memmove��֤�����Ľ������ȷ�ģ�memcpy����֤�����Ľ������ȷ��