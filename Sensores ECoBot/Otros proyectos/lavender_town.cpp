#include <Arduino.h>

/*
BUCLE: 1do^ 1sol^ 1si^ 1#fa^ (4 primeras veces, luego 20 con otro arduino), en micaso solo 4 veces

4 silencios entonces => 2SOL, 2SOL, 2#FA, 2#FA, 1SOL 1#FA 1MI 1SI , 1MI 1DO 1SIv 1MI
			2SOL, 2SOL, 2#FA, 2#FA, 1SI, 1SOL, 1FA# 1SI, 2DO^ 2DO^ (2 Veces)

			4MI	4RE	4DO		1MI, 1DO, 1SIv 1MI 	      :||

S O L O   M U E R T E
*/

#define SIv 494 //SI v
#define DO 523 //C
#define RE 587 //D
#define MI 659 //E
#define FA 698 //F
#define SOL 784 //G
#define LA 880 //A
#define SI 988 //B
#define DOs 1047 //C#
#define REs 1175 //D#
#define MIs 1319 //E#
#define FAs 1397 //F#

void setup() {
}

// ARDUINO BUCLE
void loop() {
    int i=0;
    // int cancion[] = {do,sol,si,fa};
    // int duracion[] = {1,1,1,1};

    // for(int i=0;i<24;i++){ 
    // for (int Nota = 0; Nota < 4; Nota++){
    //     float Duracion = duracion[Nota]*500;
    //     tone(13, cancion[Nota]);
    //     delay(Duracion);
    //     noTone(13);
    //             }
    //         i++;
    // }

//ARDUINO MELODÍA : 16 SEGUNDOS DE SILENCIO, LUEGO
  int song2[] ={SOL, SOL, FA, FA,
               SOL, FA, MI, SI,
               MI, DO, SIv, MI,
               SOL, SOL, FA, FA,
               SI, SOL, FA, SI,
               DOs,DO,DOs,DO,
               MI, RE, DO,
               MI,DO,SIv,MI};
  
  int duracion2[]={2,2,2,2,
                  1,1,1,1,
                  1,1,1,1,
                  2,2,2,2,
                  1,1,1,1,
                  1,1,1,1,
                  4,4,4,
                  1,1,1,1};

  for(int j=0;j<31;j++){
    float Duracion2 = duracion2[j]*500;
    tone(13, song2[j]);
    delay(Duracion2);
    noTone(13);
  	}
}