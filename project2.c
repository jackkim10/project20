#include <stdio.h>
#include <string.h>
struct BOOKSTR
{
	char title[20];
	char author[20];
	char publish[20];
	char emotion[10];
	int num;
	char borr;
};
char book_search(char *book_info, char *search, int *result);
int book_borrow(char *borr);
int book_return(char *borr);
char book_change(struct BOOKSTR *book_list);
char book_new(char *book_list);

int main()
{
	struct BOOKSTR book_list[100];
	int i, j, k,l,m,n,o,p;
	char a,z, search[100];
	m = 0;
	for(i=0;i<100;i++)
	{
		book_list[i].num = i+1;
		book_new(book_list[i].title);
		book_new(book_list[i].author);
		book_new(book_list[i].publish);
	}
	for(o=0;o=100;o++)
	{
		printf("번호 입력해십시오. \n");
		printf(" 1. 도서 검색 \n 2. 도서 대출 \n 3. 도서 반납 \n 4. 도서 등록및 교체\n 5. 책 추천\n 6. 나가기  ");
		scanf("%d", &i);
		if(i==1)
		{
			for(p=0;p=100;p++)
			{
				printf("검색방법\n");
				printf(" 1) 제목 \n 2) 저자\n 3) 출판사\n 4) 도서 번호  ");
				scanf("%d", &j);
				if(j==1)
				{
					printf("검색어를 입력해 주십시오. \n");
					scanf("%s", &search);
					printf("결과 \n");
					for(l=0;l<100;l++)
					{	
						book_search(book_list[l].title, search, &m);
						if(m == 1)
						{
							printf("  제목 : %s\n  저자 : %s\n  출판사 : %s\n  도서 번호 : %d\n", book_list[l].title,book_list[l].author,book_list[l].publish,book_list[l].num);
							printf("  대출 가능 여부 : %c\n", book_list[l].borr);
							m = 0;
						}
					}
				}
				else if(j==2)
				{
					printf("검색어를 입력해 주십시오. \n");
					scanf("%s", &search);
					printf("결과를 출력합니다. \n");
					for(l=0;l<100;l++)
					{	
						book_search(book_list[l].author, search, &m);
						if(m == 1)
						{
							printf("  저자 : %s\n  제목 : %s\n  출판사 : %s\n  도서 번호 : %d\n", book_list[l].author,book_list[l].title,book_list[l].publish,book_list[l].num);
							printf("  대출 가능 여부 : %c\n", book_list[l].borr);
							m = 0;
						}
					}
				}
				else if(j==3)
				{
					printf("검색어를 입력해 주십시오 : ");
					scanf("%s", &search);
					printf("결과를 출력합니다. \n");
					for(l=0;l<100;l++)
					{	
						book_search(book_list[l].publish, search, &m);
						if(m == 1)
						{
							printf("  출판사 : %s\n  제목 : %s\n  저자 : %s\n  도서 번호 : %d\n", book_list[l].publish,book_list[l].title,book_list[l].author,book_list[l].num);
							printf("  대출 가능 여부 : %c\n", book_list[l].borr);
							m = 0;
						}
					}
				}	
				else if(j==4)
				{
					printf("몇 번 도서를 검색하시겠습니까? \n");
					scanf("%d", &k);
					printf("  제목 : %s\n  저자 : %s\n  출판사 : %s\n", book_list[k].title, book_list[k].author,book_list[k].publish);
				}
				else
				{
					printf("오류 \n");
				}
				printf("더 검색하시겠습니까? y/n :");
				scanf(" %c", &a);
				if(a=='n')
				{
					break;
				}
			}
		}
		else if(i==2)
		{
			printf("대출할 도서의 번호를 입력해 주십시오. ");
			scanf("%d", &k);
			book_borrow(&book_list[k].borr);
		}
		else if(i==3)
		{
			printf("반납할 도서의 번호를 입력해 주십시오. ");
			scanf("%d", &k);
			book_return(&book_list[k].borr);
		}
		else if(i==4)
		{
			printf("변경할 도서의 번호를 선택해 주십시오.  ");
			scanf("%d", &n);
			book_list[n].num = n;
			book_change(&book_list[n]);
		}
		else if(i==5)
		{
			printf("감정을 입력하시오\n");
			scanf("%s", &z);
			book_rec(&book_list[z].emotion);
		}
		else if(i==6)
		{
			printf("감사합니다. \n");
			break;
		}
		else
		{
			printf("오류  \n");
		}
	}
	return 0;
}
char book_search(char *book_info, char *search, int *result)
{
	int i, j;
	char a;
	i = 0;
	j = 0;
	while(*search)
	{
		if(*search == *book_info)
		{
			book_info++;
			search++;
			i++;
			j++;
		}
		else
		{
			search=search-i;
			if(*book_info == '\0')
			{
				break;
			}
			else
			{
				book_info++;
				j++;
			}
			i = 0;
		}
	}
	if(*search == '\0')
	{
		*result = 1;
		search = search - i;
	}
	book_info = book_info-j;
	i = 0;
	j = 0;
	return 0;
}
int book_borrow(char *borr)
{
	if(*borr == 'y')
	{
		*borr = 'n';
		printf("도서가 대출되었습니다. \n");
	}
	else
	{
		printf("대출할 수 있는 도서가 아닙니다. \n");
	}
	return 0;
}
int book_return(char *borr)
{
	if(*borr == 'n')
	{
		*borr = 'y';
		printf("도서가 반납되었습니다. \n");
	}
	else
	{
		printf("반납할 수 있는 도서가 아닙니다. \n");
	}
	return 0;
}
char book_change(struct BOOKSTR *book_list)
{
	int i;
	char b;
	printf("이전에 저장되어 있던 도서의 정보는 사라집니다. 계속 하시겠습니까? y/n :");
	scanf(" %c", &b);
	if(b == 'y')
	{
		printf("새로운 도서의 정보를 입력해 주십시오. \n");
		printf("제목 : ");
		scanf("%s", &(*book_list).title);
		printf("저자 : ");
		scanf("%s", &(*book_list).author);
		printf("출판사 : ");
		scanf("%s", &(*book_list).publish);
		(*book_list).borr = 'y';
	}
	else if(b == 'n')
	{
		printf("작업이 취소되었습니다. \n");
	}
	else
	{
		printf("잘못된 작업입니다. \n");
	}
	return 0;
}
int book_rec(char *emotion)
{
	int i;
	for(i=0;i<100;i++)
	{
	}
}	
char book_new(char *book_info)
{
	*book_info = '\0';
	return 0;
}
