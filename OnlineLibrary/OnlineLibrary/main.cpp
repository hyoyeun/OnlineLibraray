#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:6031)

int GetBookNameLength(char *bookName) // 문자열 처럼 쓰고 있다.
{
	char* startPtr = bookName;
	int len = 0;
	while (true)
	{
		if (startPtr == NULL)
			break;

		startPtr++;
		len++;
	}
	return len;
}

int main()
{
	printf(">> 온라인 도서관 <<\n\n");
	char* bookNameArr[100];
	int bookIndex = 0;
	while (true)
	{
		int number = 0;
		printf("\n1번 -> 책이름 입력 \n2번 -> 입력한 책 찾기 \n3번 -> 책 목록 모두 확인\n번호를 입력하세요 : ");
		scanf("%d", &number);
		if (number == 1)
		{
			char bookName[20];
			printf("\n>> 책 이름을 입력하세요 : ");
			scanf("%s", bookName);
			bookNameArr[bookIndex] = bookName;
			bookIndex++;
			printf("*******************************\n");
		}
		else if (number == 2)
		{
			char bookName[20];

			printf("\n>> 찾을 책 이름을 작성하세요 : ");
			scanf("%s", bookName);

			for (int i = 0; i < bookIndex; i++)
			{
				char* storeBookName = bookNameArr[i];

				int inputBookLen = GetBookNameLength(bookName);
				int storeBookLen = GetBookNameLength(storeBookName);

				if (inputBookLen == storeBookLen)
				{
					printf("책이 존재합니다\n");
				}

				// 문자열의 길이를 구하는 함수 구현		
				printf("%s", bookNameArr[i]);
				printf("*******************************\n");
				continue;
				// 문자열의 각 인덱스가 같은지 
			}
		}
		else if (number == 3)
		{
			printf("\n>> 모든 책 목록을 확인합니다...\n");
			if (bookIndex == 0)
			{
				printf("책이 없습니다.\n");
				continue; 
			}
			for (int i = 0; i < bookIndex; i++)
			{
				printf("%d번 : %s\n", i + 1, bookNameArr[i]);
			}
			printf("*******************************\n");
			continue;
		}
	}
}