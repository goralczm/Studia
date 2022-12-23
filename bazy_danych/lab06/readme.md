# Bazy Danych Lab 6

## Zadanie 1
```sql=
SELECT AVG(waga) AS 'sredniaWaga'
FROM kreatura
WHERE rodzaj = 'wiking';
```
```sql=
SELECT rodzaj,
COUNT(*),
AVG(waga) AS 'sredniaWaga'
FROM kreatura
GROUP BY rodzaj;
```
```sql=
SELECT COUNT(*),
AVG(2022-YEAR(dataUr)) AS 'sredniWiek'
FROM kreatura
GROUP BY rodzaj;
```

## Zadanie 2
```sql=
SELECT rodzaj,
SUM(waga)
FROM zasob
GROUP BY rodzaj;
```
```sql=
SELECT nazwa,
AVG(waga)
FROM zasob
GROUP BY nazwa
HAVING SUM(ilosc) > 3
AND SUM(waga) > 10;
```
```sql=
SELECT COUNT(nazwa),
rodzaj
FROM zasob
WHERE rodzaj IS NOT NULL
GROUP BY rodzaj;
```

## Zadanie 3
```sql=
SELECT kreatura.nazwa,
SUM(ilosc)
FROM ekwipunek, kreatura
WHERE ekwipunek.idKreatury = kreatura.idKreatury
GROUP BY ekwipunek.idKreatury;
```
```sql=
SELECT k.nazwa,
z.nazwa
FROM ekwipunek AS e,
kreatura AS k,
zasob AS z
WHERE e.idKreatury = k.idKreatury
AND e.idZasobu = z.idZasobu
ORDER BY k.nazwa;
```
```sql=
SELECT k.nazwa
FROM kreatura AS k
LEFT JOIN ekwipunek AS e
ON k.idKreatury = e.idKreatury
WHERE e.ilosc IS NULL;
```

## Zadanie 4
```sql=
SELECT k.nazwa, z.nazwa
FROM kreatura AS k,
zasob AS z
NATURAL JOIN ekwipunek AS e
WHERE k.rodzaj = 'wiking'
AND YEAR(dataUr) BETWEEN 1670 AND 1679;
```
```sql=
SELECT k.nazwa,
z.rodzaj,
(2022-YEAR(k.dataUr)) AS 'wiek'
FROM kreatura AS k,
zasob AS z,
ekwipunek AS e
WHERE e.idKreatury = k.idKreatury
AND e.idZasobu = z.idZasobu
AND z.rodzaj = 'jedzenie'
ORDER BY wiek ASC
LIMIT 5;
```
```sql=
SELECT k1.nazwa, k2.nazwa
FROM kreatura AS k1
INNER JOIN kreatura AS k2
ON k1.idKreatury + 5 = k2.idKreatury;
```

## Zadanie 5
```sql=
SELECT * FROM kreatura;
SELECT * FROM ekwipunek;
SELECT * FROM zasob;
```
```sql=
SELECT k.rodzaj, AVG(z.waga * z.ilosc * e.ilosc) FROM kreatura AS k,
ekwipunek AS e,
zasob AS z
WHERE e.idKreatury = k.idKreatury
AND e.idZasobu = z.idZasobu
AND k.rodzaj != 'malpa'
AND k.rodzaj != 'waz'
GROUP BY k.rodzaj
HAVING SUM(e.ilosc) < 30;
```
