#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(int argc, char *argv[]){
	srand(time(0)); 
	int velicina = atoi(argv[1]);
	int polje[velicina];
	char spremnik[velicina+1];
	int brojac = 1;
	int i;
	char unos;
	for (i = 0; i < velicina; i++){
		polje[i] = brojac;
		brojac = (brojac + 1) % 10;
		spremnik[i] = '-';
	}
	spremnik[i] = '\n';
	
	for (int j = 0; j < velicina; j++){
		printf("%d", polje[j]);
	}
	printf("\n");
	for (int j = 0; j < velicina; j++){
		printf("%c", spremnik[j]);
	}
	printf("\n");
	int upis = 0;
	int pocetci[velicina];
	int krajevi[velicina];
	int duljina[velicina];
	for (int j = 0; j < velicina; j++){
		pocetci[j] = velicina + 1;
		krajevi[j] = velicina + 1;
		duljina[j] = 0;
	}
	unos = '0';
	while(1){
		printf("Unesi slovo (Z/O/D): ");				//Z->zahtjev, O->otpusti spremnik, D->defragmentacija
		scanf("%c", &unos);
		//printf("\n");
		if (unos == 'Z'){
			int kolicina = rand() % (velicina/4) + 1;
			//printf("%d \n", kolicina);
			printf("Novi zahtjev %d za %d spremnickih mjesta!\n", upis, kolicina);
			for (int j = 0; j < velicina; j++){
				printf("%d", polje[j]);
			}
			printf("\n");
			int br = 0, brZaCrtice = 0;
			for(int w = 0; w < velicina; w++){
				if(spremnik[w] == '-'){
					pocetci[br] = w;
					while(spremnik[w]=='-') {
						w++;
					}	
					krajevi[br] = w;
					duljina[br] = krajevi[br] - pocetci[br];
				}
				br++;
			}
			int check = 0;
			while(1){
				int p = 0;
				int min = velicina + 1;
				int minIndex = velicina + 1;
				int indeks;
				while(p < velicina){
					//printf("kontrola3 %d", duljina[p]);
					if (duljina[p] <= min && duljina[p] != 0) {
						min = duljina[p];
						minIndex = pocetci[p];
						indeks = p;
					}
					p++;
				}
				//printf(" %d ", min);
				if (min != 0 && kolicina <= min){
					for(int i = minIndex; i < minIndex + kolicina; i++){
						//printf("kontrola4");
						char kar = upis + '0';
						spremnik[i] = kar;
					}
					check = 1;
					break;
				}
				else duljina[indeks] = 0;
				int izbroj = 0;
				for(int h = 0; h < velicina; h++) if (duljina[h] == 0) izbroj++;
				if(izbroj == velicina) break;
			}
			if(check == 0) {
				char pomocno[velicina];
				int pomBr = 0;
				for (int i = 0; i < velicina; i++){
					pomocno[i] = '-';
				}
				for(int u = 0; u < velicina; u++){
					if (spremnik[u] != '-') {
						pomocno[pomBr] = spremnik[u];
						pomBr++;
					}
				} 
				for (int j = 0; j <= velicina; j++){
					spremnik[j] = pomocno[j];
				}
				
				br = 0; 
				brZaCrtice = 0;
				for(int w = 0; w < velicina; w++){
					if(spremnik[w] == '-'){
						pocetci[br] = w;
						while(spremnik[w]=='-') {
							w++;
						}	
						krajevi[br] = w;
						duljina[br] = krajevi[br] - pocetci[br];
					}
					br++;
				}
				while(1){
					int p = 0;
					int min = velicina + 1;
					int minIndex = velicina + 1;
					int indeks;
					while(p < velicina){
						//printf("kontrola3 %d", duljina[p]);
						if (duljina[p] <= min && duljina[p] != 0) {
							min = duljina[p];
							minIndex = pocetci[p];
							indeks = p;
						}
						p++;
					}
					//printf(" %d ", min);
					if (min != 0 && kolicina <= min){
						for(int i = minIndex; i < minIndex + kolicina; i++){
							//printf("kontrola4");
							char kar = upis + '0';
							spremnik[i] = kar;
						}
						check = 1;
						break;
					}
					else duljina[indeks] = 0;
					int izbroj = 0;
					for(int h = 0; h < velicina; h++) if (duljina[h] == 0) izbroj++;
					if(izbroj == velicina) break;
				}
				
			}
			if(check == 0) printf("Nema mjesta vise!\n");
			upis = (upis + 1) % 10;
			for (int j = 0; j <= velicina; j++){
				printf("%c", spremnik[j]);
			}
			printf("\n");
			for (int j = 0; j < velicina; j++){
				pocetci[j] = velicina + 1;
				krajevi[j] = velicina + 1;
				duljina[j] = 0;
			}
		}
		else if (unos == 'O'){
			int broj;
			printf("Koji zahtjev treba osloboditi? ");
			scanf("%d", &broj);
			printf("Oslobadjam zahtjev %d\n", broj);
			for(int i = 0; i < velicina; i++){
				if(spremnik[i] == broj+'0'){
					spremnik[i] = '-';
				}
			}
			for (int j = 0; j < velicina; j++){
				printf("%d", polje[j]);
			}
			printf("\n");
			for (int j = 0; j < velicina; j++){
				printf("%c", spremnik[j]);
			}
			printf("\n");
		}
		else if (unos == 'D'){
			char pomocno[velicina];
			int pomBr = 0;
			for (int i = 0; i < velicina; i++){
				pomocno[i] = '-';
			}
			for(int u = 0; u < velicina; u++){
				if (spremnik[u] != '-') {
					pomocno[pomBr] = spremnik[u];
					pomBr++;
				}
			} 
			for (int j = 0; j <= velicina; j++){
				spremnik[j] = pomocno[j];
			}
			for (int j = 0; j < velicina; j++){
				printf("%d", polje[j]);
			}printf("\n");
			for (int j = 0; j <= velicina; j++){
				printf("%c", spremnik[j]);
			}
			printf("\n");
		}
		scanf("%c", &unos);
		//printf("\n");
	}
}

