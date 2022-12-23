# Bazy Danych Lab 5

## Zadanie 1
```sql=
CREATE TABLE uczestnicy SELECT * FROM wikingowie.uczestnicy;
CREATE TABLE etapy_wyprawy SELECT * FROM wikingowie.etapy_wyprawy;
CREATE TABLE sektor SELECT * FROM wikingowie.sektor;
CREATE TABLE wyprawa SELECT * FROM wikingowie.wyprawa;
```
```sql=
SELECT * FROM uczestnicy;
SELECT k.nazwa, id_wyprawy
FROM kreatura k
LEFT JOIN uczestnicy u
ON k.idKreatury = u.id_uczestnika
WHERE id_wyprawy IS NULL;
```
```sql=
SELECT w.nazwa, SUM(e.ilosc)
FROM wyprawa w, uczestnicy u, ekwipunek e
WHERE w.id_wyprawy = u.id_wyprawy
AND u.id_uczestnika = e.idKreatury
GROUP BY w.nazwa;
```

## Zadanie 2
```sql=
SELECT w.nazwa, SUM(u.id_uczestnika), GROUP_CONCAT(k.nazwa)
FROM wyprawa w, uczestnicy u, kreatura k
WHERE w.id_wyprawy = u.id_wyprawy
AND u.id_uczestnika = k.idKreatury
GROUP BY w.nazwa;
```
```sql=
SELECT w.nazwa,
k.nazwa as 'Kierownik',
w.data_rozpoczecia,
ew.dziennik,
ew.idEtapu
FROM wyprawa w,
etapy_wyprawy ew,
sektor s,
kreatura k
WHERE ew.sektor = id_sektora
AND ew.idWyprawy = w.id_wyprawy
AND w.kierownik = k.idKreatury
ORDER BY w.data_rozpoczecia,
ew.idEtapu;
```

## Zadanie 3
```sql=
SELECT s.nazwa,
IFNULL(COUNT(ew.sektor), 0) AS 'Ilosc Odwiedzi'
FROM sektor s
LEFT JOIN etapy_wyprawy ew
ON s.id_sektora = ew.sektor
GROUP BY s.nazwa;
```
```sql=
SELECT k.nazwa,
IF(IFNULL(COUNT(id_wyprawy), 0) = 0, "Nie brał udziału", "Brał udział") as 'Udzial'
FROM kreatura k
LEFT JOIN uczestnicy u
ON k.idKreatury = u.id_uczestnika
GROUP BY k.nazwa
```

## Zadanie 4
```sql=
SELECT w.nazwa,
SUM(LENGTH(ew.dziennik))
FROM wyprawa w,
etapy_wyprawy ew
WHERE ew.idWyprawy = w.id_wyprawy
GROUP BY w.nazwa
HAVING SUM(LENGTH(ew.dziennik)) < 400;
```
```
SELECT w.nazwa,
SUM(e.ilosc * z.waga) / COUNT(DISTINCT u.id_uczestnika) as 'Srednia'
FROM wyprawa w,
uczestnicy u,
ekwipunek e,
zasob z
WHERE w.id_wyprawy = u.id_wyprawy
AND u.id_uczestnika = e.idKreatury
AND z.idZasobu = e.idZasobu
GROUP BY w.nazwa;
```

## Zadanie 5
```sql=
SELECT k.nazwa, w.nazwa,
DATEDIFF(w.data_rozpoczecia, k.dataUr) as 'Wiek w dniach'
FROM kreatura k,
etapy_wyprawy ew,
wyprawa w,
sektor s
WHERE ew.sektor = s.id_sektora
AND ew.idWyprawy = w.id_wyprawy
AND s.nazwa = "Chatka dziadka";
```