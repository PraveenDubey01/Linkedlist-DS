#include "list2.c"
int main()
{
	item_type item,given;
	int choice;
	
    list l;
	init(&l);
	
	while(1)
	{
		puts("1. INSERT LAST");
		puts("2. INSERT FIRST");
		puts("3. INSERT AFTER GIVEN");
		puts("4. INSERT BEFORE GIVEN");
		puts("5. DISPLAY");
		puts("6. SIZE");
		puts("7. SEARCH");
		puts("8. INSERT Sorted");
		puts("9. INSERT GIVEN POSITION");
		puts("10. Find Largest");
		puts("11. Find Smallest");
		puts("12. Delete First");
		puts("13. Delete Last");
		
		printf("Enter Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter item: ");
				scanf("%d",&item);
				insertlast(&l,item);
				break;
			case 2:
				printf("Enter item: ");
				scanf("%d",&item);
				insertfirst(&l,item);
				break;
			case 3:
				printf("Enter item: ");
				scanf("%d",&item);
				printf("Enter given: ");
				scanf("%d",&given);
				insertaftergiven(&l,item,given);
				break;				
			case 4:
				printf("Enter item: ");
				scanf("%d",&item);
				printf("Enter given: ");
				scanf("%d",&given);
				insertbeforegiven(&l,item,given);
				break;
			case 5:
				display(l.start);
				printf("\n");
				break;
				
			case 6:
				printf("%d item found\n",size(l.start));
				break;
			case 7:
				printf("Enter item: ");
				scanf("%d",&item);
				if(search(l.start,item)!=NULL)
				   printf("Item Found!\n");
				else
				   puts("Item Not Found!");
				break;
			case 8:
				printf("Enter item: ");
				scanf("%d",&item);
				insertsortedlist(&l,item);
				break;
			case 9:
				printf("Enter item: ");
				scanf("%d",&item);
				printf("Enter given: ");
				scanf("%d",&given);
				insertgivenplace(&l,item,given);
				break;		
			case 10:
				printf("%d is largest item\n",largest(l.start));
				break;
			case 11:
				printf("%d is smallest item\n",smallest(l.start));
				break;
			case 12:
				item = deletefirst(&l);
				if(item!=0)
					printf("%d is deleted from first place\n",item);
				break;
			case 13:
				item = deletelast(&l);
				if(item!=0)
					printf("%d is deleted from last place\n",item);
				break;			   	 
			default:
				exit(1);
		}
	}
}

 
