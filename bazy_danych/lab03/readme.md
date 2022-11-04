# Bazy Danych Lab 3

## Zadanie 1

```sql=
CREATE TABLE postac ( id_postaci int auto_increment primary key,
                     nazwa varchar(40),
                     rodzaj enum('wiking', 'ptak', 'kobieta'),
                     data_ur date,
                     wiek int unsigned);
INSERT INTO postac VALUES (null, 'Bjorn', 'wiking', '2000-01-01', 22);
INSERT INTO postac VALUES (null, 'Drozd', 'ptak', '1995-01-01', 27);
INSERT INTO postac VALUES (null, 'Tesciowa', 'kobieta', '1994-01-01', 28);
UPDATE postac SET wiek = 88 WHERE id_postaci = 3;
```

## Zadanie 2

```sql=
CREATE TABLE walizka ( id_walizki int auto_increment primary key,
                      pojemnosc int unsigned,
                      kolor enum('rozowy', 'czerwony', 'teczowy', 'zolty'),
                      id_wlasciciela int,
                      foreign key (id_wlasciciela) references postac(id_postaci) ON DELETE CASCADE);
INSERT INTO walizka VALUES (null, 100, 'teczowy', '1');
INSERT INTO walizka VALUES (null, 20, 'rozowy', '3');
ALTER TABLE walizka ALTER kolor SET DEFAULT 'rozowy';
```

## Zadanie 3

```sql=
CREATE TABLE izba ( adres_budynku VARCHAR(250),
                   nazwa_izby VARCHAR(100),
                   metraz INT UNSIGNED,
                   id_wlasciciela INT,
                   FOREIGN KEY(id_wlasciciela) REFERENCES postac(id_postaci) ON DELETE SET NULL,
                   PRIMARY KEY(adres_budynku, nazwa_izby));
ALTER TABLE izba ADD COLUMN kolor enum('czarny', 'zolty', 'niebieski') DEFAULT 'czarny' AFTER metraz;
INSERT INTO izba VALUES ('Mila 15a', 'Spizarnia', '350', 'niebieski', 1);
```

## Zadanie 4

```sql=
CREATE TABLE przetwory ( id_przetworu INT AUTO_INCREMENT PRIMARY KEY,
                        rok_produkcji INT(4) DEFAULT 1654,
                        id_wykonawcy INT, zawartosc VARCHAR(250),
                        dodatek VARCHAR(50) DEFAULT 'chilli',
                        id_konsumenta INT,
                        FOREIGN KEY (id_wykonawcy) REFERENCES postac(id_postaci) ON DELETE CASCADE,
                        FOREIGN KEY (id_konsumenta) REFERENCES postac(id_postaci) ON DELETE CASCADE);
INSERT INTO przetwory VALUES (null, '1555', 1, 'bigos', default, 3);
```

## Zadanie 5

```sql=
INSERT INTO postac VALUES (null, 'Frigg', 'wiking', '1000-01-01', 1022),
(null, 'Torkel', 'wiking', '1001-01-01', 1023),
(null, 'Orval', 'wiking', '1002-01-01', 1024),
(null, 'Randel', 'wiking', '1000-01-01', 1022),
(null, 'Haldor', 'wiking', '1003-01-01', 1025),
(null, 'Gudbrand', 'wiking', '1004-01-01', 1026);

CREATE TABLE statek (nazwa_statku VARCHAR(100) PRIMARY KEY,
                     rodzaj_statku ENUM('lodz', 'slup', 'brygantyna', 'galeon'),
                     data_wodowania DATE, max_ladownosc INT UNSIGNED);

INSERT INTO statek VALUES ('Zelazny Ptaszek', 'brygantyna', '1005-01-01', 250), ('Malpia Brygada', 'slup', '1006-05-06', 50);

ALTER TABLE postac ADD COLUMN funkcja VARCHAR(50);
ALTER TABLE postac ALTER COLUMN funkcja SET DEFAULT 'majtek';
UPDATE postac SET funkcja = 'majtek';
UPDATE postac SET funkcja = 'kapitan' WHERE id_postaci = 1;

ALTER TABLE postac ADD COLUMN nazwa_statku VARCHAR(100);
ALTER TABLE postac ADD FOREIGN KEY (nazwa_statku) REFERENCES statek(nazwa_statku);

UPDATE postac SET nazwa_statku = 'Malpia Brygada' WHERE id_postaci BETWEEN 4 AND 9;
UPDATE postac SET nazwa_statku = 'Zelazny Ptaszek' WHERE id_postaci = 1 OR id_postaci = 2;
DELETE FROM izba WHERE nazwa_izby = 'Spizarnia';
DROP TABLE izba;
```