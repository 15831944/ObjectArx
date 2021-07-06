//
#include "stdafx.h"

/**
 * @brief delete void*
 * ���void*ָ��Ķ��������л��ͷ�ĳЩ�ڴ棬delete void*�����ڴ�й©����Ϊ����ִ�ж�Ӧ����������
 */
class DelVoidStarTest
{
public:
	DelVoidStarTest() : data(new int[100]) { acutPrintf(L"\nDelVoidStarTest()"); }
	~DelVoidStarTest()
	{
		delete[] data;
		acutPrintf(L"\n~DelVoidStarTest()");
	}

private:
	int *data;
};

ARXCMD3(DelVoidStar_Test)
{
	acutPrintf(L"\nsizeof(int) = %d, sizeof(void*) = %d\nsizeof(int[100]) = %d, sizeof(DelVoidStarTest) = %d",
		sizeof(int), sizeof(void*), sizeof(int[100]), sizeof(DelVoidStarTest));

	DelVoidStarTest *p1 = new DelVoidStarTest;
	delete p1;
	p1 = nullptr;

	acutPrintf(L"\n------------------");

	void *p2 = new DelVoidStarTest;    
	delete p2;   // ֻ�ͷ���sizef(DelVoidStarTest)��С�Ķ��ڴ� ,�������������, ����sizeof(int)*100���ڴ�й©
	p2 = nullptr;
}
