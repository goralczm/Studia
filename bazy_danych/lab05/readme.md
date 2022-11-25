# Bazy Danych Lab 5

## Zadanie 1

```sql=
CREATE TABLE kreatura SELECT * FROM wikingowie.kreatura;
CREATE TABLE zasob SELECT * FROM wikingowie.zasob;
CREATE TABLE ekwipunek SELECT * FROM wikingowie.ekwipunek;

SELECT * FROM zasob;

SELECT * FROM zasob WHERE rodzaj = 'jedzenie';

SELECT idZasobu FROM ekwipunek WHERE idKreatury IN (1,3,5);
```

## Zadanie 2
```sql=
SELECT * FROM kreatura WHERE rodzaj != 'wiedzma' AND udzwig >= 50;

SELECT * FROM zasob WHERE waga BETWEEN 2 AND 5;

SELECT * FROM kreatura WHERE nazwa LIKE '%or%' AND udzwig BETWEEN 30 AND 70;
```

## Zadanie 3
```sql=
SELECT * FROM zasob WHERE MONTH(dataPozyskania) IN (7, 8);

SELECT * FROM zasob WHERE rodzaj IS NOT NULL ORDER BY waga ASC;

SELECT * FROM kreatura ORDER BY dataUr DESC LIMIT 5;
```

## Zadanie 4
```sql=
SELECT DISTINCT rodzaj FROM zasob WHERE rodzaj IS NOT NULL;

SELECT CONCAT(nazwa, ' - ', rodzaj) AS 'Nazwa - Rodzaj' FROM kreatura WHERE rodzaj LIKE 'wi%';

SELECT *, (ilosc*waga) AS 'Całkowita waga' FROM zasob WHERE YEAR(dataPozyskania) BETWEEN 2000 AND 2007;
```

## Zadanie 5
```sql=
SELECT *, (waga-(waga*0.3)) AS 'Masa właściwa', (waga*0.3) AS 'Masa odpadków' FROM zasob;

SELECT * FROM zasob WHERE rodzaj IS NULL;

SELECT DISTINCT rodzaj FROM zasob WHERE rodzaj IS NOT NULL AND nazwa LIKE 'ba%' OR nazwa LIKE '%os' ORDER BY rodzaj ASC;
```