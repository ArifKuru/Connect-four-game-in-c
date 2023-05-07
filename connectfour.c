#include <stdio.h>
//tahtayi yazdirma fonksiyonu
const int a=8;
const int b=8;
int yaz(int p[a][b]){
	printf("\t\t\t\t<1><2><3><4><5><6><7>\n");
	printf("\t\t\t\t");
	int i,j;
	for(i=1;i<=6;i++){
		for(j=1;j<=7;j++){
			if (p[i][j]==1){
				printf("\x1B[33m|%d|\x1B[0m",p[i][j]);
			}
			else if(p[i][j]==2){
				printf("\x1B[31m|%d|\x1B[0m",p[i][j]);
			}
			else {
			
			printf("|%d|",p[i][j]);}
		}
		printf("\n\t\t\t\t");		
		
		}
	}
	// atýlan taþ nereye kadar gidiceðini belirlemek için doluyu bulmaliyiz
int dolubul(int p[a][b],int x){
	int i;
 for(i=1;i<=8;i++){
 	if(p[i][x]!=0){
 		return i;
	 }
 }	
}
// sýra fonksiyonu
int sira(int player){
	if(player%2==0){
		return 2;
	}
	else {
		return 1;
	}
}
// oyunun bitmesi için kontrol
// oyun bitmesi için sað-sola,yukarý-asaðý,veya çapraz 4 tane ayný sayý denk gelmeli 1 veya 2
int bittirme(int p[a][b]){
	int i,j,t,g,k,l,c,d,x,y,m,n,q,w,draw;
	draw=0;
	//yukarý-asaðý kontrol
	for(j=1;j<=7;j++){
		for(i=1;i<=3;i++){
			if(p[i][j]==p[i+1][j] && p[i+1][j]==p[i+2][j] && p[i+2][j]==p[i+3][j] && p[i][j]!=0){ 
			  if(p[i][j]==2){
			  	return 2;
			  }
			  else {
			  	return 1;
			  }
			}
		}
	}
	// sað-sola kontrol
	for(t=1;t<=6;t++){
		for(g=1;g<=4;g++){
			if(p[t][g]==p[t][g+1] && p[t][g+1]==p[t][g+2] && p[t][g+2]==p[t][g+3] && p[t][g]!=0){
				if(p[t][g]==1){
					return 1;
				}
				else {
					return 2;
				}
			}
		}
	}
	//çapraz kontrol sað asaðý
	for(k=1;k<=3;k++){
		for(l=1;l<=4;l++){
			if(p[k][l]==p[k+1][l+1] && p[k+1][l+1]==p[k+2][l+2] && p[k+2][l+2]==p[k+3][l+3] && p[k][l]!=0){
				if(p[k][l]==1){
					return 1;
				}
				else {
					return 2;
				}
			}
		}
	}
// çapraz sað asaðý
for(c=1;c<=3;c++){
	for(d=7;d>=4;d--){
		if(p[c][d]==p[c+1][d-1] && p[c+1][d-1]==p[c+2][d-2] && p[c+2][d-2]==p[c+3][d-3] && p[c][d]!=0){
			if(p[c][d]==2){
				return 2;
			}
			else {
				return 1;
			}
		}
	}
}
//çapraz sol yukarý
for(x=6;x>=4;x--){
	for(y=7;y>=4;y--){
		if(p[x][y]==p[x-1][y-1] && p[x-1][y-1]==p[x-2][y-2] && p[x-2][y-2]==p[x-3][y-3] && p[x][y]!=0){
			if(p[x][y]==2){
				return 2;
			}
			else {
				return 1;
			}
		}
	}
}
//çapraz sol asaðý
for(m=6;m>=4;m--){
	for(n=1;n<=4;n++){
		if(p[m][n]==p[m-1][n+1] && p[m-1][n+1]==p[m-2][n+2] && p[m-2][n+2]==p[m-3][n+3] && p[m][n]!=0){
			if(p[m][n]==2){
				return 2;
			}
			else {
				return 1;
			}
		}
	}
}
//berabere kalma kontrolu
for(q=1;q<=6;q++){
	for(w=1;w<=7;w++){
		if(p[q][w]!=0){
			draw++;
		}
	}
}
if(draw==42){
	return 3;
}
	return 0;
}
// geçersýz girdiler için
void hata(){
	printf("\n\t\t\t\tTRY ANOTHER NUMBER\n");
}
int main(void) {
int ktrl=0; 
while(ktrl==0){
	system("cls");
int p[8][8];
int i,j,k,x,ctrl,dolu,player;
ctrl=0;
player=1;
//ilk deðerlerine atama
for(i=1;i<=6;i++){
	for(j=1;j<=7;j++){
		p[i][j]=0;
	}
}
for(k=1;k<=7;k++){
	p[7][k]=3;
}
printf("\t\tWELCOME TO CONNECT FOUR GAME YOU SHOULD INPUT COLUMN NUMBER THAT YOU WANT\n\n");
yaz(p);
//oyunun ana dönðüsü
while(ctrl==0){
printf("\n\t\t\t\t%d's turn:",sira(player));
scanf("%d",&x);
if(x>7 || x<1 || p[1][x]!=0){
	hata();
}
else {
player+=1;
dolu=dolubul(p,x);
if(sira(player)==2){
p[dolu-1][x]=1;}
else{
p[dolu-1][x]=2;
}
system("cls");
yaz(p);
ctrl=bittirme(p);
}}
if(bittirme(p)==1){
	printf("FIRST PLAYER (YELLOW) WINS");
}
else if(bittirme(p)==2){
	printf("SECOND PLAYER (RED) WINS");
}
else { 
    printf("IT'S A TIE");
}
printf("\n\t\t\t\tIF YOU WANT TO PLAY AGAIN INPUT 0 ELSE INPUT ANY ANOTHER NUMBER\n\t\t\t\t:");
scanf("%d",&ktrl);
}}
