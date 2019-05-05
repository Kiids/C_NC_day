#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//实现memmove
void * my_memmove(void * dest, const void * src, size_t n)
{
	assert(dest && src);
	//void* p1 = dest;
	//const void* p2 = src; 则之后p2 + n会报错 因为 不允许对一个指向未知尺寸类型（unknown size）的指针进行直接运算
	char* p1 = (char *)dest;
	const char* p2 = (const char *)src;
	if (p1 <= p2 && p1 >= p2 + n)  //正常情况下从前向后拷贝
	{
		while (n--)
		{
			*p1 = *p2;
		}
	}
	else  //当出现内存覆盖时从后向前拷贝
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

//memcpy和memmove（）都是C语言中的库函数，在头文件string.h中，作用是拷贝一定长度的内存的内容，原型分别如下：
//void *memcpy(void *dst, const void *src, size_t count);
//void *memmove(void *dst, const void *src, size_t count);
//他们的作用是一样的，唯一的区别是，当内存发生局部重叠的时候，memmove保证拷贝的结果是正确的，memcpy不保证拷贝的结果的正确。