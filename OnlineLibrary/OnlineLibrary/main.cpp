#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:6031)

int GetBookNameLength(char *bookName) // ���ڿ� ó�� ���� �ִ�.
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
	printf(">> �¶��� ������ <<\n\n");
	char* bookNameArr[100];
	int bookIndex = 0;
	while (true)
	{
		int number = 0;
		printf("\n1�� -> å�̸� �Է� \n2�� -> �Է��� å ã�� \n3�� -> å ��� ��� Ȯ��\n��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &number);
		if (number == 1)
		{
			char bookName[20];
			printf("\n>> å �̸��� �Է��ϼ��� : ");
			scanf("%s", bookName);
			bookNameArr[bookIndex] = bookName;
			bookIndex++;
			printf("*******************************\n");
		}
		else if (number == 2)
		{
			char bookName[20];

			printf("\n>> ã�� å �̸��� �ۼ��ϼ��� : ");
			scanf("%s", bookName);

			for (int i = 0; i < bookIndex; i++)
			{
				char* storeBookName = bookNameArr[i];

				int inputBookLen = GetBookNameLength(bookName);
				int storeBookLen = GetBookNameLength(storeBookName);

				if (inputBookLen == storeBookLen)
				{
					printf("å�� �����մϴ�\n");
				}

				// ���ڿ��� ���̸� ���ϴ� �Լ� ����		
				printf("%s", bookNameArr[i]);
				printf("*******************************\n");
				continue;
				// ���ڿ��� �� �ε����� ������ 
			}
		}
		else if (number == 3)
		{
			printf("\n>> ��� å ����� Ȯ���մϴ�...\n");
			if (bookIndex == 0)
			{
				printf("å�� �����ϴ�.\n");
				continue; 
			}
			for (int i = 0; i < bookIndex; i++)
			{
				printf("%d�� : %s\n", i + 1, bookNameArr[i]);
			}
			printf("*******************************\n");
			continue;
		}
	}
}