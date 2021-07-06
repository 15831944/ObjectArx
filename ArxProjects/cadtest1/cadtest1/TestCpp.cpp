//
#include "stdafx.h"

/**
 * @brief delete void*
 * 如果void*指向的对象析构中会释放某些内存，delete void*会有内存泄漏，因为不会执行对应的析构函数
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
	delete p2;   // 只释放了sizef(DelVoidStarTest)大小的堆内存 ,不会进析构函数, 会有sizeof(int)*100的内存泄漏
	p2 = nullptr;
}
