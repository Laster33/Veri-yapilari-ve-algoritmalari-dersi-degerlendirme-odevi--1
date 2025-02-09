#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Tarih {
    int yil;
    int ay;
    int gun;
    int saat;
};

union EpochZaman {
    time_t timeT;
    long longInt;
};

struct Tarih tarihAl() {
    struct Tarih t;

    printf("Yil girin: ");
    scanf("%d", &t.yil);

    printf("Ay girin: ");
    scanf("%d", &t.ay);

    printf("Gun girin: ");
    scanf("%d", &t.gun);

    printf("Saat girin: ");
    scanf("%d", &t.saat);

    return t;
}

time_t epochHesapla(struct Tarih t) {
    struct tm zamanBilgisi = {0};

    zamanBilgisi.tm_year = t.yil - 1900;
    zamanBilgisi.tm_mon = t.ay - 1;
    zamanBilgisi.tm_mday = t.gun;
    zamanBilgisi.tm_hour = t.saat;
    zamanBilgisi.tm_min = 0;
    zamanBilgisi.tm_sec = 0;

    return mktime(&zamanBilgisi);
}

int main() {
    struct Tarih tarih1, tarih2;
    union EpochZaman epoch1, epoch2;

    printf("Birinci tarih bilgilerini girin:\n");
    tarih1 = tarihAl();

    printf("\nIkinci tarih bilgilerini girin:\n");
    tarih2 = tarihAl();

    epoch1.timeT = epochHesapla(tarih1);
    epoch2.timeT = epochHesapla(tarih2);

    printf("\nBirinci tarihin epoch zamani: %ld\n", epoch1.longInt);
    printf("Ikinci tarihin epoch zamani: %ld\n", epoch2.longInt);

    long zamanFarki = abs(epoch2.timeT - epoch1.timeT);
    printf("\nIki tarih arasindaki zaman farki: %ld saniye\n", zamanFarki);

	long gun = zamanFarki / (24 * 60 * 60);
    long saat = (zamanFarki % (24 * 60 * 60)) / (60 * 60); 

    printf("Zaman farki: %ld gun, %ld saat\n", gun, saat);

    return 0;
}
