--Autor: Yeison Herbert Churquipa Yanqui
--yeison.churquipa.y@uni.pe
use DBSistemaRiego;

create database DBSistemaRiego;
use DBSistemaRiego;

drop table HistorialSensor;

CREATE TABLE HistorialSensor
(
    id        int  NOT NULL AUTO_INCREMENT,
    sensor    VARCHAR(30) NOT NULL,
    ubicacion VARCHAR(30) NOT NULL,
    valor     DECIMAL(9,2) UNSIGNED   NOT NULL,
    creacion  DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id)
);

insert into HistorialSensor(sensor,ubicacion,valor) value ('FC28','Jardin 2',1024);
insert into HistorialSensor(sensor,ubicacion,valor) value ('FC28','Jardin 2',370);

select id, sensor, ubicacion, valor, creacion from HistorialSensor