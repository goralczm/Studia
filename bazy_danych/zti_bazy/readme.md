# ZTI Bazy

# Lab 3 Zadania 1

## Zadanie 1
```sql
SELECT imie,
nazwisko,
YEAR(data_urodzenia) as 'Rok urodzenia'
FROM pracownik;
```

## Zadanie 2
```sql
SELECT imie,
nazwisko,
2023-YEAR(data_urodzenia) as 'Wiek'
FROM pracownik;
```

## Zadanie 3
```sql
SELECT dzial.nazwa,
COUNT(id_pracownika) as 'Ilosc pracownikow'
FROM pracownik, dzial
WHERE pracownik.dzial = dzial.id_dzialu
GROUP BY dzial.nazwa;
```

## Zadanie 4
```sql
SELECT k.nazwa_kategori,
COUNT(id_towaru) as 'Liczba produktow'
FROM towar as t, 
kategoria as k
WHERE t.kategoria = k.id_kategori
GROUP BY k.nazwa_kategori;
```

## Zadanie 5
```sql
SELECT k.nazwa_kategori,
GROUP_CONCAT(t.nazwa_towaru)
FROM towar as t,
kategoria as k
WHERE t.kategoria = k.id_kategori
GROUP BY k.nazwa_kategori;
```

## Zadanie 6
```sql
SELECT ROUND(AVG(pensja), 2) as 'Srednia pensja'
FROM pracownik;
```

## Zadanie 7
```sql
SELECT ROUND(AVG(pensja), 2) as 'Srednia pensja'
FROM pracownik
WHERE 2023-YEAR(data_zatrudnienia) >= 5;
```

## Zadanie 8
```sql
SELECT nazwa_towaru,
COUNT(ilosc) as 'Ilosc sprzedanych'
FROM towar, pozycja_zamowienia as pz
WHERE towar.id_towaru = pz.towar
GROUP BY towar
ORDER BY COUNT(ilosc) DESC
LIMIT 10;
```

## Zadanie 9
```sql
SELECT z.numer_zamowienia,
SUM(cena) as 'Wartosc zamowienia'
FROM zamowienie as z,
pozycja_zamowienia as pz
WHERE pz.zamowienie = z.id_zamowienia
AND z.data_zamowienia BETWEEN '2017-01-01' AND '2017-04-30'
GROUP BY zamowienie;
```

## Zadanie 10
```sql
SELECT p.imie, p.nazwisko,
SUM(cena) as 'Wartosc dodanych zamowien'
FROM zamowienie as z,
pozycja_zamowienia as pz,
pracownik as p
WHERE pz.zamowienie = z.id_zamowienia
AND z.pracownik_id_pracownika = p.id_pracownika
GROUP BY p.id_pracownika
ORDER BY SUM(cena) DESC;
```

# Lab 3 Zadania 2

## Zadanie 1
```sql
SELECT dzial.nazwa,
ROUND(MIN(p.pensja), 2) as 'Minimalna pensja',
ROUND(MAX(p.pensja), 2) as 'Maksymalna pensja',
ROUND(AVG(p.pensja), 2) as 'Srednia pensja'
FROM dzial, pracownik as p
WHERE p.dzial = dzial.id_dzialu
GROUP BY dzial.nazwa;
```

## Zadanie 2
```sql
SELECT k.pelna_nazwa,
SUM(pz.cena) as 'Suma zamowien'
FROM zamowienie as z,
pozycja_zamowienia as pz,
klient as k
WHERE pz.zamowienie = z.id_zamowienia
AND z.klient = k.id_klienta
GROUP BY z.klient
ORDER BY SUM(pz.cena) DESC
LIMIT 10;
```

## Zadanie 3
```sql
SELECT YEAR(z.data_zamowienia) as 'Rok',
SUM(cena) as 'Wartosc zamowienia'
FROM zamowienie as z,
pozycja_zamowienia as pz
WHERE pz.zamowienie = z.id_zamowienia
GROUP BY YEAR(z.data_zamowienia)
ORDER BY SUM(cena) DESC;
```

## Zadanie 4
```sql
SELECT SUM(cena) as 'Suma anulowanych zamowien'
FROM zamowienie as z,
status_zamowienia as sz,
pozycja_zamowienia as pz
WHERE pz.zamowienie = z.id_zamowienia
AND z.status_zamowienia = sz.id_statusu_zamowienia
AND sz.id_statusu_zamowienia = 6;
```

## Zadanie 5
```sql
SELECT ak.miejscowosc,
COUNT(z.id_zamowienia)
FROM klient as k,
zamowienie as z,
adres_klienta as ak
WHERE k.id_klienta = ak.klient
AND k.id_klienta = z.klient
AND ak.typ_adresu = 1
GROUP BY ak.miejscowosc;
```

## Zadanie 6
```sql
SELECT SUM(pz.cena) as 'Dochod firmy'
FROM zamowienie as z,
pozycja_zamowienia as pz
WHERE pz.zamowienie = z.id_zamowienia
AND z.status_zamowienia = 5;
```

## Zadanie 7
```sql
SELECT YEAR(z.data_zamowienia),
SUM(pz.cena) - SUM(t.cena_zakupu)
FROM zamowienie as z,
pozycja_zamowienia as pz,
towar as t
WHERE z.id_zamowienia = pz.zamowienie
AND pz.towar = t.id_towaru
AND z.status_zamowienia = 5
GROUP BY YEAR(z.data_zamowienia);
```

## Zadanie 8
```sql
SELECT k.nazwa_kategori,
SUM(sm.ilosc * t.cena_zakupu) as 'Wartosc produktow'
FROM towar as t,
stan_magazynowy as sm,
kategoria as k
WHERE t.id_towaru = sm.towar
AND t.kategoria = k.id_kategori
GROUP BY k.nazwa_kategori;
```

## Zadanie 9
```sql
SELECT MONTHNAME(data_urodzenia),
COUNT(id_pracownika)
FROM pracownik
GROUP BY MONTH(data_urodzenia)
ORDER BY MONTH(data_urodzenia);
```

## Zadanie 10
```sql
SELECT imie,
nazwisko,
(2023-YEAR(data_zatrudnienia))*12*pensja as 'Wydane na pracownika'
FROM pracownik;
```