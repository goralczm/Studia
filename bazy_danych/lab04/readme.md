# Bazy Danych Lab 4

## Zadanie 1

```sql=
DELETE FROM postac WHERE id_postaci = 8 or id_postaci = 9;
ALTER TABLE walizka DROP FOREIGN KEY walizka_ibfk_1;
ALTER TABLE przetwory DROP FOREIGN KEY przetwory_ibfk_1;
ALTER TABLE przetwory DROP FOREIGN KEY przetwory_ibfk_2;
ALTER TABLE postac MODIFY COLUMN id_postaci INT NOT NULL;
ALTER TABLE postac DROP PRIMARY KEY;
```

## Zadanie 2

```sql=
ALTER TABLE postac ADD COLUMN pesel CHAR(11) NOT NULL AFTER id_postaci;
ALTER TABLE postac ADD PRIMARY KEY(pesel);
UPDATE postac SET pesel=1524278743+wiek;
ALTER TABLE postac MODIFY rodzaj enum('wiking', 'ptak', 'kobieta', 'syrena');
INSERT INTO postac VALUES (8, '1524280255', 'Gertruda Nieszczera', 'syrena', '1000-01-01', 1022, 'majtek', null);
```

## Zadanie 3

```sql=
UPDATE postac SET nazwa_statku = 'Zelazny Ptaszek' WHERE nazwa LIKE '%a%';
UPDATE statek SET max_ladownosc = max_ladownosc-(max_ladownosc*0.3) WHERE data_wodowania BETWEEN '1901-01-01' AND '2000-12-31';
```