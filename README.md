# 8 Queen
  8 queen merupakan permasalahan untuk meletakkan 8 ratu pada papan catur berukuran 8x8 sedemikian hingga tidak ada ratu yang saling serang. Karena pada catur, ratu dapat menyerang secara diagonal, sebaris, dan sekolom, maka kita harus meletakkan ratu-ratu tersebut sedemikian hingga tidak ada ratu yang berada pada baris, kolom, dan diagonal yang sama.
 
# Penjelasan
Fungsi check merupakan fungsi untuk mengecek apakah peletakan ratu saat ini memiliki diagonal dan baris yang sama. Untuk peletakan secara kolom tidak dicek, karena program ini hanya meletakkan 1 ratu pada 1 kolom, lalu pindah ke kolom selanjutnya.
```
int check(int queen[], int col){
	int i;
	for(i = 0; i < col; i++){
		if((queen[i] == queen[col]) || (abs(queen[col] - queen[i]) == (col - i))){
			return 0;
        }
    }
    return 1;
}

```
Fungsi back merupakan fungsi untuk kembali ke kolom sebelumnya. Fungsi ini akan dipanggil jika peletakan ratu pada kolom saat ini tidak terdapat baris yang aman sehingga perlu kembali ke kolom sebelumnya untuk menggeser ratu ke baris yang lain.
```
void back(int &col){
    col--;
    if(col==-1){
    	exit(0);
	}
}
```
Fungsi print merupakan fungsi untuk menampilkan solusi untuk peletakan 8 queen yang berhasil dilakukan.
```
void print(int queen[]){
	static int count =0;
    count++;
    int i, j, board[8][8]={0};
    printf("Solusi %d\n", count);
    for(i = 0; i < 8; i++){
        board[queen[i]][i] = 1;           
    }
     //print  
    for(i = 0; i < 8; i++){ 
		for(j = 0; j < 8; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
    }
}
```
Pada main, ```int queen[8]; queen[0]=0; ``` menyimpan baris dimana ratu berada dan ``` int c=1; ``` untuk menandai kolom. ``` bool fromback ``` menandai apakah kita butuh mereset baris ke paling atas kolom. Pada main dilakukan loop untuk tiap kolom dan mencoba meletakkan queen pada tiap baris di kolom untuk mencari kemungkinan yang bisa. Jika sampai baris 8 pada kolom tidak ditemukan solusi maka memanggil fungsi back() dan melanjutkan loop baris dari kolom sebelumnya. Namun kalau posisi queen saat ini aman, letakkan queen kemudian break ke kolom selanjutnya, kalau tidak, terus ke baris lain di kolom saat ini. Program hanya akan menampilkan hasil solusi-solusi yang memungkinkan pada papan catur dengan '1' menandakan queen dan '0' menandakan sel kosong. Tidak ada input yang diperlukan, user hanya perlu menekan tombol enter untuk memunculkan solusi selanjutnya yang memungkinkan.
```
int main(){
	int queen[8]; queen[0]=0;
    int c=1; 
	bool fromback = false;
    while(1){
		while( c < 8){
        	if( !fromback ){
        		queen[c]=-1;
			}
            fromback = false;
            while( queen[c] < 8){
            	queen[c]++;
                while(queen[c]==8){
					back(c);
                    queen[c]++;              
                }
                if(check(queen, c) == 1){
					break;
				}                   
            }
        	c++;
     	}
	    print(queen);
	    cin.get();
	    back(c);
	    fromback = true;
    }
}
```
