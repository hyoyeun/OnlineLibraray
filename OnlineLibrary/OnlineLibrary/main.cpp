#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma warning(disable:6031)

int GetBookNameLength(char *bookName) // ���ڿ� ó�� ���� �ִ�.
{
	char* startPtr = bookName;
	int len = 0;
	while (true)
	{
		if (*startPtr == NULL)
			break;

		startPtr++;
		len++;
	}
	return len;
}

int main()
{
	printf(">> �¶��� ������ <<\n\n");
	char bookNameArr[100][20]; // ���ڿ� 100���� �ǹ���.
	int bookIndex = 0; // ���ڿ��� �ε��� : �� å�� ��ȣ
	while (true)
	{
		int number = 0;
		printf("\n1�� -> å�̸� �Է� \n2�� -> �Է��� å ã�� \n3�� -> å ��� ��� Ȯ��\n��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &number);
		if (number == 1)
		{
			printf("\n>> å �̸��� �Է��ϼ��� : ");
			scanf("%s", bookNameArr[bookIndex]);
			bookIndex++;
			printf("*******************************\n");
		}
		else if (number == 2)
		{
			char inputBookName[20];
			printf("\n>> ã�� å �̸��� �ۼ��ϼ��� : ");
			scanf("%s", inputBookName);

			for (int i = 0; i < bookIndex; i++)
			{
				char* storeBookName = bookNameArr[i]; // storeBookName : å �̸�.

				int inputBookLen = GetBookNameLength(inputBookName); // => inputBookName(ã���� �ϴ� å �̸�) : "abc" 
				int storeBookLen = GetBookNameLength(storeBookName); // => storeBookName(����� å �̸�) : "abc"

				// �� å �̸��� ���̰� ������ Ȯ��
				if (inputBookLen == storeBookLen)
				{
					// ������ ���ڿ� ���ؼ� ó���� ��.
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