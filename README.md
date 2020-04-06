# 8 Puzzle BFS

# Penjelasan

# 8 Puzzle DFS
  Metode DFS melakukan expand ke seluruh node yang berisi semua kemungkinan state secara urut satu persatu. Dalam eksplorasinya, DFS berjalan menuju node terjauh terlebih dahulu (Depth-First) sehingga pencarian goal state bisa saja tidak ditemukan atau bisa saja langkah yang ditemukan bukanlah langkah tercepat menuju ke goal state mengingat banyak kemungkinan bisa muncul dan ada banyak percabangan yang dapat terjadi di permasalahan 8 puzzle.
  
  
  File:
  - <a href = "https://github.com/rddmoon/AI1_Uninformed_Search/blob/master/8-puzzle-dfs/8-puzzle-dfs.cpp">8-puzzle-dfs.cpp</a>
  
# Penjelasan
Global variabel yang dibutuhkan. array state berukuran 9x9x9x9x9x9x9x9x9 memiliki fungsi yang mirip dengan tree node sebagai penyimpanan untuk state-state yang mungkin terjadi di 8 puzzle.
```
int node = 0;
int goal[9];
int solution = 0;
int state[9][9][9][9][9][9][9][9][9];
```
Pada fungsi main didefinisikan goal state untuk 8 puzzle dan menampilkannya ke layar. Kemudian input dari use untuk initial state dari 8 puzzle. Di sini juga terdapat pemanggil fungsi DFS dan menampilkan langkah penyelesaiannya serta node dari goal state ke layar. Pada program ini, angka '0' dijadikan sebagai patokan dalam menggeser angka di puzzle ke arah angka '0' (angka '0' dianggap sebagai space kosong dalam puzzle) untuk menemukan solusinya.
```
int main(){
    
    int game[9];
    int X;
    //buat goal
    goal[0] = 1;
    goal[1] = 2;
    goal[2] = 3;
    goal[3] = 4;
    goal[4] = 5;
    goal[5] = 6;
    goal[6] = 7;
    goal[7] = 0;
    goal[8] = 8;
    
    printf("Goal State:\n");
	  for(int i = 0;i < 3; i++){
        printf("%d ",goal[i]);
    }
    printf("\n");
    for(int i = 3;i < 6; i++){
        printf("%d ",goal[i]);
    }
    printf("\n");
    for(int i = 6;i < 9; i++){
        printf("%d ",goal[i]);
    }
    printf("\n");
    first:
    printf("\nInput initial state:\n");
    
    for(int i = 0;i < 9; i++){
        scanf("%d",&game[i]);
        if(game[i]==0){
            X = i;
        }
        if(game[i] > 9 || game[i] < 0){
        	printf("Input should be numbers from 0 to 8\n");
        	game[9] = {0};
        	goto first;
		}
    }
    memset(state, 0, sizeof(state[0][0][0][0][0][0][0][0][0])*9*9*9*9*9*9*9*9*9);
    DFS(game, X, "\nPath:\n");
    printf("\nNode: %d\n", node);
}
```
Pada fungsi DFS terdapat kondisi untuk mengecek apakah state sudah pernah dikunjungi sehingga tidak perlu dicek kembali.
```
if(state[game[0]][game[1]][game[2]][game[3]][game[4]][game[5]][game[6]][game[7]][game[8]]==0){
        node++;
        state[game[0]][game[1]][game[2]][game[3]][game[4]][game[5]][game[6]][game[7]][game[8]]=1;
    }else{
        return;
    }
```
Kode bagian di bawah ini berfungsi untuk mengecek apakah sudah mencapai goal state dan menampilkan path penyelesaian ke layar.
```
int find = 0;
    for(int i=0;i < 9;i++){   
        if(game[i] != goal[i] ){
            find = 1;
            break;
        }
    }
    if(find == 0){
        	solution = 1;
            printf("%s",path.c_str());
            return;
        }
```
Pada fungsi DFS juga terdapat kondisi dalam melakukan eksplorasi, apakah perlu mengeser angka ke atas, ke bawah, ke kanan, atau ke kiri menuju ke arah angka '0' yang merupakan tempat kosong yang konsepnya seperti pada permainan 8 puzzle biasa.
```
if(X < (3 * 2)){
        game[X] = game[X+3];
        game[X+3] =0;
        DFS(game, X+3, path+"Up\n");
        game[X+3] = game[X];
        game[X] = 0;
    }
    if((X+1) % 3 !=1 ){
        game[X] = game[X-1];
        game[X-1]=0;
        DFS(game,X-1,path+"Right\n");
        game[X-1]=game[X];
        game[X]=0;
    }
    if((X+1) % 3 !=0 ){
        game[X] = game[X+1];
        game[X+1]=0;
        DFS(game,X+1,path+"Left\n");
        game[X+1]=game[X];
        game[X]=0;
    }
    if(X > 2){
        game[X] = game[X-3];
        game[X-3]= 0;
        DFS(game,X-3,path+"Down\n");
        game[X-3]=game[X];
        game[X]=0;   
    }
```

# 8 Puzzle IDS
   Pada DFS, saat melakukan pencarian dapat terjadi masalah infinite depth. Terkadang solusi bisa berada pada cabang node yang sangat jauh dari induk, sehingga saat melakukan pencarian, DFS terus mengeksplorasi cabang-cabang itu seperti tidak ada ujungnya dan malah dapat menjauhkan dari goal atau tujuan. DFS terus melakukan ekspansi secara tak hingga dan menyebabkannya melewati cabang yang dapat menuju ke node solusi. 
   
   IDS atau Iterative Deepening Search merupakan sebuah algoritma pengembangan dari DFS. Pada IDS, untuk menghindari infinite depth pada DFS dilakukan pembatasan pada depth yang dicari sehingga pencarian hanya terbatas sampai depth itu. Kemudian jika sampai depth yang ditetapkan masih belum menemukan goal state atau solusi, maka ditambahkan depth secara iteratif. IDS juga membantu algoritma DFS menemukan langkah terpendek atau solusi yang paling dekat dengan node induk.
   
   File:
   - <a href = "https://github.com/rddmoon/AI1_Uninformed_Search/blob/master/8-puzzle-ids/8-puzzle-ids.cpp">8-puzzle-ids.cpp</a>
   
# Penjelasan
Source code kurang lebih sama dengan penjelasan 8 puzzle DFS, karena hanya ditambahkan limit untuk depth yang perlu ditelusuri. Limit depth berada di fungsi main. Pada awal depth = 0 kemudian menjadi 10 sebelum memanggil fungsi DFS. While loop menambahkan depth secara iteratif selama solusi belum ditemukan.
```
int depth = 0;
    while (!solution){
        depth += 10;
        memset(state, 0, sizeof(state[0][0][0][0][0][0][0][0][0])*9*9*9*9*9*9*9*9*9);
        DFS(game, X, "\nPath:\n", depth);
    } 
```

# 8 Queen
  8 queen merupakan permasalahan untuk meletakkan 8 ratu pada papan catur berukuran 8x8 sedemikian hingga tidak ada ratu yang saling serang. Karena pada catur, ratu dapat menyerang secara diagonal, sebaris, dan sekolom, maka kita harus meletakkan ratu-ratu tersebut sedemikian hingga tidak ada ratu yang berada pada baris, kolom, dan diagonal yang sama.
  
  File:
  - <a href = "https://github.com/rddmoon/AI1_Uninformed_Search/blob/master/8-queen/8-queen.cpp">8-queen.cpp</a>
 
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
