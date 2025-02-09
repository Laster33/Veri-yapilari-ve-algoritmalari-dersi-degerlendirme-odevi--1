# Veri-yapilari-ve-algoritmalari-dersi-degerlendirme-odevi--1

Bu C programı, kullanıcıdan iki tarih alır ve bu tarihler arasındaki zaman farkını hesaplar. Program, tarihleri epoch zamanına (1 Ocak 1970'ten bu yana geçen saniye sayısı) dönüştürür ve iki tarih arasındaki farkı saniye, gün ve saat cinsinden gösterir.

## Nasıl Çalışır?

1. Program, kullanıcıdan iki tarih bilgisi ister:
   - Yıl
   - Ay
   - Gün
   - Saat

2. Girilen tarihler, `mktime()` fonksiyonu kullanılarak epoch zamanına dönüştürülür.

3. İki epoch zamanı arasındaki fark hesaplanır ve bu fark saniye, gün ve saat cinsinden ekrana yazdırılır.

## Kod Yapısı

- **`struct Tarih`**: Tarih bilgilerini (yıl, ay, gün, saat) saklamak için kullanılan bir yapı.
- **`union EpochZaman`**: Epoch zamanını hem `time_t` hem de `long` türünde saklamak için kullanılan bir birleşim (union).
- **`tarihAl()`**: Kullanıcıdan tarih bilgilerini alır ve `struct Tarih` türünde döndürür.
- **`epochHesapla()`**: Verilen tarihi epoch zamanına dönüştürür.
- **`main()`**: Programın ana işlevi. Kullanıcıdan iki tarih alır, epoch zamanlarını hesaplar ve aralarındaki farkı gösterir.

## Nasıl Kullanılır?

1. Programı derleyin:
   ```bash
   gcc -o epoch_hesapla epoch_hesapla.c
