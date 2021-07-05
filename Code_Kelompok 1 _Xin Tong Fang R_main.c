#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CSI "\e["

#define GREEN_COLOR CSI "0;92m"
#define YELLOW_COLOR CSI "1;93m"
#define WHITE_COLOR CSI "1;97m"
#define RESET_COLOR CSI "0m"

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

#define ENTER 13

//Validitas Order
int valid = 0;

//Deklarasi Menu Makanan
int MieKucai = 0;
int BabiHong = 0;
int BebekPeking = 0;
long long priceMieKucai = 0;
long long priceBabiHong = 0;
long long priceBebekPeking = 0;

//Deklarasi Menu Minuman
int IceDogger = 0;
int IceTea = 0;
int MineralWater = 0;
long long priceIceDogger = 0;
long long priceIceTea = 0;
long long priceMineralWater = 0;

//Deklarasi Total
long long total= 0;

struct Node{
	char name[100];
	int MieKucai;
	int BabiHong;
	int BebekPeking;
	long long priceMieKucai;
	long long priceBabiHong;
	long long priceBebekPeking;
	
	int IceDogger;
	int IceTea;
	int MineralWater;
	long long priceIceDogger;
	long long priceIceTea ;
	long long priceMineralWater;
	
	long long total;
		
	struct Node *next;
}*head = NULL, *tail = NULL;

//buat node baru
struct Node *createNode(char name[]){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	strcpy(temp->name, name);
	temp->MieKucai = MieKucai;
	temp->BabiHong = BabiHong;
	temp->BebekPeking = BebekPeking;
	temp->priceMieKucai = priceMieKucai;
	temp->priceBabiHong = priceBabiHong;
	temp->priceBebekPeking = priceBebekPeking;
	
	temp->IceDogger = IceDogger;
	temp->IceTea = IceTea;
	temp->MineralWater = MineralWater;
	temp->priceIceDogger = priceIceDogger;
	temp->priceIceTea = priceIceTea;
	temp->priceMineralWater = priceMineralWater;
	 
	temp->total = total;
	
	temp->next = NULL;
	return temp;
}

//insert node
void insert(char name[]){
	struct Node *curr = createNode(name);
    if (head == NULL)
    {
        head = tail = curr;
    }else{
        tail->next = curr;
        tail = curr;
        tail->next = NULL;
    }	
}

// setting koordinat
void set_pos(int x, int y) {
    printf(CSI "%d;%dH", y, x);
}

//clear screen tanpa ngedip
void cls() {
    printf(CSI "H");
    printf(CSI "J");
}

void homePage(int choice) {
	// Buat Waktu Local
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf("%s\n\n", asctime (timeinfo) );
	
	int y = 10;
	int x = 50;
    set_pos(x, y);
    if (choice == 1) {
        printf(GREEN_COLOR ">> Order <<" RESET_COLOR);
    } else {
        printf("   Order");
    }

    set_pos(x, y+1);
    if (choice == 2) {
        printf(GREEN_COLOR ">> Queue <<" RESET_COLOR);
    } else {
        printf("   Queue");
    }

}

void foodMenuPage(int chooseFood){
	int y = 5;
	int x = 50;
    set_pos(x, y);
    printf(YELLOW_COLOR "Menu Makanan" RESET_COLOR);
    set_pos(x - 5, y + 2);
    printf(WHITE_COLOR "Menu" RESET_COLOR); 
    set_pos(x + 10, y + 2);
    printf(WHITE_COLOR "Quantity" RESET_COLOR);
    set_pos(x + 25, y + 2 );
    printf(WHITE_COLOR "Price" RESET_COLOR);

    //makanan
    
    //mie kucai
    if(chooseFood == 1){
    	set_pos(x - 9, y + 4);
    	printf(GREEN_COLOR ">> Mie Kucai" RESET_COLOR);
    	set_pos(x + 13, y + 4);
    	printf(GREEN_COLOR "x %d" RESET_COLOR, MieKucai);
    	set_pos(x + 23, y + 4);
    	printf(GREEN_COLOR "Rp. %lld" RESET_COLOR, priceMieKucai);
	}else{
	    set_pos(x - 6 , y + 4);
	    printf("Mie Kucai");
	    set_pos(x + 13, y + 4);
	    printf("x %d", MieKucai);
		set_pos(x + 23, y + 4);
    	printf("Rp. %lld",priceMieKucai);		
	}

    // Babi hong
    if(chooseFood == 2){
	    set_pos(x - 9, y + 6);
	    printf(GREEN_COLOR ">> Babi Hong" RESET_COLOR);
	    set_pos(x + 13, y + 6);
	    printf(GREEN_COLOR "x %d" RESET_COLOR, BabiHong);
		set_pos(x + 23, y + 6);
    	printf(GREEN_COLOR "Rp. %lld" RESET_COLOR, priceBabiHong); 		
	}else{
	    set_pos(x - 6, y + 6);
	    printf("Babi Hong");
	    set_pos(x + 13, y + 6);
	    printf("x %d", BabiHong);
		set_pos(x + 23, y + 6);
    	printf("Rp. %lld",priceBabiHong);			
	}

    
    //Bebek Peking
    if(chooseFood == 3){
	    set_pos(x - 9, y + 8);
	    printf(GREEN_COLOR ">> Bebek Peking" RESET_COLOR);
	    set_pos(x + 13 , y + 8);
	    printf(GREEN_COLOR "x %d" RESET_COLOR, BebekPeking);  
		set_pos(x + 23, y + 8);
    	printf(GREEN_COLOR "Rp. %lld" RESET_COLOR, priceBebekPeking);	
	}else{
	    set_pos(x - 6, y + 8);
	    printf("Bebek Peking");
	    set_pos(x + 13 , y + 8);
	    printf("x %d", BebekPeking);
		set_pos(x + 23, y + 8);
    	printf("Rp. %lld", priceBebekPeking);		
	}
	
	//Finish
	if(chooseFood == 4){
		set_pos(x + 13, y + 10);
		printf(GREEN_COLOR "DONE" RESET_COLOR);		
	}else{
		set_pos(x + 13, y + 10);
		printf("DONE");		
	}
	total = priceMieKucai + priceBabiHong + priceBebekPeking + priceIceDogger + priceIceTea + priceMineralWater;
}

void foodPage(){
	int chooseFood = 1;
	while(1){
		cls();
		foodMenuPage(chooseFood);
		int keys = getch();
		
		if(keys == ENTER && chooseFood == 4){
			break;
		}
		
		if(keys == ARROW_LEFT){
			switch(chooseFood){
				case 1:
					if(MieKucai == 0){
						break;
					}
					MieKucai -= 1;
					priceMieKucai = MieKucai * 15000;
					break;
				case 2:
					if(BabiHong == 0){
						break;
					}
					BabiHong -= 1;
					priceBabiHong = BabiHong * 30000;
					break;
				case 3:
					if(BebekPeking == 0){
						break;
					}
					BebekPeking -= 1;
					priceBebekPeking = BebekPeking * 20000;
					break;
			}
		}
		
		if(keys == ARROW_RIGHT){
			switch(chooseFood){
				case 1:
					MieKucai += 1;
					priceMieKucai = MieKucai * 15000;
					break;
				case 2:
					BabiHong += 1;
					priceBabiHong = BabiHong * 30000;
					break;
				case 3:
					BebekPeking += 1;
					priceBebekPeking = BebekPeking * 20000;
					break;
			}			
		}
		
        switch (keys) {
            case ARROW_UP:
                chooseFood--;
                break;
            case ARROW_DOWN:
                chooseFood++;
                break;
        }
        
        if(chooseFood < 1){
        	chooseFood = 4;
		}else if(chooseFood > 4){
			chooseFood = 1;
		}
	}
}

void drinkMenuPage(int chooseDrink){
	int y = 5;
	int x = 50;
    set_pos(x, y);
    printf(YELLOW_COLOR "Menu Minuman" RESET_COLOR);
    set_pos(x - 5, y + 2);
    printf(WHITE_COLOR "Menu" RESET_COLOR); 
    set_pos(x + 10, y + 2);
    printf(WHITE_COLOR "Quantity" RESET_COLOR);
    set_pos(x + 25, y + 2 );
    printf(WHITE_COLOR "Price" RESET_COLOR);
    
    //minuman
    
    //ice dogger
    if(chooseDrink == 1){
    	set_pos(x - 9, y + 4);
    	printf(GREEN_COLOR ">> Ice Dogger" RESET_COLOR);
    	set_pos(x + 13, y + 4);
    	printf(GREEN_COLOR "x %d" RESET_COLOR, IceDogger);
    	set_pos(x + 23, y + 4);
    	printf(GREEN_COLOR "Rp. %lld" RESET_COLOR, priceIceDogger);
	}else{
	    set_pos(x - 6 , y + 4);
	    printf("Ice Dogger");
	    set_pos(x + 13, y + 4);
	    printf("x %d", IceDogger);
		set_pos(x + 23, y + 4);
    	printf("Rp. %lld",priceIceDogger);		
	}

    // Ice tea
    if(chooseDrink == 2){
	    set_pos(x - 9, y + 6);
	    printf(GREEN_COLOR ">> Ice Tea" RESET_COLOR);
	    set_pos(x + 13, y + 6);
	    printf(GREEN_COLOR "x %d" RESET_COLOR, IceTea);  
		set_pos(x + 23, y + 6);
    	printf(GREEN_COLOR "Rp. %lld" RESET_COLOR, priceIceTea);		
	}else{
	    set_pos(x - 6, y + 6);
	    printf("Ice Tea");
	    set_pos(x + 13, y + 6);
	    printf("x %d", IceTea);
		set_pos(x + 23, y + 6);
    	printf("Rp. %lld",priceIceTea);		
	}

    
    //Mineral Water
    if(chooseDrink == 3){
	    set_pos(x - 9, y + 8);
	    printf(GREEN_COLOR ">> Mineral Water" RESET_COLOR);
	    set_pos(x + 13 , y + 8);
	    printf(GREEN_COLOR "x %d" RESET_COLOR, MineralWater);  	
	    set_pos(x + 23, y + 8);
    	printf(GREEN_COLOR "Rp. %lld" RESET_COLOR,priceMineralWater);
	}else{
	    set_pos(x - 6, y + 8);
	    printf("Mineral Water");
	    set_pos(x + 13 , y + 8);
	    printf("x %d", MineralWater);
		set_pos(x + 23, y + 8);
    	printf("Rp. %lld", priceMineralWater);	
	}
	
	//Finish
	if(chooseDrink == 4){
		set_pos(x + 3, y + 10);
		printf(GREEN_COLOR "DONE" RESET_COLOR);		
	}else{
		set_pos(x + 3, y + 10);
		printf("DONE");		
	}
	total = priceMieKucai + priceBabiHong + priceBebekPeking + priceIceDogger + priceIceTea + priceMineralWater;
}

void drinkPage(){
	int chooseDrink = 1;
	while(1){
		cls();
		drinkMenuPage(chooseDrink);
		int keys = getch();
		
		if(keys == ENTER && chooseDrink == 4){
			break;
		}
		
		if(keys == ARROW_LEFT){
			switch(chooseDrink){
				case 1:
					if(IceDogger == 0){
						break;
					}
					IceDogger -= 1;
					priceIceDogger =  IceDogger * 10000;
					break;
				case 2:
					if(IceTea == 0){
						break;
					}
					IceTea -= 1;
					priceIceTea = IceTea * 8000;
					break;
				case 3:
					if(MineralWater == 0){
						break;
					}
					MineralWater -= 1;
					priceMineralWater = MineralWater * 5000;
					break;
			}
		}
		
		if(keys == ARROW_RIGHT){
			switch(chooseDrink){
				case 1:
					IceDogger += 1;
					priceIceDogger =  IceDogger * 10000;
					break;
				case 2:
					IceTea += 1;
					priceIceTea = IceTea * 8000;
					break;
				case 3:
					MineralWater += 1;
					priceMineralWater = MineralWater * 5000;
					break;
			}			
		}
		
        switch (keys) {
            case ARROW_UP:
                chooseDrink--;
                break;
            case ARROW_DOWN:
                chooseDrink++;
                break;
        }
        
        if(chooseDrink < 1){
        	chooseDrink = 4;
		}else if(chooseDrink > 4){
			chooseDrink = 1;
		}
	}
}

void finalMenuOrderPage(char name[], int choice){
		int y = 5;
		int x = 40;
    	set_pos(x, y);
    	printf(YELLOW_COLOR "Your Name : " RESET_COLOR);
    	set_pos(x + 12, y);
    	printf("%s", name);
    	
    	y = 8;
	    x = 8;
		//cart
		set_pos(x + 20, y);
		printf("Cart");
		
		//Deklarasi Makanan
		set_pos(x + 20, y + 2);
		printf("Makanan : ");
		//Menu Makanan
		set_pos(x + 20, y + 3);
		printf("Mie Kucai x%d pcs         Rp.%lld,-", MieKucai, priceMieKucai);
		set_pos(x + 20, y + 4);
		printf("Babi Hong x%d pcs         Rp.%lld,-", BabiHong, priceBabiHong);
		set_pos(x + 20, y + 5);
		printf("Bebek Peking x%d pcs      Rp.%lld,-", BebekPeking, priceBebekPeking);
		
		//Deklarasi Minuman
		set_pos(x + 20, y + 7);
		printf("Minuman : ");
		set_pos(x + 20, y + 8);
		printf("Ice Dogger x%d pcs        Rp.%lld,-", IceDogger, priceIceDogger);
		set_pos(x + 20, y + 9);
		printf("Ice Tea x%d pcs           Rp.%lld,-", IceTea, priceIceTea);
		set_pos(x + 20, y + 10);
		printf("Mineral Water x%d pcs     Rp.%lld,-",MineralWater, priceMineralWater);
		set_pos(x + 20, y + 11);
		printf("====================================\n");
		set_pos(x + 20, y + 12);
		printf("Total Price :            Rp.%lld,-",total);
		
		if(choice == 1){
			set_pos(x + 60, y + 5);
			printf(GREEN_COLOR ">> Order" RESET_COLOR);
		}else{
			set_pos(x + 63, y + 5);
			printf("Order");
		}
		
		if(choice == 2){
			set_pos(x + 60, y + 6);
			printf(GREEN_COLOR ">> Cancel" RESET_COLOR);
		}else{
			set_pos(x + 63, y + 6);
			printf("Cancel");
		}
}

void afterFinalOrderPage(char name[]){
	cls();
	int x = 5;
	int y = 3;
	set_pos(x, y);
	printf("Xing Tong Fang");
	set_pos(x + 2, y + 1);
	printf("Restaurant");
	x = 40;
	y = 10;
		
	if(MieKucai == 0 && BabiHong == 0 && BebekPeking == 0 && IceDogger == 0 && IceTea == 0 && MineralWater == 0){
		valid = 0;
		set_pos(x, y);
		printf("Sorry Mr./Mr.s %s", name);
		printf(", You cart is empty...");
		set_pos(x, y + 1);
		printf("Go order please...");
		getchar();
		return;
	}
	
	set_pos(x, y);
	printf("Thanks Mr./Mrs. %s ", name);
	printf("for ordering...");
	set_pos(x, y + 1);
	printf("Please go to cashier for payment.");
	
	
	insert(name);
	getchar();
	//reset
	//makanan
	MieKucai = 0;
	BabiHong = 0;
	BebekPeking = 0;
	priceMieKucai = 0;
	priceBabiHong = 0;
	priceBebekPeking = 0;
				
	//minuman
	IceDogger = 0;
	IceTea = 0;
	MineralWater = 0;
	priceIceDogger = 0;
	priceIceTea = 0;
	priceMineralWater = 0;	
	
	//total
	total = 0;
}

void finalOrderPage(){
	valid = 0;
	cls();
	char name[100];
	int y = 5;
	int x = 40;
    set_pos(x, y);
    printf(YELLOW_COLOR "Your Name : " RESET_COLOR);
    scanf("%[^\n]", name); getchar();
    int choice = 1;
    while(1){
    	cls();
		finalMenuOrderPage(name, choice);
		int keys = getch();
		
        switch (keys) {
            case ARROW_UP:
                choice--;
                break;
            case ARROW_DOWN:
                choice++;
                break;
        }
        
        if(choice < 1){
        	choice = 2;
		}else if(choice > 2){
			choice = 1 ;
		}
		
		if(keys == ENTER){
			if(choice == 1){
				afterFinalOrderPage(name);
				valid = 1;
				break;
			}
			else if(choice == 2){
				break;
			}
		}
	}
    
}

void orderMenuPage(int choose){
	int x = 50;
	int y = 10;
	
	set_pos(x , y);
	if(choose == 1){
		printf(GREEN_COLOR ">> Foods <<" RESET_COLOR);
	}else{
		printf("   Foods");
	}
	
	set_pos(x, y + 1);
	if(choose == 2){
		printf(GREEN_COLOR ">> Drinks <<" RESET_COLOR);
	}else{
		printf("   Drinks");
	}
	
	set_pos(x, y + 2);
	if(choose == 3){
		printf(GREEN_COLOR ">> Order <<" RESET_COLOR);
	}else{
		printf("   Order");
	}
	
	set_pos(x, y + 3);
	if(choose == 4){
		printf(GREEN_COLOR ">> Back <<" RESET_COLOR);
	}else{
		printf("   Back");
	}
	
	y = 8;
	//cart
	set_pos(x + 20, y);
	printf("Cart");
	
	//Deklarasi Makanan
	set_pos(x + 20, y + 2);
	printf("Makanan : ");
	//Menu Makanan
	set_pos(x + 20, y + 3);
	printf("Mie Kucai x%d pcs         Rp.%lld,-", MieKucai, priceMieKucai);
	set_pos(x + 20, y + 4);
	printf("Babi Hong x%d pcs         Rp.%lld,-", BabiHong, priceBabiHong);
	set_pos(x + 20, y + 5);
	printf("Bebek Peking x%d pcs      Rp.%lld,-", BebekPeking, priceBebekPeking);
	
	//Deklarasi Minuman
	set_pos(x + 20, y + 7);
	printf("Minuman : ");
	set_pos(x + 20, y + 8);
	printf("Ice Dogger x%d pcs        Rp.%lld,-", IceDogger, priceIceDogger);
	set_pos(x + 20, y + 9);
	printf("Ice Tea x%d pcs           Rp.%lld,-", IceTea, priceIceTea);
	set_pos(x + 20, y + 10);
	printf("Mineral Water x%d pcs     Rp.%lld,-",MineralWater, priceMineralWater);
	set_pos(x + 20, y + 11);
	printf("====================================\n");
	//Deklarasi Total
	set_pos(x + 20, y + 12);
	printf("Total Price:             Rp.%lld,-",total);
	
}

void orderPage(){
	int choose = 1;
	while(1){
		cls();
		orderMenuPage(choose);
		int keys = getch();
		
		if(keys == ENTER){
			if(choose == 1){
				foodPage();
			}else if(choose == 2){
				drinkPage();
			}else if(choose == 3){
				finalOrderPage();
				if(valid == 1){
					break;
				}
			}else if(choose == 4){
				//reset
				
				//makanan
				MieKucai = 0;
				BabiHong = 0;
				BebekPeking = 0;
				priceMieKucai = 0;
				priceBabiHong = 0;
				priceBebekPeking = 0;
				
				//minuman
				IceDogger = 0;
				IceTea = 0;
				MineralWater = 0;
				priceIceDogger = 0;
				priceIceTea = 0;
				priceMineralWater = 0;
				//total
				total = 0;	
				break;
			}
		}
		
        switch (keys) {
            case ARROW_UP:
                choose--;
                break;
            case ARROW_DOWN:
                choose++;
                break;
        }
		
		if(choose < 1){
			choose = 4;
		}else if(choose > 4){
			choose = 1;
		}
	}
}

void queueMenuPage(int choose){
	int x = 50;
	int y = 10;
	
	set_pos(x - 1 , y);
	if(choose == 1){
		printf(GREEN_COLOR ">> Show Queue <<" RESET_COLOR);
	}else{
		printf("   Show Queue");
	}
	
	set_pos(x - 2, y + 1);
	if(choose == 2){
		printf(GREEN_COLOR ">> Print Payment <<" RESET_COLOR);
	}else{
		printf("   Print Payment");
	}
	
	set_pos(x + 1, y + 2);
	if(choose == 3){
		printf(GREEN_COLOR ">> History <<" RESET_COLOR);
	}else{
		printf("   History");
	}
	
	set_pos(x + 2, y + 3);
	if(choose == 4){
		printf(GREEN_COLOR ">> Back <<" RESET_COLOR);
	}else{
		printf("   Back");
	}	
}

void showQueue(){
	cls();
	int x = 10;
	int y = 4;
	set_pos(x, y);
	printf(YELLOW_COLOR "Queue" RESET_COLOR);
	
	set_pos(x, y + 2);
	struct Node *curr = head;
	if(curr == NULL){
		printf("Order Empty...");
		getchar();
		return;
	}else{
		int i = 1;
		int z = y + 2;
		while(curr){
			set_pos(x, z);
			printf("%d. %s", i, curr->name);
			curr = curr->next;
			z += 1;
			i += 1;
		}
		fflush(stdin);
		set_pos(x , z + 1);
		printf(GREEN_COLOR">> Back <<" RESET_COLOR);
		while (getch() != ENTER) {
        // do nothing
    	}
		return;	
	}
}

void sucessProcess(){
	cls();
	
	//pop -> ngehapus
	struct Node *curr = head;
	head = head->next;
	curr->next = NULL;
	free(curr);
	
	int x = 40;
	int y = 10;
	set_pos(x, y);
	printf(YELLOW_COLOR "Thank You For Ordering, Print Sucessful!!!" RESET_COLOR);
	getchar();
	return;
}

void saveListName(){
	struct Node *curr = head;
	FILE *file = fopen("HistoryOrder/NameList.txt", "a");
	fprintf(file, "%s\n", curr->name);
	fclose(file);
	return;
}

void saveProcessing(){
	struct Node *curr = head;
	char nameBuffer[300];
	sprintf(nameBuffer, "HistoryOrder/%s.txt", curr->name);
	//ex :
	//nameBuffer = "HistoryOrder/Alvian.txt"
	
	saveListName();
	
	//save        
	FILE *file = fopen(nameBuffer, "w");
	fprintf(file, "%s\n", curr->name);
	fprintf(file, "Mie Kucai x %d      Rp.%lld,-\n", curr->MieKucai,curr->priceMieKucai);
	fprintf(file, "Babi Hong x %d      Rp.%lld,-\n", curr->BabiHong,curr->priceBabiHong);
	fprintf(file, "Bebek Peking x %d   Rp.%lld,-\n", curr->BebekPeking,curr->priceBebekPeking);
	
	fprintf(file, "Ice Dogger x %d     Rp.%lld,-\n", curr->IceDogger,curr->priceIceDogger);
	fprintf(file, "Ice Tea x %d        Rp.%lld,-\n", curr->IceTea,curr->priceIceTea);
	fprintf(file, "Mineral Water x %d  Rp.%lld,-\n", curr->MineralWater,curr->priceMineralWater);
	fprintf(file, "=============================\n");
	fprintf(file, "Total Price:       Rp.%lld,-\n",curr->total);
	fclose(file);
	return;
}

void processQueue(){
	cls();
	char id[10];
	char pw[10];
	set_pos(50, 10);
	printf("Username: ");
	scanf("%s", id); getchar();
	set_pos(50,11);
	printf("Password: ");
	scanf("%s", pw); getchar();
	if(strcmp(id, "admin") != 0 && strcmp(pw, "admin") != 0){
		cls();
		set_pos(50, 11);
		printf(YELLOW_COLOR "Wrong Password!" RESET_COLOR);
		getchar();
		return;
	}
	cls();
	struct Node *curr = head;
	if(head == NULL){
		int x = 50;
		int y = 10;
		set_pos(x - 8, y);
		printf(YELLOW_COLOR "Can't Process, Because No One Order..." RESET_COLOR);
		getchar();
		return;
	}else{
		int x = 50;
		int y = 10;
		set_pos(x, y);
		printf(GREEN_COLOR "%s" RESET_COLOR, curr->name);
		set_pos(x, y + 1);
		printf("Mie Kucai x %d     Rp.%lld,-", curr->MieKucai,curr->priceMieKucai);
		set_pos(x, y + 2);
		printf("Babi Hong x %d     Rp.%lld,-", curr->BabiHong,curr->priceBabiHong);
		set_pos(x, y + 3);
		printf("Bebek Peking x %d  Rp.%lld,-", curr->BebekPeking,curr->priceBebekPeking);
		set_pos(x, y + 4);
		printf("Ice Dogger x %d    Rp.%lld,-", curr->IceDogger,curr->priceIceDogger);
		set_pos(x, y + 5);
		printf("Ice Tea x %d       Rp.%lld,-", curr->IceTea,curr->priceIceTea);
		set_pos(x, y + 6);
		printf("Mineral Water x %d Rp.%lld,-", curr->MineralWater,curr->priceMineralWater);
		set_pos(x, y + 7);
		printf("=============================");
		set_pos(x, y + 8);
		printf("Total Price:      Rp.%lld,-",curr->total);
		set_pos(x , y + 10);
		printf(YELLOW_COLOR "Press enter to process" RESET_COLOR);
		//wait until enter
		while (getch() != ENTER) {
        // do nothing
    	}
    	
		saveProcessing();
		sucessProcess();
	}
}

int Yaxis = 0;

int loadAndPrintData(){
	Yaxis = 0;
	int j = 1;
	FILE *checkFile = fopen("HistoryOrder/NameList.txt", "r");
	char temp[300];
	int x = 50;
	int y = 3;
	
	while(fscanf(checkFile, " %[^\n]", temp) != EOF){
		set_pos(x, y);
		printf("%d. %s\n", j ,temp);
		j += 1;
		y += 1;
	}
	fclose(checkFile);
	Yaxis = y;
	return j - 1;
}

void historyPage(){
	cls();
	char id[10];
	char pw[10];
	set_pos(50, 10);
	printf("Username: ");
	scanf("%s", id); getchar();
	set_pos(50,11);
	printf("Password: ");
	scanf("%s", pw); getchar();
	if(strcmp(id, "admin") != 0 && strcmp(pw, "admin") != 0){
		cls();
		set_pos(50, 11);
		printf(YELLOW_COLOR "Wrong Password!" RESET_COLOR);
		getchar();
		return;
	}
	cls();
	int k = loadAndPrintData();
	if(k == 0){
		set_pos(50, 10);
		printf(YELLOW_COLOR "No Data!!!\n" RESET_COLOR);
	}
	int x = 48;
	
	char tempName[100];
	if(k != 0){
		set_pos(x, Yaxis + 1);
		printf("Search Name : ");
		scanf("%[^\n]", tempName); getchar();	
	}
	
	cls();
	set_pos(49, 1);
	printf(YELLOW_COLOR "================" RESET_COLOR);
	set_pos(49, 2); 
	printf(YELLOW_COLOR "|    HISTORY   |" RESET_COLOR);
	set_pos(49, 3);
	printf(YELLOW_COLOR "================" RESET_COLOR);
	char path[300];
	sprintf(path, "HistoryOrder/%s.txt", tempName);
	FILE *file = fopen(path, "r");
	char temp[300];
	int cek = 0;
	int z = 45;
	int v = 5;
	printf(GREEN_COLOR);
	while(fscanf(file," %[^\n]\n", temp) != EOF){
		set_pos(z, v);
		printf("%s", temp);
		cek += 1;
		v+= 1;
	} printf("\n");
	printf(RESET_COLOR);
	set_pos(z + 7, v + 1);
	printf(WHITE_COLOR ">> Back <<" RESET_COLOR);
	if(cek == 0){
		set_pos(40, 13);
		printf(YELLOW_COLOR "Nama yang anda cari tidak ada...." RESET_COLOR);
	}
	
	while(getch() != ENTER){
		//do nothing
	}
	return;
}

void queuePage(){
	int choose = 1;
	while(1){
		cls();
		queueMenuPage(choose);
		int key = getch();
		
		switch (key) {
            case ARROW_UP:
                choose--;
                break;
            case ARROW_DOWN:
                choose++;
                break;
        }
		
		if(key == ENTER){
			if(choose == 1){
				showQueue();
			}else if(choose == 2){
				processQueue();
			}else if(choose == 3){
				historyPage();
			}else if(choose == 4){
				break;
			}
		}
		
		
		if(choose < 1){
			choose = 4;
		}else if(choose > 4){
			choose = 1;
		}		
		
	}
}

int main() {
    system("cls");
    int choice = 1;
    while (1) {
        cls();
        homePage(choice);
        int key = getch();

        if(key == ENTER){
        	//2 Menu
        	if(choice == 1){
        		orderPage();
			}
			if(choice == 2){
				queuePage();
			}
        }

        switch (key) {
            case ARROW_UP:
                choice--;
                break;
            case ARROW_DOWN:
                choice++;
                break;
        }

        if (choice < 1) {
            choice = 2;
        } else if (choice > 2) {
            choice = 1;
        }
    }

    return 0;
}
